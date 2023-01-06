#include <stdio.h>
#include "Mtrx.h"
#pragma warning(disable: 4996)	//scanf관련 보안경고 무시
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
	dM = createDoubleMtrx(*row_size, *col_size);  //2차원 배열 할당
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < col; n++)
		{
			if (fscanf(fin, "%lf", &input_data) != EOF)
				dM[m][n] = input_data; //데이터 입력
		}
	}
	return dM;
}

double** createDoubleMtrx(int row_size, int col_size)	//이중포인터를 이용한 2차원 Matrix 동적 메모리할당
{
	double** ppDA;
	ppDA = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		ppDA[r] = (double*)calloc(col_size, sizeof(double));
	}
	return ppDA;
}

void printMtrx(double** mA, int row_size, int column_size)	//Matrix를 출력하는 함수
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < column_size; j++)
		{
			if ((i == 0) && (j == 0))	//첫번째 행 출력에서 0xa6, 0xa3 출력
				printf("%c%c%7.2lf", a6, a3, mA[i][j]);
			else if ((i == 0) && j == (column_size - 1))	//첫번째 행 마지막 출력에서 0xa6, 0xa4출력
				printf("%7.2lf%c%c", mA[i][j], a6, a4);
			else if ((i > 0) && (i < row_size - 1) && (j == 0))	//두번째 행 출력부터 마지막행 이전까지는 0xa6, 0xa2출력
				printf("%c%c%7.2lf", a6, a2, mA[i][j]);
			else if ((i > 0) && (i < row_size - 1) && (j == (column_size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a2);
			else if ((i == (row_size - 1)) && (j == 0))
				printf("%c%c%7.2lf", a6, a6, mA[i][j]);	//행렬 마지막행 첫번째 열에서 0xa6, 0xa6출력
			else if ((i == (row_size - 1)) && (j == (column_size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a5);	//행렬 마지막행 마지막 열에서 0xa6, 0xa5출력
			else
				printf("%7.2lf", mA[i][j]);	//각 행의 첫번째, 마지막 열이 아니면 일반 출력
		}
		printf("\n");
	}
}
void deleteDoubleMtrx(double** ppM, int row_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(ppM[r]); //메모리 반납
	}
	free(ppM); //이중 포인터 반납
}
double** addMtrx(double** mA, double** mB, int row_size, int col_size)	//Matrix 덧셈 연산
{
	double** mR = NULL;
	mR = createDoubleMtrx(row_size, col_size);  //2차원 배열 할당
	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < col_size; c++)
		{
			mR[r][c] = mA[r][c] + mB[r][c];
		}
	}
	return mR;
}

double** subMtrx(double** mA, double** mB, int row_size, int col_size)	//Matrix 뺄셈 연산
{
	double** mR = NULL;
	mR = createDoubleMtrx(row_size, col_size);  //2차원 배열 할당
	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < col_size; c++)
		{
			mR[r][c] = mA[r][c] - mB[r][c];
		}
	}
	return mR;
}

double** mulMtrx(double** mA, double** mB, int row_size_A, int k_size, int col_size_B)	//Matrix 곱셈 연산
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