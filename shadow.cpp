#include "main.h"
#include "shadow.h"
#define NUM_Shadow (1)

typedef struct
{
	D3DXVECTOR3 g_posShadow;	//位置
	D3DXVECTOR3 g_rotShadow;	//向き
	D3DXMATRIX g_mtxWorldShadow;	//ワールドマトリックス
	bool g_bUse_shadow;
}Shadow;

Shadow g_Shadow[NUM_Shadow];
//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffShadow = NULL;
LPDIRECT3DTEXTURE9 g_pTextureShadow = NULL;



//初期化処理
void InitShadow(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		g_Shadow[nCnt].g_bUse_shadow = false;

		//テクスチャ読み込み
		D3DXCreateTextureFromFile(pDevice, "data\\texture\\shadow000.jpg", &g_pTextureShadow);

		//各種変数の初期化
		g_Shadow[nCnt].g_posShadow = D3DXVECTOR3(0.0f, 0.1f, 0.0f);
		g_Shadow[nCnt].g_rotShadow = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	}
	
	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_Shadow, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffShadow, NULL);


	VERTEX_3D* pVtx; //頂点座標へのポインタ

	//頂点バッファをロックし、頂点座標へのポインタを取得
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-30.0f, 0.1f,30.0f);
		pVtx[1].pos = D3DXVECTOR3(30.0f, 0.1f, 30.0f);
		pVtx[2].pos = D3DXVECTOR3(-30.0f, 0.1f, -30.0f);
		pVtx[3].pos = D3DXVECTOR3(30.0f, 0.1f, -30.0f);

		//法線ベクトルの設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		pVtx[0].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
		pVtx[1].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
		pVtx[2].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
		pVtx[3].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);

		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}
	
	//頂点バッファをアンロック
	g_pVtxBuffShadow->Unlock();
}

//終了処理
void UninitShadow(void)
{
	/*for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{

	}*/
	//テクスチャの破棄
	if (g_pTextureShadow != NULL)
	{
		g_pTextureShadow->Release();
		g_pTextureShadow = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffShadow != NULL)
	{
		g_pVtxBuffShadow->Release();
		g_pVtxBuffShadow = NULL;
	}
}

//更新処理
void UpdateShadow(void)
{

}

//描画処理
void DrawShadow(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//計算用マトリックス

	//減算合成の設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		if (g_Shadow[nCnt].g_bUse_shadow == false)
		{
			continue;
		}

		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_Shadow[nCnt].g_mtxWorldShadow);

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Shadow[nCnt].g_rotShadow.y, g_Shadow[nCnt].g_rotShadow.x, g_Shadow[nCnt].g_rotShadow.z);

		D3DXMatrixMultiply(&g_Shadow[nCnt].g_mtxWorldShadow, &g_Shadow[nCnt].g_mtxWorldShadow, &mtxRot);

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_Shadow[nCnt].g_posShadow.x, g_Shadow[nCnt].g_posShadow.y, g_Shadow[nCnt].g_posShadow.z);

		D3DXMatrixMultiply(&g_Shadow[nCnt].g_mtxWorldShadow, &g_Shadow[nCnt].g_mtxWorldShadow, &mtxTrans);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_Shadow[nCnt].g_mtxWorldShadow);

		//頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffShadow, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);

		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureShadow);
		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);
	}

	//通常の合成に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

int SetShadow(void)
{
	int nCntShadow = -1;

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		if (g_Shadow[nCnt].g_bUse_shadow == false)
		{
			nCntShadow = nCnt;
			g_Shadow[nCnt].g_bUse_shadow = true;
			break;
		}
	}
	return nCntShadow;
}

//位置設定処理
void SetPositionShadow(int nldxShadow, D3DXVECTOR3 pos)
{
	if (nldxShadow == -1)
	{
		return;
	}

	g_Shadow[nldxShadow].g_posShadow.x = pos.x;
	g_Shadow[nldxShadow].g_posShadow.z = pos.z;
}
