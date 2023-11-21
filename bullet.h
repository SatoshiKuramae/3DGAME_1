//========================
//
//
//
//
//========================
#include "main.h"

typedef struct
{
	D3DXVECTOR3 g_posBullet;//�ʒu
	D3DXMATRIX g_mtxWorldBullet;//���[���h�}�g���b�N�X
	D3DXVECTOR3 rotBullet;//�p�x
	D3DXVECTOR3 moveBullet;	//�ړ���
	bool bUse;//�g���邩�ǂ���
	int nLife;//���C�t
}Bullet;
//�v���g�^�C�v�錾
void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, int nLife);