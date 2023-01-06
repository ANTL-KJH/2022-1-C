/*
* 파일명 : "Charater sorter.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 문자를 입력받고 입력받은 문자를 구분하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.13
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.13  v1.0	최초작성
*/

#include <stdio.h>
#include <conio.h>
int main()
{
	char input_char = 0;
	//	char trash;
	while (input_char != 46)	//'.'마침표 기호가 오면 프로그램 반복 종료
	{
		printf("Input a character('.'을 입력하면 종료) : ");
		//scanf_s("%c", &input_char);
		//trash = getchar();
		input_char = _getch();
		if (input_char >= 33 && input_char <= 126)	//문자 영역
		{
			if (input_char >= 65 && input_char <= 90)
			{
				printf("a alphabet upper-case, ");
				if (input_char == 65 || input_char == 69 || input_char == 73 || input_char == 79 || input_char == 85)
					printf("vowel, ");
				else
					printf("consonant, ");
			}
			else if (input_char >= 97 && input_char <= 122)
			{
				printf("a alphabet lower-case, ");
				if (input_char == 97 || input_char == 101 || input_char == 105 || input_char == 111 || input_char == 118)
					printf("vowel, ");
				else
					printf("consonant, ");
			}
			else if (input_char >= 48 && input_char <= 57)
				printf("decimal number, ");
			else
				printf("symbol (not decimal number, not alphabet)");
		}
		else if (input_char == 10 || input_char == 13)//LF 또는 CR은 스킵(문자 입력시 버퍼에 LF(\n)이 남아 있음
		{
			printf("\n");
			continue;

		}

		else
			printf("Not character and symbol");
		printf("\n");
	}
	printf("프로그램을 종료합니다.");
	return 0;
}