/*
* 파일명 : "Big random generator.cpp"
* 프로그램의 목적 및 기본 기능:
*	-사전 정의되어있는 Matrix를 곱셈 연산하고 출력하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.23
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.23  v1.0	최초작성
* 김재현			2022.03.24	v1.1	printArraySample 함수에서 line size 삭제
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_SIZE 10

void genRandArray(int mA[], int size);
void printArraySample(int mA[], int size);
int main()
{
	int* array; //동적 메모리 할당을 위한 포인터
	for (int size = 200000; size <= 1000000; size += 200000)
	{
		printf("Testing generation of dynamic array of random numbers (size: %d)\n", size);
		array = (int*)calloc(size, sizeof(int)); //200000, 400000 사이즈 순서로 동적 메모리 할당
		if (array == NULL)
		{
			printf("Error in dynamic memory allocation for integer array of size (%d)\n", size);
			exit(-1);
		}
		genRandArray(array, size);	//배열로 array 전달
		printArraySample(array, size);
		free(array);
	}
	return 0;
}

void genRandArray(int mA[], int size)
{
	char* flag;	//중복확인용 배열
	unsigned int uint_32;
	unsigned int bigRand;
	int bigRandMax = 32767;
	int count = 0;

	flag = (char*)malloc(sizeof(char) * size); //동적 메모리 할당
	srand((unsigned)time(NULL));

	while (count < size)
	{
		uint_32 = ((long)rand() << 15) | rand(); //변수에 RAND_MAX을 초과하는 랜덤숫자 생성
		bigRand = uint_32 % size;	//배열이 size개 이므로 bigRand를 size로 나눈 나머지만 사용

		if (flag[bigRand] == 1)	//flag[bigRand]값이 1이면 중복, 랜덤 숫자가 중복된 숫자면 mA배열에 입력 하지않음
		{
			continue;
		}

		else //중복 숫자가 아니면 배열에 1 입력
		{
			flag[bigRand] = 1;
			mA[count] = bigRand;//생성된 랜덤 숫자를 배열에 저장
			count++;
		}
	}
	free(flag);
}
void printArraySample(int mA[], int size)
{
	for (int i = 0; i < 3 * LINE_SIZE; i++)//앞 30개 출력 반복문
	{
		printf(" %6d", mA[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("   .  .  .  .\n");
	for (int i = size - 3 * LINE_SIZE; i < size; i++)//뒤 30개 출력 반복문
	{
		printf(" %6d", mA[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}