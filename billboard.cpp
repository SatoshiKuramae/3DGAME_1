#include "main.h"
#include "Billboard.h"
#include "shadow.h"
#define NUM_Billboard (1)
//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBillboard = NULL;		//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureBillboard = NULL;
Billboard g_Billboard[NUM_Billboard];
//初期化処理
void InitBillboard(void)
{
	int nCount=0;

	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\coin.png", &g_pTextureBillboard);

	for (nCount = 0; nCount < NUM_Billboard; nCount++)
	{
		g_Billboard[nCount].g_posBillboard = D3DXVECTOR3(0.0f, 50.0f, 0.0f);
		g_Billboard[nCount].rotBillboard = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Billboard[nCount].g_nldxShadow_BILL = SetShadow();
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_Billboard, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffBillboard, NULL);


	VERTEX_3D* pVtx; //頂点座標へのポインタ

	//頂点バッファをロックし、頂点座標へのポインタを取得
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x - 10.0f, g_Billboard[nCnt].g_posBillboard.y + 10.0f, g_Billboard[nCnt].g_posBillboard.z);
		pVtx[1].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x + 10.0f, g_Billboard[nCnt].g_posBillboard.y + 10.0f, g_Billboard[nCnt].g_posBillboard.z);
		pVtx[2].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x - 10.0f, g_Billboard[nCnt].g_posBillboard.y - 10.0f, g_Billboard[nCnt].g_posBillboard.z);
		pVtx[3].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x + 10.0f, g_Billboard[nCnt].g_posBillboard.y - 10.0f, g_Billboard[nCnt].g_posBillboard.z);

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

		pVtx += 4;
	}
	
	//頂点バッファをアンロック
	g_pVtxBuffBillboard->Unlock();
}

//終了処理
void UninitBillboard(void)
{
	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//テクスチャの破棄
		if (g_pTextureBillboard != NULL)
		{
			g_pTextureBillboard->Release();
			g_pTextureBillboard = NULL;
		}
	}
	//頂点バッファの破棄
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}
}

//更新処理
void UpdateBillboard(void)
{
	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//影の位置を設定
		SetPositionShadow(g_Billboard[nCnt].g_nldxShadow_BILL, g_Billboard[nCnt].g_posBillboard);
	}
}

//描画処理
void DrawBillboard(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//計算用マトリックス
	D3DXMATRIX mtxView;



	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_Billboard[nCnt].g_mtxWorldBillboard);
	
		//ビューマトリックスを取得
		pDevice->GetTransform(D3DTS_VIEW, &mtxView);

		//ポリゴンをカメラに対し正面に向ける
		D3DXMatrixInverse(&g_Billboard[nCnt].g_mtxWorldBillboard, NULL, &mtxView);

		//逆行列を求める
		D3DXMatrixInverse(&g_Billboard[nCnt].g_mtxWorldBillboard, NULL, &mtxView);

		g_Billboard[nCnt].g_mtxWorldBillboard._41 = 0.0f;
		g_Billboard[nCnt].g_mtxWorldBillboard._42 = 0.0f;
		g_Billboard[nCnt].g_mtxWorldBillboard._43 = 0.0f;

		
		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_Billboard[nCnt].g_posBillboard.x, g_Billboard[nCnt].g_posBillboard.y, g_Billboard[nCnt].g_posBillboard.z);

		D3DXMatrixMultiply(&g_Billboard[nCnt].g_mtxWorldBillboard, &g_Billboard[nCnt].g_mtxWorldBillboard, &mtxTrans);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_Billboard[nCnt].g_mtxWorldBillboard);

		//頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);

		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureBillboard);

		//ビルボードの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}