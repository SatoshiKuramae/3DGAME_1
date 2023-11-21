#include "main.h"
#include "meshfield.h"
#define NUM_MESH (9)
//���b�V���t�B�[���h�̃e�N�X�`��
LPDIRECT3DTEXTURE9 g_pTextureMeshField = NULL;
//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffMeshField = NULL;
//�C���f�b�N�X�o�b�t�@�ւ̃|�C���^
LPDIRECT3DINDEXBUFFER9 g_pIdxBuffMeshField = NULL;
//���b�V���t�B�[���h�̈ʒu
D3DXVECTOR3 g_posMeshField;
//���b�V���t�B�[���h�̌���
D3DXVECTOR3 g_rotMeshField;
//���b�V���t�B�[���h�̃��[���h�}�g���b�N�X
D3DXMATRIX g_mtxWorldMeshField;

//����������
void Initmeshfield(void)
{

	g_posMeshField = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_rotMeshField = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) *  NUM_MESH, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffMeshField, NULL);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\field.png", &g_pTextureMeshField);
	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD) * 14,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIdxBuffMeshField,
		NULL);
	
	//���_���̐ݒ�


	VERTEX_3D* pVtx; //���_���W�ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���W�ւ̃|�C���^���擾
	g_pVtxBuffMeshField->Lock(0, 0, (void**)&pVtx, 0);

	//�C���f�b�N�X�o�b�t�@�����b�N
	WORD* pldx;
	g_pIdxBuffMeshField->Lock(0, 0, (void**)&pldx, 0);
	

	//���_���̐ݒ�
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

	//�@���x�N�g���̐ݒ�
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

	//�C���f�b�N�X�̐ݒ�
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

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffMeshField->Unlock();
}

//�I������
void Uninitmeshfield(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureMeshField != NULL)
	{
		g_pTextureMeshField->Release();
		g_pTextureMeshField = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffMeshField != NULL)
	{
		g_pVtxBuffMeshField->Release();
		g_pVtxBuffMeshField = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̉��
	if (g_pIdxBuffMeshField != NULL)
	{
		g_pIdxBuffMeshField->Release();
		g_pIdxBuffMeshField = NULL;
	}
}

//�X�V����
void Updatemeshfield(void)
{

}

//�`�揈��
void Drawmeshfield(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X

		//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldMeshField);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotMeshField.y, g_rotMeshField.x, g_rotMeshField.z);

	D3DXMatrixMultiply(&g_mtxWorldMeshField, &g_mtxWorldMeshField, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_posMeshField.x, g_posMeshField.y, g_posMeshField.z);

	D3DXMatrixMultiply(&g_mtxWorldMeshField, &g_mtxWorldMeshField, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldMeshField);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffMeshField, 0, sizeof(VERTEX_3D));

	//�C���f�b�N�X�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(g_pIdxBuffMeshField);

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureMeshField);

	//�|���S���̕`��
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, 9, 0, 12);

}