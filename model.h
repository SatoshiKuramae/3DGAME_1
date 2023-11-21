#ifndef _MODEL_H_
#define _MODEL_H_
#include "main.h"


typedef struct
{
	D3DXVECTOR3 g_posModel;					//�ʒu
	D3DXVECTOR3	g_rotModel;					//����
	D3DXVECTOR3 g_moveModel;				//�ړ���
	D3DXVECTOR3 DestRot;					//�ړI�̊p�x
	D3DXVECTOR3 DiffRot;					// �ړI�̊p�x�����݂̊p�x�Ƃ̍�
	D3DXVECTOR3 MoveRot;					//��]��
}MODEL;


//�v���g�^�C�v�錾
void InitModel(void);
void UninitModel(void);
void UpdateModel(void);
void DrawModel(void);
void rot_offset(float* rot);
D3DXVECTOR3 GetModelrot(void);
MODEL* GetModel(void);

#endif