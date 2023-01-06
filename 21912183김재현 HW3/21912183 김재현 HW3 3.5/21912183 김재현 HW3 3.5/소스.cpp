/*
* 파일명 : "Matrix Calculator and Matrix Printer.cpp"
* 프로그램의 목적 및 기본 기능:
*	-사전 정의되어있는 Matrix를 곱셈 연산하고 출력하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.13
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.13  v1.0	최초작성
* 김재현			2022.03.18	v1.1	프로그램 완성
*/

#include <stdio.h>
#define SIZE 5

void multiplyMtrx(double A[][SIZE], double B[][SIZE], double X[][SIZE], int size);
void printMtrx(double mA[][SIZE], int size);

int main(void)
{
	double mA[SIZE][SIZE] = { {5.0, 4.0, 3.0, 2.0, 1.0},	//matrix A 값 입력
	{6.0, 7.0, 8.0, 9.0, 10.0},
	{11.0, 12.0, 13.0, 14.0, 15.0},
	{16.0, 17.0, 18.0, 19.0, 20.0},
	{21.0, 22.0, 23.0, 24.0, 25.0}
	};
	double mB[SIZE][SIZE] = { {1.0, 0.0, 0.0, 0.0, 0.0},	//matrix B 값 입력
	{0.0, 1.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 0.0, 1.0}
	};
	double mR[SIZE][SIZE] = { 0.0, };	//mR 초기화
	printf("Matrix A : \n");
	printMtrx(mA, SIZE);
	printf("Matrix B : \n");
	printMtrx(mB, SIZE);
	printf("Matrix A * B : \n");
	multiplyMtrx(mA, mB, mR, SIZE);
	printMtrx(mR, SIZE);	//곱셈한 행렬 출력

	return 0;
}

void multiplyMtrx(double A[][SIZE], double B[][SIZE], double X[][SIZE], int size)	//행렬의 곱셈
{
	for (int i = 0; i < size; i++)
	{
		for (int p = 0; p < size; p++)
		{
			for (int q = 0; q < size; q++)
			{
				X[i][p] += A[i][q] * B[q][p];
			}
		}
	}
}
void printMtrx(double mA[][SIZE], int size)	//행렬을 출력하는 함수
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if ((i == 0) && (j == 0))	//첫번째 행 출력에서 0xa6, 0xa3 출력
				printf("%c%c%7.2lf", a6, a3, mA[i][j]);
			else if ((i == 0) && j == (size - 1))	//첫번째 행 마지막 출력에서 0xa6, 0xa4출력
				printf("%7.2lf%c%c", mA[i][j], a6, a4);
			else if ((i > 0) && (i < size - 1) && (j == 0))	//두번째 행 출력부터 마지막행 이전까지는 0xa6, 0xa2출력
				printf("%c%c%7.2lf", a6, a2, mA[i][j]);
			else if ((i > 0) && (i < size - 1) && (j == (size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a2);
			else if ((i == (size - 1)) && (j == 0))
				printf("%c%c%7.2lf", a6, a6, mA[i][j]);	//행렬 마지막행 첫번째 열에서 0xa6, 0xa6출력
			else if ((i == (size - 1)) && (j == (size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a5);	//행렬 마지막행 마지막 열에서 0xa6, 0xa5출력
			else
				printf("%7.2lf", mA[i][j]);	//각 행의 첫번째, 마지막 열이 아니면 일반 출력
		}
		printf("\n");
	}
}
