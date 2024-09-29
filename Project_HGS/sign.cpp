//============================================
//
//	印 [sign.cpp]
//	Author:筋肉★小笠原★筋肉 + 酒井南勝
//
//============================================
#include "sign.h"
#include "object2D.h"
#include "input.h"
#include "joycon.h"
#include "manager.h"
#include "renderer.h"
#include "aim.h"
#include "game.h"
#include "useful.h"

#include "debugproc.h"

#include "tutorial.h"

#include "sound.h"

// 名前空間
namespace
{
	const D3DXVECTOR3 POS = { 800.0f, 220.0f, 0.0f };

	const char* PEN_TEX_PATH = "data\\TEXTURE\\makimono\\hude.png";	// ペンのテクスチャパス
	const D3DXCOLOR COLOR_PEN = { 1.0f, 1.0f, 1.0f, 0.3f };
	const float SIZE_PEN = 80.0f;

	const float PEN_JUDGE_LENGTH = 50.0f;	// ペン判定を生成する間隔
	const float JUDGE_LENGTH = 70.0f;	// ペン判定と印判定が触れたと判定される長さ

	const int SURPLUS = 3;	// 判定の有余

	const float OVER_LENGTH = 5.0f;	// 超えてはいけない距離
	const int OVER_SET = (int)OVER_LENGTH;	// 置く距離
}

//====================================================================
//= コンストラクタ
//====================================================================
CSign::CSign(SIGNTYPE type)
{
	// 値のクリア
	ZeroMemory(&m_aPen, sizeof(m_aPen));
	ZeroMemory(&m_info, sizeof(m_info));
	
	m_nNum = 0;
	m_nNumJudge = 0;
	m_type = type;

	m_nMissCount = 0;

	ZeroMemory(&m_aInfo, sizeof(m_aInfo));
	m_nNumSign = 0;

	m_bUse = false;
}

//====================================================================
//= デストラクタ
//====================================================================
CSign::~CSign()
{

}

//====================================================================
//= 生成処理
//====================================================================
CSign* CSign::Create(SIGNTYPE type)
{
	CSign* pSign = nullptr;

	if (!pSign)
	{
		pSign = new CSign(type);

		pSign->Init();
	}

	return pSign;
}

//====================================================================
//= 初期化処理
//====================================================================
HRESULT CSign::Init()
{
	switch (m_type)
	{
	case SIGNTYPE_NONE:
		break;
	case SIGNTYPE_FIRE:
		m_info.pos = POS;
		Load("data\\TXT\\SIGN\\fire.txt");
		break;
	case SIGNTYPE_FOG:
		m_info.pos = POS;
		Load("data\\TXT\\SIGN\\fog.txt");
		break;
	case SIGNTYPE_DOUBLE:
		m_info.pos = POS;
		Load("data\\TXT\\SIGN\\double.txt");
		break;
	default:
		break;
	}

	return E_NOTIMPL;
}

//====================================================================
//= 終了処理
//====================================================================
void CSign::Uninit()
{
	for (int i = 0; i < MAX_SIGN; i++)
	{
		if (m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck->Uninit();
			m_info.aCheack[i].pSignCheck = nullptr;
			m_info.aCheack[i].bUse = false;
		}

		if (m_aPen[i].pSign2D)
		{
			m_aPen[i].pSign2D->Uninit();
			m_aPen[i].pSign2D = nullptr;
			m_aPen[i].nID = 0;
			m_aPen[i].bJudge = false;
		}

		if (m_aPen[i].pJudge2D)
		{
			m_aPen[i].pJudge2D->Uninit();
			m_aPen[i].pJudge2D = nullptr;
		}
		m_aPen[i].posJudge = {};
	}

	SetDeathFlag(true);
}

//====================================================================
//= 更新処理
//====================================================================
void CSign::Update()
{
	if (!m_info.bEnd)
	{
		// 
		Sign();

		// 判定
		SignCheck();
	}

	if (m_info.bEnd)
	{
		Misstake();
	}
}

//====================================================================
//= 描画処理
//====================================================================
void CSign::Draw()
{

}

