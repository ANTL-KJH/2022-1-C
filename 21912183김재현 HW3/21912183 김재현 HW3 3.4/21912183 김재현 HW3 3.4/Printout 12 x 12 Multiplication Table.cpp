/*
* 파일명 : "Printout 12 x 12 Multiplication Table.cpp"
* 프로그램의 목적 및 기본 기능:
*	-중첩 for문을 이용하여 12 x 12 Multiplication Table을 출력하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.13
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.13  v1.0	최초작성
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
		else	//Multiplication Table 1,2번째 줄을 제외한 나머지는 같은 출력의 반복
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