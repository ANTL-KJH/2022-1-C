/*strings.cpp*/
#include "Std.h"
#include "str.h"

void Fgetwords(FILE* fin, char word_m[][Word_len_Max], int* w_len)	//get words from file
{
	int count = 0;
	char word[15];
	while (feof(fin) == 0)	//������ ���� �����ϸ� �ݺ� ����
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
	min = (char*)calloc(Word_len_Max, sizeof(char));	//�ܾ �ӽ������� dynamic matrix allocation
	for (int i = 0; i < SIZE; i++)
	{
		strcpy(min, word_m[i]);	//�ʱ� ���� min�� ����
		min_idx = i;	//�ʱ� idx�� min_idx�� ����
		for (int left = i + 1; left < SIZE; left++)
		{
			if (strcmp(min, word_m[left]) > 0)	//min�� left�� ���� left���� ������� strcpy
			{
				strcpy(min, word_m[left]);
				min_idx = left;
			}
		}
		if (min_idx != i)	//min���� ���� ���� �����ϴ� ��� swap
		{
			strcpy(word_m[min_idx], word_m[i]);
			strcpy(word_m[i], min);
		}
	}
	free(min);	//free memory
}