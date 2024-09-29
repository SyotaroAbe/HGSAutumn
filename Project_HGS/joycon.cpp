//========================================================================================
//
//　ジョイコンの処理[joycon.cpp]
//	Author:hashimoto kenta
//
//========================================================================================
#include "joycon.h"
#include "game.h"
#include "debugproc.h"
#include "2DEffect.h"


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

// 説明
// windowsでは“Wireless Gamepad”と認識されます。
// ランプはビットフラグで、4桁。ランプの一番上から10進数で 1, 2, 4, 8 と対応しています。
// 参考URL: https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering

#define VENDOR_ID  0x057E  // Nintendo Co., Ltd //0d1406
#define MOVE_GYRO_MIN (1.0f)
#define MOVE_ACCEL_MIN (0.02f)
#define INIT_ROT_CONTROL (0.1f)

//====================================================================
// コンストラクタ
//====================================================================
CJoycon::CJoycon()
{
    // read input report
    m_buff[0x40]; memset(m_buff, 0x00, size_t(0x40));
    // 読み込むサイズを指定。
    m_size = sizeof(m_buff);
    m_globalCount = 0;
    m_device = nullptr;
    m_Product_id = 0;
    m_Accel_AbsoluteValue = 0.0f;
    m_OldAccel_AbsoluteValue = 0.0f;
    m_bInitStick = false;
    m_InitX = 0;
    m_InitY = 0;
    m_bTriggerButton = false;
    m_bInitGyro = false;

    m_bTriggerStick = false;
    m_UpdateX = 0;
    m_UpdateY = 0;
    m_Stick = JOYSTICK_MAX;

    m_CurMode = CScene::GetMode();
    m_bRead = false;
    m_nCntRugResolved = 0;
    m_nCntRugResolved2 = 0;
    m_nCntRugResolved3 = 0;
    m_nCntRugResolved4 = 60;

    m_rot = INITVECTOR3;
    m_pos = INITVECTOR3;
    m_SlashPos = INITVECTOR3;
    m_InitSlashPos = SCREEN_CENTER;
}

//====================================================================
// デストラクタ
//====================================================================
CJoycon::~CJoycon()
{

}

//====================================
// 初期化(hidapi)
//====================================
void CJoycon::initialize_hidapi()
{
    if (hid_init()) {
        std::cerr << "Failed to initialize HIDAPI." << std::endl;
        exit(-1);
    }
}

//====================================
// ジョイコンL見つけて接続します
//====================================
hid_device* CJoycon::open_joycon_L()
{
    struct hid_device_info* devs = hid_enumerate(0, 0); // Joy-ConのベンダーIDとプロダクトID
    struct hid_device_info* devsNow = nullptr;
    hid_device* handle = nullptr;

    while (devs)
    {
        devsNow = devs;
        if (devs->product_id == CJoycon::PRODUCT_ID_L)
        {
            // プロダクトID等を指定して、HID deviceをopenする。そうすると、そのhidデバイスの情報が載ったhid_deviceが帰ってくる。
            handle = hid_open(devs->vendor_id, devs->product_id, devs->serial_number);
            m_Product_id = devs->product_id;
        }

        devs = devsNow->next;

        //メモリ開放
        if (devsNow->path)
            free(devsNow->path);
        if (devsNow->serial_number)
            free(devsNow->serial_number);
        if (devsNow->manufacturer_string)
            free(devsNow->manufacturer_string);
        if (devsNow->product_string)
            free(devsNow->product_string);

        free(devsNow);
    }
    devs = hid_enumerate(0, 0);

    //devs = hid_enumerate(0, 0);
    hid_free_enumeration(devs);
    return handle;
}

