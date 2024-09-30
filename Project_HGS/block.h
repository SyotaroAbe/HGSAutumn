//============================================
//
//	ブロックのスーパークラス [block.h]
//	Author:nakamura riku
//
//============================================
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "main.h"
#include "object2D.h"

// ブロッククラス
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

	// 取得処理・設定処理

private:
	D3DXVECTOR3 m_move;							// 移動量
	float m_fWight;								// 幅
	float m_fHeight;							// 高さ
	bool bDeath;
};
#endif