//====================================================================
//= 印の跡
//====================================================================
void CSign::Sign()
{
	CInputMouse* pMouse = CManager::GetInstance()->GetInputMouse();
	CInputKeyboard* pKey = CManager::GetInstance()->GetInputKeyboard();
	CJoycon* pJoycon = CManager::GetInstance()->GetJoyconR();
	CAim* pAim = nullptr;

	switch (CScene::GetMode())
	{
	case CScene::MODE_GAME:
		pAim = CGame::GetAim();
		break;
	case CScene::MODE_TUTORIAL:
		pAim = CTutorial::GetAim();
		break;
	}
	
	if (pMouse->GetPress(pMouse->PUSH_LEFT) || pJoycon->GetCommonButton() == CJoycon::BUTTON_ZLZR)
	{// 指定のキーが押された場合
		if (pMouse != nullptr || pJoycon != nullptr)
		{
			SignMouse(pAim);

			// 印使用状態
			m_bUse = true;
		}
	}
	else if (pKey->GetRerease(DIK_B) || pMouse->GetRerease(pMouse->PUSH_LEFT) ||
		(pJoycon->GetCommonButton() != CJoycon::BUTTON_ZLZR && pJoycon->GetTriggerButton() == true))
	{// 指定のキーを離した場合にミス判定にする
		Misstake();

		// 印不使用状態
		m_bUse = false;
	}
}

//====================================================================
//= マウスを使用した印を描く処理
//====================================================================
void CSign::SignMouse(CAim* pAim)
{
	if (pAim->GetSpeed().x > 0.0f || pAim->GetSpeed().x < 0.0f ||
		pAim->GetSpeed().y > 0.0f || pAim->GetSpeed().y < 0.0f)
	{// マウスの移動量が指定値を越していた場合

		for (int i = 0; i < MAX_SIGN; i++)
		{
			if (!m_aPen[i].pSign2D)
			{// 書く
				m_aPen[i].pSign2D = CObject2D::Create();
				m_aPen[i].pSign2D->SetWidth(SIZE_PEN);
				m_aPen[i].pSign2D->SetHeight(SIZE_PEN);
				m_aPen[i].pSign2D->SetPos(*pAim->GetScreenPos());
				m_aPen[i].pSign2D->SetColor(COLOR_PEN);
				m_aPen[i].pSign2D->SetTexture(PEN_TEX_PATH);

				// 修正
				SignOver(i);

				break;
			}
		}

		// 筆で書く音
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_WRITE_BRUSH);

		// 判定処理
		Judge();
	}
}

//====================================================================
//= オーバーした印の修正
//====================================================================
void CSign::SignOver(int nIdx)
{
	if (nIdx != 0)
	{
		if (m_aPen[nIdx - 1].pSign2D && m_aPen[nIdx].pSign2D)
		{// 
			// 位置情報の取得
			D3DXVECTOR3 posOld = m_aPen[nIdx - 1].pSign2D->GetPos();
			D3DXVECTOR3 posNow = m_aPen[nIdx].pSign2D->GetPos();

			// 距離計算
			float fLength = sqrtf((posOld.x - posNow.x) * (posOld.x - posNow.x) + (posOld.y - posNow.y) * (posOld.y - posNow.y));

			if (fLength > OVER_LENGTH)
			{// 距離が離れていた場合
				// 角度を算出
				float fAngle = atan2f((posNow.x - posOld.x), (posNow.y - posOld.y));

				// forカウント用
				int nCnt = 0;

				for (int j = 0; j < MAX_SIGN; j++)
				{
					if (!m_aPen[j].pSign2D)
					{// 書く
						m_aPen[j].pSign2D = CObject2D::Create();
						m_aPen[j].pSign2D->SetWidth(SIZE_PEN);
						m_aPen[j].pSign2D->SetHeight(SIZE_PEN);
						m_aPen[j].pSign2D->SetColor(COLOR_PEN);
						m_aPen[j].pSign2D->SetTexture(PEN_TEX_PATH);

						nCnt++;

						m_aPen[j].pSign2D->SetPos(
							{// 位置設定
								posOld.x + (sinf(fAngle) * (nCnt * OVER_SET)),
								posOld.y + (cosf(fAngle) * (nCnt * OVER_SET)),
								0.0f
							});

						// 距離計算
						fLength = sqrtf((m_aPen[j].pSign2D->GetPos().x - posNow.x) * (m_aPen[j].pSign2D->GetPos().x - posNow.x) + (m_aPen[j].pSign2D->GetPos().y - posNow.y) * (m_aPen[j].pSign2D->GetPos().y - posNow.y));

						if (fLength < (float)OVER_SET)
						{// 離れていた筆へ近づいたら
							break;
						}
					}
				}
			}
		}
	}
}

