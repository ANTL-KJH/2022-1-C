/*GaussJordan_Algorithms.cpp*/

#include "GaussJordan.h"
#include "Matrix.h"

void getAugmentedMatrixData(FILE* fin, double** augMtrx, int size_N)	//fgetMtrx GaussJordan Ver
{
	double input_data = 0.0;
	if (fin == NULL)
	{
		printf("File open error!!\n");
		exit(-1);
	}
	for (int m = 0; m < size_N; m++)
	{
		for (int n = 0; n < size_N + 1; n++)
		{
			if (fscanf(fin, "%lf", &input_data) != EOF)
				augMtrx[m][n] = input_data;
		}
	}
}

void pivoting(double** augMtrx, int size_N, int p, int* piv_found)
{
	double xmax = 0.0, xtemp;
	int j, k, max_row;
	xmax = fabs(augMtrx[p][p]);	//fabs�� ���밪����, math.h
	max_row = p;
	for (j = p + 1; j < size_N; j++)	//p���� ����ū ���� ã��
	{
		if (fabs(augMtrx[j][p]) > xmax)
		{
			xmax = fabs(augMtrx[j][p]);
			max_row = j;
		}
	}
	if (fabs(xmax) < EPSILON) { // EPSILON = 0.000001, �ִ밪�� EPSILON���� ������ False(���� �߻� ���ɼ�)
		*piv_found = 0;	//piv_found�� solExist�κ��� ���޹���
	}
	else {
		*piv_found = 1; //�ذ� ����
		if (max_row != p)	//�ִ밪�� �ִ� ���� ����
		{
			for (k = p; k <= size_N; k++) {
				xtemp = augMtrx[p][k];
				augMtrx[p][k] = augMtrx[max_row][k];
				augMtrx[max_row][k] = xtemp;
			}
		}
	}
}

void diagonalize_FileOut(FILE* fout, double** augMtrx, int size_N, int* solExist) //solExist�� ���� ���� ���� 
{
	int j, k, p = 0; // pivot index
	double pivWeight, w;
	for (p = 0; (*solExist) && (p < size_N); p++)
	{
		pivoting(augMtrx, size_N, p, solExist);	//pivoting

		if (*solExist) {
			if (augMtrx[p][p] != 1.0)	//�ҰŹ��� ����ϴ� ��,���� ���� 1�� �ƴѰ�� �ش� ������ ���� ���ҵ��� ����
			{
				pivWeight = augMtrx[p][p];
				augMtrx[p][p] = 1.0; //pivot row�� p��° element�� 1.0���� ����(�ҰŸ� �����ϴ� ���� �ش� element������ ������ �Ͱ� ����)
				for (k = p + 1; k <= size_N; k++)
				{
					augMtrx[p][k] /= pivWeight;	//scaling, 1.0���� ������
				}
			}
		}
		else {
			break;
		}
		for (j = 0; j < size_N; j++)
		{
			if ((j != p) && (augMtrx[j][p] != 0.0))	//pivot row ������ ���� pivot col�� 0�� �ƴѰ�
			{
				w = augMtrx[j][p]; //weight
				augMtrx[j][p] = 0.0;	//�Ұ� ����
				for (k = p + 1; k <= size_N; k++) {
					augMtrx[j][k] = augMtrx[j][k] - w * augMtrx[p][k]; //�Ұ� ����, pivot row�� ���� col ���� weight�� ���ؼ� ���� ����
				}
			}
		}
	}
}