#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "main.h"
#define NUM_MODEL (15)

;
//モデルの構造体
typedef struct
{
	LPD3DXMESH pMesh;
	LPD3DXBUFFER pBuffMat;
	DWORD nNumMat;
	D3DXMATRIX ModelmtxWorld;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nIdxModelParent;	//親モデルのインデックス
}ModelParts;


typedef struct
{
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3	g_oldposplayer;				//過去の位置
	D3DXVECTOR3 g_posplayer;				//位置
	D3DXVECTOR3	g_rotplayer;				//向き
	D3DXVECTOR3 g_moveplayer;				//移動量
	D3DXVECTOR3 DestRot;					//目的の角度
	D3DXVECTOR3 DiffRot;					// 目的の角度を現在の角度との差
	D3DXVECTOR3 MoveRot;					//回転量
	ModelParts aModel[NUM_MODEL];			//モデルのパーツ数
}Player;

typedef struct
{
	int LOOP;	//ループするかの判定
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


//プロトタイプ宣言
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void rot_offset(float* rot);
void LoadPlayer(void);
D3DXVECTOR3 GetPlayerrot(void);
Player* GetPlayer(void);

#endif