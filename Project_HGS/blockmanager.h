//============================================
//
//	�u���b�N�S�ʂ̃}�l�[�W���[ [blockmanager.h]
//	Author:nakamura riku
//
//============================================
#ifndef _BLOCKMANAGER_H_
#define _BLOCKMANAGER_H_

#include "main.h"
#include <list>

// �O���錾
class CBlock;

// �u���b�N�}�l�[�W���[�N���X
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

	// �擾�����E�ݒ菈��

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