//========================================================================================
//
//　ジョイコンの処理[joycon.h]
//	Author:hashimoto kenta
//
//========================================================================================
#ifndef _JOYCON_H_
#define _JOYCON_H_

#include "main.h"
#include "hidapi.h"
#include <stdint.h>
#include "manager.h"

//ジョイコンのクラス宣言
class CJoycon
{
public:
	CJoycon();
	~CJoycon();

	//===============================
	// プロダクトID
	//===============================
	typedef enum
	{
		PRODUCT_ID_L = 0x2006,
		PRODUCT_ID_R = 0x2007,
		PRODUCT_ID_MAX
	}PRODUCT_ID;

	//===============================
	// サブコマンド
	//===============================
	typedef enum
	{
		SUBCMD_LIGHT_SET = 0x30,        //プレイヤーライトの設定
		SUBCMD_LIGHT_GET = 0x31,        //プレイヤーライトの取得
		SUBCMD_LIGHT_HOME = 0x38,       //HOMEライトの設定
		SUBCMD_IMU = 0x40,              //6軸センサーの有効化
		SUBCMD_IMU_SENSI_SET = 0x41,    //6軸センサーの感度設定
		SUBCMD_IMU_REGI_WRITE = 0x42,   //6軸センサーのレジスター書込
		SUBCMD_IMU_REGI_READ = 0x43,    //6軸センサーのレジスター読込
		SUBCMD_VIB = 0x48,              //振動の有効化
		SUBCMD_MAX
	}SUBCOMMAND;

	//===============================
	// ボタン(左右それぞれ)(buff[3],buff[5])
	//===============================
	typedef enum
	{
		BUTTON_Y = 0x01,   //1
		BUTTON_X = 0x02,   //2
		BUTTON_B = 0x04,   //4
		BUTTON_A = 0x08,   //8
		BUTTON_SR = 0x10,  //16
		BUTTON_SL = 0x20,  //32
		BUTTON_LR = 0x40,   //64
		BUTTON_ZLZR = 0x80,  //128
	}JOYCON_BUTTON;

	//===============================
	// 特殊ボタン (左右合一ボタン)(buff[4])
	//===============================
	typedef enum
	{
		BUTTON_MINUS = 0x01,   //1
		BUTTON_PLUS = 0x02,   //2
		BUTTON_STICK_R = 0x04,   //4
		BUTTON_STICK_L = 0x08,   //8
		BUTTON_HOME = 0x10,  //16
		BUTTON_PHOTO = 0x20,  //32
	}JOYCON_BUTTON_SP;

	//===============================
	//スティック
	//===============================
	typedef enum
	{
		JOYSTICK_U = 0,
		JOYSTICK_UR,
		JOYSTICK_R,
		JOYSTICK_DR,
		JOYSTICK_D,
		JOYSTICK_DL,
		JOYSTICK_L,
		JOYSTICK_UL,
		JOYSTICK_NUT,
		JOYSTICK_MAX,
	}JOYCON_STICK;

	void SendSubcommand(hid_device* m_device, uint8_t command, uint8_t data[], int len, int* m_globalCount);
	void enable_sensors(hid_device* handle);
	hid_device* open_joycon_L();
	hid_device* open_joycon_R();
	void initialize_hidapi();

	void Sensor_Update();
	void Button_Update();
	void Stick_Update();

	HRESULT Init_L();
	HRESULT Init_R();
	void Uninit();
	void Update();

	D3DXVECTOR3 GetAccel() { return m_Accel_Correction; }
	D3DXVECTOR3 GetGyro() { return m_Gyro_Radian; }
	D3DXVECTOR3 GetAccelNormal() { return m_Accel; }
	D3DXVECTOR3 GetVelocity() { return m_Velocity; }
	D3DXVECTOR3 GetGyroVelocity() { return m_GyroVelocity; }
	D3DXVECTOR3 GetSlashPos() { return m_SlashPos; }
	void SetSlashPos(D3DXVECTOR3 pos) { m_SlashPos = pos; }
	D3DXVECTOR3 GetInitSlashPos() { return m_InitSlashPos; }