//====================================================================
//= 判定
//====================================================================
void CSign::Judge()
{
	// 情報の取得
	CAim* pAim = nullptr;

	switch (CScene::GetMode())
	{
	case CScene::MODE_GAME:
		pAim = CGame::GetAim();
		break;
	case CScene::MODE_TUTORIAL:
		pAim = CTutorial::GetAim();
		break;
	}

	float fLength = 0.0f;
	
	if (m_nNumJudge != 0)
	{
		D3DXVECTOR3 pos1 = m_aPen[m_nNumJudge - 1].posJudge;
		D3DXVECTOR3 pos2 = *pAim->GetScreenPos();

		// 距離計算
		fLength = sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
	}
	
	if (fLength > PEN_JUDGE_LENGTH || m_nNumJudge == 0)
	{// 判定の位置を設置

#ifdef _DEBUG
		// 分かりやすいようにポリゴン表示
		m_aPen[m_nNumJudge].pJudge2D = CObject2D::Create();
		m_aPen[m_nNumJudge].pJudge2D->SetWidth(50.0f);
		m_aPen[m_nNumJudge].pJudge2D->SetHeight(50.0f);
		m_aPen[m_nNumJudge].pJudge2D->SetPos(*pAim->GetScreenPos());
		m_aPen[m_nNumJudge].pJudge2D->SetColor({ 0.0f, 0.0f, 1.0f, 1.0f });
		m_aPen[m_nNumJudge].pJudge2D->SetTexture("data\\TEXTURE\\effect\\effect000.png");
		// ここまで↑
#endif
		// 判定の位置を設定
		m_aPen[m_nNumJudge].posJudge = *pAim->GetScreenPos();
		m_aPen[m_nNumJudge].nID = m_nNumJudge;	// IDを設定
		m_aPen[m_nNumJudge].bUse = true;

		m_nNumJudge++;	// 番号のカウントアップ
	}
}

//====================================================================
//= 印のチェック
//====================================================================
void CSign::SignCheck()
{
	// 変数宣言
	D3DXVECTOR3 posSign = {};
	D3DXVECTOR3 posPen = {};
	float fRadius = 0.0f;
	int nNumTouch = 0;

	for (int i = 0; i < MAX_SIGN; i++)
	{
		if (m_info.aCheack[i].bUse || !m_info.aCheack[i].pSignCheck)
		{// チェックポインタが生成されていない||チェック済の場合
			continue;
		}

		for (int j = 0; j < MAX_SIGN; j++)
		{
			if (!m_aPen[j].bUse || m_aPen[j].bBool)
			{
				continue;
			}

			// 情報の取得
			posSign = m_info.aCheack[i].pSignCheck->GetPos();	// なぞられる側の判定の位置
			posPen = m_aPen[j].posJudge;	// なぞる側の判定の位置

			// 判定と判定の距離を計算
			fRadius = sqrtf((posSign.x - posPen.x) * (posSign.x - posPen.x) + (posSign.y - posPen.y) * (posSign.y - posPen.y));

			if (fRadius <= JUDGE_LENGTH)
			{// 円の判定が範囲内の場合

				if (!m_info.aCheack[i].bUse)
				{// 使用されていない場合(同じ判定に触れないようにするため)
					m_info.aCheack[i].nJudgeID = m_nNum;	// 判定IDを設定
					m_info.aCheack[i].bUse = true;	// 使用された

#ifdef _DEBUG
					m_info.aCheack[i].pSignCheck->SetColor({ 1.0f, 0.0f, 0.0f, 1.0 });
#endif

					m_nNum++;	// 判定IDのカウントを進める
					m_nMissCount = 0;

					m_aPen[j].bJudge = true;
					m_aPen[j].bBool = true;
				}

				if (m_nNum == m_info.nEndID)
				{// 判定した数と最後の判定IDが一致した場合
					Success();
				}
				//else if (m_nNum - 1 != i)
				//{// 順番通りに触らなかった場合に失敗にする
				//	Misstake();
				//}
			}
			else
			{
				m_nMissCount++;

				m_aPen[j].bBool = true;
			}

			if (m_nMissCount > SURPLUS)
			{
				Misstake();
			}
		}
	}
}

