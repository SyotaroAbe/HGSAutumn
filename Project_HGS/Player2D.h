//============================================
//
//	�v���C���[2D�̃T���v�� [Player2D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _PLAYER2D_H_
#define _PLAYER2D_H_

#include "main.h"
#include "object2D.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CPlayer2D : public CObject2D
{
public:

	CPlayer2D(int nPriority = 6);
	~CPlayer2D();

	static CPlayer2D* Create(int nPriority = 6);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�擾�����E�ݒ菈��
	int GetSample(void) { return m_nSample; }
	void SetSample(int Sample) { m_nSample = Sample; }
	D3DXVECTOR3 GetMove(void) { return m_Move; }
	void SetMove(D3DXVECTOR3 move) { m_Move = move; }
	D3DXVECTOR3 GetPosOld(void) { return m_PosOld; }
	bool GetLanding(void) { return m_bLanding; }
	void SetLanding(bool bLanding) { m_bLanding = bLanding; }
	void Death();
private:
	void Move(D3DXVECTOR3* pos);
	void Jump();
	int m_nSample;							//�T���v���ϐ�
	D3DXVECTOR3 m_Move;						//�ړ����x
	D3DXVECTOR3 m_PosOld;						//�ړ����x
	bool m_bLanding;						//�ڒn���
};
#endif