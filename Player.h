#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "main.h"
#define NUM_MODEL (15)

;
//���f���̍\����
typedef struct
{
	LPD3DXMESH pMesh;
	LPD3DXBUFFER pBuffMat;
	DWORD nNumMat;
	D3DXMATRIX ModelmtxWorld;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nIdxModelParent;	//�e���f���̃C���f�b�N�X
}ModelParts;


typedef struct
{
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3	g_oldposplayer;				//�ߋ��̈ʒu
	D3DXVECTOR3 g_posplayer;				//�ʒu
	D3DXVECTOR3	g_rotplayer;				//����
	D3DXVECTOR3 g_moveplayer;				//�ړ���
	D3DXVECTOR3 DestRot;					//�ړI�̊p�x
	D3DXVECTOR3 DiffRot;					// �ړI�̊p�x�����݂̊p�x�Ƃ̍�
	D3DXVECTOR3 MoveRot;					//��]��
	ModelParts aModel[NUM_MODEL];			//���f���̃p�[�c��
}Player;

typedef struct
{
	int LOOP;	//���[�v���邩�̔���
	int NUMKEY;
	int KeySet;
}MotionSet;

typedef struct
{
	int FRAME;
	int Key;
}KeySet;

typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
}Key;


//�v���g�^�C�v�錾
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void rot_offset(float* rot);
void LoadPlayer(void);
D3DXVECTOR3 GetPlayerrot(void);
Player* GetPlayer(void);

#endif