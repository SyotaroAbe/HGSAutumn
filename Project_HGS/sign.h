//============================================
//
//	印 [sign.h]
//	Author:筋肉★小笠原★筋肉
//
//============================================

#include "main.h"
#include "object.h"

// 前方宣言
class CObject2D;
class CAim;
class CInputMouse;
class CJoycon;

// 照準クラス
class CSign : public CObject
{
private:
	static const int MAX_SIGN = 1024;

public:
	enum SIGNTYPE
	{
		SIGNTYPE_NONE = 0,	// なし
		SIGNTYPE_FIRE,		// 火遁の印
		SIGNTYPE_FOG,		// 霧隠れ
		SIGNTYPE_DOUBLE,	// 分身
		MAX_TYPE,
	};

private:
	struct SCheck	// 一致するか調べる構造体
	{
		CObject2D* pSignCheck;
		int nMyID;
		int nJudgeID;
		bool bUse;
	};

	struct SCheckInfo
	{
		SCheck aCheack[MAX_SIGN];	// なぞり判定の構造体
		D3DXVECTOR3 pos;	// 基準となる位置
		int nEndID;
		bool bEnd;	// 完了
	};

	struct SPen	// ペン
	{
		CObject2D* pSign2D;
		int nID;
		bool bUse;

		CObject2D* pJudge2D;		// 判定の位置が分かりやすいように後で消す
		D3DXVECTOR3 posJudge;	// 判定の位置
		bool bJudge;	// 判定したかどうか
		bool bBool;
	};

	// ファイルから読み込んだ情報
	struct SLoadInfo
	{
		D3DXVECTOR3 pos;
		int nID;
	};

public:

	CSign(SIGNTYPE type = SIGNTYPE_NONE);
	~CSign();

	static CSign* Create(SIGNTYPE type);

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	bool GetEnd() { return m_info.bEnd; }
	void SetType(SIGNTYPE type) { m_type = type; }
	SIGNTYPE GetType() { return m_type; }
	bool GetUse() { return m_bUse; }

private:
	void Sign();			// 見た目状の書いたあと
	void SignMouse(CAim* pAim);
	void SignOver(int nIdx);

	void Judge();			// 判定用の書いたあと
	void SignCheck();		// なぞれてるかチェック
	void Misstake();		// 失敗
	void Success();			// 成功

	void Load(char* pTecPath);

	// 変数宣言
	SCheckInfo m_info;
	SPen m_aPen[MAX_SIGN];

	int m_nNum;			// 判定に触れた総数
	int m_nNumJudge;	// 筆の判定の総数(ID設定用)
	int m_nMissCount;	// 失敗数(印判定に触れてない数)

	SIGNTYPE m_type;	// 印の種類

	bool m_bUse;

	// ファイルから読み込んだ情報
	SLoadInfo m_aInfo[MAX_SIGN];
	int m_nNumSign;
};