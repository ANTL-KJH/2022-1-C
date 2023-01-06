/*Matrix.cpp*/
#include "Matrix.h"

void printMtrx(const char* p, double** mA, int row_size, int column_size)	//Matrix를 출력하는 함수
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
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

void fprintMtrx(FILE* fout, const char* p, double** mA, int row_size, int col_size)   //2차원 배열 출력
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	printf("%s", p);
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

double** fGetAugMtrx(FILE* fin, int* size)
{
	double** Mtrx;
	double input_data;
	int row;
	if (fin == NULL)
	{
		printf("File open error!!\n");
		exit(-1);
	}
	fscanf(fin, "%d", &row);	//File에서 size scan
	*size = row;
	Mtrx = (double**)calloc(row, sizeof(double));	//2D Dynamic Matrix Allocation
	for (int i = 0; i < row; i++)
	{
		Mtrx[i] = (double*)calloc(row+1, sizeof(double));
	}
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < row+1; n++)
		{
			if (fscanf(fin, "%lf", &input_data) != EOF)
				Mtrx[m][n] = input_data; //데이터 입력
		}
	}
	return Mtrx;
}