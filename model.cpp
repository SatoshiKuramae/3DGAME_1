#include "main.h"
#include "model.h"
#include "input.h"
#include "shadow.h"
#include "camera.h"
#include "bullet.h"

#define TEST_MODEL	(0)

#define DEFROT_MOD (0.3f)
#define MOVEROT_MOD	(0.1f)
#define MODEL_SPEED (1.0f)


//�O���[�o���ϐ�
LPD3DXMESH	g_pMeshModel = NULL;		//���b�V���i���_���j�ւ̃|�C���^
LPD3DXBUFFER g_pBuffMatModel = NULL;		//�}�e���A���ւ̃|�C���^
DWORD g_dwNumMatModel = 0;				//�}�e���A���̐�
D3DXMATRIX g_mtxWorldModel;			//���[���h�}�g���b�N�X
int g_nldxShadow = -1;
MODEL g_Model;
bool g_rolling;



//����������
void InitModel(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e��ϐ��̏�����
	g_dwNumMatModel = 0;
	g_Model.g_posModel = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
	g_Model.g_rotModel = D3DXVECTOR3(0.0f, 3.14f, 0.0f);
	g_Model.g_moveModel = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_rolling = false;
	g_nldxShadow = SetShadow();

	//X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\model.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &g_pBuffMatModel, NULL, &g_dwNumMatModel, &g_pMeshModel);

}

