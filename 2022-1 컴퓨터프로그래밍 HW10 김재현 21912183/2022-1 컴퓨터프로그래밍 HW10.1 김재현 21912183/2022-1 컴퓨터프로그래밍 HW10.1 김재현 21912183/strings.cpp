/*strings.cpp*/
#include "Std.h"
#include "str.h"

void Fgetwords(FILE* fin, char word_m[][Word_len_Max], int* w_len)	//get words from file
{
	int count = 0;
	char word[15];
	while (feof(fin) == 0)	//파일의 끝에 도달하면 반복 종료
	{
		fscanf(fin, "%s", word);	//get words
		strcpy(word_m[count], word);
		w_len[count] = strlen(word_m[count]);	//word length check
		count++;
	}
}

void sorting_word(char word_m[][Word_len_Max])	//sorting words
{
	char* min;
	int min_idx;
	min = (char*)calloc(Word_len_Max, sizeof(char));	//단어를 임시저장할 dynamic matrix allocation
	for (int i = 0; i < SIZE; i++)
	{
		strcpy(min, word_m[i]);	//초기 값을 min에 저장
		min_idx = i;	//초기 idx를 min_idx에 저장
		for (int left = i + 1; left < SIZE; left++)
		{
			if (strcmp(min, word_m[left]) > 0)	//min과 left값 비교후 left값이 작은경우 strcpy
			{
				strcpy(min, word_m[left]);
				min_idx = left;
			}
		}
		if (min_idx != i)	//min보다 작은 값이 존재하는 경우 swap
		{
			strcpy(word_m[min_idx], word_m[i]);
			strcpy(word_m[i], min);
		}
	}
	free(min);	//free memory
}