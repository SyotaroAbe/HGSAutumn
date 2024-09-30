//============================================
//
//	ブロックのスーパークラス [block.cpp]
//	Author:nakamura riku
//
//============================================
#include "block.h"
#include "Player2D.h"
#include "renderer.h"
#include "manager.h"
#include "useful.h"

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
// 初期化処理
//====================================================================
HRESULT CBlock::Init(void)
{
	CObject2D::Init();

	//テクスチャ設定
	SetTexture("data\\TEXTURE\\0_1.png");

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
	m_posOld = pos;

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

//====================================================================
// 足場ブロック
//====================================================================
// 生成処理
//====================================================================
CBlockBase* CBlockBase::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority)
{
	CBlockBase* pBlock = NULL;

	if (pBlock == NULL)
	{
		//オブジェクト2Dの生成
		pBlock = new CBlockBase();
	}

	if (pBlock != NULL)
	{
		pBlock->SetPos(pos);
		pBlock->SetWidth(fWight);
		pBlock->SetHeight(fHeight);
		pBlock->SetMove(move);

		//オブジェクトの初期化処理
		if (FAILED(pBlock->Init()))
		{//初期化処理が失敗した場合
			return NULL;
		}
	}

	return pBlock;
}

//====================================================================
// 当たり判定処理
//====================================================================
void CBlockBase::Collision(CPlayer2D* pPlayer2D)
{
	// プレイヤー側変数
	D3DXVECTOR3 playerPos = pPlayer2D->GetPos();
	D3DXVECTOR3 playerPosOld = pPlayer2D->GetPosOld();
	D3DXVECTOR3 playerMove = pPlayer2D->GetMove();
	float playerHeight = pPlayer2D->GetHeight() * 0.5f;
	float playerWidth = pPlayer2D->GetWidth() * 0.5f;
	bool playerLanding = pPlayer2D->GetLanding();

	// ブロック側変数
	D3DXVECTOR3 blockPos = GetPos();
	D3DXVECTOR3 blockPosOld = GetPosOld();
	D3DXVECTOR3 blockMove = GetMove();
	float blockHeight = GetHeight() * 0.5f;
	float blockWidth = GetWidth() * 0.5f;

	if ((playerPos.x + playerWidth > blockPos.x - blockWidth &&
		playerPos.x + playerWidth < blockPos.x + blockWidth) ||
		(playerPos.x - playerWidth > blockPos.x - blockWidth &&
		playerPos.x - playerWidth < blockPos.x + blockWidth))
	{
		if (playerPos.y + playerHeight > blockPos.y - blockHeight &&
			playerPos.y + playerHeight < blockPos.y + blockHeight)
		{
			playerPos.y = blockPos.y - blockHeight - playerHeight + blockMove.y;
			playerLanding = true;
		}
	}

	if ((playerPos.x + playerWidth > blockPos.x - blockWidth &&
		playerPos.x + playerWidth < blockPos.x + blockWidth) ||
		(playerPos.x - playerWidth > blockPos.x - blockWidth &&
			playerPos.x - playerWidth < blockPos.x + blockWidth))
	{
		if (playerPos.y - playerHeight > blockPos.y - blockHeight &&
			playerPos.y - playerHeight < blockPos.y + blockHeight)
		{
			playerPos.y = blockPos.y + blockHeight + playerHeight;
		}
	}

	/*if ((playerPos.y + playerHeight > blockPos.y - blockHeight &&
		playerPos.y + playerHeight < blockPos.y + blockHeight) || 
		(playerPos.y - playerHeight > blockPos.y - blockHeight &&
			playerPos.y - playerHeight < blockPos.y + blockHeight))
	{
		playerMove.x *= -1.0f;
	}*/

	pPlayer2D->SetPos(playerPos);
	pPlayer2D->SetMove(playerMove);
	pPlayer2D->SetLanding(playerLanding);
}

//====================================================================
// 棘ブロック
//====================================================================
// 生成処理
//====================================================================
CBlockSpike* CBlockSpike::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWight, float fHeight, int nPriority)
{
	CBlockSpike* pBlock = NULL;

	if (pBlock == NULL)
	{
		//オブジェクト2Dの生成
		pBlock = new CBlockSpike();
	}

	if (pBlock != NULL)
	{
		pBlock->SetPos(pos);
		pBlock->SetWidth(fWight);
		pBlock->SetHeight(fHeight);
		pBlock->SetMove(move);

		//オブジェクトの初期化処理
		if (FAILED(pBlock->Init()))
		{//初期化処理が失敗した場合
			return NULL;
		}
	}

	return pBlock;
}

//====================================================================
// 当たり判定処理
//====================================================================
void CBlockSpike::Collision(CPlayer2D* pPlayer2D)
{
	// プレイヤー側変数
	D3DXVECTOR3 playerPos = pPlayer2D->GetPos();
	float playerHeight = pPlayer2D->GetHeight();
	float playerWidth = pPlayer2D->GetWidth();

	// ブロック側変数
	D3DXVECTOR3 blockPos = GetPos();
	float blockHeight = GetHeight();
	float blockWidth = GetWidth();

	if (fabsf((playerPos - blockPos).y) < playerHeight + blockHeight &&
		fabsf((playerPos - blockPos).x) < playerWidth + blockWidth)
	{
		// 棘に当たった時の処理
	}
}