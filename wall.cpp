#include "main.h"
#include "polygon.h"
#include "wall.h"
#define NUM_POLYGON (4)
//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffWall = NULL;
LPDIRECT3DTEXTURE9 g_pTextureWall = NULL;

D3DXVECTOR3 g_posWall;	//位置
D3DXVECTOR3 g_rotWall;	//向き
D3DXMATRIX g_mtxWorldWall;	//ワールドマトリックス


//初期化処理
void InitWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\wall.png", &g_pTextureWall);

	//各種変数の初期化
	g_posWall = D3DXVECTOR3(0.0f, 0.0f, 200.0f);
	g_rotWall = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_POLYGON, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffWall, NULL);


	VERTEX_3D* pVtx; //頂点座標へのポインタ

	//頂点バッファをロックし、頂点座標へのポインタを取得
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos.x = g_posWall.x - 400.0f;
	pVtx[0].pos.y = g_posWall.y + 400.0f;
	pVtx[0].pos.z = g_posWall.z;
	pVtx[1].pos.x = g_posWall.x + 400.0f;
	pVtx[1].pos.y = g_posWall.y + 400.0f;
	pVtx[1].pos.z = g_posWall.z;
	pVtx[2].pos.x = g_posWall.x - 400.0f;
	pVtx[2].pos.z = g_posWall.z;
	pVtx[3].pos.x = g_posWall.x + 400.0f;
	pVtx[3].pos.z = g_posWall.z;


	//法線ベクトルの設定
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, -1.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, -1.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, -1.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, -1.0f);

	pVtx[0].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
	pVtx[1].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
	pVtx[2].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
	pVtx[3].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);


	//頂点バッファをアンロック
	g_pVtxBuffWall->Unlock();
}

//終了処理
void UninitWall(void)
{
	//テクスチャの破棄
	if (g_pTextureWall != NULL)
	{
		g_pTextureWall->Release();
		g_pTextureWall = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}
}

//更新処理
void UpdateWall(void)
{

}

//描画処理
void DrawWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//計算用マトリックス


	for (int nCnt = 0; nCnt < NUM_POLYGON; nCnt++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_mtxWorldWall);
		if (nCnt == 0)
		{
			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x, g_posWall.y, g_posWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}
		if (nCnt == 1)
		{
			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y+1.57f, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x+200.0f, g_posWall.y, g_posWall.z-200.0f);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}
		if (nCnt == 2)
		{
			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y - 1.57f, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x - 200.0f, g_posWall.y, g_posWall.z - 200.0f);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}
		if (nCnt == 3)
		{
			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y - 3.14f, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x, g_posWall.y, g_posWall.z - 400.0f);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldWall);

		//頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffWall, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);

		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureWall);
		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}