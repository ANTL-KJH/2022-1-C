/*
* 파일명 : "21912183 김재현 HW10 10.1.sln"
* 프로그램의 목적 및 기본 기능 :
* -파일로부터 단어를 입력받아 단어길이 check및 sorting하고 파일에 출력하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.05.14
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.05.14	v1.0	최초작성
*/
#include "Std.h"
#include "str.h"
int main(void)
{
	FILE* fin, * fout;
	const char* WORDS = "words_input.txt";	//input file
	const char* WORDS_OUT = "words_output.txt";	//output file
	char words[SIZE][Word_len_Max];	//파일로부터 입력받은 단어를 저장할 matrix
	int word_len[SIZE];	//단어의 길이를 저장할 matrix
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