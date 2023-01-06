/*BigArray_Algorithms.cpp*/
#include "BigArray_Algorithms.h"

void genBigRandArray(int array[], int bigRandSize, int offset)	//bigrand�� ����� �Լ� ����(offset ~ offset + size)
{
	char* flag;
	int count = 0;
	unsigned int u_int32 = 0;
	unsigned int bigRand;
	flag = (char*)calloc(bigRandSize, sizeof(char));
	while (count < bigRandSize)
	{
		u_int32 = ((long)rand() << 15) | rand();
		bigRand = u_int32 % bigRandSize;
		if (flag[bigRand] == 1)
		{
			continue;
		}
		else {
			flag[bigRand] = 1;
			array[count++] = bigRand;
		}
	}
	free(flag);
}

void printBigArraySample(int* array, int size, int line_size, int num_sample_lines)	//�迭�� ó���� ���κ��� ������ ����ϴ� �Լ�
{
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++, array++) //�ϳ��� ��� 29��° ���� �� 30��
		{
			printf("%8d", *array);
		}
		printf("\n");
	}
	printf("    .  .  .  .  .  . \n");
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++, array++) //�� �ڿ��� ���� 30�� ���
		{
			printf("%8d", *(array + size - 2 * (line_size * num_sample_lines)));
		}
		printf("\n");
	}
}

void suffleArray(int* array, int size)	//array Shuffle
{
	int i1, i2, d;
	srand((unsigned)time(NULL));

	for (int i = 0; i < size / 2; i++)
	{
		i1 = ((unsigned long)rand() << 15 | rand()) % size;
		i2 = ((unsigned long)rand() << 15 | rand()) % size;

		d = array[i1];
		array[i1] = array[i2];
		array[i2] = d;
	}
}