//============================================
//
//	�u���b�N�S�ʂ̃}�l�[�W���[ [blockmanager.cpp]
//	Author:nakamura riku
//
//============================================
#include "blockmanager.h"
#include "block.h"
#include "Player2D.h"
#include "renderer.h"
#include "manager.h"

// �}�N����`

// �ÓI�����o�ϐ��錾
CBlockManager* CBlockManager::pBlockManager = nullptr;

//====================================================================
// �R���X�g���N�^
//====================================================================
CBlockManager::CBlockManager()
{
	listBlock.clear();
	m_nBlockCounter = 0;
}

//====================================================================
// �f�X�g���N�^
//====================================================================
CBlockManager::~CBlockManager()
{

}

//====================================================================
// ��������
//====================================================================
CBlockManager* CBlockManager::GetInstance()
{
	if (pBlockManager == nullptr)
	{
		pBlockManager = new CBlockManager;
	}
	return pBlockManager;
}

//====================================================================
// ����������
//====================================================================
HRESULT CBlockManager::Init(void)
{
	return S_OK;
}

//====================================================================
// �I������
//====================================================================
void CBlockManager::Uninit(void)
{
	listBlock.clear();
}

//====================================================================
// �X�V����
//====================================================================
void CBlockManager::Update(void)
{
	switch (CScene::GetMode())
	{
	case CScene::MODE_TITLE:
		TitleUpdate();
		break;

	case CScene::MODE_GAME:
		GameUpdate();
		break;

	case CScene::MODE_TUTORIAL:
		TutorialUpdate();
		break;

	case CScene::MODE_RESULT:
		break;
	}
}

//====================================================================
// �^�C�g���ł̍X�V����
//====================================================================
void CBlockManager::TitleUpdate(void)
{
	listBlock.clear();
}

//====================================================================
// �Q�[���ł̍X�V����
//====================================================================
void CBlockManager::GameUpdate(void)
{
	m_nBlockCounter++;

	if (m_nBlockCounter > 300)
	{
		CBlock* pBlock = CBlockBase::Create(D3DXVECTOR3(640.0f, 800.0f, 0.0f), D3DXVECTOR3(0.0f, -1.0f, 0.0f), 250.0f, 50.0f);
		listBlock.push_back(pBlock);

		m_nBlockCounter = 0;
	}

	// �e�u���b�N�̍X�V
	for (auto itrBlock : listBlock)
	{
		// �܂��j������Ă��Ȃ��Ȃ�X�V
		if (itrBlock->GetDeathFlag() != true)
		{
			itrBlock->Update();
		}
	}

	// �e�u���b�N���j���\��Ȃ烊�X�g�������
	std::list<CBlock*>  listBlockDef = listBlock;
	for (auto itrBlock : listBlock)
	{
		if (itrBlock->GetDeathFlag())
		{
			listBlockDef.remove(itrBlock);
		}
	}
	listBlock = listBlockDef;
}

//====================================================================
// �`���[�g���A���ł̍X�V����
//====================================================================
void CBlockManager::TutorialUpdate(void)
{

}

//====================================================================
// �`�揈��
//====================================================================
void CBlockManager::Draw(void)
{
	
}

//====================================================================
// �����蔻�菈��
//====================================================================
void CBlockManager::Collision(CPlayer2D* pPlayer2D)
{
	// �e�u���b�N�̍X�V
	for (auto itrBlock : listBlock)
	{
		// �܂��j������Ă��Ȃ��Ȃ�X�V
		if (itrBlock->GetDeathFlag() != true)
		{
			itrBlock->Collision(pPlayer2D);
		}
	}
}