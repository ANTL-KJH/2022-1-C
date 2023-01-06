/*
* ���ϸ� : "main.cpp"
* ���α׷��� ���� �� �⺻ ���:
* -���߼ҽ��� ��������� �̿��Ͽ� BigRandom����, suffle�ϰ� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.04.03
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.04.03  v1.0	�����ۼ�
*/
#include "BigArray.h"
#define Data_Output_File "output.txt"
#define ESC 0x1B

void print_rand_array_sample(FILE* fout, int size);
int main(void)
{
	int size = 0, menu = 0;
	FILE* fout;
	fout = fopen(Data_Output_File, "w");
	while (menu != ESC)	//ESC�� �ԷµǸ� �ݺ��� ����
	{
		while (1)
		{
			printf("Input size of big array (more than 50,000) = ");
			scanf_s("%d", &size);
			if (size > 50000)
			{
				break;
			}
			else	//50000���� ū ���ڰ� �Էµ��������� �������� ���
			{
				printf("Input Error\n");
			}
		}
		print_rand_array_sample(fout, size);
		printf("Press any key..(Exit = ESC)\n");
		menu = _getch();
		if (menu == ESC)
			break;
	}
	return 0;
}

void print_rand_array_sample(FILE* fout, int size)	//������ ����ϴ��Լ�
{
	int* array;
	int shuffle = 0;
	array = (int*)calloc(size, sizeof(int));
	genBigRandArray(array, size);
	printBigArraySample(array, size, 10, 2);
	fprintBigArraySample(fout, array, size, 10, 2);
	printf("Do you want to suffle?(yes:1, No:any key):");
	scanf_s("%d", &shuffle);
	if (shuffle == 1)	//shuffle�� 1�� �ԷµǸ� shuffle ����
	{
		suffleBigArray(array, size);
		printf("Shuffling. . .\n");
		fprintf(fout, "Shuffling. . .\n");
		printBigArraySample(array, size, LINE_SIZE, SAMPLE_LINE_SIZE);
		fprintBigArraySample(fout, array, size, LINE_SIZE, SAMPLE_LINE_SIZE);
	}
}