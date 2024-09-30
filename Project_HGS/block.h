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

// �u���b�N�N���X
class CBlock : public CObject2D
{
public:

	CBlock(int nPriority = 6);
	~CBlock();

	static CBlock* Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority = 6);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	// �擾�����E�ݒ菈��

private:
	D3DXVECTOR3 m_move;							// �ړ���
	float m_fWight;								// ��
	float m_fHeight;							// ����
	bool bDeath;
};
#endif