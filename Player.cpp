#include <stdio.h>
#include <string.h>
#include "main.h"
#include "Player.h"
#include "input.h"
#include "shadow.h"
#include "camera.h"
#include "bullet.h"


#define TEST_player	(0)
#define DEFROT_MOD (0.3f)
#define MOVEROT_MOD	(0.1f)
#define player_SPEED (2.0f)
#define PARTS_FILE	"data\\motion(2).txt"

static const char* ModelFile[NUM_MODEL] =
{
	"data\\MODEL\\body.x",
	"data\\MODEL\\hip.x",
	"data\\MODEL\\head.x",
	"data\\MODEL\\L_arm1.x",
	"data\\MODEL\\L_arm2.x",
	"data\\MODEL\\L_hand.x",
	"data\\MODEL\\R_arm1.x",
	"data\\MODEL\\R_arm2.x",
	"data\\MODEL\\R_hand.x",
	"data\\MODEL\\R_leg1.x",
	"data\\MODEL\\R_leg2.x",
	"data\\MODEL\\R_foot.x",
	"data\\MODEL\\L_leg1.x",
	"data\\MODEL\\L_leg2.x",
	"data\\MODEL\\L_foot.x",
};
//
//int OYAindex[NUM_MODEL]
//{
//	-1,
//	0,
//	0,
//	0,
//	3,
//	4,
//	0,
//	6,
//	7,
//	1,
//	9,
//	10,
//	1,
//	12,
//	13,
//};
//
//D3DXVECTOR3 modelpos[NUM_MODEL]
//{
//	D3DXVECTOR3(0.0f,0.0f,0.0f),
//	D3DXVECTOR3(0.0f,0.0f,0.0f),
//	D3DXVECTOR3(0.0f,18.0f,-23.0f),
//	D3DXVECTOR3(30.0f,25.0f,0.0f),
//	D3DXVECTOR3(38.0f,0.0f,0.0f),
//	D3DXVECTOR3(37.0f,0.0f,0.0f),
//	D3DXVECTOR3(-30.0f,25.0f,0.0f),
//	D3DXVECTOR3(-38.0f,0.0f,0.0f),
//	D3DXVECTOR3(-37.0f,0.0f,0.0f),
//	D3DXVECTOR3(-13.0f,-22.0f,0.0f),
//	D3DXVECTOR3(0.0f,-28.0f,0.0f),
//	D3DXVECTOR3(0.0f,-35.0f,0.0f),
//	D3DXVECTOR3(13.0f,-22.0f,0.0f),
//	D3DXVECTOR3(0.0f,-28.0f,0.0f),
//	D3DXVECTOR3(0.5f,-35.0f,0.0f)
//};

//グローバル変数
int g_nldxShadow = -1;
Player g_player;

bool g_rolling;


//初期化処理
void InitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//各種変数の初期化
	//g_dwNumMatplayer = 0;
	g_player.g_oldposplayer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.g_posplayer = D3DXVECTOR3(0.0f, 100.0f, 0.0f);
	g_player.g_rotplayer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.g_moveplayer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_rolling = false;
	g_nldxShadow = SetShadow();

	LoadPlayer();

	/*for (int nCnt = 0; nCnt < NUM_MODEL; nCnt++)
	{
		g_player.aModel[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_player.aModel[nCnt].nIdxModelParent = OYAindex[nCnt];
		g_player.aModel[nCnt].pos = modelpos[nCnt];
	}*/

	for (int nCnt = 0; nCnt < NUM_MODEL; nCnt++)
	{
		//Xファイルの読み込み
		D3DXLoadMeshFromX(ModelFile[nCnt],
			D3DXMESH_SYSTEMMEM, pDevice,
			NULL,
			&g_player.aModel[nCnt].pBuffMat,
			NULL,
			&g_player.aModel[nCnt].nNumMat,
			&g_player.aModel[nCnt].pMesh);
	}

}

//終了処理
void UninitPlayer(void)
{
	for (int nCnt = 0; nCnt < NUM_MODEL; nCnt++)
	{
		//メッシュの破棄
		if (g_player.aModel[nCnt].pMesh != NULL)
		{
			g_player.aModel[nCnt].pMesh->Release();
			g_player.aModel[nCnt].pMesh = NULL;
		}

		//マテリアルの破棄
		if (g_player.aModel[nCnt].pBuffMat != NULL)
		{
			g_player.aModel[nCnt].pBuffMat->Release();
			g_player.aModel[nCnt].pBuffMat = NULL;
		}
	}
}

