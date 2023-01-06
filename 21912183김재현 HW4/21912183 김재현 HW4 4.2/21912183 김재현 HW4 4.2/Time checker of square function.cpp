/*
* ���ϸ� : "Time checker of square function.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-�ݺ���, ����Լ� �ΰ��� ������� ���� �����ϴ� �Լ��� ����ð��� Ȯ���ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.23
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.23  v1.0	�����ۼ�
*/
#include <stdio.h>
#include <time.h>
#include <Windows.h>
double powerRecur(double base, int exponent);
double powerIter(double base, int exponent);
int main(void)
{
	time_t time_before, time_after;
	int t_diff;
	LONGLONG t_diff_pc;
	LARGE_INTEGER freq, t1, t2;
	double t_elapse_ms;
	double result_i, result_r;
	double base = 1.015; //���� 1.015

	QueryPerformanceFrequency(&freq); //frequency üũ
	for (int expo = 1000; expo <= 4000; expo += 1000)
	{
		time(&time_before);	//�Լ� ���� �� �ð�����
		QueryPerformanceCounter(&t1); //CPU ����Ƚ�� ����
		result_i = powerIter(base, expo);	//�ݺ����� ����� ��������
		QueryPerformanceCounter(&t2);	//�Լ� ������ ����Ƚ�� ����
		time(&time_after);	//�Լ� ���� �� �ð�����

		t_diff = difftime(time_after, time_before);	//�ð� ���� ����
		t_diff_pc = t2.QuadPart - t1.QuadPart;	//��Ȯ�� ������ ���� QuadPart���,
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 1000000;	//cpu ����Ƚ�� �� / frequency = ���� �ð�(sec) micro second ����
		printf("PowerItera(1.015, %d) by iterative = %40.5lf, took (%3d) sec, (% 10.2lf) micro - second\n", expo, result_i, t_diff, t_elapse_ms);
		
		time(&time_before);	//�Լ� ���� �� �ð�����
		QueryPerformanceCounter(&t1);
		result_r = powerRecur(base, expo);	//����Լ��� ����� ��������
		QueryPerformanceCounter(&t2);//�Լ� ���� �� �ð�����
		time(&time_after);
		t_diff = difftime(time_after, time_before);
		t_diff_pc = t2.QuadPart - t1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / freq.QuadPart) * 1000000;
		printf("PowerRecur(1.015, %d) by recursive = %40.5lf, took (%3d) sec, (% 10.2lf) micro - second\n", expo, result_r, t_diff, t_elapse_ms);
	}
	return 0;
}

double powerIter(double base, int exponent)	//�ݺ����� ����� �ŵ����� ����
{
	double result = 1;
	double stor = 0;
	for (int i = 0; i < exponent; i++)
	{
		stor = result;
		result = stor * base; //result�� base�� ���ϰ� ����
	}

	return result;
}

double powerRecur(double base, int exponent) //����Լ��� ����� �ŵ����� ����
{
	if (exponent == 0) // ������ 0�̸� ���� ����� 1
		return 1;

	return base * powerRecur(base, exponent - 1); //����Լ� ���(exponent�� 1�� ����)
}