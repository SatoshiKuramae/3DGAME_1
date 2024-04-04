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
//�O���[�o���ϐ�
Camera	g_camera;	//�J�����̏��


float posR;
float posV;
//�J�����̎��_���W
float g_PosV_y;
float g_PosV_z;
//�J�����̒����_���W


//����������
void InitCamera(void)
{
	g_camera.flattery = false;

	g_PosV_y = CAMERAPOS_V_Y;
	g_PosV_z = CAMERAPOS_V_Z;

	g_camera.posV = D3DXVECTOR3(0.0f, 200.0f, -600.0f);
	g_camera.posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_camera.vecU = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
}

//�I������
void UninitCamera(void)
{

}

//�X�V����
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

	//posR=�����_posV=���_vecU=���_�̃x�N�g��

	//���_�̈ړ�
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

	//��]�̕␳
	if (g_camera.rot.y > D3DX_PI)
	{
		g_camera.rot.y = -D3DX_PI;
	}
	else if (g_camera.rot.y < -D3DX_PI)
	{
		g_camera.rot.y = D3DX_PI;
	}

	//�����_�܂ł̋�����ς���
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

	//���_�̈ʒu�ړ��i�O�㍶�E�j
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

//�ݒ菈��
void SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_camera.mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&g_camera.mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 3000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &g_camera.mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_camera.mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&g_camera.mtxView, &g_camera.posV, &g_camera.posR, &g_camera.vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &g_camera.mtxView);
}

Camera* GetCamera(void)
{
	return &g_camera;
}