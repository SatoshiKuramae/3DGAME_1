//========================
//
//
//
//========================

#include "camera.h"
#include "main.h"
#include "Player.h"
#include "input.h"

#define CAMERASPEED (1.0f)
#define CAMERAPOS_V_X (0.0f)
#define CAMERAPOS_V_Y (400.0f)
#define CAMERAPOS_V_Z (1200.0f) 
//グローバル変数
Camera	g_camera;	//カメラの情報


float posR;
float posV;
//カメラの視点座標
float g_PosV_y;
float g_PosV_z;
//カメラの注視点座標


//初期化処理
void InitCamera(void)
{
	g_camera.flattery = false;

	g_PosV_y = CAMERAPOS_V_Y;
	g_PosV_z = CAMERAPOS_V_Z;

	g_camera.posV = D3DXVECTOR3(0.0f, 200.0f, -600.0f);
	g_camera.posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_camera.vecU = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
}

//終了処理
void UninitCamera(void)
{

}

//更新処理
void UpdateCamera(void)
{
	Player* pPlayer = GetPlayer();
	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		if (g_camera.flattery == false)
		{
			g_camera.flattery = true;
		}
		else
		{
			g_camera.flattery = false;
		}
	}

	//posR=注視点posV=視点vecU=視点のベクトル

	//視点の移動
	if (GetKeyboardpress(DIK_C) == true)
	{
		g_camera.rot.y += 0.1f;

		g_camera.posV.x = sinf(g_camera.rot.y + D3DX_PI) * sqrtf(g_PosV_z * g_PosV_z + g_PosV_y * g_PosV_y) / 2 + g_camera.posR.x;
		g_camera.posV.z = cosf(g_camera.rot.y + D3DX_PI) * sqrtf(g_PosV_z * g_PosV_z + g_PosV_y * g_PosV_y) / 2 + g_camera.posR.z;
	}
	if (GetKeyboardpress(DIK_Z) == true)
	{
		g_camera.rot.y -= 0.1f;

		g_camera.posV.x = sinf(g_camera.rot.y + D3DX_PI) * sqrtf(g_PosV_z * g_PosV_z + g_PosV_y * g_PosV_y) / 2 + g_camera.posR.x;
		g_camera.posV.z = cosf(g_camera.rot.y + D3DX_PI) * sqrtf(g_PosV_z * g_PosV_z + g_PosV_y * g_PosV_y) / 2 + g_camera.posR.z;
	}
	if (GetKeyboardpress(DIK_Y) == true)
	{
		g_camera.rot.x += 0.1f;
		g_camera.posV.y += 1.0f;
	}
	if (GetKeyboardpress(DIK_N) == true)
	{
		g_camera.rot.x -= 0.1f;
		g_camera.posV.y -= 1.0f;
	}

	//回転の補正
	if (g_camera.rot.y > D3DX_PI)
	{
		g_camera.rot.y = -D3DX_PI;
	}
	else if (g_camera.rot.y < -D3DX_PI)
	{
		g_camera.rot.y = D3DX_PI;
	}

	//注視点までの距離を変える
	if (GetKeyboardpress(DIK_Q) == true)
	{
		g_camera.posV.z += 1.0f;
		g_PosV_z += 1.0f;
		g_PosV_y -= 1.0f;
	}

	if (GetKeyboardpress(DIK_E) == true)
	{
		g_camera.posV.z -= 1.0f;
		g_PosV_z -= 1.0f;
	}

	//視点の位置移動（前後左右）
	if (GetKeyboardpress(DIK_UP) == true)
	{
		g_camera.posV.z += CAMERASPEED;
		g_camera.posR.z += CAMERASPEED;
	}

	if (GetKeyboardpress(DIK_DOWN) == true)
	{
		g_camera.posV.z -= CAMERASPEED;
		g_camera.posR.z -= CAMERASPEED;
	}

	if (GetKeyboardpress(DIK_RIGHT) == true)
	{
		g_camera.posV.x += CAMERASPEED;
		g_camera.posR.x += CAMERASPEED;
	}
	if (GetKeyboardpress(DIK_LEFT) == true)
	{
		g_camera.posV.x -= CAMERASPEED;
		g_camera.posR.x -= CAMERASPEED;
	}
	
	if (g_camera.flattery == true)
	{
		g_camera.posR = pPlayer->g_posplayer;
		g_camera.posV.x = sinf(g_camera.rot.y + D3DX_PI) * sqrtf(g_PosV_z * g_PosV_z + g_PosV_y * g_PosV_y) / 2 + pPlayer->g_posplayer.x;
		g_camera.posV.z = cosf(g_camera.rot.y + D3DX_PI) * sqrtf(g_PosV_z * g_PosV_z + g_PosV_y * g_PosV_y) / 2 + pPlayer->g_posplayer.z;
	}
}

//設定処理
void SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&g_camera.mtxProjection);

	//プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&g_camera.mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 3000.0f);

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &g_camera.mtxProjection);

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&g_camera.mtxView);

	//ビューマトリックスの作成
	D3DXMatrixLookAtLH(&g_camera.mtxView, &g_camera.posV, &g_camera.posR, &g_camera.vecU);

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &g_camera.mtxView);
}

Camera* GetCamera(void)
{
	return &g_camera;
}