#include "main.h"
#include "Bullet.h"
#include "Player.h"
#include "shadow.h"
#define NUM_BULLET (1000)
//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;
Bullet g_Bullet[NUM_BULLET];
int g_nldxShadow_Bullet = -2;

//����������
void InitBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\texture\\coin.png", &g_pTextureBullet);

	for (int nCnt = 0; nCnt < NUM_BULLET; nCnt++)
	{
		g_Bullet[nCnt].g_posBullet = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Bullet[nCnt].rotBullet = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Bullet[nCnt].bUse = false;
		g_Bullet[nCnt].nLife = 0;
		g_nldxShadow_Bullet = SetShadow();
	}


	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUM_BULLET, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffBullet, NULL);

	VERTEX_3D* pVtx; //���_���W�ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���W�ւ̃|�C���^���擾
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_BULLET; nCnt++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(g_Bullet[nCnt].g_posBullet.x - 10.0f, g_Bullet[nCnt].g_posBullet.y + 10.0f, g_Bullet[nCnt].g_posBullet.z);
		pVtx[1].pos = D3DXVECTOR3(g_Bullet[nCnt].g_posBullet.x + 10.0f, g_Bullet[nCnt].g_posBullet.y + 10.0f, g_Bullet[nCnt].g_posBullet.z);
		pVtx[2].pos = D3DXVECTOR3(g_Bullet[nCnt].g_posBullet.x - 10.0f, g_Bullet[nCnt].g_posBullet.y - 10.0f, g_Bullet[nCnt].g_posBullet.z);
		pVtx[3].pos = D3DXVECTOR3(g_Bullet[nCnt].g_posBullet.x + 10.0f, g_Bullet[nCnt].g_posBullet.y - 10.0f, g_Bullet[nCnt].g_posBullet.z);

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
	g_pVtxBuffBullet->Unlock();
}

//�I������
void UninitBullet(void)
{
	for (int nCnt = 0; nCnt < NUM_BULLET; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureBullet != NULL)
		{
			g_pTextureBullet->Release();
			g_pTextureBullet = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}
}

//�X�V����
void UpdateBullet(void)
{
	Player* pPlayer = GetPlayer();
	for (int nCnt = 0; nCnt < NUM_BULLET; nCnt++)
	{
		SetPositionShadow(g_nldxShadow_Bullet, g_Bullet[nCnt].g_posBullet);

		g_Bullet[nCnt].nLife--;
		if (g_Bullet[nCnt].nLife < 0)
		{
			g_Bullet[nCnt].bUse = false;
		}
		if (g_Bullet[nCnt].bUse == true)
		{
			g_Bullet[nCnt].g_posBullet.x -= g_Bullet[nCnt].moveBullet.x * 10.0f;
			g_Bullet[nCnt].g_posBullet.z += g_Bullet[nCnt].moveBullet.z * 10.0f;
		}
	}

}

//�`�揈��
void DrawBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxView;

	//�A���t�@�e�X�g��L��
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCnt = 0; nCnt < NUM_BULLET; nCnt++)
	{
		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_Bullet[nCnt].g_mtxWorldBullet);

		//�r���[�}�g���b�N�X���擾
		pDevice->GetTransform(D3DTS_VIEW, &mtxView);

		//�|���S�����J�����ɑ΂����ʂɌ�����
		D3DXMatrixInverse(&g_Bullet[nCnt].g_mtxWorldBullet, NULL, &mtxView);

		//�t�s������߂�
		D3DXMatrixInverse(&g_Bullet[nCnt].g_mtxWorldBullet, NULL, &mtxView);

		g_Bullet[nCnt].g_mtxWorldBullet._41 = 0.0f;
		g_Bullet[nCnt].g_mtxWorldBullet._42 = 0.0f;
		g_Bullet[nCnt].g_mtxWorldBullet._43 = 0.0f;


		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_Bullet[nCnt].g_posBullet.x, g_Bullet[nCnt].g_posBullet.y, g_Bullet[nCnt].g_posBullet.z);

		D3DXMatrixMultiply(&g_Bullet[nCnt].g_mtxWorldBullet, &g_Bullet[nCnt].g_mtxWorldBullet, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_Bullet[nCnt].g_mtxWorldBullet);

		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		if (g_Bullet[nCnt].bUse == true)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBullet);


			//�r���{�[�h�̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
		}
	}

	//�A���t�@�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nLife)
{
	int nCntBullet;

	for (nCntBullet = 0; nCntBullet < NUM_BULLET; nCntBullet++)
	{
		if (g_Bullet[nCntBullet].bUse == false)
		{
			g_Bullet[nCntBullet].g_posBullet = pos;
			g_Bullet[nCntBullet].moveBullet.x = cosf(rot.y - (D3DX_PI * 0.5f)) * 5.0f;
			g_Bullet[nCntBullet].moveBullet.z = sinf(rot.y - (D3DX_PI * 0.5f)) * 5.0f;
			g_Bullet[nCntBullet].nLife = 100;
			g_Bullet[nCntBullet].bUse = true;		//�g�p���Ă����Ԃɂ���

			break;
		}
	}
}