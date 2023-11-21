//====================
//
//
//
//====================

#include "main.h"

//�J�����̍\����
typedef struct
{
	D3DXVECTOR3 posV;	//���_
	D3DXVECTOR3 posR;	//�����_
	D3DXVECTOR3 vecU;	//������x�N�g��
	D3DXVECTOR3 TargetPosV;		//�ړI�̎��_
	D3DXVECTOR3 TargetPosR;		//�ړI�̒����_
	D3DXMATRIX mtxProjection;	//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX mtxView;	//�r���[�}�g���b�N�X
	D3DXVECTOR3 rot;	//����
	bool flattery;		//�J�����̒Ǐ]
}Camera;

//�v���g�^�C�v�錾
void InitCamera(void);
void UninitCamera(void);
void UpdateCamera(void);
void SetCamera(void);
void SetPosCamera(D3DXVECTOR3 Camerapos(D3DXVECTOR3 posR, D3DXVECTOR3 posV));
Camera* GetCamera(void);
