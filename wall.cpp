#include "main.h"
#include "polygon.h"
#include "wall.h"
#define NUM_POLYGON (4)
//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffWall = NULL;
LPDIRECT3DTEXTURE9 g_pTextureWall = NULL;

D3DXVECTOR3 g_posWall;	//�ʒu
D3DXVECTOR3 g_rotWall;	//����
D3DXMATRIX g_mtxWorldWall;	//���[���h�}�g���b�N�X


//����������
void InitWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\wall.png", &g_pTextureWall);

	//�e��ϐ��̏�����
	g_posWall = D3DXVECTOR3(0.0f, 0.0f, 200.0f);
	g_rotWall = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_POLYGON, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffWall, NULL);


	VERTEX_3D* pVtx; //���_���W�ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���W�ւ̃|�C���^���擾
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos.x = g_posWall.x - 400.0f;
	pVtx[0].pos.y = g_posWall.y + 400.0f;
	pVtx[0].pos.z = g_posWall.z;
	pVtx[1].pos.x = g_posWall.x + 400.0f;
	pVtx[1].pos.y = g_posWall.y + 400.0f;
	pVtx[1].pos.z = g_posWall.z;
	pVtx[2].pos.x = g_posWall.x - 400.0f;
	pVtx[2].pos.z = g_posWall.z;
	pVtx[3].pos.x = g_posWall.x + 400.0f;
	pVtx[3].pos.z = g_posWall.z;


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


	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffWall->Unlock();
}

//�I������
void UninitWall(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureWall != NULL)
	{
		g_pTextureWall->Release();
		g_pTextureWall = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}
}

//�X�V����
void UpdateWall(void)
{

}

//�`�揈��
void DrawWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X


	for (int nCnt = 0; nCnt < NUM_POLYGON; nCnt++)
	{
		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_mtxWorldWall);
		if (nCnt == 0)
		{
			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x, g_posWall.y, g_posWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}
		if (nCnt == 1)
		{
			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y+1.57f, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x+200.0f, g_posWall.y, g_posWall.z-200.0f);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}
		if (nCnt == 2)
		{
			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y - 1.57f, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x - 200.0f, g_posWall.y, g_posWall.z - 200.0f);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}
		if (nCnt == 3)
		{
			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotWall.y - 3.14f, g_rotWall.x, g_rotWall.z);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_posWall.x, g_posWall.y, g_posWall.z - 400.0f);

			D3DXMatrixMultiply(&g_mtxWorldWall, &g_mtxWorldWall, &mtxTrans);
		}

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldWall);

		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffWall, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureWall);
		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}