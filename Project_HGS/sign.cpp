//============================================
//
//	�� [sign.cpp]
//	Author:�ؓ������}�����ؓ� + ����쏟
//
//============================================
#include "sign.h"
#include "object2D.h"
#include "input.h"
#include "joycon.h"
#include "manager.h"
#include "renderer.h"
#include "aim.h"
#include "game.h"
#include "useful.h"

#include "debugproc.h"

#include "tutorial.h"

#include "sound.h"

// ���O���
namespace
{
	const D3DXVECTOR3 POS = { 800.0f, 220.0f, 0.0f };

	const char* PEN_TEX_PATH = "data\\TEXTURE\\makimono\\hude.png";	// �y���̃e�N�X�`���p�X
	const D3DXCOLOR COLOR_PEN = { 1.0f, 1.0f, 1.0f, 0.3f };
	const float SIZE_PEN = 80.0f;

	const float PEN_JUDGE_LENGTH = 50.0f;	// �y������𐶐�����Ԋu
	const float JUDGE_LENGTH = 70.0f;	// �y������ƈ󔻒肪�G�ꂽ�Ɣ��肳��钷��

	const int SURPLUS = 3;	// ����̗L�]

	const float OVER_LENGTH = 5.0f;	// �����Ă͂����Ȃ�����
	const int OVER_SET = (int)OVER_LENGTH;	// �u������
}

//====================================================================
//= �R���X�g���N�^
//====================================================================
CSign::CSign(SIGNTYPE type)
{
	// �l�̃N���A
	ZeroMemory(&m_aPen, sizeof(m_aPen));
	ZeroMemory(&m_info, sizeof(m_info));
	
	m_nNum = 0;
	m_nNumJudge = 0;
	m_type = type;

	m_nMissCount = 0;

	ZeroMemory(&m_aInfo, sizeof(m_aInfo));
	m_nNumSign = 0;

	m_bUse = false;
}

//====================================================================
//= �f�X�g���N�^
//====================================================================
CSign::~CSign()
{

}

//====================================================================
//= ��������
//====================================================================
CSign* CSign::Create(SIGNTYPE type)
{
	CSign* pSign = nullptr;

	if (!pSign)
	{
		pSign = new CSign(type);

		pSign->Init();
	}

	return pSign;
}

//====================================================================
//= ����������
//====================================================================
HRESULT CSign::Init()
{
	switch (m_type)
	{
	case SIGNTYPE_NONE:
		break;
	case SIGNTYPE_FIRE:
		m_info.pos = POS;
		Load("data\\TXT\\SIGN\\fire.txt");
		break;
	case SIGNTYPE_FOG:
		m_info.pos = POS;
		Load("data\\TXT\\SIGN\\fog.txt");
		break;
	case SIGNTYPE_DOUBLE:
		m_info.pos = POS;
		Load("data\\TXT\\SIGN\\double.txt");
		break;
	default:
		break;
	}

	return E_NOTIMPL;
}

//====================================================================
//= �I������
//====================================================================
void CSign::Uninit()
{
	for (int i = 0; i < MAX_SIGN; i++)
	{
		if (m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck->Uninit();
			m_info.aCheack[i].pSignCheck = nullptr;
			m_info.aCheack[i].bUse = false;
		}

		if (m_aPen[i].pSign2D)
		{
			m_aPen[i].pSign2D->Uninit();
			m_aPen[i].pSign2D = nullptr;
			m_aPen[i].nID = 0;
			m_aPen[i].bJudge = false;
		}

		if (m_aPen[i].pJudge2D)
		{
			m_aPen[i].pJudge2D->Uninit();
			m_aPen[i].pJudge2D = nullptr;
		}
		m_aPen[i].posJudge = {};
	}

	SetDeathFlag(true);
}

//====================================================================
//= �X�V����
//====================================================================
void CSign::Update()
{
	if (!m_info.bEnd)
	{
		// 
		Sign();

		// ����
		SignCheck();
	}

	if (m_info.bEnd)
	{
		Misstake();
	}
}

//====================================================================
//= �`�揈��
//====================================================================
void CSign::Draw()
{

}