//更新処理
void UpdatePlayer(void)
{
	int nCnt = 0;
	Camera* pCamera = GetCamera();
	//影の位置を設定
	SetPositionShadow(g_nldxShadow, g_player.g_posplayer);

#if TEST_player

	if (GetKeyboardpress(DIK_SPACE) == true)
	{
		SetBullet(g_player.g_posplayer, D3DXVECTOR3(sinf(g_player.g_rotplayer.y + D3DX_PI), 0.0f, cosf(g_player.g_rotplayer.y - +D3DX_PI)), g_player.g_rotplayer, 5);
	}

	if (GetKeyboardpress(DIK_W) == true)
	{
		g_player.g_rotplayer.y = pCamera->rot.y + D3DX_PI;

		g_player.g_moveplayer.x -= sinf(pCamera->rot.y + D3DX_PI) * player_SPEED;
		g_player.g_moveplayer.z -= cosf(pCamera->rot.y + D3DX_PI) * player_SPEED;
		if (GetKeyboardpress(DIK_D) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * -0.75f;
		}
		if (GetKeyboardpress(DIK_A) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * 0.75f;
		}
	}
	if (GetKeyboardpress(DIK_A) == true)
	{
		g_player.g_rotplayer.y = pCamera->rot.y - D3DX_PI / 2;

		g_player.g_moveplayer.x -= sinf(pCamera->rot.y + D3DX_PI / 2) * player_SPEED;
		g_player.g_moveplayer.z -= cosf(pCamera->rot.y + D3DX_PI / 2) * player_SPEED;

		if (GetKeyboardpress(DIK_W) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * 0.75f;
		}
		if (GetKeyboardpress(DIK_S) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * 0.25f;
		}

	}
	if (GetKeyboardpress(DIK_S) == true)
	{
		g_player.g_rotplayer.y = pCamera->rot.y + D3DX_PI * 0.0f;

		g_player.g_moveplayer.x += sinf(pCamera->rot.y + D3DX_PI) * player_SPEED;
		g_player.g_moveplayer.z += cosf(pCamera->rot.y + D3DX_PI) * player_SPEED;
		if (GetKeyboardpress(DIK_A) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * 0.25f;
		}
		if (GetKeyboardpress(DIK_D) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * -0.25f;
		}
	}
	if (GetKeyboardpress(DIK_D) == true)
	{
		g_player.g_rotplayer.y = pCamera->rot.y + D3DX_PI / 2;

		g_player.g_moveplayer.x += sinf(pCamera->rot.y + D3DX_PI / 2) * player_SPEED;
		g_player.g_moveplayer.z += cosf(pCamera->rot.y + D3DX_PI / 2) * player_SPEED;
		if (GetKeyboardpress(DIK_W) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * -0.75f;
		}
		if (GetKeyboardpress(DIK_S) == true)
		{
			g_player.g_rotplayer.y = D3DX_PI * -0.25f;
		}
	}
#else

	bool bMove = false;	// 動くか否か

	if (GetKeyboardpress(DIK_SPACE) == true)
	{
		SetBullet(g_player.g_posplayer, g_player.g_rotplayer, 5);
	}

	if (GetKeyboardpress(DIK_W) == true)
	{
		bMove = true;
		g_player.DestRot.y = pCamera->rot.y - D3DX_PI;
		if (GetKeyboardpress(DIK_D) == true)
		{
			g_player.DestRot.y = pCamera->rot.y - D3DX_PI * 0.75f;
		}
		if (GetKeyboardpress(DIK_A) == true)
		{
			g_player.DestRot.y = pCamera->rot.y + D3DX_PI * 0.75f;
		}
	}
	else if (GetKeyboardpress(DIK_A) == true)
	{
		bMove = true;
		g_player.DestRot.y = pCamera->rot.y + D3DX_PI * 0.5f;
		if (GetKeyboardpress(DIK_W) == true)
		{
			g_player.DestRot.y = pCamera->rot.y - D3DX_PI * 0.75f;
		}
		if (GetKeyboardpress(DIK_S) == true)
		{
			g_player.DestRot.y = pCamera->rot.y + D3DX_PI * 0.25f;
		}
	}
	else if (GetKeyboardpress(DIK_S) == true)
	{
		bMove = true;
		g_player.DestRot.y = pCamera->rot.y;
		if (GetKeyboardpress(DIK_D) == true)
		{
			g_player.DestRot.y = pCamera->rot.y - D3DX_PI * 0.25f;
		}
		if (GetKeyboardpress(DIK_A) == true)
		{
			g_player.DestRot.y = pCamera->rot.y + D3DX_PI * 0.25f;
		}
	}
	else if (GetKeyboardpress(DIK_D) == true)
	{
		bMove = true;
		g_player.DestRot.y = pCamera->rot.y - D3DX_PI * 0.5f;
		if (GetKeyboardpress(DIK_W) == true)
		{
			g_player.DestRot.y = pCamera->rot.y - D3DX_PI * 0.75f;
		}
		if (GetKeyboardpress(DIK_S) == true)
		{
			g_player.DestRot.y = pCamera->rot.y + D3DX_PI * 0.25f;
		}
	}

	if (GetKeyboardTrigger(DIK_SPACE) == true)
	{

	}
	if (GetKeyboardpress(DIK_M) == true)
	{
		g_player.aModel[3].rot.y = 1.5f;
		g_player.aModel[3].rot.z -= 0.1f;

		g_player.aModel[6].rot.y = -1.5f;
		g_player.aModel[6].rot.z += 0.1f;
	}
	if (GetKeyboardpress(DIK_K) == true)
	{
		if (g_rolling == false)
		{
			g_player.aModel[2].rot.y += 0.1f;
			if (g_player.aModel[2].rot.y >= 1.5f)
			{
				g_rolling = true;
			}
		}
		else if (g_rolling == true)
		{
			g_player.aModel[2].rot.y -= 0.1f;
			if (g_player.aModel[2].rot.y <= -1.5f)
			{
				g_rolling = false;
			}
		}
	}
	// 目的の角度の補正
	if (fabsf(g_player.DestRot.y) > D3DX_PI)
	{
		float fOverRot = fabsf(g_player.DestRot.y) - D3DX_PI;
		float fNewRot = -(D3DX_PI - fOverRot);
		if (g_player.DestRot.y < 0)
		{
			fNewRot *= -1.0f;		//反転
		}
		g_player.DestRot.y = fNewRot;
	}

	float fRotDiff = g_player.DestRot.y - g_player.g_rotplayer.y;	// 目的の角度と現在の角度の差

	if (fabsf(fRotDiff) > D3DX_PI)
	{
		float fDecRot = D3DX_PI * 2.0f;
		if (fRotDiff < 0)
		{
			fDecRot *= -1.0f;
		}
		g_player.DestRot.y -= fDecRot;
		fRotDiff = g_player.DestRot.y - g_player.g_rotplayer.y;		// 改めて差を求める
	}

	g_player.g_rotplayer.y += (fRotDiff * 0.1f);					// 向きの更新

	// 現在の角度の補正
	if (fabsf(g_player.g_rotplayer.y) > D3DX_PI)
	{
		float fOverRot = fabsf(g_player.g_rotplayer.y) - D3DX_PI;
		float fNewRot = -(D3DX_PI - fOverRot);
		if (g_player.g_rotplayer.y < 0)
		{
			fNewRot *= -1.0f;
		}
		g_player.g_rotplayer.y = fNewRot;
	}

	if (bMove == true)
	{
		g_player.g_moveplayer.x -= sinf(D3DX_PI - g_player.DestRot.y) * player_SPEED;
		g_player.g_moveplayer.z += cosf(D3DX_PI - g_player.DestRot.y) * player_SPEED;
	}

#endif

	//前の位置を保存
	g_player.g_oldposplayer = g_player.g_posplayer;

	//位置を更新
	g_player.g_posplayer.x += g_player.g_moveplayer.x;
	g_player.g_posplayer.y += g_player.g_moveplayer.y;
	g_player.g_posplayer.z += g_player.g_moveplayer.z;

	//速度の減衰
	g_player.g_moveplayer.x += (0.0f - g_player.g_moveplayer.x) * 0.5f;
	g_player.g_moveplayer.y += (0.0f - g_player.g_moveplayer.y) * 0.5f;
	g_player.g_moveplayer.z += (0.0f - g_player.g_moveplayer.z) * 0.5f;
}

