//============================================
//
//	プレイヤー2Dのサンプル [Player2D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Player2D.h"
#include "renderer.h"
#include "manager.h"
#include "blockmanager.h"
#include "input.h"

//マクロ定義
#define SAMPLE_WIGHT (60.0f)		//横幅
#define SAMPLE_HEIGHT (80.0f)		//縦幅

namespace
{
	D3DXVECTOR2 Size		 = D3DXVECTOR2(60.0f, 80.0f);//プレイヤーの大きさ
	float move_player		= 5.0f; //プレイヤーの移動速度
	float jump_player		= 5.0f; //プレイヤーのジャンプ強度		
	float gravity			= 0.1f;	//重力
	D3DXVECTOR3 move_space	= D3DXVECTOR3(250.0f, 250.0f, 0.0f);//中心からの移動範囲
	D3DXVECTOR3 pos_max		= SCREEN_CENTER + move_space;
	D3DXVECTOR3 pos_min		= SCREEN_CENTER - move_space;
}
//====================================================================
//コンストラクタ
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
//デストラクタ
//====================================================================
CPlayer2D::~CPlayer2D()
{

}

//====================================================================
//生成処理
//====================================================================
CPlayer2D* CPlayer2D::Create(int nPriority)
{
	CPlayer2D* pSample2D = NULL;

	if (pSample2D == NULL)
	{
		//オブジェクト2Dの生成
		pSample2D = new CPlayer2D(nPriority);
	}

	//オブジェクトの初期化処理
	if (FAILED(pSample2D->Init()))
	{//初期化処理が失敗した場合
		return NULL;
	}

	return pSample2D;
}

//====================================================================
//初期化処理
//====================================================================
HRESULT CPlayer2D::Init(void)
{
	CObject2D::Init();

	////テクスチャ設定
	//SetTexture("data\\TEXTURE\\Number01.png");

	//新しくcppを作成した時は新しいTYPEを列挙に追加して指定すること
	SetType(CObject::TYPE_PLAYER2D);

	m_Move.x = move_player;
	return S_OK;
}

//====================================================================
//終了処理
//====================================================================
void CPlayer2D::Uninit(void)
{
	CObject2D::Uninit();
}

//====================================================================
//更新処理
//====================================================================
void CPlayer2D::Update(void)
{
	//頂点情報の更新
	CObject2D::Update();

	D3DXVECTOR3 pos = GetPos();
	m_PosOld = pos;
	Move(&pos);

	Jump();
	//移動範囲のチェック
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
	//重力と落下限界
	m_Move.y += gravity;
	if (pos.y > pos_max.y)
	{
		//ブロックの判定が完成するまでひとまず下辺を床とする
		pos.y = pos_max.y;
		m_Move.y = 0.0f;
		m_bLanding = true;
	}

	SetPos(pos);

	CManager::GetInstance()->GetBlockManager()->Collision(this);
}

//====================================================================
//描画処理
//====================================================================
void CPlayer2D::Draw(void)
{
	CObject2D::Draw();
}

//====================================================================
//移動処理
//====================================================================
void CPlayer2D::Move(D3DXVECTOR3* pos)
{
	float fMove = 5.0f;
	*pos += m_Move;
}

//====================================================================
//ジャンプ処理
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