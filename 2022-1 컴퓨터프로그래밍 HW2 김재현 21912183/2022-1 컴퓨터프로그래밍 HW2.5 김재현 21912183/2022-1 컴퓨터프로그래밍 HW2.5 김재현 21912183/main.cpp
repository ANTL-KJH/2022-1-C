/*
* 파일명 : "Find the day of week from 01.01.01.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 년, 월, 일을 입력받고
*    서기 1년 1월 1일로부터 몇번째 날짜인지와 요일을 찾는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.12
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.12  v1.0	최초작성
* 김재현			2022.03.13	v1.1	연산시 논리적 오류 수정
*/

#include <stdio.h>
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
const char* weekday_names[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int counting_days(int y, int m, int d);
int main(void)
{
	int year, month, day, result, day_of_week;
	printf("년, 월, 일을 입력하시오(ex.2022 03 12): ");
	scanf_s("%d %d %d", &year, &month, &day);
	result = counting_days(year, month, day);
	printf("%d년 %d월 %d일은 서기 1년 1월 1일로 부터 %d번째 날입니다.\n", year, month, day, result);
	day_of_week = result % 7;	//요일 연산
	printf("%d년 %d월 %d일은 %s입니다.", year, month, day, weekday_names[day_of_week]);
	return 0;
}

int counting_days(int y, int m, int d)
{
	int count = 0, i;
	for (i = 1; i < y; i++)	//입력한 년의 전년도까지 날짜를 계산
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			count = count + 366;
		else
			count = count + 365;
	}
	for (i = 1; i < m; i++)	//입력한 달의 전달까지 날짜를 계산
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			count = count + 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			count = count + 30;
			break;
		case 2:
			if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
			{
				count = count + 29;
				break;
			}
			else
			{
				count = count + 28;
				break;
			}
		}

	}
	for (i = 0; i < d; i++)
		count++;
	return count;
}