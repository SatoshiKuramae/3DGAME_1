#include "main.h"
#include "Billboard.h"
#include "shadow.h"
#define NUM_Billboard (1)
//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBillboard = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureBillboard = NULL;
Billboard g_Billboard[NUM_Billboard];
//����������
void InitBillboard(void)
{
	int nCount=0;

	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\coin.png", &g_pTextureBillboard);

	for (nCount = 0; nCount < NUM_Billboard; nCount++)
	{
		g_Billboard[nCount].g_posBillboard = D3DXVECTOR3(0.0f, 50.0f, 0.0f);
		g_Billboard[nCount].rotBillboard = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Billboard[nCount].g_nldxShadow_BILL = SetShadow();
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_Billboard, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffBillboard, NULL);


	VERTEX_3D* pVtx; //���_���W�ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���W�ւ̃|�C���^���擾
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x - 10.0f, g_Billboard[nCnt].g_posBillboard.y + 10.0f, g_Billboard[nCnt].g_posBillboard.z);
		pVtx[1].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x + 10.0f, g_Billboard[nCnt].g_posBillboard.y + 10.0f, g_Billboard[nCnt].g_posBillboard.z);
		pVtx[2].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x - 10.0f, g_Billboard[nCnt].g_posBillboard.y - 10.0f, g_Billboard[nCnt].g_posBillboard.z);
		pVtx[3].pos = D3DXVECTOR3(g_Billboard[nCnt].g_posBillboard.x + 10.0f, g_Billboard[nCnt].g_posBillboard.y - 10.0f, g_Billboard[nCnt].g_posBillboard.z);

		//�@���x�N�g���̐ݒ�
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
	
	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffBillboard->Unlock();
}

//�I������
void UninitBillboard(void)
{
	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureBillboard != NULL)
		{
			g_pTextureBillboard->Release();
			g_pTextureBillboard = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}
}

//�X�V����
void UpdateBillboard(void)
{
	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//�e�̈ʒu��ݒ�
		SetPositionShadow(g_Billboard[nCnt].g_nldxShadow_BILL, g_Billboard[nCnt].g_posBillboard);
	}
}

//�`�揈��
void DrawBillboard(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxView;



	for (int nCnt = 0; nCnt < NUM_Billboard; nCnt++)
	{
		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_Billboard[nCnt].g_mtxWorldBillboard);
	
		//�r���[�}�g���b�N�X���擾
		pDevice->GetTransform(D3DTS_VIEW, &mtxView);

		//�|���S�����J�����ɑ΂����ʂɌ�����
		D3DXMatrixInverse(&g_Billboard[nCnt].g_mtxWorldBillboard, NULL, &mtxView);

		//�t�s������߂�
		D3DXMatrixInverse(&g_Billboard[nCnt].g_mtxWorldBillboard, NULL, &mtxView);

		g_Billboard[nCnt].g_mtxWorldBillboard._41 = 0.0f;
		g_Billboard[nCnt].g_mtxWorldBillboard._42 = 0.0f;
		g_Billboard[nCnt].g_mtxWorldBillboard._43 = 0.0f;

		
		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_Billboard[nCnt].g_posBillboard.x, g_Billboard[nCnt].g_posBillboard.y, g_Billboard[nCnt].g_posBillboard.z);

		D3DXMatrixMultiply(&g_Billboard[nCnt].g_mtxWorldBillboard, &g_Billboard[nCnt].g_mtxWorldBillboard, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_Billboard[nCnt].g_mtxWorldBillboard);

		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureBillboard);

		//�r���{�[�h�̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}