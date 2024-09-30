//============================================
//
//	ブロック全般のマネージャー [blockmanager.h]
//	Author:nakamura riku
//
//============================================
#ifndef _BLOCKMANAGER_H_
#define _BLOCKMANAGER_H_

#include "main.h"
#include <list>

// 前方宣言
class CBlock;

// ブロックマネージャークラス
class CBlockManager
{
public:

	CBlockManager();
	~CBlockManager();

	static CBlockManager* GetInstance();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	// 取得処理・設定処理

private:
	void TitleUpdate(void);
	void GameUpdate(void);
	void TutorialUpdate(void);

	void Collision(void);

	static CBlockManager* pBlockManager;
	std::list<CBlock*> listBlock;

	int m_nBlockCounter;
};
#endif