//====================================================================
//= ��̐�
//====================================================================
void CSign::Sign()
{
	CInputMouse* pMouse = CManager::GetInstance()->GetInputMouse();
	CInputKeyboard* pKey = CManager::GetInstance()->GetInputKeyboard();
	CJoycon* pJoycon = CManager::GetInstance()->GetJoyconR();
	CAim* pAim = nullptr;

	switch (CScene::GetMode())
	{
	case CScene::MODE_GAME:
		pAim = CGame::GetAim();
		break;
	case CScene::MODE_TUTORIAL:
		pAim = CTutorial::GetAim();
		break;
	}
	
	if (pMouse->GetPress(pMouse->PUSH_LEFT) || pJoycon->GetCommonButton() == CJoycon::BUTTON_ZLZR)
	{// �w��̃L�[�������ꂽ�ꍇ
		if (pMouse != nullptr || pJoycon != nullptr)
		{
			SignMouse(pAim);

			// ��g�p���
			m_bUse = true;
		}
	}
	else if (pKey->GetRerease(DIK_B) || pMouse->GetRerease(pMouse->PUSH_LEFT) ||
		(pJoycon->GetCommonButton() != CJoycon::BUTTON_ZLZR && pJoycon->GetTriggerButton() == true))
	{// �w��̃L�[�𗣂����ꍇ�Ƀ~�X����ɂ���
		Misstake();

		// ��s�g�p���
		m_bUse = false;
	}
}

//====================================================================
//= �}�E�X���g�p�������`������
//====================================================================
void CSign::SignMouse(CAim* pAim)
{
	if (pAim->GetSpeed().x > 0.0f || pAim->GetSpeed().x < 0.0f ||
		pAim->GetSpeed().y > 0.0f || pAim->GetSpeed().y < 0.0f)
	{// �}�E�X�̈ړ��ʂ��w��l���z���Ă����ꍇ

		for (int i = 0; i < MAX_SIGN; i++)
		{
			if (!m_aPen[i].pSign2D)
			{// ����
				m_aPen[i].pSign2D = CObject2D::Create();
				m_aPen[i].pSign2D->SetWidth(SIZE_PEN);
				m_aPen[i].pSign2D->SetHeight(SIZE_PEN);
				m_aPen[i].pSign2D->SetPos(*pAim->GetScreenPos());
				m_aPen[i].pSign2D->SetColor(COLOR_PEN);
				m_aPen[i].pSign2D->SetTexture(PEN_TEX_PATH);

				// �C��
				SignOver(i);

				break;
			}
		}

		// �M�ŏ�����
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_WRITE_BRUSH);

		// ���菈��
		Judge();
	}
}

//====================================================================
//= �I�[�o�[������̏C��
//====================================================================
void CSign::SignOver(int nIdx)
{
	if (nIdx != 0)
	{
		if (m_aPen[nIdx - 1].pSign2D && m_aPen[nIdx].pSign2D)
		{// 
			// �ʒu���̎擾
			D3DXVECTOR3 posOld = m_aPen[nIdx - 1].pSign2D->GetPos();
			D3DXVECTOR3 posNow = m_aPen[nIdx].pSign2D->GetPos();

			// �����v�Z
			float fLength = sqrtf((posOld.x - posNow.x) * (posOld.x - posNow.x) + (posOld.y - posNow.y) * (posOld.y - posNow.y));

			if (fLength > OVER_LENGTH)
			{// ����������Ă����ꍇ
				// �p�x���Z�o
				float fAngle = atan2f((posNow.x - posOld.x), (posNow.y - posOld.y));

				// for�J�E���g�p
				int nCnt = 0;

				for (int j = 0; j < MAX_SIGN; j++)
				{
					if (!m_aPen[j].pSign2D)
					{// ����
						m_aPen[j].pSign2D = CObject2D::Create();
						m_aPen[j].pSign2D->SetWidth(SIZE_PEN);
						m_aPen[j].pSign2D->SetHeight(SIZE_PEN);
						m_aPen[j].pSign2D->SetColor(COLOR_PEN);
						m_aPen[j].pSign2D->SetTexture(PEN_TEX_PATH);

						nCnt++;

						m_aPen[j].pSign2D->SetPos(
							{// �ʒu�ݒ�
								posOld.x + (sinf(fAngle) * (nCnt * OVER_SET)),
								posOld.y + (cosf(fAngle) * (nCnt * OVER_SET)),
								0.0f
							});

						// �����v�Z
						fLength = sqrtf((m_aPen[j].pSign2D->GetPos().x - posNow.x) * (m_aPen[j].pSign2D->GetPos().x - posNow.x) + (m_aPen[j].pSign2D->GetPos().y - posNow.y) * (m_aPen[j].pSign2D->GetPos().y - posNow.y));

						if (fLength < (float)OVER_SET)
						{// ����Ă����M�֋߂Â�����
							break;
						}
					}
				}
			}
		}
	}
}

