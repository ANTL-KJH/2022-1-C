/*
* ���ϸ� : "Big random generator.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-���� ���ǵǾ��ִ� Matrix�� ���� �����ϰ� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.23
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.23  v1.0	�����ۼ�
* ������			2022.03.24	v1.1	printArraySample �Լ����� line size ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_SIZE 10

void genRandArray(int mA[], int size);
void printArraySample(int mA[], int size);
int main()
{
	int* array; //���� �޸� �Ҵ��� ���� ������
	for (int size = 200000; size <= 1000000; size += 200000)
	{
		printf("Testing generation of dynamic array of random numbers (size: %d)\n", size);
		array = (int*)calloc(size, sizeof(int)); //200000, 400000 ������ ������ ���� �޸� �Ҵ�
		if (array == NULL)
		{
			printf("Error in dynamic memory allocation for integer array of size (%d)\n", size);
			exit(-1);
		}
		genRandArray(array, size);	//�迭�� array ����
		printArraySample(array, size);
		free(array);
	}
	return 0;
}

void genRandArray(int mA[], int size)
{
	char* flag;	//�ߺ�Ȯ�ο� �迭
	unsigned int uint_32;
	unsigned int bigRand;
	int bigRandMax = 32767;
	int count = 0;

	flag = (char*)malloc(sizeof(char) * size); //���� �޸� �Ҵ�
	srand((unsigned)time(NULL));

	while (count < size)
	{
		uint_32 = ((long)rand() << 15) | rand(); //������ RAND_MAX�� �ʰ��ϴ� �������� ����
		bigRand = uint_32 % size;	//�迭�� size�� �̹Ƿ� bigRand�� size�� ���� �������� ���

		if (flag[bigRand] == 1)	//flag[bigRand]���� 1�̸� �ߺ�, ���� ���ڰ� �ߺ��� ���ڸ� mA�迭�� �Է� ��������
		{
			continue;
		}

		else //�ߺ� ���ڰ� �ƴϸ� �迭�� 1 �Է�
		{
			flag[bigRand] = 1;
			mA[count] = bigRand;//������ ���� ���ڸ� �迭�� ����
			count++;
		}
	}
	free(flag);
}
void printArraySample(int mA[], int size)
{
	for (int i = 0; i < 3 * LINE_SIZE; i++)//�� 30�� ��� �ݺ���
	{
		printf(" %6d", mA[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("   .  .  .  .\n");
	for (int i = size - 3 * LINE_SIZE; i < size; i++)//�� 30�� ��� �ݺ���
	{
		printf(" %6d", mA[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}