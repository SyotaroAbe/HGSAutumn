//============================================
//
//	ゲーム用ポーズ処理 [GamePause.cpp]
//	Author:sakamoto kai
//
//============================================
#include "GamePause.h"
#include "manager.h"
#include "input.h"
#include "texture.h"
#include "object2D.h"
#include "Fade.h"
#include "sound.h"

//マクロ定義
#define PAUSE_POS (D3DXVECTOR3(640.0f, 100.0f, 0.0f))
#define PAUSE_WIGHT (600.0f)
#define PAUSE_HEIGHT (200.0f)
#define UI_POS (D3DXVECTOR3(640.0f, 300.0f, 0.0f))
#define UI_WIGHT (600.0f)
#define UI_HEIGHT (150.0f)
#define UI_HSIDE (175.0f)

//静的メンバ変数宣言
CObject2D* CGamePause::m_pPauseUI[MAX_PAUSE] = {};
CObject2D* CGamePause::m_pPauseFG[MAX_FG] = {};
CObject2D* CGamePause::m_pPauseMark = NULL;
bool CGamePause::m_bColor = false;

//====================================================================
//コンストラクタ
//====================================================================
CGamePause::CGamePause()
{
	m_PauseSelect = 0;
	m_Appear = false;
}

//====================================================================
//デストラクタ
//====================================================================
CGamePause::~CGamePause()
{

}

//====================================================================
//生成処理
//====================================================================
CGamePause* CGamePause::Create()
{
	CGamePause* pPause = NULL;

	if (pPause == NULL)
	{
		//敵の生成
		pPause = new CGamePause();
	}

	//オブジェクトの初期化処理
	if (FAILED(pPause->Init()))
	{//初期化処理が失敗した場合
		return NULL;
	}

	return pPause;
}

//====================================================================
//初期化処理
//====================================================================
HRESULT CGamePause::Init(void)
{
	for (int nCnt = 0; nCnt < MAX_FG; nCnt++)
	{
		m_pPauseFG[nCnt] = CObject2D::Create(7);
		m_pPauseFG[nCnt]->SetType(CObject::TYPE_TUTORIALUI);

		switch (nCnt)
		{
		case 0:
			m_pPauseFG[nCnt]->SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
			m_pPauseFG[nCnt]->SetWidth(1280.0f);
			m_pPauseFG[nCnt]->SetHeight(720.0f);
			m_pPauseFG[nCnt]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
			break;

		case 1:
			m_pPauseFG[nCnt]->SetPos(PAUSE_POS);
			m_pPauseFG[nCnt]->SetWidth(PAUSE_WIGHT);
			m_pPauseFG[nCnt]->SetHeight(PAUSE_HEIGHT);
			m_pPauseFG[nCnt]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
			m_pPauseFG[nCnt]->SetTexture("data\\TEXTURE\\pause\\paper00.png");
			break;

		default:
			break;
		}
	}

	for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
	{
		m_pPauseUI[nCnt] = CObject2D::Create(7);
		m_pPauseUI[nCnt]->SetType(CObject::TYPE_TUTORIALUI);
		switch (nCnt)
		{
		case 0:
			m_pPauseUI[nCnt]->SetWidth(UI_WIGHT);
			m_pPauseUI[nCnt]->SetHeight(UI_HEIGHT);
			break;
		case 1:
			m_pPauseUI[nCnt]->SetWidth(UI_WIGHT);
			m_pPauseUI[nCnt]->SetHeight(UI_HEIGHT);
			break;
		case 2:
			m_pPauseUI[nCnt]->SetWidth(UI_WIGHT);
			m_pPauseUI[nCnt]->SetHeight(UI_HEIGHT);
			break;
		}
		m_pPauseUI[nCnt]->SetPos(D3DXVECTOR3(UI_POS.x, UI_POS.y + nCnt * UI_HSIDE, UI_POS.z));
		m_pPauseUI[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));

		m_InitPos[nCnt] = m_pPauseUI[nCnt]->GetPos();
	}
	m_pPauseUI[0]->SetTexture("data\\TEXTURE\\pause\\pause_00.png");
	m_pPauseUI[1]->SetTexture("data\\TEXTURE\\pause\\pause_01.png");
	m_pPauseUI[2]->SetTexture("data\\TEXTURE\\pause\\pause_02.png");

	m_pPauseMark = CObject2D::Create(7);
	m_pPauseMark->SetType(CObject::TYPE_TUTORIALUI);
	m_pPauseMark->SetWidth(140.0f);
	m_pPauseMark->SetHeight(140.0f);
	m_pPauseMark->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_pPauseMark->SetPos(INITVECTOR3);
	m_pPauseMark->SetTexture("data\\TEXTURE\\pause\\shuriken00.png");

	m_MoveRot = 0.04f;
	m_MarkRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	return S_OK;
}

//====================================================================
//終了処理
//====================================================================
void CGamePause::Uninit(void)
{

}

//====================================================================
//更新処理
//====================================================================
void CGamePause::Update(void)
{
	//キーボードの取得
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();
	CInputJoypad* pInputJoypad = CManager::GetInstance()->GetInputJoyPad();

	if (CManager::GetInstance()->GetPause() == true)
	{
		for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
		{
			if (nCnt == m_PauseSelect)
			{
				m_pPauseUI[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
				m_pPauseUI[nCnt]->SetWidth(700.0f);
				m_pPauseUI[nCnt]->SetHeight(200.0f);

				m_pPauseMark->SetPos(D3DXVECTOR3(m_InitPos[nCnt].x - 410.0f, m_InitPos[nCnt].y - 57.0f, m_InitPos[nCnt].z));
			}
			else
			{
				m_pPauseUI[nCnt]->SetColor(D3DXCOLOR(0.6f, 0.6f, 0.6f, 0.75f));
				m_pPauseUI[nCnt]->SetWidth(UI_WIGHT);
				m_pPauseUI[nCnt]->SetHeight(UI_HEIGHT);

				m_pPauseUI[nCnt]->SetPos(D3DXVECTOR3(m_InitPos[nCnt].x, m_InitPos[nCnt].y, m_InitPos[nCnt].z));
			}
		}
	}

	if (m_Appear == true)
	{
		for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
		{
			m_pPauseUI[nCnt]->SetAppear(true);
		}
		for (int nCnt = 0; nCnt < MAX_FG; nCnt++)
		{
			m_pPauseFG[nCnt]->SetAppear(true);
		}
		m_pPauseMark->SetAppear(true);

		if (!m_bColor)
		{
			m_pPauseFG[0]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.8f));
			m_pPauseFG[1]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
		m_bColor = true;
	}
	else
	{
		for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
		{
			m_pPauseUI[nCnt]->SetAppear(false);
		}
		for (int nCnt = 0; nCnt < MAX_FG; nCnt++)
		{
			m_pPauseFG[nCnt]->SetAppear(false);
		}
		m_pPauseMark->SetAppear(false);

		if (m_bColor)
		{
			m_pPauseFG[0]->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
			m_pPauseFG[1]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
		m_bColor = false;
	}
}

//====================================================================
//描画処理
//====================================================================
void CGamePause::Draw(void)
{

}