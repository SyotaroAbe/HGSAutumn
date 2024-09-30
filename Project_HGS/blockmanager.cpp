//============================================
//
//	ブロック全般のマネージャー [blockmanager.cpp]
//	Author:nakamura riku
//
//============================================
#include "blockmanager.h"
#include "block.h"
#include "Player2D.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"

// マクロ定義

// 静的メンバ変数宣言
CBlockManager* CBlockManager::pBlockManager = nullptr;

//====================================================================
// コンストラクタ
//====================================================================
CBlockManager::CBlockManager()
{
	listBlock.clear();
	m_nBlockCounter = 0;
}

//====================================================================
// デストラクタ
//====================================================================
CBlockManager::~CBlockManager()
{

}

//====================================================================
// 生成処理
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
// 初期化処理
//====================================================================
HRESULT CBlockManager::Init(void)
{
	return S_OK;
}

//====================================================================
// 終了処理
//====================================================================
void CBlockManager::Uninit(void)
{
	listBlock.clear();
}

//====================================================================
// 更新処理
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
// タイトルでの更新処理
//====================================================================
void CBlockManager::TitleUpdate(void)
{
	listBlock.clear();
}

//====================================================================
// ゲームでの更新処理
//====================================================================
void CBlockManager::GameUpdate(void)
{
	if (!CManager::GetInstance()->GetPause())
	{
		SetStage();
		
		// 各ブロックの更新
		for (auto itrBlock : listBlock)
		{
			// まだ破棄されていないなら更新
			if (itrBlock->GetDeathFlag() != true)
			{
				//itrBlock->Update();
			}
		}

		// 各ブロックが破棄予定ならリストから消去
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
}

//====================================================================
// チュートリアルでの更新処理
//====================================================================
void CBlockManager::TutorialUpdate(void)
{

}

//====================================================================
// 描画処理
//====================================================================
void CBlockManager::Draw(void)
{
	
}

//====================================================================
// 当たり判定処理
//====================================================================
void CBlockManager::Collision(CPlayer2D* pPlayer2D)
{
	// 各ブロックの更新
	for (auto itrBlock : listBlock)
	{
		// まだ破棄されていないなら更新
		if (itrBlock->GetDeathFlag() != true)
		{
			itrBlock->Collision(pPlayer2D);
		}
	}
}

//====================================================================
// ステージの配置処理
//====================================================================
void  CBlockManager::SetStage(void)
{
	m_nBlockCounter++;

	if (m_nBlockCounter > m_nBlockRandom)
	{
		int blockPosX = (rand() & 3) - 1;
		while (1)
		{
			blockPosX = (rand() & 3) - 1;

			if (m_nBlockRandomPos != blockPosX)
				break;
		}
		m_nBlockRandomPos = blockPosX;

		int blockWight = (rand() & 3);
		CBlock* pBlock = CBlockBase::Create(D3DXVECTOR3(640.0f + ((float)blockPosX * 200.0f), 800.0f, 0.0f), D3DXVECTOR3(0.0f, -1.0f, 0.0f), 200.0f + (100.0f *(float)blockWight), 50.0f);
		listBlock.push_back(pBlock);

		m_nBlockRandom = (rand() & 100) + 150;
		m_nBlockCounter = 0;
	}
}
