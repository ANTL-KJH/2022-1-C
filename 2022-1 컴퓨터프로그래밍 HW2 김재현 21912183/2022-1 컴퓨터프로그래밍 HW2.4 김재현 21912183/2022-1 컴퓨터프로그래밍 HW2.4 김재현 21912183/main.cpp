/*
* ���ϸ� : "Number Sorter.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� 1 ~ 32,765 ������ ������ �Է¹ް�
	 ��, õ, ��, ��, ���� ������ ���� �����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.09
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.09  v1.0	�����ۼ�
* ������			2022.03.11	v1.1	������ ����
*/

#include <stdio.h>
#define def_ten_thousand 10000
#define def_thousand 1000
#define def_hundred 100
#define def_ten 10
int main()
{
	int input_number = 0;
	int ten_thousand = 0;
	int thousand = 0;
	int hundred = 0;
	int ten = 0;
	int one = 0;
	printf("1~32,765 ������ ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &input_number);

	ten_thousand = input_number / def_ten_thousand;
	thousand = (input_number - ten_thousand * def_ten_thousand) / def_thousand;
	hundred = (input_number - ten_thousand * def_ten_thousand - thousand * def_thousand) / def_hundred;
	ten = (input_number - ten_thousand * def_ten_thousand - thousand * def_thousand - hundred * def_hundred) / def_ten;
	one = (input_number - ten_thousand * def_ten_thousand - thousand * def_thousand - hundred * def_hundred - ten * def_ten);

	if (ten_thousand != 0)	//���� �ڸ��� 0�̸� �Ʒ� ������� �̵�
	{
		printf("%d : %d�� %dõ %d�� %d�� %d", input_number, ten_thousand, thousand, hundred, ten, one);
	}
	else
		if (thousand != 0)
			printf("%d : %dõ %d�� %d�� %d", input_number, thousand, hundred, ten, one);
		else
			if (hundred != 0)
				printf("%d : %d�� %d�� %d", input_number, hundred, ten, one);
			else
				if (ten != 0)
					printf("%d :%d�� %d", input_number, ten, one);
				else	//���� �ڸ����� 0�̸� ���� �ڸ��� ���
					printf("%d : %d", input_number, one);
	return 0;
}