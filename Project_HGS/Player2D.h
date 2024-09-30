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

private:
	void Move(D3DXVECTOR3* pos);

	int m_nSample;							//�T���v���ϐ�
	bool m_bRight;							//�E�������Ă��邩�ǂ���
};
#endif