//====================================================================
//= ����
//====================================================================
void CSign::Judge()
{
	// ���̎擾
	CAim* pAim = nullptr;

	switch (CScene::GetMode())
	{
	case CScene::MODE_GAME:
		pAim = CGame::GetAim();
		break;
	case CScene::MODE_TUTORIAL:
		pAim = CTutorial::GetAim();
		break;
	}

	float fLength = 0.0f;
	
	if (m_nNumJudge != 0)
	{
		D3DXVECTOR3 pos1 = m_aPen[m_nNumJudge - 1].posJudge;
		D3DXVECTOR3 pos2 = *pAim->GetScreenPos();

		// �����v�Z
		fLength = sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
	}
	
	if (fLength > PEN_JUDGE_LENGTH || m_nNumJudge == 0)
	{// ����̈ʒu��ݒu

#ifdef _DEBUG
		// ������₷���悤�Ƀ|���S���\��
		m_aPen[m_nNumJudge].pJudge2D = CObject2D::Create();
		m_aPen[m_nNumJudge].pJudge2D->SetWidth(50.0f);
		m_aPen[m_nNumJudge].pJudge2D->SetHeight(50.0f);
		m_aPen[m_nNumJudge].pJudge2D->SetPos(*pAim->GetScreenPos());
		m_aPen[m_nNumJudge].pJudge2D->SetColor({ 0.0f, 0.0f, 1.0f, 1.0f });
		m_aPen[m_nNumJudge].pJudge2D->SetTexture("data\\TEXTURE\\effect\\effect000.png");
		// �����܂Ł�
#endif
		// ����̈ʒu��ݒ�
		m_aPen[m_nNumJudge].posJudge = *pAim->GetScreenPos();
		m_aPen[m_nNumJudge].nID = m_nNumJudge;	// ID��ݒ�
		m_aPen[m_nNumJudge].bUse = true;

		m_nNumJudge++;	// �ԍ��̃J�E���g�A�b�v
	}
}

//====================================================================
//= ��̃`�F�b�N
//====================================================================
void CSign::SignCheck()
{
	// �ϐ��錾
	D3DXVECTOR3 posSign = {};
	D3DXVECTOR3 posPen = {};
	float fRadius = 0.0f;
	int nNumTouch = 0;

	for (int i = 0; i < MAX_SIGN; i++)
	{
		if (m_info.aCheack[i].bUse || !m_info.aCheack[i].pSignCheck)
		{// �`�F�b�N�|�C���^����������Ă��Ȃ�||�`�F�b�N�ς̏ꍇ
			continue;
		}

		for (int j = 0; j < MAX_SIGN; j++)
		{
			if (!m_aPen[j].bUse || m_aPen[j].bBool)
			{
				continue;
			}

			// ���̎擾
			posSign = m_info.aCheack[i].pSignCheck->GetPos();	// �Ȃ����鑤�̔���̈ʒu
			posPen = m_aPen[j].posJudge;	// �Ȃ��鑤�̔���̈ʒu

			// ����Ɣ���̋������v�Z
			fRadius = sqrtf((posSign.x - posPen.x) * (posSign.x - posPen.x) + (posSign.y - posPen.y) * (posSign.y - posPen.y));

			if (fRadius <= JUDGE_LENGTH)
			{// �~�̔��肪�͈͓��̏ꍇ

				if (!m_info.aCheack[i].bUse)
				{// �g�p����Ă��Ȃ��ꍇ(��������ɐG��Ȃ��悤�ɂ��邽��)
					m_info.aCheack[i].nJudgeID = m_nNum;	// ����ID��ݒ�
					m_info.aCheack[i].bUse = true;	// �g�p���ꂽ

#ifdef _DEBUG
					m_info.aCheack[i].pSignCheck->SetColor({ 1.0f, 0.0f, 0.0f, 1.0 });
#endif

					m_nNum++;	// ����ID�̃J�E���g��i�߂�
					m_nMissCount = 0;

					m_aPen[j].bJudge = true;
					m_aPen[j].bBool = true;
				}

				if (m_nNum == m_info.nEndID)
				{// ���肵�����ƍŌ�̔���ID����v�����ꍇ
					Success();
				}
				//else if (m_nNum - 1 != i)
				//{// ���Ԓʂ�ɐG��Ȃ������ꍇ�Ɏ��s�ɂ���
				//	Misstake();
				//}
			}
			else
			{
				m_nMissCount++;

				m_aPen[j].bBool = true;
			}

			if (m_nMissCount > SURPLUS)
			{
				Misstake();
			}
		}
	}
}

