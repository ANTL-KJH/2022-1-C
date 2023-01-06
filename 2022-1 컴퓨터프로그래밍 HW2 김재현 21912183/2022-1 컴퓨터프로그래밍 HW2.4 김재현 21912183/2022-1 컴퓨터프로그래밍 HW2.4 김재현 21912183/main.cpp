/*
* 파일명 : "Number Sorter.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 1 ~ 32,765 범위의 정수를 입력받고
	 만, 천, 백, 십, 일의 단위로 값을 구분하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.09
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.09  v1.0	최초작성
* 김재현			2022.03.11	v1.1	가독성 개선
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
	printf("1~32,765 사이의 정수를 입력하시오 : ");
	scanf_s("%d", &input_number);

	ten_thousand = input_number / def_ten_thousand;
	thousand = (input_number - ten_thousand * def_ten_thousand) / def_thousand;
	hundred = (input_number - ten_thousand * def_ten_thousand - thousand * def_thousand) / def_hundred;
	ten = (input_number - ten_thousand * def_ten_thousand - thousand * def_thousand - hundred * def_hundred) / def_ten;
	one = (input_number - ten_thousand * def_ten_thousand - thousand * def_thousand - hundred * def_hundred - ten * def_ten);

	if (ten_thousand != 0)	//만의 자리가 0이면 아래 출력으로 이동
	{
		printf("%d : %d만 %d천 %d백 %d십 %d", input_number, ten_thousand, thousand, hundred, ten, one);
	}
	else
		if (thousand != 0)
			printf("%d : %d천 %d백 %d십 %d", input_number, thousand, hundred, ten, one);
		else
			if (hundred != 0)
				printf("%d : %d백 %d십 %d", input_number, hundred, ten, one);
			else
				if (ten != 0)
					printf("%d :%d십 %d", input_number, ten, one);
				else	//십의 자리까지 0이면 일의 자리만 출력
					printf("%d : %d", input_number, one);
	return 0;
}