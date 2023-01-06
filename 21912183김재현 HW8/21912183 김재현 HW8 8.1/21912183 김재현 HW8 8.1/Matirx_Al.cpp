/*Matrix_Al*/
#include "StandardH.h"
#include "Matrix.h"

void printMtrx(const char* p, double** mA, int row_size, int column_size)	//Matrix를 출력하는 함수
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	printf("%s =\n", p);
	if (column_size == 1)
	{
		for (int i = 0; i < row_size; i++)
		{
			if (i == 0)	//첫번째 행 출력에서 0xa6, 0xa3 출력
				printf("%c%c", a6, a3);
			else if ((i > 0) && (i < row_size - 1))//두번째 행 출력부터 마지막행 이전까지는 0xa6, 0xa2출력
				printf("%c%c", a6, a2);
			else if (i == (row_size - 1))
				printf("%c%c", a6, a6);	//행렬 마지막행 첫번째 열에서 0xa6, 0xa6출력
			printf("%7.2lf", mA[i][0]);	//각 행의 첫번째, 마지막 열이 아니면 일반 출력
			if (i == 0)	//첫번째 행 마지막 출력에서 0xa6, 0xa4출력
				printf("%c%c", a6, a4);
			else if ((i > 0) && (i < row_size - 1))
				printf("%c%c", a6, a2);
			else if ((i == (row_size - 1)))
				printf("%c%c", a6, a5);	//행렬 마지막행 마지막 열에서 0xa6, 0xa5출력
			printf("\n");
		}
	}
	else
	{
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
}

double** createDynamicDoubleMatrix(int row_size, int col_size)	//이중포인터를 이용한 2차원 Matrix 동적 메모리할당
{
	double** ppDA;
	ppDA = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		ppDA[r] = (double*)calloc(col_size, sizeof(double));
	}
	return ppDA;
}

void deleteDynMtrx(double** Mtrx, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(Mtrx[r]); //메모리 반납
	}
	free(Mtrx); //이중 포인터 반납
}

double** fGetMtrx(FILE* fp, int* row_size, int* col_size)
{
	double input_data = 0.0; //임시로 값을 받을 변수
	double** dM; //배열 포인터
	int row = 0, col = 0;

	if (fp == NULL)
	{
		printf("File open error!!\n");
		exit(-1);
	}
	fscanf(fp, "%d %d", &row, &col);
	*row_size = row;
	*col_size = col;
	dM = createDynamicDoubleMatrix(row, col);  //2차원 배열 할당
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < col; n++)
		{
			if (fscanf(fp, "%lf", &input_data) != EOF)
				dM[m][n] = input_data; //데이터 입력
		}
	}
	return dM;
}

double** addMtrx(double** mA, double** mB, int row_size, int column_size)	//Matrix add
{
	double** mR;
	mR = createDynamicDoubleMatrix(row_size, column_size);

	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < column_size; c++)
		{
			mR[r][c] = mA[r][c] + mB[r][c];
		}
	}
	return mR;
}

double** subMtrx(double** mA, double** mB, int row_size, int column_size)	//Matrix Sub
{
	double** mR;
	mR = createDynamicDoubleMatrix(row_size, column_size);

	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < column_size; c++)
		{
			mR[r][c] = mA[r][c] - mB[r][c];
		}
	}
	return mR;
}

double** mulMtrx(double** mA, double** mB, int row_size, int col_size, int n_col_size)	//Matrix Multiply
{
	double** mR;
	mR = createDynamicDoubleMatrix(row_size, col_size);
	for (int r = 0; r < row_size; r++)
	{
		for (int c = 0; c < col_size; c++)
		{
			mR[r][c] = 0;
			for (int k = 0; k < n_col_size; k++)
				mR[r][c] += mA[r][k] * mB[k][c];
		}
	}
	return mR;
}

void fprintMtrx(FILE* fout, double** mA, int row_size, int col_size)   //2차원 배열 출력
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	if (col_size == 1)
	{
		for (int i = 0; i < row_size; i++)
		{
			if (i == 0)	//첫번째 행 출력에서 0xa6, 0xa3 출력
				fprintf(fout, "%c%c", a6, a3);
			else if ((i > 0) && (i < row_size - 1))//두번째 행 출력부터 마지막행 이전까지는 0xa6, 0xa2출력
				fprintf(fout, "%c%c", a6, a2);
			else if (i == (row_size - 1))
				fprintf(fout, "%c%c", a6, a6);	//행렬 마지막행 첫번째 열에서 0xa6, 0xa6출력
			fprintf(fout, "%7.2lf", mA[i][0]);	//각 행의 첫번째, 마지막 열이 아니면 일반 출력
			if (i == 0)	//첫번째 행 마지막 출력에서 0xa6, 0xa4출력
				fprintf(fout, "%c%c", a6, a4);
			else if ((i > 0) && (i < row_size - 1))
				fprintf(fout, "%c%c", a6, a2);
			else if ((i == (row_size - 1)))
				fprintf(fout, "%c%c", a6, a5);	//행렬 마지막행 마지막 열에서 0xa6, 0xa5출력
			fprintf(fout, "\n");
		}
	}
	else
	{
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				if ((i == 0) && (j == 0))
					fprintf(fout, "%c%c%9.2lf", a6, a3, mA[i][j]); //첫부분
				else if ((i == 0) && j == (col_size - 1))
					fprintf(fout, "%9.2lf%c%c", mA[i][j], a6, a4); //첫줄의 끝부분
				else if ((i > 0) && (i < row_size - 1) && (j == 0))
					fprintf(fout, "%c%c%9.2lf", a6, a2, mA[i][j]);  //세로 막대기
				else if ((i > 0) && (i < row_size - 1) && (j == (col_size - 1)))
					fprintf(fout, "%9.2lf%c%c", mA[i][j], a6, a2);  //세로 막대기
				else if ((i == (row_size - 1)) && (j == 0))
					fprintf(fout, "%c%c%9.2lf", a6, a6, mA[i][j]);  //끝줄의 첫부분
				else if ((i == (row_size - 1)) && (j == (col_size - 1)))
					fprintf(fout, "%9.2lf%c%c", mA[i][j], a6, a5);  //끝줄의 끝부분
				else
					fprintf(fout, "%9.2lf", mA[i][j]);  //이외 위치 숫자 출력
			}
			fprintf(fout, "\n");
		}
	}
}