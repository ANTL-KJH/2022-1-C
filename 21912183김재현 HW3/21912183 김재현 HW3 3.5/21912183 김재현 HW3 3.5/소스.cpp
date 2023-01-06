/*
* ���ϸ� : "Matrix Calculator and Matrix Printer.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-���� ���ǵǾ��ִ� Matrix�� ���� �����ϰ� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.13
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.13  v1.0	�����ۼ�
* ������			2022.03.18	v1.1	���α׷� �ϼ�
*/

#include <stdio.h>
#define SIZE 5

void multiplyMtrx(double A[][SIZE], double B[][SIZE], double X[][SIZE], int size);
void printMtrx(double mA[][SIZE], int size);

int main(void)
{
	double mA[SIZE][SIZE] = { {5.0, 4.0, 3.0, 2.0, 1.0},	//matrix A �� �Է�
	{6.0, 7.0, 8.0, 9.0, 10.0},
	{11.0, 12.0, 13.0, 14.0, 15.0},
	{16.0, 17.0, 18.0, 19.0, 20.0},
	{21.0, 22.0, 23.0, 24.0, 25.0}
	};
	double mB[SIZE][SIZE] = { {1.0, 0.0, 0.0, 0.0, 0.0},	//matrix B �� �Է�
	{0.0, 1.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 0.0, 1.0}
	};
	double mR[SIZE][SIZE] = { 0.0, };	//mR �ʱ�ȭ
	printf("Matrix A : \n");
	printMtrx(mA, SIZE);
	printf("Matrix B : \n");
	printMtrx(mB, SIZE);
	printf("Matrix A * B : \n");
	multiplyMtrx(mA, mB, mR, SIZE);
	printMtrx(mR, SIZE);	//������ ��� ���

	return 0;
}

void multiplyMtrx(double A[][SIZE], double B[][SIZE], double X[][SIZE], int size)	//����� ����
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
void printMtrx(double mA[][SIZE], int size)	//����� ����ϴ� �Լ�
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if ((i == 0) && (j == 0))	//ù��° �� ��¿��� 0xa6, 0xa3 ���
				printf("%c%c%7.2lf", a6, a3, mA[i][j]);
			else if ((i == 0) && j == (size - 1))	//ù��° �� ������ ��¿��� 0xa6, 0xa4���
				printf("%7.2lf%c%c", mA[i][j], a6, a4);
			else if ((i > 0) && (i < size - 1) && (j == 0))	//�ι�° �� ��º��� �������� ���������� 0xa6, 0xa2���
				printf("%c%c%7.2lf", a6, a2, mA[i][j]);
			else if ((i > 0) && (i < size - 1) && (j == (size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a2);
			else if ((i == (size - 1)) && (j == 0))
				printf("%c%c%7.2lf", a6, a6, mA[i][j]);	//��� �������� ù��° ������ 0xa6, 0xa6���
			else if ((i == (size - 1)) && (j == (size - 1)))
				printf("%7.2lf%c%c", mA[i][j], a6, a5);	//��� �������� ������ ������ 0xa6, 0xa5���
			else
				printf("%7.2lf", mA[i][j]);	//�� ���� ù��°, ������ ���� �ƴϸ� �Ϲ� ���
		}
		printf("\n");
	}
}
