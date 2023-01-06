/*Matrix.cpp*/
#include "Matrix.h"

void printMtrx(const char* p, double** mA, int row_size, int column_size)	//Matrix�� ����ϴ� �Լ�
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	if (column_size == 1)
	{
		for (int i = 0; i < row_size; i++)
		{
			if (i == 0)	//ù��° �� ��¿��� 0xa6, 0xa3 ���
				printf("%c%c", a6, a3);
			else if ((i > 0) && (i < row_size - 1))//�ι�° �� ��º��� �������� ���������� 0xa6, 0xa2���
				printf("%c%c", a6, a2);
			else if (i == (row_size - 1))
				printf("%c%c", a6, a6);	//��� �������� ù��° ������ 0xa6, 0xa6���
			printf("%7.2lf", mA[i][0]);	//�� ���� ù��°, ������ ���� �ƴϸ� �Ϲ� ���
			if (i == 0)	//ù��° �� ������ ��¿��� 0xa6, 0xa4���
				printf("%c%c", a6, a4);
			else if ((i > 0) && (i < row_size - 1))
				printf("%c%c", a6, a2);
			else if ((i == (row_size - 1)))
				printf("%c%c", a6, a5);	//��� �������� ������ ������ 0xa6, 0xa5���
			printf("\n");
		}

	}
	else
	{
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
}

void fprintMtrx(FILE* fout, const char* p, double** mA, int row_size, int col_size)   //2���� �迭 ���
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	printf("%s", p);
	if (col_size == 1)
	{
		for (int i = 0; i < row_size; i++)
		{
			if (i == 0)	//ù��° �� ��¿��� 0xa6, 0xa3 ���
				fprintf(fout, "%c%c", a6, a3);
			else if ((i > 0) && (i < row_size - 1))//�ι�° �� ��º��� �������� ���������� 0xa6, 0xa2���
				fprintf(fout, "%c%c", a6, a2);
			else if (i == (row_size - 1))
				fprintf(fout, "%c%c", a6, a6);	//��� �������� ù��° ������ 0xa6, 0xa6���
			fprintf(fout, "%7.2lf", mA[i][0]);	//�� ���� ù��°, ������ ���� �ƴϸ� �Ϲ� ���
			if (i == 0)	//ù��° �� ������ ��¿��� 0xa6, 0xa4���
				fprintf(fout, "%c%c", a6, a4);
			else if ((i > 0) && (i < row_size - 1))
				fprintf(fout, "%c%c", a6, a2);
			else if ((i == (row_size - 1)))
				fprintf(fout, "%c%c", a6, a5);	//��� �������� ������ ������ 0xa6, 0xa5���
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
					fprintf(fout, "%c%c%9.2lf", a6, a3, mA[i][j]); //ù�κ�
				else if ((i == 0) && j == (col_size - 1))
					fprintf(fout, "%9.2lf%c%c", mA[i][j], a6, a4); //ù���� ���κ�
				else if ((i > 0) && (i < row_size - 1) && (j == 0))
					fprintf(fout, "%c%c%9.2lf", a6, a2, mA[i][j]);  //���� �����
				else if ((i > 0) && (i < row_size - 1) && (j == (col_size - 1)))
					fprintf(fout, "%9.2lf%c%c", mA[i][j], a6, a2);  //���� �����
				else if ((i == (row_size - 1)) && (j == 0))
					fprintf(fout, "%c%c%9.2lf", a6, a6, mA[i][j]);  //������ ù�κ�
				else if ((i == (row_size - 1)) && (j == (col_size - 1)))
					fprintf(fout, "%9.2lf%c%c", mA[i][j], a6, a5);  //������ ���κ�
				else
					fprintf(fout, "%9.2lf", mA[i][j]);  //�̿� ��ġ ���� ���
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
	fscanf(fin, "%d", &row);	//File���� size scan
	*size = row;
	Mtrx = (double**)calloc(row, sizeof(double));	//2D Dynamic Matrix Allocation
	for (int i = 0; i < row; i++)
	{
		Mtrx[i] = (double*)calloc(row + 1, sizeof(double));
	}
	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < row + 1; n++)
		{
			if (fscanf(fin, "%lf", &input_data) != EOF)
				Mtrx[m][n] = input_data; //������ �Է�
		}
	}
	return Mtrx;
}