/*
* ���ϸ� : "Charater sorter.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� ���ڸ� �Է¹ް� �Է¹��� ���ڸ� �����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.13
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.13  v1.0	�����ۼ�
*/

#include <stdio.h>
#include <conio.h>
int main()
{
	char input_char = 0;
	//	char trash;
	while (input_char != 46)	//'.'��ħǥ ��ȣ�� ���� ���α׷� �ݺ� ����
	{
		printf("Input a character('.'�� �Է��ϸ� ����) : ");
		//scanf_s("%c", &input_char);
		//trash = getchar();
		input_char = _getch();
		if (input_char >= 33 && input_char <= 126)	//���� ����
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
		else if (input_char == 10 || input_char == 13)//LF �Ǵ� CR�� ��ŵ(���� �Է½� ���ۿ� LF(\n)�� ���� ����
		{
			printf("\n");
			continue;

		}

		else
			printf("Not character and symbol");
		printf("\n");
	}
	printf("���α׷��� �����մϴ�.");
	return 0;
}