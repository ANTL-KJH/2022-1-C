/*
* ���ϸ� : "21912183������ HW9 9.2.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -�ð�, ��, �ʷ� �������� �ð��� �Է¹ް� �����ϴ� �ð� ����� ������ �ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.05.09
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.05.09	v1.0	�����ۼ�
*/
#include "StdH.h"
#include "Time.h"

int main(void)
{
	Time t1, t2;
	Time times[NUM_TIMES];	//Time ����ü �迭 ����
	int incr_secs, diff_sec;
	t1 = t2 = inputTime();	//time �Է�
	printf("Input time t1 = "); printTime(&t1); printf("\n");
	printf("input seconds to increment : ");
	scanf("%d", &incr_secs);	//������ų sec �Է�
	incrementTime(&t2, incr_secs);	//�ð� ���� �� ����
	printf("After incrementing %d secs, t2 = ", incr_secs); printTime(&t2); printf("\n");
	diff_sec = compareTime(&t1, &t2);	//t1�� t2 ��
	printf("Difference between t1 and t2 is %d secs\n", diff_sec);	//�ð� ���� ���
	times[0] = initTime(23, 59, 59);	//times �迭 �Է�
	times[1] = initTime(9, 0, 5);
	times[2] = initTime(13, 30, 0);
	times[3] = initTime(3, 59, 59);
	times[4] = initTime(0, 0, 0);
	printf("\nBefore sorting times : \n");
	for (int i = 0; i < NUM_TIMES; i++)
	{
		printf("times[%d] = ", i); printTime(&times[i]); printf("\n");
	}
	selectSortTime(times, NUM_TIMES);	//times ����
	printf("After selection sorting of times : \n");
	for (int i = 0; i < NUM_TIMES; i++)
	{
		printf("times[%d] = ", i); printTime(&times[i]); printf("\n");
	}
	return 0;
}