#include <stdio.h>
#include "Mtrx.h"
#pragma warning(disable: 4996)	//scanf���� ���Ȱ�� ����
double** fGetMtrx(FILE* fin, int* row_size, int* col_size)
{
	int row = 0, col = 0;
	row = *row_size;
	col = *col_size;
	double input_data = 0.0;
	double** dM;

	if (fin == NULL)
	{
		printf("File open error!!\n");
		exit(-1);
	}
	dM = createDoubleMtrx(*row_size, *col_size);  //2���� �迭 �Ҵ�
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < col; n++)
		{
			if (fscanf(fin, "%lf", &input_data) != EOF)
				dM[m][n] = input_data; //������ �Է�
		}
	}
	return dM;
}

double** createDoubleMtrx(int row_size, int col_size)	//���������͸� �̿��� 2���� Matrix ���� �޸��Ҵ�
{
	double** ppDA;
	ppDA = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		ppDA[r] = (double*)calloc(col_size, sizeof(double));
	}
	return ppDA;
}

void printMtrx(double** mA, int row_size, int column_size)	//Matrix�� ����ϴ� �Լ�
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < column_size; j++)
		{
			if ((i == 0) && (j == 0))	//ù��° �� ��¿��� 0xa6, 0xa3 ���
				printf("%c%c%7.2lf", a6, a3, mA[i][j]);
			else if ((i == 0) && j == (column_size - 1))	//ù��° �� ������ ��¿��� 0xa6, 0xa4���
				printf("%7.2lf%c%c", mA[i][j], a6, a4);
			else if ((i > 0) && (i < row_size - 1) && (j == 0))	//�ι�° �� ��º��� �������� ���������� 0xa6, 0xa2���
				printf("%c%c%7.2lf", a6, a2, mA[i][j]);
			else if ((i > 0) && (i < row_size - 1) && (j == (column_size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a2);
			else if ((i == (row_size - 1)) && (j == 0))
				printf("%c%c%7.2lf", a6, a6, mA[i][j]);	//��� �������� ù��° ������ 0xa6, 0xa6���
			else if ((i == (row_size - 1)) && (j == (column_size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a5);	//��� �������� ������ ������ 0xa6, 0xa5���
			else
				printf("%7.2lf", mA[i][j]);	//�� ���� ù��°, ������ ���� �ƴϸ� �Ϲ� ���
		}
		printf("\n");
	}
}
void deleteDoubleMtrx(double** ppM, int row_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(ppM[r]); //�޸� �ݳ�
	}
	free(ppM); //���� ������ �ݳ�
}
double** addMtrx(double** mA, double** mB, int row_size, int col_size)	//Matrix ���� ����
{
	double** mR = NULL;
	mR = createDoubleMtrx(row_size, col_size);  //2���� �迭 �Ҵ�
	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < col_size; c++)
		{
			mR[r][c] = mA[r][c] + mB[r][c];
		}
	}
	return mR;
}

double** subMtrx(double** mA, double** mB, int row_size, int col_size)	//Matrix ���� ����
{
	double** mR = NULL;
	mR = createDoubleMtrx(row_size, col_size);  //2���� �迭 �Ҵ�
	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < col_size; c++)
		{
			mR[r][c] = mA[r][c] - mB[r][c];
		}
	}
	return mR;
}

double** mulMtrx(double** mA, double** mB, int row_size_A, int k_size, int col_size_B)	//Matrix ���� ����
{
	double** mR = NULL;
	mR = createDoubleMtrx(row_size_A, col_size_B);
	for (int r = 0; r < row_size_A; r++)
	{
		for (int c = 0; c < col_size_B; c++)
		{
			mR[r][c] = 0;
			for (int k = 0; k < k_size; k++)
				mR[r][c] += mA[r][k] * mB[k][c];
		}
	}
	return mR;
}