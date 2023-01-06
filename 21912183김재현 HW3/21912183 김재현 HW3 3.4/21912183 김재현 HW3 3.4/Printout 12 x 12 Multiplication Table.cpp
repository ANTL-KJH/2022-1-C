/*
* ���ϸ� : "Printout 12 x 12 Multiplication Table.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-��ø for���� �̿��Ͽ� 12 x 12 Multiplication Table�� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.13
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.13  v1.0	�����ۼ�
*/

#include <stdio.h>
#define Limits 12
int main(void)
{
	int i = 0, o = 0;
	printf(">>> 12 x 12 Multiplication Table <<<\n\n");
	for (i = 0; i < Limits + 2; i++)
	{
		if (i == 0)
		{
			printf("    |");
		}
		else if (i == 1)
		{
			printf("====+");
		}
		else	//Multiplication Table 1,2��° ���� ������ �������� ���� ����� �ݺ�
			printf("%3d |", i - 1);
		for (o = 1; o <= Limits; o++)
		{
			if (i == 0)
			{
				printf("%5d", o);
			}
			else if (i == 1)
			{
				printf("=====");
			}
			else
				printf("%5d", (i - 1) * o);
		}
		printf("\n");
	}
	return 0;
}