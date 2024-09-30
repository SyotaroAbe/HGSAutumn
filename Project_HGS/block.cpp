//============================================
//
//	ブロックのスーパークラス [block.cpp]
//	Author:nakamura riku
//
//============================================
#include "block.h"
#include "renderer.h"
#include "manager.h"

// マクロ定義

//====================================================================
// コンストラクタ
//====================================================================
CBlock::CBlock(int nPriority) : CObject2D(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//====================================================================
// デストラクタ
//====================================================================
CBlock::~CBlock()
{

}

//====================================================================
// 生成処理
//====================================================================
CBlock* CBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority)
{
	CBlock* pBlock = NULL;

	if (pBlock == NULL)
	{
		//オブジェクト2Dの生成
		pBlock = new CBlock();
	}

	if (pBlock != NULL)
	{
		pBlock->SetPos(pos);
		pBlock->SetWidth(fWight);
		pBlock->SetHeight(fHeight);
		pBlock->m_move = move;

		//オブジェクトの初期化処理
		if (FAILED(pBlock->Init()))
		{//初期化処理が失敗した場合
			return NULL;
		}
	}

	return pBlock;
}

//====================================================================
// 初期化処理
//====================================================================
HRESULT CBlock::Init(void)
{
	CObject2D::Init();

	//テクスチャ設定
	SetTexture("data\\TEXTURE\\Number01.png");

	//新しくcppを作成した時は新しいTYPEを列挙に追加して指定すること
	SetType(CObject::TYPE_BLOCK);

	return S_OK;
}

//====================================================================
// 終了処理
//====================================================================
void CBlock::Uninit(void)
{
	CObject2D::Uninit();
}

//====================================================================
// 更新処理
//====================================================================
void CBlock::Update(void)
{
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 posOld = GetPosOld();

	pos += m_move;

	if (pos.y < GetHeight() * -4.0f)
		Uninit();

	SetPos(pos);

	//頂点情報の更新
	CObject2D::Update();

	//----頂点情報を変更したい場合は以下のコードを使用すること-----
	//VERTEX_2D* pVtx;	//頂点ポインタを所得

	////頂点バッファをロックし、両店情報へのポインタを所得
	//GetVtxBuff()->Lock(0, 0, (void**)&pVtx, 0);

	////位置
	//pVtx[0].pos = m_pos;
	//pVtx[1].pos = m_pos;
	//pVtx[2].pos = m_pos;
	//pVtx[3].pos = m_pos;

	////色
	//pVtx[0].col;
	//pVtx[1].col;
	//pVtx[2].col;
	//pVtx[3].col;

	////テクスチャ
	//pVtx[0].tex;
	//pVtx[1].tex;
	//pVtx[2].tex;
	//pVtx[3].tex;

	////頂点バッファをアンロックする
	//GetVtxBuff()->Unlock();
}

//====================================================================
// 描画処理
//====================================================================
void CBlock::Draw(void)
{
	CObject2D::Draw();
}