//=======================
//
//main.h
//Author Kuramaesatoshi
//
//=======================
#ifndef _MAIN_H_
#define _MAIN_H_
#include <Windows.h>
#include "d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)
#include "dinput.h"
#include "Xinput.h"//ジョイパッド

//プロトタイプ宣言
LPDIRECT3DDEVICE9 GetDevice(void);

//ライブラリのリンク
#pragma comment(lib,"d3d9.lib")		//描画処理に必要
#pragma	comment(lib,"d3dx9.lib")	//[d3d9.lib]の拡張ライブラリ
#pragma comment(lib,"dxguid.lib")	//DirectXコンポーネント使用に必要
#pragma comment(lib, "winmm.lib")	//システム時刻取得時に必要
#pragma comment(lib, "dinput8.lib")	//入力処理に必要
#pragma comment(lib,"xinput.lib") //ジョイパッド
//マクロ定義
#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define FVF_VERTEX_3D	(D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define RED (255)
#define GREEN (255)
#define BLUE (255)
#define A (255)


void Update(void);
void Draw(void);
void Uninit(void);
void DrawFPS(void);


//頂点情報[3D]の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 nor;
	D3DCOLOR col;
	D3DXVECTOR2 tex;
}VERTEX_3D;

#endif

