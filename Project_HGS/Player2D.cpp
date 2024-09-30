//============================================
//
//	�v���C���[2D�̃T���v�� [Player2D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Player2D.h"
#include "renderer.h"
#include "manager.h"

//�}�N����`
#define SAMPLE_WIGHT (60.0f)		//����
#define SAMPLE_HEIGHT (80.0f)		//�c��

//====================================================================
//�R���X�g���N�^
//====================================================================
CPlayer2D::CPlayer2D(int nPriority) : CObject2D(nPriority)
{
	SetWidth(SAMPLE_WIGHT);
	SetHeight(SAMPLE_HEIGHT);
	m_nSample = 0;
	m_bRight = true;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CPlayer2D::~CPlayer2D()
{

}

//====================================================================
//��������
//====================================================================
CPlayer2D* CPlayer2D::Create(int nPriority)
{
	CPlayer2D* pSample2D = NULL;

	if (pSample2D == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pSample2D = new CPlayer2D(nPriority);
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pSample2D->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pSample2D;
}

//====================================================================
//����������
//====================================================================
HRESULT CPlayer2D::Init(void)
{
	CObject2D::Init();

	////�e�N�X�`���ݒ�
	//SetTexture("data\\TEXTURE\\Number01.png");

	//�V����cpp���쐬�������͐V����TYPE��񋓂ɒǉ����Ďw�肷�邱��
	SetType(CObject::TYPE_SAMPLE);

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CPlayer2D::Uninit(void)
{
	CObject2D::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CPlayer2D::Update(void)
{
	//���_���̍X�V
	CObject2D::Update();

	D3DXVECTOR3 pos = GetPos();

	Move(&pos);

	SetPos(pos);
}

//====================================================================
//�`�揈��
//====================================================================
void CPlayer2D::Draw(void)
{
	CObject2D::Draw();
}

//====================================================================
//�ړ�����
//====================================================================
void CPlayer2D::Move(D3DXVECTOR3* pos)
{
	float fMove = 5.0f;

	if (m_bRight)
	{
		pos->x += fMove;
	}
	else
	{
		pos->x -= fMove;
	}
}