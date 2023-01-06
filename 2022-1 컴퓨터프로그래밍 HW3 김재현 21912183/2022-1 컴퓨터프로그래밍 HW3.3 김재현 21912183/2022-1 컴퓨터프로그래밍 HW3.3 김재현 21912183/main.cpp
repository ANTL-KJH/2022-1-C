/*
* ���ϸ� : "Printout calendar.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� year�� month�� �Է¹ް� �޷��� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.13
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.13  v1.0	�����ۼ�
*/

#include <stdio.h>
#include <stdbool.h>
#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7
#define MONTHS_PER_YEAR 12
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };	//������ ���� enum�� ����� ���� ���� SUN = 0
enum MONTH { JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };	//������ ���� enum�� ����� �� �̸� ���� JAN = 1
const char* weekDayName[DAYS_PER_WEEK] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[MONTHS_PER_YEAR + 1] = { "", "January", "February",
"March", "April","May", "June", "July", "August", "September", "October", "November", "December" };
bool isLeapYear(int leap_year);	//�������� Ȯ���ϴ� �Լ� �����̸� true ��ȯ
int getDaysFromJan01AD01(int year, int month, int d);
void printCalendar(int year, int month);
int main(void)
{
	int input_year = 0, input_month = 0;
	do
	{
		printf("Input year (0 to quit) and month for print_calendar() : ");
		scanf_s("%d %d", &input_year, &input_month);
		if (input_year == 0)
		{
			printf("���α׷��� �����մϴ�.");
			return 0;
		}
		printCalendar(input_year, input_month);
	} while (input_year != 0 && (input_month >= 1 && input_month <= 12));
}
void printCalendar(int year, int month)
{
	int weekDay;
	int daysFromJan01AD01 = 0;
	int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	daysFromJan01AD01 = getDaysFromJan01AD01(year, month, 1);
	weekDay = (daysFromJan01AD01 - 1 + WEEKDAY_AD01Jan01) % DAYS_PER_WEEK;	//�Է¹��� ���� 1���� ���� ����
	//01�� 01�� 01���� �������̹Ƿ� WEEKDAY_AD01JAN01�� ���ϰ� 01.01.01(������)�� ī���� �Ǿ����Ƿ� 1�� ����
	if (isLeapYear(year))
		daysInMonth[2] = 29;
	printf(">>>>>>> %s of %d <<<<<<<<\n", monthName[month], year);
	printf("=====================================\n");
	for (int wk = SUN; wk <= SAT; wk++)
	{
		printf("%5s", weekDayName[wk]);
	}
	printf("\n-------------------------------------\n");
	for (int blank = 0; blank < weekDay; blank++)
	{
		printf("     ");
	}
	for (int day = 1; day <= daysInMonth[month]; day++)
	{
		printf("%5d", day);
		weekDay++;
		if (weekDay == 7)
		{
			if (day != daysInMonth[month])	//������ ���� ������� ��� �ٹٲ� ���� ��� ����
				printf("\n");
			weekDay = 0;
		}
	}
	printf("\n-------------------------------------\n");
}

int getDaysFromJan01AD01(int year, int month, int d)
{
	int daysFromAD01Jan01 = 0;
	int daysInYear;
	int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;
	for (int y = 1; y < year; y++)
	{
		daysInYear = isLeapYear(y) ? 366 : 365;
		daysFromAD01Jan01 += daysInYear;
	}
	if (isLeapYear(year))
		daysInMonth[2] = 29;
	for (int m = 1; m < month; m++)
	{
		daysFromAD01Jan01 += daysInMonth[m];
	}
	daysFromAD01Jan01 += d;
	return daysFromAD01Jan01;
}

bool isLeapYear(int leap_year)
{
	if ((leap_year % 4 == 0 && leap_year % 100 != 0) || leap_year % 400 == 0)
		return true;
	else
		return false;
}