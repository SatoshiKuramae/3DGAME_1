#include "main.h"
#include "meshfield.h"
#define NUM_MESH (9)
//メッシュフィールドのテクスチャ
LPDIRECT3DTEXTURE9 g_pTextureMeshField = NULL;
//頂点バッファへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffMeshField = NULL;
//インデックスバッファへのポインタ
LPDIRECT3DINDEXBUFFER9 g_pIdxBuffMeshField = NULL;
//メッシュフィールドの位置
D3DXVECTOR3 g_posMeshField;
//メッシュフィールドの向き
D3DXVECTOR3 g_rotMeshField;
//メッシュフィールドのワールドマトリックス
D3DXMATRIX g_mtxWorldMeshField;

//初期化処理
void Initmeshfield(void)
{

	g_posMeshField = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_rotMeshField = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) *  NUM_MESH, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffMeshField, NULL);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\field.png", &g_pTextureMeshField);
	//インデックスバッファの生成
	pDevice->CreateIndexBuffer(sizeof(WORD) * 14,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIdxBuffMeshField,
		NULL);
	
	//頂点情報の設定


	VERTEX_3D* pVtx; //頂点座標へのポインタ

	//頂点バッファをロックし、頂点座標へのポインタを取得
	g_pVtxBuffMeshField->Lock(0, 0, (void**)&pVtx, 0);

	//インデックスバッファをロック
	WORD* pldx;
	g_pIdxBuffMeshField->Lock(0, 0, (void**)&pldx, 0);
	

	//頂点情報の設定
	pVtx[0].pos = (D3DXVECTOR3(-50.0f, 10.0f, 50.0f));
	pVtx[1].pos = (D3DXVECTOR3(0.0f, 10.0f, 50.0f));
	pVtx[2].pos = (D3DXVECTOR3(50.0f, 10.0f, 50.0f));
	pVtx[3].pos = (D3DXVECTOR3(-50.0f, 10.0f, 0.0f));
	pVtx[4].pos = (D3DXVECTOR3(0.0f, 100.0f, 0.0f));
	pVtx[5].pos = (D3DXVECTOR3(50.0f, 10.0f, 0.0f));
	pVtx[6].pos = (D3DXVECTOR3(-50.0f, 10.0f, -50.0f));
	pVtx[7].pos = (D3DXVECTOR3(0.0f, 10.0f, -50.0f));
	pVtx[8].pos = (D3DXVECTOR3(50.0f, 10.0f, -50.0f));

	pVtx[0].tex = (D3DXVECTOR2(0.0f, 0.0f));
	pVtx[1].tex = (D3DXVECTOR2(0.5f, 0.0f));
	pVtx[2].tex = (D3DXVECTOR2(1.0f, 0.0f));
	pVtx[3].tex = (D3DXVECTOR2(0.0f, 0.5f));
	pVtx[4].tex = (D3DXVECTOR2(0.5f, 0.5f));
	pVtx[5].tex = (D3DXVECTOR2(1.0f, 0.5f));
	pVtx[6].tex = (D3DXVECTOR2(0.0f, 1.0f));
	pVtx[7].tex = (D3DXVECTOR2(0.5f, 1.0f));
	pVtx[8].tex = (D3DXVECTOR2(1.0f, 0.0f));

	//法線ベクトルの設定
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[4].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[5].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[6].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[7].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);
	pVtx[8].nor = D3DXVECTOR3(0.0f, 1.0f, 1.0f);

	for (int nCnt = 0; nCnt < NUM_MESH; nCnt++)
	{
		pVtx[nCnt].col = D3DCOLOR_RGBA(RED, GREEN, BLUE, A);
	}

	//インデックスの設定
	pldx[0] = 3;
	pldx[1] = 0;
	pldx[2] = 4;
	pldx[3] = 1;
	pldx[4] = 5;
	pldx[5] = 2;
	pldx[6] = 2;
	pldx[7] = 6;
	pldx[8] = 6;
	pldx[9] = 3;
	pldx[10] = 7;
	pldx[11] = 4;
	pldx[12] = 8;
	pldx[13] = 5;

	g_pIdxBuffMeshField->Unlock();

	//頂点バッファをアンロック
	g_pVtxBuffMeshField->Unlock();
}

//終了処理
void Uninitmeshfield(void)
{
	//テクスチャの破棄
	if (g_pTextureMeshField != NULL)
	{
		g_pTextureMeshField->Release();
		g_pTextureMeshField = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffMeshField != NULL)
	{
		g_pVtxBuffMeshField->Release();
		g_pVtxBuffMeshField = NULL;
	}

	//インデックスバッファの解放
	if (g_pIdxBuffMeshField != NULL)
	{
		g_pIdxBuffMeshField->Release();
		g_pIdxBuffMeshField = NULL;
	}
}

//更新処理
void Updatemeshfield(void)
{

}

//描画処理
void Drawmeshfield(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//計算用マトリックス

		//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldMeshField);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotMeshField.y, g_rotMeshField.x, g_rotMeshField.z);

	D3DXMatrixMultiply(&g_mtxWorldMeshField, &g_mtxWorldMeshField, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_posMeshField.x, g_posMeshField.y, g_posMeshField.z);

	D3DXMatrixMultiply(&g_mtxWorldMeshField, &g_mtxWorldMeshField, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldMeshField);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffMeshField, 0, sizeof(VERTEX_3D));

	//インデックスバッファをデータストリームに設定
	pDevice->SetIndices(g_pIdxBuffMeshField);

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureMeshField);

	//ポリゴンの描画
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, 9, 0, 12);

}