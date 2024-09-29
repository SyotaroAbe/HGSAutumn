//========================================================================================
//
//�@�W���C�R���̏���[joycon.h]
//	Author:hashimoto kenta
//
//========================================================================================
#ifndef _JOYCON_H_
#define _JOYCON_H_

#include "main.h"
#include "hidapi.h"
#include <stdint.h>
#include "manager.h"

//�W���C�R���̃N���X�錾
class CJoycon
{
public:
	CJoycon();
	~CJoycon();

	//===============================
	// �v���_�N�gID
	//===============================
	typedef enum
	{
		PRODUCT_ID_L = 0x2006,
		PRODUCT_ID_R = 0x2007,
		PRODUCT_ID_MAX
	}PRODUCT_ID;

	//===============================
	// �T�u�R�}���h
	//===============================
	typedef enum
	{
		SUBCMD_LIGHT_SET = 0x30,        //�v���C���[���C�g�̐ݒ�
		SUBCMD_LIGHT_GET = 0x31,        //�v���C���[���C�g�̎擾
		SUBCMD_LIGHT_HOME = 0x38,       //HOME���C�g�̐ݒ�
		SUBCMD_IMU = 0x40,              //6���Z���T�[�̗L����
		SUBCMD_IMU_SENSI_SET = 0x41,    //6���Z���T�[�̊��x�ݒ�
		SUBCMD_IMU_REGI_WRITE = 0x42,   //6���Z���T�[�̃��W�X�^�[����
		SUBCMD_IMU_REGI_READ = 0x43,    //6���Z���T�[�̃��W�X�^�[�Ǎ�
		SUBCMD_VIB = 0x48,              //�U���̗L����
		SUBCMD_MAX
	}SUBCOMMAND;

	//===============================
	// �{�^��(���E���ꂼ��)(buff[3],buff[5])
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
	// ����{�^�� (���E����{�^��)(buff[4])
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
	//�X�e�B�b�N
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
	void ControlIMU(D3DXVECTOR3* IMUdata, const float Controldata);	// IMU�̐�������
	bool InitRot();					// �����̒l�̏���������

	D3DXVECTOR3 m_Accel;			// 
	D3DXVECTOR3 m_Accel_Correction;	// ���x�̂��������x
	D3DXVECTOR3 m_Gyro_Radian;		// �x���@�ł̉�]���x�̒l

	D3DXVECTOR3 m_Velocity;
	D3DXVECTOR3 m_SlashPos;
	D3DXVECTOR3 m_InitSlashPos;
	D3DXVECTOR3 m_GyroVelocity;

	D3DXVECTOR3 m_accel[3];			// �����x�̌v�Z�p�ϐ�
	float m_gyro[3];				// ��]���x�̌v�Z�p�ϐ�
	bool m_bInitGyro;				// �W���C���̒l���������������ǂ���

	float m_Accel_AbsoluteValue;	// �����x�̐�Βl
	float m_OldAccel_AbsoluteValue;	// �ЂƂO�̉����x�̐�Βl
	float m_Velocity_AbsoluteValue;	// ���x�̐�Βl
	float m_OldVelocity_AbsoluteValue;	// ���x�̐�Βl

	int m_globalCount;
	int m_DifferButton;				// LR�قȂ�l������{�^��
	int m_CommonButton;				// LR���ʂ̒l������{�^��
	bool m_bTriggerButton;			// �{�^���̔�����g���K�[�ɂ��邩�ǂ���
	int m_OldDifferButton;			// �ЂƂO��LR�قȂ�l������{�^��
	int m_OldCommonButton;			// �ЂƂO��LR���ʂ̒l������{�^��
	int m_Product_id;				// �v���_�N�gID
	hid_device* m_device;			// �W���C�R���̏��
	uint8_t m_buff[0x31];
	size_t m_size;					// �o�t�T�C�Y
	JOYCON_STICK m_Stick;			// �X�e�B�b�N�̒l

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
	CScene::MODE m_CurMode;			// ���݂̃��[�h

	bool m_bIMU;
	bool m_bRead;

	D3DXVECTOR3 m_rot;			// ����
	D3DXVECTOR3 m_pos;			// �ʒu
};

#endif