	hid_device* GetDevice() { return m_device; }

	float GetAccel_AbsoluteValue() { return m_Accel_AbsoluteValue; }
	float GetOldAccel_AbsoluteValue() { return m_OldAccel_AbsoluteValue; }
	float GetVelocity_AbsoluteValue() { return m_Velocity_AbsoluteValue; }
	float GetOldVelocity_AbsoluteValue() { return m_OldVelocity_AbsoluteValue; }

	void SetDifferButton(int ButtonType) { m_DifferButton = ButtonType; }
	int GetDifferButton() { return m_DifferButton; }
	void SetCommonButton(int ButtonType) { m_CommonButton = ButtonType; }
	int GetCommonButton() { return m_CommonButton; }
	void SetOldDifferButton(int ButtonType) { m_OldDifferButton = ButtonType; }
	int GetOldDifferButton() { return m_OldDifferButton; }
	void SetOldCommonButton(int ButtonType) { m_OldCommonButton = ButtonType; }
	int GetOldCommonButton() { return m_OldCommonButton; }

	void TriggerStick();
	bool GetTriggerStick() { return m_bTriggerStick; }
	void TriggerButton();
	bool GetTriggerButton() { return m_bTriggerButton; }

	int GetProduct_id() { return m_Product_id; }

	D3DXVECTOR3 Get_Joycon_Stick();
	D3DXVECTOR3 Get_Joycon_OldStick();

	D3DXVECTOR3 SetRot(D3DXVECTOR3 Rot) { m_rot = Rot; }
	D3DXVECTOR3 GetRot() { return m_rot; }

	bool SlashCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut);

protected:
	void ControlIMU(D3DXVECTOR3* IMUdata, const float Controldata);	// IMUの制限処理
	bool InitRot();					// 向きの値の初期化処理

	D3DXVECTOR3 m_Accel;			// 
	D3DXVECTOR3 m_Accel_Correction;	// 精度のいい加速度
	D3DXVECTOR3 m_Gyro_Radian;		// 度数法での回転速度の値

	D3DXVECTOR3 m_Velocity;
	D3DXVECTOR3 m_SlashPos;
	D3DXVECTOR3 m_InitSlashPos;
	D3DXVECTOR3 m_GyroVelocity;

	D3DXVECTOR3 m_accel[3];			// 加速度の計算用変数
	float m_gyro[3];				// 回転速度の計算用変数
	bool m_bInitGyro;				// ジャイロの値を初期化したかどうか

	float m_Accel_AbsoluteValue;	// 加速度の絶対値
	float m_OldAccel_AbsoluteValue;	// ひとつ前の加速度の絶対値
	float m_Velocity_AbsoluteValue;	// 速度の絶対値
	float m_OldVelocity_AbsoluteValue;	// 速度の絶対値

	int m_globalCount;
	int m_DifferButton;				// LR異なる値が入るボタン
	int m_CommonButton;				// LR共通の値が入るボタン
	bool m_bTriggerButton;			// ボタンの判定をトリガーにするかどうか
	int m_OldDifferButton;			// ひとつ前のLR異なる値が入るボタン
	int m_OldCommonButton;			// ひとつ前のLR共通の値が入るボタン
	int m_Product_id;				// プロダクトID
	hid_device* m_device;			// ジョイコンの情報
	uint8_t m_buff[0x31];
	size_t m_size;					// バフサイズ
	JOYCON_STICK m_Stick;			// スティックの値

	bool m_bInitStick;
	bool m_bTriggerStick;
	uint16_t m_InitX;
	uint16_t m_InitY;

	int m_UpdateX;
	int m_UpdateY;
	int m_OldUpdateX;
	int m_OldUpdateY;

	int m_nCntRugResolved;
	int m_nCntRugResolved2;
	int m_nCntRugResolved3;
	int m_nCntRugResolved4;
	CScene::MODE m_CurMode;			// 現在のモード

	bool m_bIMU;
	bool m_bRead;

	D3DXVECTOR3 m_rot;			// 向き
	D3DXVECTOR3 m_pos;			// 位置
};

#endif
