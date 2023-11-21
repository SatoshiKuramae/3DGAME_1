//========================
//
//
//
//
//========================
#include "main.h"

typedef struct
{
	D3DXVECTOR3 g_posBullet;//位置
	D3DXMATRIX g_mtxWorldBullet;//ワールドマトリックス
	D3DXVECTOR3 rotBullet;//角度
	D3DXVECTOR3 moveBullet;	//移動量
	bool bUse;//使われるかどうか
	int nLife;//ライフ
}Bullet;
//プロトタイプ宣言
void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, int nLife);