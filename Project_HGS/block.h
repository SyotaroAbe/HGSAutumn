//============================================
//
//	�u���b�N�̃X�[�p�[�N���X [block.h]
//	Author:nakamura riku
//
//============================================
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "main.h"
#include "object2D.h"

// �O���錾
class CPlayer2D;

// �u���b�N�X�[�p�[�N���X
class CBlock : public CObject2D
{
public:

	CBlock(int nPriority = 6);
	~CBlock();

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	virtual void Collision(CPlayer2D* pPlayer2D) = 0;

	// �擾�����E�ݒ菈��
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	D3DXVECTOR3 GetPosOld(void) { return m_posOld; }

private:
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_move;							// �ړ���
};

// ����N���X
class CBlockBase : public CBlock
{
public:

	CBlockBase(int nPriority = 6) {};
	~CBlockBase() {};

	static CBlockBase* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority = 6);

	HRESULT Init(void) { return CBlock::Init(); };
	void Uninit(void) { CBlock::Uninit(); };
	void Update(void) { CBlock::Update(); };
	void Draw(void) { CBlock::Draw(); };

	void Collision(CPlayer2D* pPlayer2D);

	// �擾�����E�ݒ菈��

private:

};

// ���N���X
class CBlockSpike : public CBlock
{
public:

	CBlockSpike(int nPriority = 6) {};
	~CBlockSpike() {};

	static CBlockSpike* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority = 6);

	HRESULT Init(void) { return CBlock::Init(); };
	void Uninit(void) { CBlock::Uninit(); };
	void Update(void) { CBlock::Update(); };
	void Draw(void) { CBlock::Draw(); };

	void Collision(CPlayer2D* pPlayer2D);

	// �擾�����E�ݒ菈��

private:

};

// �o�l�N���X
class CBlockSpring : public CBlock
{
public:

	CBlockSpring(int nPriority = 6) {};
	~CBlockSpring() {};

	static CBlockSpring* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority = 6);

	HRESULT Init(void) { return CBlock::Init(); };
	void Uninit(void) { CBlock::Uninit(); };
	void Update(void) { CBlock::Update(); };
	void Draw(void) { CBlock::Draw(); };

	void Collision(CPlayer2D* pPlayer2D);

	// �擾�����E�ݒ菈��

private:

};
#endif