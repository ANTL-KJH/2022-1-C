/*
* ���ϸ� : "Find the day of week from 01.01.01.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� ��, ��, ���� �Է¹ް�
*    ���� 1�� 1�� 1�Ϸκ��� ���° ��¥������ ������ ã�� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.12
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.12  v1.0	�����ۼ�
* ������			2022.03.13	v1.1	����� ���� ���� ����
*/

#include <stdio.h>
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
const char* weekday_names[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int counting_days(int y, int m, int d);
int main(void)
{
	int year, month, day, result, day_of_week;
	printf("��, ��, ���� �Է��Ͻÿ�(ex.2022 03 12): ");
	scanf_s("%d %d %d", &year, &month, &day);
	result = counting_days(year, month, day);
	printf("%d�� %d�� %d���� ���� 1�� 1�� 1�Ϸ� ���� %d��° ���Դϴ�.\n", year, month, day, result);
	day_of_week = result % 7;	//���� ����
	printf("%d�� %d�� %d���� %s�Դϴ�.", year, month, day, weekday_names[day_of_week]);
	return 0;
}

int counting_days(int y, int m, int d)
{
	int count = 0, i;
	for (i = 1; i < y; i++)	//�Է��� ���� ���⵵���� ��¥�� ���
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			count = count + 366;
		else
			count = count + 365;
	}
	for (i = 1; i < m; i++)	//�Է��� ���� ���ޱ��� ��¥�� ���
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