//====================================
// ジョイコンR見つけて接続します
//====================================
hid_device* CJoycon::open_joycon_R()
{
    struct hid_device_info* devs = hid_enumerate(0, 0); // Joy-ConのベンダーIDとプロダクトID
    struct hid_device_info* devsNow = nullptr;
    hid_device* handle = nullptr;

    while (devs)
    {
        devsNow = devs;
        if (devs->product_id == CJoycon::PRODUCT_ID_R)
        {
            // プロダクトID等を指定して、HID deviceをopenする。そうすると、そのhidデバイスの情報が載ったhid_deviceが帰ってくる。
            handle = hid_open(devs->vendor_id, devs->product_id, devs->serial_number);
            m_Product_id = devs->product_id;
        }

        devs = devsNow->next;

        //メモリ開放
        if (devsNow->path)
            free(devsNow->path);
        if (devsNow->serial_number)
            free(devsNow->serial_number);
        if (devsNow->manufacturer_string)
            free(devsNow->manufacturer_string);
        if (devsNow->product_string)
            free(devsNow->product_string);

        free(devsNow);
    }
    devs = hid_enumerate(0, 0);

    //devs = hid_enumerate(0, 0);
    hid_free_enumeration(devs);
    return handle;
}

//====================================
// Joyconに出力
//====================================
void CJoycon::SendSubcommand(hid_device* m_device, uint8_t command, uint8_t data[], int len, int* m_globalCount)
{
    uint8_t buf[0x40];
    memset(buf, 0x0, size_t(0x40));

    buf[0] = 1; // 0x10 for rumble only
    buf[1] = *m_globalCount; // Increment by 1 for each packet sent. It loops in 0x0 - 0xF range.

    if (*m_globalCount == 0xf0) {
        *m_globalCount = 0x00;
    }
    else {
        (*m_globalCount)++;
    }

    buf[10] = command;
    memcpy(buf + 11, data, len);

    hid_write(m_device, buf, 0x40);
}

//====================================
// センサーを有効にする
//====================================
void CJoycon::enable_sensors(hid_device* handle)
{
    uint8_t data[0x04];

    m_bIMU = true;

    hid_set_nonblocking(m_device, 0);

    // 0x30番のサブコマンドに、0x01を送信します。
    data[0] = 0x01; //Report ID
    SendSubcommand(m_device, 0x30, data, 1, &m_globalCount);

    do
    {
        data[0] = 0x30; //command
        SendSubcommand(m_device, 0x03, data, 1, &m_globalCount);

        data[0] = 0x01; //command
        SendSubcommand(m_device, 0x40, data, 1, &m_globalCount);

        data[0] = 0x03; //command
        data[1] = 0x00; //command
        data[2] = 0x01; //command
        data[3] = 0x01; //command
        SendSubcommand(m_device, 0x41, data, 1, &m_globalCount);

        // input report を受けとる。
        int ret = hid_read(m_device, m_buff, m_size);

    } while (*m_buff != 0x30 || m_buff[13] == 0);       //入力レポートのIDが48だったら、IMUデータが入っているか
}

