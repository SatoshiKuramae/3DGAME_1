//====================
//
//
//
//====================

#include "main.h"

//カメラの構造体
typedef struct
{
	D3DXVECTOR3 posV;	//視点
	D3DXVECTOR3 posR;	//注視点
	D3DXVECTOR3 vecU;	//上方向ベクトル
	D3DXVECTOR3 TargetPosV;		//目的の視点
	D3DXVECTOR3 TargetPosR;		//目的の注視点
	D3DXMATRIX mtxProjection;	//プロジェクションマトリックス
	D3DXMATRIX mtxView;	//ビューマトリックス
	D3DXVECTOR3 rot;	//向き
	bool flattery;		//カメラの追従
}Camera;

//プロトタイプ宣言
void InitCamera(void);
void UninitCamera(void);
void UpdateCamera(void);
void SetCamera(void);
void SetPosCamera(D3DXVECTOR3 Camerapos(D3DXVECTOR3 posR, D3DXVECTOR3 posV));
Camera* GetCamera(void);
