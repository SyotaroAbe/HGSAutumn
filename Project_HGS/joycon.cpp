//========================================================================================
//
//�@�W���C�R���̏���[joycon.cpp]
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

// ����
// windows�ł́gWireless Gamepad�h�ƔF������܂��B
// �����v�̓r�b�g�t���O�ŁA4���B�����v�̈�ԏォ��10�i���� 1, 2, 4, 8 �ƑΉ����Ă��܂��B
// �Q�lURL: https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering

#define VENDOR_ID  0x057E  // Nintendo Co., Ltd //0d1406
#define MOVE_GYRO_MIN (1.0f)
#define MOVE_ACCEL_MIN (0.02f)
#define INIT_ROT_CONTROL (0.1f)

//====================================================================
// �R���X�g���N�^
//====================================================================
CJoycon::CJoycon()
{
    // read input report
    m_buff[0x40]; memset(m_buff, 0x00, size_t(0x40));
    // �ǂݍ��ރT�C�Y���w��B
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
// �f�X�g���N�^
//====================================================================
CJoycon::~CJoycon()
{

}

//====================================
// ������(hidapi)
//====================================
void CJoycon::initialize_hidapi()
{
    if (hid_init()) {
        std::cerr << "Failed to initialize HIDAPI." << std::endl;
        exit(-1);
    }
}

//====================================
// �W���C�R��L�����Đڑ����܂�
//====================================
hid_device* CJoycon::open_joycon_L()
{
    struct hid_device_info* devs = hid_enumerate(0, 0); // Joy-Con�̃x���_�[ID�ƃv���_�N�gID
    struct hid_device_info* devsNow = nullptr;
    hid_device* handle = nullptr;

    while (devs)
    {
        devsNow = devs;
        if (devs->product_id == CJoycon::PRODUCT_ID_L)
        {
            // �v���_�N�gID�����w�肵�āAHID device��open����B��������ƁA����hid�f�o�C�X�̏�񂪍ڂ���hid_device���A���Ă���B
            handle = hid_open(devs->vendor_id, devs->product_id, devs->serial_number);
            m_Product_id = devs->product_id;
        }

        devs = devsNow->next;

        //�������J��
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
// �W���C�R��R�����Đڑ����܂�
//====================================
hid_device* CJoycon::open_joycon_R()
{
    struct hid_device_info* devs = hid_enumerate(0, 0); // Joy-Con�̃x���_�[ID�ƃv���_�N�gID
    struct hid_device_info* devsNow = nullptr;
    hid_device* handle = nullptr;

    while (devs)
    {
        devsNow = devs;
        if (devs->product_id == CJoycon::PRODUCT_ID_R)
        {
            // �v���_�N�gID�����w�肵�āAHID device��open����B��������ƁA����hid�f�o�C�X�̏�񂪍ڂ���hid_device���A���Ă���B
            handle = hid_open(devs->vendor_id, devs->product_id, devs->serial_number);
            m_Product_id = devs->product_id;
        }

        devs = devsNow->next;

        //�������J��
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
// Joycon�ɏo��
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
// �Z���T�[��L���ɂ���
//====================================
void CJoycon::enable_sensors(hid_device* handle)
{
    uint8_t data[0x04];

    m_bIMU = true;

    hid_set_nonblocking(m_device, 0);

    // 0x30�Ԃ̃T�u�R�}���h�ɁA0x01�𑗐M���܂��B
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

        // input report ���󂯂Ƃ�B
        int ret = hid_read(m_device, m_buff, m_size);

    } while (*m_buff != 0x30 || m_buff[13] == 0);       //���̓��|�[�g��ID��48��������AIMU�f�[�^�������Ă��邩
}

//====================================
// IMU�̍X�V����
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
            // �����x���擾
            int index = 13 + 2 * i + j * 12;
            accel[i] = (m_buff[index] | (m_buff[index + 1] << 8));

            // �����x��␳
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

        // �����x�𐧌�
        ControlIMU(&m_accel[j], MOVE_ACCEL_MIN);
    }

    m_Accel = m_accel[2];

    // ���x�̂��������x���Z�o�i5�~���b���Ɏ���������x�����Ɂj
    m_Accel_Correction = ((m_accel[2] - m_accel[1]) + (m_accel[1] - m_accel[0])) / 2;

    // �����x�̐�Βl�����߂�
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
        // ��]���x���擾
        int index = 19 + 2 * i;
        gyro[i] = (m_buff[index] | (m_buff[index + 1] << 8));

        // ��]���x��␳
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
        CManager::GetInstance()->GetDebugProc()->Print("���x %f, %f, %f\n", m_Velocity.x, m_Velocity.y, m_Velocity.z);
        CManager::GetInstance()->GetDebugProc()->Print("pos %f, %f, %f\n", m_pos.x, m_pos.y, m_pos.z);
        CManager::GetInstance()->GetDebugProc()->Print("���x��Βl %f\n", m_Velocity_AbsoluteValue);
    }

    if (m_CommonButton & BUTTON_LR &&
        m_bTriggerButton == true)
    {
    }
}

//====================================
// �{�^���̍X�V����
//====================================
void CJoycon::Button_Update()
{
    // �{�^���ݒ�
    switch (m_Product_id)
    {
    case PRODUCT_ID_L:
        SetCommonButton(m_buff[5]);
        break;

    case PRODUCT_ID_R:
        SetCommonButton(m_buff[3]);
        break;
    }

    // �{�^���ݒ�
    SetDifferButton(m_buff[4]);

    TriggerButton();

    CManager::GetInstance()->GetDebugProc()->Print("�{�^�� : %d\n", GetDifferButton());
}

//====================================
// �X�e�B�b�N�̍X�V����
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

    CManager::GetInstance()->GetDebugProc()->Print("�X�e�B�b�N %d : %d\n", m_InitX - stick_horizontal, m_InitY - stick_vertical);
    CManager::GetInstance()->GetDebugProc()->Print("�X�e�B�b�N %d : %d\n", m_UpdateX, m_UpdateY);
}