//====================================
// IMUの更新処理
//====================================
void CJoycon::Sensor_Update()
{
    int16_t accel[3];
    int16_t gyro[3];

    m_OldAccel_AbsoluteValue = m_Accel_AbsoluteValue;
    m_OldVelocity_AbsoluteValue = m_Velocity_AbsoluteValue;

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            // 加速度を取得
            int index = 13 + 2 * i + j * 12;
            accel[i] = (m_buff[index] | (m_buff[index + 1] << 8));

            // 加速度を補正
            float correctedAccel = (float)accel[i] * 0.000244f;
            if (i == 0)
            {
                m_accel[j].x = correctedAccel;
            }
            else if (i == 1)
            {
                m_accel[j].y = correctedAccel;
            }
            else if (i == 2)
            {
                m_accel[j].z = correctedAccel;
            }
        }

        // 加速度を制御
        ControlIMU(&m_accel[j], MOVE_ACCEL_MIN);
    }

    m_Accel = m_accel[2];

    // 精度のいい加速度を算出（5ミリ秒毎に取った加速度を元に）
    m_Accel_Correction = ((m_accel[2] - m_accel[1]) + (m_accel[1] - m_accel[0])) / 2;

    // 加速度の絶対値を求める
    m_Accel_AbsoluteValue = sqrtf(m_Accel_Correction.z * m_Accel_Correction.z + m_Accel_Correction.y * m_Accel_Correction.y);

    if (m_CommonButton & BUTTON_ZLZR)
    {
        m_Velocity += m_Accel_Correction;
        m_Velocity_AbsoluteValue = sqrtf(m_Velocity.z * m_Velocity.z + m_Velocity.y * m_Velocity.y);

        m_SlashPos.x += m_Gyro_Radian.z * 0.6f;
        m_SlashPos.y -= m_Gyro_Radian.y * 0.8f;

#ifdef _DEBUG
        C2DEffect* pEffect = C2DEffect::Create();
        pEffect->SetRadius(30.0f);
        pEffect->SetPos(m_SlashPos);
        CManager::GetInstance()->GetDebugProc()->Print("SlashPos %f, %f, %f\n", m_SlashPos.x, m_SlashPos.y, m_SlashPos.z);
#endif // _DEBUG
    }
    else
    {
        m_Velocity = INITVECTOR3;
        m_SlashPos = SCREEN_CENTER;
    }
    m_pos += m_Velocity;

    for (int i = 0; i < 3; i++)
    {
        // 回転速度を取得
        int index = 19 + 2 * i;
        gyro[i] = (m_buff[index] | (m_buff[index + 1] << 8));

        // 回転速度を補正
        float correctedGyro = (float)gyro[i] * 0.007f; // 0.070f * 0.1f = 0.007f
        if (i == 0)
        {
            m_gyro[i] = correctedGyro;
        }
        else if (i == 1)
        {
            m_gyro[i] = correctedGyro;
        }
        else if (i == 2)
        {
            m_gyro[i] = correctedGyro;
        }
    }

    m_Gyro_Radian.x = m_gyro[0];
    m_Gyro_Radian.y = m_gyro[1];
    m_Gyro_Radian.z = m_gyro[2];

    ControlIMU(&m_Gyro_Radian, MOVE_GYRO_MIN);

    if (m_CommonButton & BUTTON_LR)
    {
        m_GyroVelocity += m_Gyro_Radian * 0.001;
    }

    else
    {
        m_GyroVelocity = INITVECTOR3;
    }

    m_rot += m_Gyro_Radian * 0.0026f;

    if (m_Product_id == PRODUCT_ID_R)
    {
        CManager::GetInstance()->GetDebugProc()->Print("Accel %f, %f, %f\n", m_Accel_Correction.x, m_Accel_Correction.y, m_Accel_Correction.z);
        CManager::GetInstance()->GetDebugProc()->Print("Gyro %f, %f, %f\n", m_Gyro_Radian.x, m_Gyro_Radian.y, m_Gyro_Radian.z);
        CManager::GetInstance()->GetDebugProc()->Print("Rot %f, %f, %f\n", m_rot.x, m_rot.y, m_rot.z);
        CManager::GetInstance()->GetDebugProc()->Print("速度 %f, %f, %f\n", m_Velocity.x, m_Velocity.y, m_Velocity.z);
        CManager::GetInstance()->GetDebugProc()->Print("pos %f, %f, %f\n", m_pos.x, m_pos.y, m_pos.z);
        CManager::GetInstance()->GetDebugProc()->Print("速度絶対値 %f\n", m_Velocity_AbsoluteValue);
    }

    if (m_CommonButton & BUTTON_LR &&
        m_bTriggerButton == true)
    {
    }
}

//====================================
// ボタンの更新処理
//====================================
void CJoycon::Button_Update()
{
    // ボタン設定
    switch (m_Product_id)
    {
    case PRODUCT_ID_L:
        SetCommonButton(m_buff[5]);
        break;

    case PRODUCT_ID_R:
        SetCommonButton(m_buff[3]);
        break;
    }

    // ボタン設定
    SetDifferButton(m_buff[4]);

    TriggerButton();

    CManager::GetInstance()->GetDebugProc()->Print("ボタン : %d\n", GetDifferButton());
}

//====================================
// スティックの更新処理
//====================================
void CJoycon::Stick_Update()
{
    uint8_t* data = m_buff + 9;

    uint16_t stick_horizontal = (data[0] | ((data[1] & 0xF) << 8));
    uint16_t stick_vertical = ((data[1] >> 4) | (data[2] << 4));

    if (m_bInitStick == false)
    {
        m_InitX = stick_horizontal;
        m_InitY = stick_vertical;
        m_bInitStick = true;
    }

    m_UpdateX = m_InitX - stick_horizontal;
    m_UpdateY = m_InitY - stick_vertical;

    TriggerStick();

    CManager::GetInstance()->GetDebugProc()->Print("スティック %d : %d\n", m_InitX - stick_horizontal, m_InitY - stick_vertical);
    CManager::GetInstance()->GetDebugProc()->Print("スティック %d : %d\n", m_UpdateX, m_UpdateY);
}

