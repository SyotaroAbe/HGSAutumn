//============================================
//
//	ミニマップカメラの処理 [MiniMapCamera.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _MINIMAPCAMERA_H_
#define _MINIMAPCAMERA_H_

#include "main.h"

//カメラクラス
class CMiniMapCamera
{
public:
	CMiniMapCamera();
	~CMiniMapCamera();

	//カメラのモード
	enum CAMERAMODE
	{
		CAMERAMODE_CONTROL = 0,	//操作
		CAMERAMODE_DOWNVIEW,	//見下ろし
		CAMERAMODE_MAX,
	};

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void SetCamera(void);
	void SetCameraPos(D3DXVECTOR3 Pos) { m_posV = Pos; m_posR = Pos; }
	D3DXVECTOR3 GetCameraPos(void) { return m_posR; }
	void SetCameraPosY(float PosY) { m_EventPosY = PosY; }
	void ResetCamera(void);
	void SetBib(bool Set) { m_bBib = Set; }
	float GetPosY(void) { return m_posR.y; }
	void SetRot(D3DXVECTOR3 Rot) { m_rot = Rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	CAMERAMODE GetCameraMode(void) { return CameraMode; }
	void SetFollowTime(int Time) { m_FollowTime = Time; }
	D3DXVECTOR3 GetPosV(void) { return m_posV; }
	D3DXVECTOR3 GetPosR(void) { return m_posR; }
	D3DXVECTOR3 GetVecU(void) { return m_vecU; }
	void SetAttention(bool Set) { m_bAttention = Set; }
	bool GetAttention(void) { return m_bAttention; }
	D3DXMATRIX GetViewMatrix() { return m_mtxView; }
	D3DXMATRIX GetProjectionMatrix() { return m_mtxProjection; }
	void SetHomingSpeed(float Speed) { m_fHomingSpeed = Speed; }

private:
	void ControlCamera(void);
	void DownviewCamera(void);

	D3DXMATRIX m_mtxView;		//ビューマトリックス
	D3DXMATRIX m_mtxProjection;	//プロジェクションマトリックス
	D3DVIEWPORT9 m_viewport;	//ビューポート
	D3DXVECTOR3 m_move;			//移動量
	D3DXVECTOR3 m_posV;			//視点
	D3DXVECTOR3 m_posR;			//注視点
	D3DXVECTOR3 m_vecU;			//上方向ベクトル
	D3DXVECTOR3 m_rot;			//現在の向き
	D3DXVECTOR3 m_rotOld;		//過去の向き
	D3DXVECTOR3 m_posVDest;		//目的の視点
	D3DXVECTOR3 m_posRDest;		//目的の注視点
	D3DXVECTOR3 m_PlayerPos;	//プレイヤーの位置
	D3DXVECTOR3 m_DelCameraPos;	//リスポーンカメラ位置
	CAMERAMODE CameraMode;		//カメラの状態
	D3DXVECTOR3 m_fRotMove;		//向きのカメラ移動速度
	float m_CameraDistance;		//注視点とカメラの距離
	float m_EventPosY;			//イベント時のカメラの高さ
	float m_fHomingSpeed;		//カメラ移動のホーミング速度
	bool m_bFollowY;			//カメラの上下追従をするかどうか
	bool m_bBib;				//カメラが振動するかどうか
	float m_fBibPowor;			//カメラ振動の強さ
	int m_FollowTime;			//回り込み時間
	int m_FollowDistance;		//追従時のカメラ距離
	bool m_bAttention;			//注目状態
};

#endif