//====================================
// �W���C�R���̏���������
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
// �W���C�R���̏���������
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
// �W���C�R���̏I������
//====================================
void CJoycon::Uninit()
{
    hid_close(m_device);

    hid_exit();
}

//====================================
// �W���C�R���̍X�V����
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

    // input report ���󂯂Ƃ�B
    int ret = hid_read(m_device, m_buff, m_size);

    // input�̃��O���Ȃ�������
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
    //    // IMU�̍X�V
    //    Sensor_Update();

    //    if (InitRot())
    //    {
    //        m_bInitGyro = true;
    //    }

    //    return;
    //}

    // �ЂƂO�̃{�^����ۑ�
    SetOldDifferButton(m_DifferButton);
    SetOldCommonButton(m_CommonButton);

    m_OldUpdateX = m_UpdateX;
    m_OldUpdateY = m_UpdateY;

    if (m_bIMU == true)
    {
        // IMU�̍X�V
        Sensor_Update();

        // �{�^���̍X�V
        Button_Update();

        // �X�e�B�b�N�̍X�V
        Stick_Update();
    }

    else
    {
        // �{�^���̍X�V
        Button_Update();
    }
}

//====================================================================
// �X�e�B�b�N�̃g���K�[����
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
// �{�^���̃g���K�[����
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
// �W���C�R���̃X�e�B�b�N�����擾
//====================================================================
D3DXVECTOR3 CJoycon::Get_Joycon_Stick()
{
    //���[�J���ϐ��錾
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
        D3DXVec3Normalize(&Stick, &Stick);	//�x�N�g���𐳋K������
    }

    return Stick;
}

//====================================================================
// �W���C�R���̃X�e�B�b�N�����擾
//====================================================================
D3DXVECTOR3 CJoycon::Get_Joycon_OldStick()
{
    //���[�J���ϐ��錾
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
        D3DXVec3Normalize(&Stick, &Stick);	//�x�N�g���𐳋K������
    }

    return Stick;
}

//====================================
// IMU�̐�������
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
// �W���C���̒l�̏���������
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
// �W���C���̒l�̏���������
//====================================
bool CJoycon::SlashCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut)
{
    bool b = false;

    if (sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x)
        + (pos1.y - pos2.y) * (pos1.y - pos2.y)) >= nRadiusOut)
    {//�~�̔��肪��������

        b = true;
    }

    return b;
}

