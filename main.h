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
#include "Xinput.h"//�W���C�p�b�h

//�v���g�^�C�v�錾
LPDIRECT3DDEVICE9 GetDevice(void);

//���C�u�����̃����N
#pragma comment(lib,"d3d9.lib")		//�`�揈���ɕK�v
#pragma	comment(lib,"d3dx9.lib")	//[d3d9.lib]�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")	//DirectX�R���|�[�l���g�g�p�ɕK�v
#pragma comment(lib, "winmm.lib")	//�V�X�e�������擾���ɕK�v
#pragma comment(lib, "dinput8.lib")	//���͏����ɕK�v
#pragma comment(lib,"xinput.lib") //�W���C�p�b�h
//�}�N����`
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


//���_���[3D]�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 nor;
	D3DCOLOR col;
	D3DXVECTOR2 tex;
}VERTEX_3D;

#endif

