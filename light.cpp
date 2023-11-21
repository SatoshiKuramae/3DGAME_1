//======================
//
//
//
//======================
#include "main.h"
#include "light.h"
#include "input.h"
#define NUM_LIGHT	(3)

//グローバル変数
D3DLIGHT9 g_light[NUM_LIGHT];	//ライトの情報

//初期化処理
void InitLight(void)
{
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXVECTOR3	vecDir;		//設定用方向ベクトル
	float Lightangle=0.0f;
	for (int nCnt = 0; nCnt < NUM_LIGHT; nCnt++)
	{
		//ライト情報をクリアする
		ZeroMemory(&g_light[nCnt], sizeof(D3DLIGHT9));

		//ライトの種類を設定
		g_light[nCnt].Type = D3DLIGHT_DIRECTIONAL;

		//ライトの拡散光を設定
		g_light[nCnt].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		if (nCnt == 0)
		{
			//ライトの方向を設定
			vecDir = D3DXVECTOR3(0.0f, -0.8f, 0.4f);
		}
		if (nCnt == 1)
		{//ライトの方向を設定
			vecDir = D3DXVECTOR3(-0.8f, -0.5f, -0.8f);
		}
		if (nCnt == 2)
		{
			//ライトの方向を設定
			vecDir = D3DXVECTOR3(-0.8f, -0.5f, -0.4f);
		}


		D3DXVec3Normalize(&vecDir, &vecDir);	//ベクトルを正規化
		g_light[nCnt].Direction = vecDir;

		//ライトを設定
		pDevice->SetLight(0, &g_light[nCnt]);

		//ライトを有効にする
		pDevice->LightEnable(nCnt, TRUE);
	}
}

//終了処理
void UninitLight(void)
{

}

//更新処理
void UpdateLight(void)
{

}