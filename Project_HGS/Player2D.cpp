//============================================
//
//	�v���C���[2D�̃T���v�� [Player2D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Player2D.h"
#include "renderer.h"
#include "manager.h"
#include "blockmanager.h"
#include "input.h"

//�}�N����`
#define SAMPLE_WIGHT (60.0f)		//����
#define SAMPLE_HEIGHT (80.0f)		//�c��

namespace
{
	D3DXVECTOR2 Size		 = D3DXVECTOR2(60.0f, 80.0f);//�v���C���[�̑傫��
	float move_player		= 5.0f; //�v���C���[�̈ړ����x
	float jump_player		= 5.0f; //�v���C���[�̃W�����v���x		
	float gravity			= 0.1f;	//�d��
	D3DXVECTOR3 move_space	= D3DXVECTOR3(250.0f, 250.0f, 0.0f);//���S����̈ړ��͈�
	D3DXVECTOR3 pos_max		= SCREEN_CENTER + move_space;
	D3DXVECTOR3 pos_min		= SCREEN_CENTER - move_space;
}
//====================================================================
//�R���X�g���N�^
//====================================================================
CPlayer2D::CPlayer2D(int nPriority) : CObject2D(nPriority)
{
	SetWidth(SAMPLE_WIGHT);
	SetHeight(SAMPLE_HEIGHT);
	SetWidth(Size.x);
	SetHeight(Size.y);
	m_Move = INITVECTOR3;
	m_nSample = 0;
	m_bLanding = false;
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
	SetType(CObject::TYPE_PLAYER2D);

	m_Move.x = move_player;
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
	m_PosOld = pos;
	Move(&pos);

	Jump();
	//�ړ��͈͂̃`�F�b�N
	if (pos_max.x < (pos.x + (Size.x / 2)))
	{
		pos.x = pos_max.x - (Size.x / 2);
		m_Move.x *= -1.0f;
	}
	else if (pos_min.x > (pos.x - (Size.x / 2)))
	{
		pos.x = pos_min.x + (Size.x / 2);
		m_Move.x *= -1.0f;
	}
	//�d�͂Ɨ������E
	m_Move.y += gravity;
	if (pos.y > pos_max.y)
	{
		//�u���b�N�̔��肪��������܂łЂƂ܂����ӂ����Ƃ���
		pos.y = pos_max.y;
		m_Move.y = 0.0f;
		m_bLanding = true;
	}

	SetPos(pos);

	CManager::GetInstance()->GetBlockManager()->Collision(this);
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
	*pos += m_Move;
}

//====================================================================
//�W�����v����
//====================================================================
void CPlayer2D::Jump()
{
	CInputKeyboard* pInputKey = CManager::GetInstance()->GetInputKeyboard();
	CInputJoypad* pInputPad = CManager::GetInstance()->GetInputJoyPad();
	if (m_bLanding &&(pInputKey->GetTrigger(DIK_SPACE) || pInputPad->GetTrigger(CInputJoypad::BUTTON_A,0)))
	{
		m_bLanding = false;
		m_Move.y = -jump_player;
	}
}