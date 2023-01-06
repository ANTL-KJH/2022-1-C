/*Time.cpp*/
#include "StdH.h"
#include "Time.h"

Time inputTime()	//�ð� �Է��ϴ� �Լ�
{
	Time T_in;
	do
	{
		printf("input hour minute sec : ");
		scanf("%d %d %d", &T_in.hour, &T_in.min, &T_in.sec);
		if ((T_in.hour < 0 || T_in.hour > 23) || (T_in.min < 0 || T_in.min > 59) || (T_in.sec < 0 || T_in.sec > 59))
			printf("Wrong Input!!\n");
	} while ((T_in.hour < 0 || T_in.hour > 23) || (T_in.min < 0 || T_in.min > 59) || (T_in.sec < 0 || T_in.sec > 59));	//���ǿ� ���� �ʴ� ��� �ݺ�
	return T_in;
}

void printTime(const Time* t)	//�ð� ����Լ�
{
	printf("(%02d:%02d:%02d)", t->hour, t->min, t->sec);
}

void incrementTime(Time* t, int incr_sec)	//�Էµ� sec�� ���ϴ� �Լ�
{
	t->sec += incr_sec;
	if (t->sec >= MIN)	//sec�� 60�̻��� ���
	{
		t->min = t->min + (t->sec / MIN);
		t->sec = t->sec % MIN;
		if (t->min >= MIN)	//min�� 60�̻��� ���
		{
			t->hour = t->hour + t->min / MIN;
			t->min = t->min % MIN;
			if (t->hour >= 24)	//hour�� 24�̻��� ���
			{
				t->hour = t->hour % 24;
			}
		}
	}
}
int convert_to_Sec(const Time* t)	//�ð��� �ʷ� ȯ��
{
	int rtrn_sec;
	rtrn_sec = t->hour * HOUR + t->min * MIN + t->sec;
	return rtrn_sec;
}

int compareTime(const Time* t1, const Time* t2)
{
	int sec_t1, sec_t2, result;
	sec_t1 = convert_to_Sec(t1);
	sec_t2 = convert_to_Sec(t2);
	if (sec_t2 >= sec_t1)
	{
		result = sec_t2 - sec_t1;
	}
	else	//t1�� �ð��� �� ū��� 24�ð��� �ʰ��� ������ �Ǵ� 24�ð� ���� �� ����
	{
		result = (sec_t2 + 24 * HOUR) - sec_t1;
	}
	return result;
}

Time initTime(int h, int m, int s)	//�迭�� �ð� �Է�
{
	Time t;
	t.hour = h;
	t.min = m;
	t.sec = s;
	return t;
}

void selectSortTime(Time* times, int size)	//�ð��� ���� ��������
{
	Time* min;
	Time temp;
	int min_idx;
	for (int i = 0; i < size; i++)
	{
		min = &times[i];
		min_idx = i;
		for (int left = i + 1; left < size; left++)
		{
			if (convert_to_Sec(min) > convert_to_Sec(&times[left]))	//�� ����� sec ������ convert�Ͽ� ��
			{
				min_idx = left;
			}
		}
		temp = times[i];
		times[i] = times[min_idx];
		times[min_idx] = temp;
	}
}