//�I������
void UninitModel(void)
{
	//���b�V���̔j��
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//�}�e���A���̔j��
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//�X�V����
void UpdateModel(void)
{
	Camera* pCamera=GetCamera();
	//�e�̈ʒu��ݒ�
	SetPositionShadow(g_nldxShadow, g_Model.g_posModel);

#if TEST_MODEL

	if (GetKeyboardpress(DIK_SPACE) == true)
	{
		SetBullet(g_Model.g_posModel, D3DXVECTOR3(sinf(g_Model.g_rotModel.y + D3DX_PI), 0.0f, cosf(g_Model.g_rotModel.y -+ D3DX_PI)), g_Model.g_rotModel, 5);
	}

	if (GetKeyboardpress(DIK_W) == true)
	{
		g_Model.g_rotModel.y = pCamera->rot.y + D3DX_PI;

		g_Model.g_moveModel.x -= sinf(pCamera->rot.y + D3DX_PI) * MODEL_SPEED;
		g_Model.g_moveModel.z -= cosf(pCamera->rot.y + D3DX_PI) * MODEL_SPEED;
		if (GetKeyboardpress(DIK_D) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * -0.75f;
		}
		if (GetKeyboardpress(DIK_A) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * 0.75f;
		}
	}
	if (GetKeyboardpress(DIK_A) == true)
	{
		g_Model.g_rotModel.y = pCamera->rot.y - D3DX_PI / 2;

		g_Model.g_moveModel.x -= sinf(pCamera->rot.y + D3DX_PI / 2) * MODEL_SPEED;
		g_Model.g_moveModel.z -= cosf(pCamera->rot.y + D3DX_PI / 2) * MODEL_SPEED;
		
		if (GetKeyboardpress(DIK_W) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * 0.75f;
		}
		if (GetKeyboardpress(DIK_S) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * 0.25f;
		}

	}
	if (GetKeyboardpress(DIK_S) == true)
	{
		g_Model.g_rotModel.y = pCamera->rot.y + D3DX_PI * 0.0f;

		g_Model.g_moveModel.x += sinf(pCamera->rot.y + D3DX_PI) * MODEL_SPEED;
		g_Model.g_moveModel.z += cosf(pCamera->rot.y + D3DX_PI) * MODEL_SPEED;
		if (GetKeyboardpress(DIK_A) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * 0.25f;
		}
		if (GetKeyboardpress(DIK_D) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * -0.25f;
		}
	}
	if (GetKeyboardpress(DIK_D) == true)
	{
		g_Model.g_rotModel.y = pCamera->rot.y + D3DX_PI / 2;

		g_Model.g_moveModel.x += sinf(pCamera->rot.y + D3DX_PI / 2) * MODEL_SPEED;
		g_Model.g_moveModel.z += cosf(pCamera->rot.y + D3DX_PI / 2) * MODEL_SPEED;
		if (GetKeyboardpress(DIK_W) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * -0.75f;
		}
		if (GetKeyboardpress(DIK_S) == true)
		{
			g_Model.g_rotModel.y = D3DX_PI * -0.25f;
		}
	}
#else

	bool bMove = false;	// �������ۂ�

	if (GetKeyboardpress(DIK_SPACE) == true)
	{
		SetBullet(g_Model.g_posModel, D3DXVECTOR3(sinf(g_Model.g_rotModel.y), 0.0f, cosf(g_Model.g_rotModel.y)), g_Model.g_rotModel, 5);
	}

	if (GetKeyboardpress(DIK_W) == true)
	{
		bMove = true;
		g_Model.DestRot.y = pCamera->rot.y + D3DX_PI * 1.0f;
	}
	if (GetKeyboardpress(DIK_A) == true)
	{
		bMove = true;
		g_Model.DestRot.y = pCamera->rot.y + D3DX_PI * 0.5f;
	}
	if (GetKeyboardpress(DIK_S) == true)
	{
		bMove = true;

		g_Model.DestRot.y = pCamera->rot.y + D3DX_PI * 0.0f;
	}
	if (GetKeyboardpress(DIK_D) == true)
	{
		bMove = true;
		
		g_Model.DestRot.y = pCamera->rot.y - D3DX_PI * 0.5f;
	}



	if (g_Model.DestRot.y > D3DX_PI)
	{
		float frot_dif = g_Model.DestRot.y - D3DX_PI;
		float revisionRot = -(D3DX_PI - frot_dif);

		if (revisionRot < 0)
		{
			g_Model.DestRot.y = revisionRot * -1.0f;
		}
		else
		{
			g_Model.DestRot.y = revisionRot;
		}
	}
	else if (g_Model.DestRot.y < -D3DX_PI)
	{
		float frot_dif = D3DX_PI - g_Model.DestRot.y;
		float revisionRot = -(D3DX_PI - frot_dif);

		if (revisionRot > 0)
		{
			g_Model.DestRot.y = revisionRot * -1.0f;
		}
		else
		{
			g_Model.DestRot.y = revisionRot;
		}
	}

	float diff = g_Model.DestRot.y - g_Model.g_rotModel.y;	// �ړI�̊p�x�ƌ��݂̊p�x�Ƃ̍������߂�

	if (fabsf(diff > D3DX_PI))
	{
		if (diff < 0)
		{
			g_Model.DestRot.y += (D3DX_PI * 2);
		}
		else
		{
			g_Model.DestRot.y -= (D3DX_PI * 2);
		}

		diff = g_Model.DestRot.y - g_Model.g_rotModel.y;
	}

	g_Model.g_rotModel.y += (diff * 0.1f);						// �����̍X�V
	/*g_Model.MoveRot.y = fDiffRot * MOVEROT_MOD;	*/				// ��]�ʂ̍X�V

	//���݂̌����̕␳
	if (g_Model.g_rotModel.y > D3DX_PI)
	{
		float frot_dif = g_Model.g_rotModel.y - D3DX_PI;
		float revisionRot = -(D3DX_PI - frot_dif);

		if (revisionRot < 0)
		{
			g_Model.g_rotModel.y = revisionRot * -1.0f;
		}
		else
		{
			g_Model.g_rotModel.y = revisionRot;
		}
	}
	else if (g_Model.g_rotModel.y < -D3DX_PI)
	{
		float frot_dif = D3DX_PI - g_Model.g_rotModel.y;
		float revisionRot = +(D3DX_PI - frot_dif);

		if (revisionRot < 0)
		{
			g_Model.g_rotModel.y = revisionRot * -1.0f;
		}
		else
		{
			g_Model.g_rotModel.y = revisionRot;
		}
	}

	if (bMove == true)
	{
		g_Model.g_moveModel.x -= sinf(/*pCamera->rot.y -*/ g_Model.DestRot.y) * MODEL_SPEED;
		g_Model.g_moveModel.z -= cosf(/*pCamera->rot.y -*/ g_Model.DestRot.y) * MODEL_SPEED;
	}
	
#endif

	//�ʒu���X�V
	g_Model.g_posModel.x += g_Model.g_moveModel.x;
	g_Model.g_posModel.y += g_Model.g_moveModel.y;
	g_Model.g_posModel.z += g_Model.g_moveModel.z;

	//���x�̌���
	g_Model.g_moveModel.x += (0.0f - g_Model.g_moveModel.x) * 0.5f;
	g_Model.g_moveModel.y += (0.0f - g_Model.g_moveModel.y) * 0.5f;
	g_Model.g_moveModel.z += (0.0f - g_Model.g_moveModel.z) * 0.5f;
}

//�`�揈��
void DrawModel(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;				//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;						//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL* pMat;							//�}�e���A���f�[�^�ւ̃|�C���^

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldModel);
	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Model.g_rotModel.y, g_Model.g_rotModel.x, g_Model.g_rotModel.z);

	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxRot);
	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_Model.g_posModel.x, g_Model.g_posModel.y, g_Model.g_posModel.z);

	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxTrans);
	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldModel);

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)g_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)g_dwNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, NULL);

		//���f���i�p�[�c�j�̕`��
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}	

MODEL* GetModel(void)
{
	return &g_Model;
}

D3DXVECTOR3 GetModelrot(void)
{
	return g_Model.g_rotModel;
}