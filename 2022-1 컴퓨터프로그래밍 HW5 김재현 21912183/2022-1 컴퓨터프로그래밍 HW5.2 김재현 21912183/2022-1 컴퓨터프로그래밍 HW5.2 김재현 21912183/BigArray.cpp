/*BigArray.cpp*/
#include "BigArray.h"

void genBigRandArray(int* array, int bigRandSize)	//bigrand를 만드는 함수
{
	char* flag;
	int count = 0;
	unsigned int u_int32 = 0;
	unsigned int bigRand;
	srand((unsigned int)time(NULL));	//시간을 Seed로 사용하여 난수 발생
	flag = (char*)calloc(bigRandSize, sizeof(char));	//중복방지 flag
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

void suffleBigArray(int* array, int size)	//두개의 난수를 뽑아 난수 위치에 있는 수를 바꾸는 함수
{
	int i1, i2, d;
	srand((unsigned)time(NULL));
	for (int i = 0; i < size / 2; i++)
	{
		i1 = (((unsigned int)rand() << 15) | rand()) % size;
		i2 = (((unsigned int)rand() << 15) | rand()) % size;
		d = array[i1];
		array[i1] = array[i2];
		array[i2] = d;
	}
}

void printBigArraySample(int* array, int size, int line_size, int num_sample_lines)	//배열의 처음과 끝부분의 샘플을 출력하는 함수
{
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++, array++) //하나씩 출력 29번째 까지 총 30개
		{
			printf("%8d", *array);
		}
		printf("\n");
	}
	printf("    .  .  .  .  .  . \n");
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++, array++) //맨 뒤에서 부터 30개 출력
		{
			printf("%8d", *(array + size - 2 * (line_size * num_sample_lines)));
			//처음 30개 출력할 때 array주소가 30 증가했으므로 size만큼 더하고 60을 빼줘야 맨뒤에서 30개 출력가능
		}
		printf("\n");
	}
}

void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines)	//배열의 처음과 끝부분의 샘플을 파일에 출력하는 함수
{
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++, array++) //하나씩 출력 29번째 까지 총 30개
		{
			fprintf(fout, "%8d", *array);
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "    .  .  .  .  .  . \n");
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < line_size; j++, array++)	//뒤에서 부터 30개 출력
		{
			fprintf(fout, "%8d", *(array + size - 2 * (line_size * num_sample_lines)));
		}
		fprintf(fout, "\n");
	}
}