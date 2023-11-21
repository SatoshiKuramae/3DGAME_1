#include "main.h"
#include "shadow.h"
#define NUM_Shadow (1)

typedef struct
{
	D3DXVECTOR3 g_posShadow;	//�ʒu
	D3DXVECTOR3 g_rotShadow;	//����
	D3DXMATRIX g_mtxWorldShadow;	//���[���h�}�g���b�N�X
	bool g_bUse_shadow;
}Shadow;

Shadow g_Shadow[NUM_Shadow];
//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffShadow = NULL;
LPDIRECT3DTEXTURE9 g_pTextureShadow = NULL;



//����������
void InitShadow(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		g_Shadow[nCnt].g_bUse_shadow = false;

		//�e�N�X�`���ǂݍ���
		D3DXCreateTextureFromFile(pDevice, "data\\texture\\shadow000.jpg", &g_pTextureShadow);

		//�e��ϐ��̏�����
		g_Shadow[nCnt].g_posShadow = D3DXVECTOR3(0.0f, 0.1f, 0.0f);
		g_Shadow[nCnt].g_rotShadow = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	}
	
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_Shadow, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffShadow, NULL);


	VERTEX_3D* pVtx; //���_���W�ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���W�ւ̃|�C���^���擾
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-30.0f, 0.1f,30.0f);
		pVtx[1].pos = D3DXVECTOR3(30.0f, 0.1f, 30.0f);
		pVtx[2].pos = D3DXVECTOR3(-30.0f, 0.1f, -30.0f);
		pVtx[3].pos = D3DXVECTOR3(30.0f, 0.1f, -30.0f);

		//�@���x�N�g���̐ݒ�
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
	
	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffShadow->Unlock();
}

//�I������
void UninitShadow(void)
{
	/*for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{

	}*/
	//�e�N�X�`���̔j��
	if (g_pTextureShadow != NULL)
	{
		g_pTextureShadow->Release();
		g_pTextureShadow = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffShadow != NULL)
	{
		g_pVtxBuffShadow->Release();
		g_pVtxBuffShadow = NULL;
	}
}

//�X�V����
void UpdateShadow(void)
{

}

//�`�揈��
void DrawShadow(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X

	//���Z�����̐ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	for (int nCnt = 0; nCnt < NUM_Shadow; nCnt++)
	{
		if (g_Shadow[nCnt].g_bUse_shadow == false)
		{
			continue;
		}

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_Shadow[nCnt].g_mtxWorldShadow);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Shadow[nCnt].g_rotShadow.y, g_Shadow[nCnt].g_rotShadow.x, g_Shadow[nCnt].g_rotShadow.z);

		D3DXMatrixMultiply(&g_Shadow[nCnt].g_mtxWorldShadow, &g_Shadow[nCnt].g_mtxWorldShadow, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_Shadow[nCnt].g_posShadow.x, g_Shadow[nCnt].g_posShadow.y, g_Shadow[nCnt].g_posShadow.z);

		D3DXMatrixMultiply(&g_Shadow[nCnt].g_mtxWorldShadow, &g_Shadow[nCnt].g_mtxWorldShadow, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_Shadow[nCnt].g_mtxWorldShadow);

		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffShadow, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureShadow);
		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);
	}

	//�ʏ�̍����ɖ߂�
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

//�ʒu�ݒ菈��
void SetPositionShadow(int nldxShadow, D3DXVECTOR3 pos)
{
	if (nldxShadow == -1)
	{
		return;
	}

	g_Shadow[nldxShadow].g_posShadow.x = pos.x;
	g_Shadow[nldxShadow].g_posShadow.z = pos.z;
}