//====================================================================
//= ���s
//====================================================================
void CSign::Misstake()
{
	for (int i = 0; i < MAX_SIGN; i++)
	{
		if (m_info.aCheack[i].pSignCheck)
		{
#ifdef _DEBUG
			m_info.aCheack[i].pSignCheck->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
#endif
			m_info.aCheack[i].nJudgeID = 0;
			m_info.aCheack[i].bUse = false;
		}

		if (m_aPen[i].pSign2D)
		{
			m_aPen[i].pSign2D->Uninit();
			m_aPen[i].pSign2D = nullptr;
			m_aPen[i].nID = 0;
			m_aPen[i].bJudge = false;
			m_aPen[i].bBool = false;
			m_aPen[i].bUse = false;
		}

		if (m_aPen[i].pJudge2D)
		{
			m_aPen[i].pJudge2D->Uninit();
			m_aPen[i].pJudge2D = nullptr;
		}
		m_aPen[i].posJudge = {};
	}

	m_nNumJudge = 0;
	m_nNum = 0;
	m_nMissCount = 0;
}

//====================================================================
//= ����
//====================================================================
void CSign::Success()
{
	for (int i = 0; i < MAX_SIGN; i++)
	{
#ifdef _DEBUG
		if (m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck->SetColor({ 1.0f, 0.0f, 1.0f, 1.0 });
		}
#else
		if (m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck->SetColorA(0.0f);
		}
#endif
		m_info.aCheack[i].nJudgeID = 0;
		m_info.aCheack[i].bUse = false;
	}

	m_info.bEnd = true;	// ������������I��
}

//===========================================================================================
// �O���t�@�C������ǂݍ���
//===========================================================================================
void CSign::Load(char* pTecPath)
{
	// �ϐ��錾
	char cTemp[256] = {};

	m_nNumSign = 0;

	// �l�̃N���A
	ZeroMemory(&m_aInfo[0], sizeof(m_aInfo));

	// �t�@�C������ǂݍ���
	FILE* pFile = fopen(pTecPath, "r");

	if (pFile != nullptr)
	{// �t�@�C�����J�����ꍇ

		while (strcmp(&cTemp[0], "END_SCRIPT") != 0)
		{
			// �����ǂݍ���
			(void)fscanf(pFile, "%s", &cTemp[0]);

			if (strcmp(cTemp, "SET_SIGN") == 0)
			{// �Ǎ��J�n

				while (1)
				{
					// �����ǂݍ���
					(void)fscanf(pFile, "%s", &cTemp[0]);

					// �ړ���
					if (strcmp(cTemp, "POS") == 0)
					{
						(void)fscanf(pFile, "%s", &cTemp[0]);

						(void)fscanf(pFile, "%f", &m_aInfo[m_nNumSign].pos.x);
						(void)fscanf(pFile, "%f", &m_aInfo[m_nNumSign].pos.y);
					}

					if (strcmp(cTemp, "ID") == 0)
					{
						(void)fscanf(pFile, "%s", &cTemp[0]);

						(void)fscanf(pFile, "%d", &m_aInfo[m_nNumSign].nID);
					}

					if (strcmp(cTemp, "END_SIGN") == 0)
					{// �I��

						m_nNumSign++;
						break;
					}
				}
			}
		}

		// �t�@�C�������
		fclose(pFile);
	}
	else
	{
		assert(("�t�@�C���ǂݍ��݂Ɏ��s", false));
	}


	// ��̔��萶�� ��ŏ���
	for (int i = 0; i < m_nNumSign; i++)
	{

		if (!m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck = CObject2D::Create();
			m_info.aCheack[i].pSignCheck->SetPos(m_aInfo[i].pos);
			m_info.aCheack[i].pSignCheck->SetWidth(100.0f);
			m_info.aCheack[i].pSignCheck->SetHeight(100.0f);
			m_info.aCheack[i].pSignCheck->SetTexture("data\\TEXTURE\\effect\\effect000.png");

#ifdef _DEBUG
			m_info.aCheack[i].pSignCheck->SetColorA(1.0f);
#else
			m_info.aCheack[i].pSignCheck->SetColorA(0.0f);
#endif

			m_info.aCheack[i].nMyID = i;	// �������g��ID
			m_info.nEndID = i + 1;
		}
		
	}
}
