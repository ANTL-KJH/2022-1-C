/*
* ���ϸ� : "21912183 ������ HW10 10.1.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -���Ϸκ��� �ܾ �Է¹޾� �ܾ���� check�� sorting�ϰ� ���Ͽ� ����ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.05.14
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.05.14	v1.0	�����ۼ�
*/
#include "Std.h"
#include "str.h"
int main(void)
{
	FILE* fin, * fout;
	const char* WORDS = "words_input.txt";	//input file
	const char* WORDS_OUT = "words_output.txt";	//output file
	char words[SIZE][Word_len_Max];	//���Ϸκ��� �Է¹��� �ܾ ������ matrix
	int word_len[SIZE];	//�ܾ��� ���̸� ������ matrix
	fin = fopen(WORDS, "r");	//input file open
	if (fin == NULL)
	{
		printf("Error in file open - words_input.txt !!\n");
		exit(-1);
	}
	fout = fopen(WORDS_OUT, "w");	//output file open
	if (fout == NULL)
	{
		printf("Error in file open - words_output.txt !!\n");
		exit(-1);
	}
	Fgetwords(fin, words, word_len);	//get words from file
	for (int i = 0; i < SIZE; i++)	//printout
	{
		printf("(%2d)th-word : %15s (word_length:%2d)\n", i, words[i], word_len[i]);
		fprintf(fout, "(%2d)th-word : %15s (word_length:%2d)\n", i, words[i], word_len[i]);
	}
	sorting_word(words);	//sorting words
	for (int i = 0; i < SIZE; i++)	//printout
	{
		printf("%9s", words[i]);
		fprintf(fout, "%9s", words[i]);
		if (i == 4)
		{
			printf("\n");
			fprintf(fout, "\n");
		}
	}
	fclose(fin);	//file close
	fclose(fout);
	return 0;
}