//描画処理
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;				//計算用マトリックス
	D3DMATERIAL9 matDef;						//現在のマテリアル保存用
	D3DXMATERIAL* pMat;							//マテリアルデータへのポインタ

	////ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_player.mtxWorld);
	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_player.g_rotplayer.y, g_player.g_rotplayer.x, g_player.g_rotplayer.z);

	D3DXMatrixMultiply(&g_player.mtxWorld, &g_player.mtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_player.g_posplayer.x, g_player.g_posplayer.y, g_player.g_posplayer.z);

	D3DXMatrixMultiply(&g_player.mtxWorld, &g_player.mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_player.mtxWorld);

	//現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);

	for (int nCnt = 0; nCnt < NUM_MODEL; nCnt++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_player.aModel[nCnt].ModelmtxWorld);
		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_player.aModel[nCnt].rot.y, g_player.aModel[nCnt].rot.x, g_player.aModel[nCnt].rot.z);
		D3DXMatrixMultiply(&g_player.aModel[nCnt].ModelmtxWorld, &g_player.aModel[nCnt].ModelmtxWorld, &mtxRot);

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_player.aModel[nCnt].pos.x, g_player.aModel[nCnt].pos.y, g_player.aModel[nCnt].pos.z);
		D3DXMatrixMultiply(&g_player.aModel[nCnt].ModelmtxWorld, &g_player.aModel[nCnt].ModelmtxWorld, &mtxTrans);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_player.aModel[nCnt].ModelmtxWorld);

		//自分の親モデルのマトリックスとの掛け算
		D3DXMATRIX mtxParent;

		if (g_player.aModel[nCnt].nIdxModelParent == -1)
		{
			mtxParent = g_player.mtxWorld;
		}
		else
		{
			mtxParent = g_player.aModel[g_player.aModel[nCnt].nIdxModelParent].ModelmtxWorld;
		}

		D3DXMatrixMultiply(&g_player.aModel[nCnt].ModelmtxWorld, &g_player.aModel[nCnt].ModelmtxWorld, &mtxParent);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_player.aModel[nCnt].ModelmtxWorld);


		for (int nCntMat = 0; nCntMat < (int)g_player.aModel[nCnt].nNumMat; nCntMat++)
		{

			//マテリアルデータへのポインタを取得
			pMat = (D3DXMATERIAL*)g_player.aModel[nCnt].pBuffMat->GetBufferPointer();

			//マテリアルの設定
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			//テクスチャの設定
			pDevice->SetTexture(0, NULL);

			//モデル（パーツ）の描画
			g_player.aModel[nCnt].pMesh->DrawSubset(nCntMat);
		}
	}
	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);
}