//====================================================================
//= 失敗
//====================================================================
void CSign::Misstake()
{
	for (int i = 0; i < MAX_SIGN; i++)
	{
		if (m_info.aCheack[i].pSignCheck)
		{
#ifdef _DEBUG
			m_info.aCheack[i].pSignCheck->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
#endif
			m_info.aCheack[i].nJudgeID = 0;
			m_info.aCheack[i].bUse = false;
		}

		if (m_aPen[i].pSign2D)
		{
			m_aPen[i].pSign2D->Uninit();
			m_aPen[i].pSign2D = nullptr;
			m_aPen[i].nID = 0;
			m_aPen[i].bJudge = false;
			m_aPen[i].bBool = false;
			m_aPen[i].bUse = false;
		}

		if (m_aPen[i].pJudge2D)
		{
			m_aPen[i].pJudge2D->Uninit();
			m_aPen[i].pJudge2D = nullptr;
		}
		m_aPen[i].posJudge = {};
	}

	m_nNumJudge = 0;
	m_nNum = 0;
	m_nMissCount = 0;
}

//====================================================================
//= 成功
//====================================================================
void CSign::Success()
{
	for (int i = 0; i < MAX_SIGN; i++)
	{
#ifdef _DEBUG
		if (m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck->SetColor({ 1.0f, 0.0f, 1.0f, 1.0 });
		}
#else
		if (m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck->SetColorA(0.0f);
		}
#endif
		m_info.aCheack[i].nJudgeID = 0;
		m_info.aCheack[i].bUse = false;
	}

	m_info.bEnd = true;	// 成功したから終了
}

//===========================================================================================
// 外部ファイルから読み込む
//===========================================================================================
void CSign::Load(char* pTecPath)
{
	// 変数宣言
	char cTemp[256] = {};

	m_nNumSign = 0;

	// 値のクリア
	ZeroMemory(&m_aInfo[0], sizeof(m_aInfo));

	// ファイルから読み込む
	FILE* pFile = fopen(pTecPath, "r");

	if (pFile != nullptr)
	{// ファイルが開けた場合

		while (strcmp(&cTemp[0], "END_SCRIPT") != 0)
		{
			// 文字読み込み
			(void)fscanf(pFile, "%s", &cTemp[0]);

			if (strcmp(cTemp, "SET_SIGN") == 0)
			{// 読込開始

				while (1)
				{
					// 文字読み込み
					(void)fscanf(pFile, "%s", &cTemp[0]);

					// 移動量
					if (strcmp(cTemp, "POS") == 0)
					{
						(void)fscanf(pFile, "%s", &cTemp[0]);

						(void)fscanf(pFile, "%f", &m_aInfo[m_nNumSign].pos.x);
						(void)fscanf(pFile, "%f", &m_aInfo[m_nNumSign].pos.y);
					}

					if (strcmp(cTemp, "ID") == 0)
					{
						(void)fscanf(pFile, "%s", &cTemp[0]);

						(void)fscanf(pFile, "%d", &m_aInfo[m_nNumSign].nID);
					}

					if (strcmp(cTemp, "END_SIGN") == 0)
					{// 終了

						m_nNumSign++;
						break;
					}
				}
			}
		}

		// ファイルを閉じる
		fclose(pFile);
	}
	else
	{
		assert(("ファイル読み込みに失敗", false));
	}


	// 印の判定生成 後で消す
	for (int i = 0; i < m_nNumSign; i++)
	{

		if (!m_info.aCheack[i].pSignCheck)
		{
			m_info.aCheack[i].pSignCheck = CObject2D::Create();
			m_info.aCheack[i].pSignCheck->SetPos(m_aInfo[i].pos);
			m_info.aCheack[i].pSignCheck->SetWidth(100.0f);
			m_info.aCheack[i].pSignCheck->SetHeight(100.0f);
			m_info.aCheack[i].pSignCheck->SetTexture("data\\TEXTURE\\effect\\effect000.png");

#ifdef _DEBUG
			m_info.aCheack[i].pSignCheck->SetColorA(1.0f);
#else
			m_info.aCheack[i].pSignCheck->SetColorA(0.0f);
#endif

			m_info.aCheack[i].nMyID = i;	// 自分自身のID
			m_info.nEndID = i + 1;
		}
		
	}
}
