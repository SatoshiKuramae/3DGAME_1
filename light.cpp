//======================
//
//
//
//======================
#include "main.h"
#include "light.h"
#include "input.h"
#define NUM_LIGHT	(3)

//�O���[�o���ϐ�
D3DLIGHT9 g_light[NUM_LIGHT];	//���C�g�̏��

//����������
void InitLight(void)
{
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXVECTOR3	vecDir;		//�ݒ�p�����x�N�g��
	float Lightangle=0.0f;
	for (int nCnt = 0; nCnt < NUM_LIGHT; nCnt++)
	{
		//���C�g�����N���A����
		ZeroMemory(&g_light[nCnt], sizeof(D3DLIGHT9));

		//���C�g�̎�ނ�ݒ�
		g_light[nCnt].Type = D3DLIGHT_DIRECTIONAL;

		//���C�g�̊g�U����ݒ�
		g_light[nCnt].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		if (nCnt == 0)
		{
			//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(0.0f, -0.8f, 0.4f);
		}
		if (nCnt == 1)
		{//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(-0.8f, -0.5f, -0.8f);
		}
		if (nCnt == 2)
		{
			//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(-0.8f, -0.5f, -0.4f);
		}


		D3DXVec3Normalize(&vecDir, &vecDir);	//�x�N�g���𐳋K��
		g_light[nCnt].Direction = vecDir;

		//���C�g��ݒ�
		pDevice->SetLight(0, &g_light[nCnt]);

		//���C�g��L���ɂ���
		pDevice->LightEnable(nCnt, TRUE);
	}
}

//�I������
void UninitLight(void)
{

}

//�X�V����
void UpdateLight(void)
{

}