void LoadPlayer(void)
{
	int nCnt = 0;		//現在のデータ

	char aDataSearch[1000];	//データ検索用
	char aSymbol[4];		// =用

	FILE* pFile = fopen(PARTS_FILE, "r");

	if (pFile == NULL)
	{//ファイルが開けなかったら処理を終了する
		return;
	}

	while (1)
	{//ENDが見つかるまで続ける
		fscanf(pFile, "%s", aDataSearch);	//検索

		if (!strcmp(aDataSearch, "END_SCRIPT"))
		{//読み込み終了
			fclose(pFile);
			break;
		}
		if (aDataSearch[0] == '#')
		{//繰り返す
			continue;
		}

		if (!strcmp(aDataSearch, "CHARACTERSET"))
		{
			//項目ごとにデータを代入
			while (1)
			{

				fscanf(pFile, "%s", aDataSearch);

				if (aDataSearch[0] == '#')
				{//繰り返す
					continue;
				}

				if (!strcmp(aDataSearch, "END_PARTSSET"))
				{
					break;
				}
				else if (!strcmp(aDataSearch, "INDEX"))
				{
					fscanf(pFile, "%s %d",
						&aSymbol[0],
						&g_player.aModel[nCnt].nIdxParts);
				}
				else if (!strcmp(aDataSearch, "PARENT"))
				{
					fscanf(pFile, "%s %d", 
						&aSymbol[0],
						&g_player.aModel[nCnt].nIdxModelParent);
				}
				else if (!strcmp(aDataSearch, "POS"))
				{
					fscanf(pFile, "%s %f %f %f",
						&aSymbol[0],
						&g_player.aModel[nCnt].pos.x,
						&g_player.aModel[nCnt].pos.y,
						&g_player.aModel[nCnt].pos.z);
				}
				else if (!strcmp(aDataSearch, "ROT"))
				{
					fscanf(pFile, "%s %f %f %f", 
						&aSymbol[0],
						&g_player.aModel[nCnt].rot.x, 
						&g_player.aModel[nCnt].rot.y,
						&g_player.aModel[nCnt].rot.z);
				}
			}
			nCnt++;
		}
	}
}


Player* GetPlayer(void)
{
	return &g_player;
}

D3DXVECTOR3 GetPlayerrot(void)
{
	return g_player.g_rotplayer;
}