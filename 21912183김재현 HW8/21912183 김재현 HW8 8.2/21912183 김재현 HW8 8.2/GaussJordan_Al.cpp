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
	xmax = fabs(augMtrx[p][p]);	//fabs는 절대값연산, math.h
	max_row = p;
	for (j = p + 1; j < size_N; j++)	//p열에 가장큰 값을 찾음
	{
		if (fabs(augMtrx[j][p]) > xmax)
		{
			xmax = fabs(augMtrx[j][p]);
			max_row = j;
		}
	}
	if (fabs(xmax) < EPSILON) { // EPSILON = 0.000001, 최대값이 EPSILON보다 작으면 False(오차 발생 가능성)
		*piv_found = 0;	//piv_found는 solExist로부터 전달받음
	}
	else {
		*piv_found = 1; //해가 존재
		if (max_row != p)	//최대값이 있는 열과 변경
		{
			for (k = p; k <= size_N; k++) {
				xtemp = augMtrx[p][k];
				augMtrx[p][k] = augMtrx[max_row][k];
				augMtrx[max_row][k] = xtemp;
			}
		}
	}
}

void diagonalize_FileOut(FILE* fout, double** augMtrx, int size_N, int* solExist) //solExist는 해의 존재 유무 
{
	int j, k, p = 0; // pivot index
	double pivWeight, w;
	for (p = 0; (*solExist) && (p < size_N); p++)
	{
		pivoting(augMtrx, size_N, p, solExist);	//pivoting

		if (*solExist) {
			if (augMtrx[p][p] != 1.0)	//소거법을 사용하는 행,열의 값이 1이 아닌경우 해당 값으로 열의 원소들을 나눔
			{
				pivWeight = augMtrx[p][p];
				augMtrx[p][p] = 1.0; //pivot row의 p번째 element를 1.0으로 변경(소거를 진행하는 열을 해당 element값으로 나누는 것과 같다)
				for (k = p + 1; k <= size_N; k++)
				{
					augMtrx[p][k] /= pivWeight;	//scaling, 1.0으로 비례축소
				}
			}
		}
		else {
			break;
		}
		for (j = 0; j < size_N; j++)
		{
			if ((j != p) && (augMtrx[j][p] != 0.0))	//pivot row 이후의 열에 pivot col이 0이 아닌값
			{
				w = augMtrx[j][p]; //weight
				augMtrx[j][p] = 0.0;	//소거 연산
				for (k = p + 1; k <= size_N; k++) {
					augMtrx[j][k] = augMtrx[j][k] - w * augMtrx[p][k]; //소거 연산, pivot row의 연산 col 값에 weight를 곱해서 빼기 연산
				}
			}
		}
	}
}