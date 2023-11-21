//========================
//
//
//
//
//========================


typedef struct
{
	D3DXVECTOR3 g_posBillboard;
	D3DXMATRIX g_mtxWorldBillboard;
	D3DXVECTOR3 rotBillboard;
	int g_nldxShadow_BILL;
}Billboard;

//プロトタイプ宣言
void InitBillboard(void);
void UninitBillboard(void);
void UpdateBillboard(void);
void DrawBillboard(void);