//====================================
// ジョイコンの初期化処理
//====================================
HRESULT CJoycon::Init_L()
{
    initialize_hidapi();
    m_device = open_joycon_L();

    m_bIMU = false;

    if (m_device != NULL)
    {
        enable_sensors(m_device);
    }

    else
    {
        return S_OK;
    }

    m_size = 49;

    uint8_t* data = m_buff + 9;

    uint16_t stick_horizontal = (data[0] | ((data[1] & 0xF) << 8));
    uint16_t stick_vertical = ((data[1] >> 4) | (data[2] << 4));

    if (m_bInitStick == false)
    {
        m_InitX = stick_horizontal;
        m_InitY = stick_vertical;
        m_bInitStick = true;
    }

    return S_OK;
}

//====================================
// ジョイコンの初期化処理
//====================================
HRESULT CJoycon::Init_R()
{
    initialize_hidapi();
    m_device = open_joycon_R();

    m_bIMU = false;

    if (m_device != NULL)
    {
        enable_sensors(m_device);
    }

    else
    {
        return S_OK;
    }

    m_size = 49;

    uint8_t* data = m_buff + 9;

    uint16_t stick_horizontal = (data[0] | ((data[1] & 0xF) << 8));
    uint16_t stick_vertical = ((data[1] >> 4) | (data[2] << 4));

    if (m_bInitStick == false)
    {
        m_InitX = stick_horizontal;
        m_InitY = stick_vertical;
        m_bInitStick = true;
    }

    return S_OK;
}


//====================================
// ジョイコンの終了処理
//====================================
void CJoycon::Uninit()
{
    hid_close(m_device);

    hid_exit();
}

//====================================
// ジョイコンの更新処理
//====================================
void CJoycon::Update()
{
    if (m_device == NULL)
    {
        return;
    }

    if (m_CurMode != CScene::GetMode())
    {
        m_nCntRugResolved = 0;
        m_nCntRugResolved2 = 0;
        m_nCntRugResolved3 = 0;
        m_CurMode = CScene::GetMode();
    }

    // input report を受けとる。
    int ret = hid_read(m_device, m_buff, m_size);

    // inputのラグをなくす処理
    if (m_bRead == false)
    {
        ret = hid_read(m_device, m_buff, m_size);

        m_bRead = true;
    }

    else
    {
        m_nCntRugResolved++;
        m_nCntRugResolved2++;

        switch (m_nCntRugResolved3)
        {
        case 0:
            if (m_nCntRugResolved >= 1)
            {
                m_bRead = false;
                m_nCntRugResolved = 0;
            }

            break;


        default:
            if (m_nCntRugResolved >= 4)
            {
                m_bRead = false;
                m_nCntRugResolved = 0;
            }

            break;
        }

        if (m_nCntRugResolved4 == m_nCntRugResolved2 && m_nCntRugResolved3 <= 1)
        {
            m_nCntRugResolved3++;
            m_nCntRugResolved2 = 0;
        }

        if (m_nCntRugResolved4 < m_nCntRugResolved2)
        {
            m_nCntRugResolved2 = 0;
        }
    }

    //if (!m_bInitGyro)
    //{
    //    // IMUの更新
    //    Sensor_Update();

    //    if (InitRot())
    //    {
    //        m_bInitGyro = true;
    //    }

    //    return;
    //}

    // ひとつ前のボタンを保存
    SetOldDifferButton(m_DifferButton);
    SetOldCommonButton(m_CommonButton);

    m_OldUpdateX = m_UpdateX;
    m_OldUpdateY = m_UpdateY;

    if (m_bIMU == true)
    {
        // IMUの更新
        Sensor_Update();

        // ボタンの更新
        Button_Update();

        // スティックの更新
        Stick_Update();
    }

    else
    {
        // ボタンの更新
        Button_Update();
    }
}

