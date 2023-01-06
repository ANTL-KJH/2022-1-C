/*
* 파일명 : "main.cpp"
* 프로그램의 목적 및 기본 기능:
* -다중소스와 헤더파일을 이용하여 BigRandom생성, suffle하고 출력하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.04.03
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.04.03  v1.0	최초작성
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
	while (menu != ESC)	//ESC가 입력되면 반복문 종료
	{
		while (1)
		{
			printf("Input size of big array (more than 50,000) = ");
			scanf_s("%d", &size);
			if (size > 50000)
			{
				break;
			}
			else	//50000보다 큰 숫자가 입력되지않으면 오류문구 출력
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

void print_rand_array_sample(FILE* fout, int size)	//샘플을 출력하는함수
{
	int* array;
	int shuffle = 0;
	array = (int*)calloc(size, sizeof(int));
	genBigRandArray(array, size);
	printBigArraySample(array, size, 10, 2);
	fprintBigArraySample(fout, array, size, 10, 2);
	printf("Do you want to suffle?(yes:1, No:any key):");
	scanf_s("%d", &shuffle);
	if (shuffle == 1)	//shuffle에 1이 입력되면 shuffle 진행
	{
		suffleBigArray(array, size);
		printf("Shuffling. . .\n");
		fprintf(fout, "Shuffling. . .\n");
		printBigArraySample(array, size, LINE_SIZE, SAMPLE_LINE_SIZE);
		fprintBigArraySample(fout, array, size, LINE_SIZE, SAMPLE_LINE_SIZE);
	}
}