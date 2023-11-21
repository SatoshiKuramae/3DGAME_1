#ifndef _MODEL_H_
#define _MODEL_H_
#include "main.h"


typedef struct
{
	D3DXVECTOR3 g_posModel;					//位置
	D3DXVECTOR3	g_rotModel;					//向き
	D3DXVECTOR3 g_moveModel;				//移動量
	D3DXVECTOR3 DestRot;					//目的の角度
	D3DXVECTOR3 DiffRot;					// 目的の角度を現在の角度との差
	D3DXVECTOR3 MoveRot;					//回転量
}MODEL;


//プロトタイプ宣言
void InitModel(void);
void UninitModel(void);
void UpdateModel(void);
void DrawModel(void);
void rot_offset(float* rot);
D3DXVECTOR3 GetModelrot(void);
MODEL* GetModel(void);

#endif