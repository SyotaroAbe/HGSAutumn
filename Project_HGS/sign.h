//============================================
//
//	�� [sign.h]
//	Author:�ؓ������}�����ؓ�
//
//============================================

#include "main.h"
#include "object.h"

// �O���錾
class CObject2D;
class CAim;
class CInputMouse;
class CJoycon;

// �Ə��N���X
class CSign : public CObject
{
private:
	static const int MAX_SIGN = 1024;

public:
	enum SIGNTYPE
	{
		SIGNTYPE_NONE = 0,	// �Ȃ�
		SIGNTYPE_FIRE,		// �Γق̈�
		SIGNTYPE_FOG,		// ���B��
		SIGNTYPE_DOUBLE,	// ���g
		MAX_TYPE,
	};

private:
	struct SCheck	// ��v���邩���ׂ�\����
	{
		CObject2D* pSignCheck;
		int nMyID;
		int nJudgeID;
		bool bUse;
	};

	struct SCheckInfo
	{
		SCheck aCheack[MAX_SIGN];	// �Ȃ��蔻��̍\����
		D3DXVECTOR3 pos;	// ��ƂȂ�ʒu
		int nEndID;
		bool bEnd;	// ����
	};

	struct SPen	// �y��
	{
		CObject2D* pSign2D;
		int nID;
		bool bUse;

		CObject2D* pJudge2D;		// ����̈ʒu��������₷���悤�Ɍ�ŏ���
		D3DXVECTOR3 posJudge;	// ����̈ʒu
		bool bJudge;	// ���肵�����ǂ���
		bool bBool;
	};

	// �t�@�C������ǂݍ��񂾏��
	struct SLoadInfo
	{
		D3DXVECTOR3 pos;
		int nID;
	};

public:

	CSign(SIGNTYPE type = SIGNTYPE_NONE);
	~CSign();

	static CSign* Create(SIGNTYPE type);

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	bool GetEnd() { return m_info.bEnd; }
	void SetType(SIGNTYPE type) { m_type = type; }
	SIGNTYPE GetType() { return m_type; }
	bool GetUse() { return m_bUse; }

private:
	void Sign();			// �����ڏ�̏���������
	void SignMouse(CAim* pAim);
	void SignOver(int nIdx);

	void Judge();			// ����p�̏���������
	void SignCheck();		// �Ȃ���Ă邩�`�F�b�N
	void Misstake();		// ���s
	void Success();			// ����

	void Load(char* pTecPath);

	// �ϐ��錾
	SCheckInfo m_info;
	SPen m_aPen[MAX_SIGN];

	int m_nNum;			// ����ɐG�ꂽ����
	int m_nNumJudge;	// �M�̔���̑���(ID�ݒ�p)
	int m_nMissCount;	// ���s��(�󔻒�ɐG��ĂȂ���)

	SIGNTYPE m_type;	// ��̎��

	bool m_bUse;

	// �t�@�C������ǂݍ��񂾏��
	SLoadInfo m_aInfo[MAX_SIGN];
	int m_nNumSign;
};