//====================================================================
// スティックのトリガー判定
//====================================================================
void CJoycon::TriggerStick()
{
    if (Get_Joycon_Stick().x >= 0.9f && Get_Joycon_OldStick().x < 0.9f ||
        Get_Joycon_Stick().x <= -0.9f && Get_Joycon_OldStick().x > -0.9f ||
        Get_Joycon_Stick().y >= 0.9f && Get_Joycon_OldStick().y < 0.9f ||
        Get_Joycon_Stick().y <= -0.9f && Get_Joycon_OldStick().y > -0.9f)
    {
        m_bTriggerStick = true;
    }

    else
    {
        m_bTriggerStick = false;
    }
}

//====================================================================
// ボタンのトリガー判定
//====================================================================
void CJoycon::TriggerButton()
{
    if (m_DifferButton != m_OldDifferButton || m_OldCommonButton != m_CommonButton)
    {
        m_bTriggerButton = true;
    }

    else
    {
        m_bTriggerButton = false;
    }
}

//====================================================================
// ジョイコンのスティック情報を取得
//====================================================================
D3DXVECTOR3 CJoycon::Get_Joycon_Stick()
{
    //ローカル変数宣言
    D3DXVECTOR3 Stick = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

    Stick.x = ((float)m_UpdateX / (float)1000) * -1;
    if (fabsf(Stick.x) < (float)500 / (float)1000)
    {
        Stick.x = 0.0f;
    }

    Stick.y = ((float)m_UpdateY / (float)1000) * -1;
    if (fabsf(Stick.y) < (float)500 / (float)1000)
    {
        Stick.y = 0.0f;
    }

    if (Stick.x > 0.5f || Stick.x < -0.5f && Stick.y > 0.5f || Stick.y < -0.5f)
    {
        D3DXVec3Normalize(&Stick, &Stick);	//ベクトルを正規化する
    }

    return Stick;
}

//====================================================================
// ジョイコンのスティック情報を取得
//====================================================================
D3DXVECTOR3 CJoycon::Get_Joycon_OldStick()
{
    //ローカル変数宣言
    D3DXVECTOR3 Stick = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

    Stick.x = ((float)m_OldUpdateX / (float)1000) * -1;
    if (fabsf(Stick.x) < (float)500 / (float)1000)
    {
        Stick.x = 0.0f;
    }

    Stick.y = ((float)m_OldUpdateY / (float)1000) * -1;
    if (fabsf(Stick.y) < (float)500 / (float)1000)
    {
        Stick.y = 0.0f;
    }

    if (Stick.x > 0.5f || Stick.x < -0.5f && Stick.y > 0.5f || Stick.y < -0.5f)
    {
        D3DXVec3Normalize(&Stick, &Stick);	//ベクトルを正規化する
    }

    return Stick;
}

//====================================
// IMUの制限処理
//====================================
void CJoycon::ControlIMU(D3DXVECTOR3* IMUdata, const float Controldata)
{
    if (IMUdata->x <= Controldata && IMUdata->x >= -Controldata)
    {
        IMUdata->x = 0.0f;
    }

    if (IMUdata->y <= Controldata && IMUdata->y >= -Controldata)
    {
        IMUdata->y = 0.0f;
    }

    if (IMUdata->z <= Controldata && IMUdata->z >= -Controldata)
    {
        IMUdata->z = 0.0f;
    }
}

//====================================
// ジャイロの値の初期化処理
//====================================
bool CJoycon::InitRot()
{
    bool b = false;

    if (m_Accel.x <= INIT_ROT_CONTROL && m_Accel.x >= -INIT_ROT_CONTROL &&
        m_Accel.y <= INIT_ROT_CONTROL && m_Accel.y >= -INIT_ROT_CONTROL &&
        m_Accel.z <= INIT_ROT_CONTROL - 1.0f && m_Accel.z >= -1.0f)
    {
        m_rot = INITVECTOR3;
        b = true;
    }

    return b;
}

//====================================
// ジャイロの値の初期化処理
//====================================
bool CJoycon::SlashCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut)
{
    bool b = false;

    if (sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x)
        + (pos1.y - pos2.y) * (pos1.y - pos2.y)) >= nRadiusOut)
    {//円の判定が当たった

        b = true;
    }

    return b;
}

