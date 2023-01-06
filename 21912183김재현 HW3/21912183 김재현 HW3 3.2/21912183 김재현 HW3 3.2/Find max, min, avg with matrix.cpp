/*
* ���ϸ� : "Find max, min, avg with matrix.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� ������ �Է¹ް� �ִ�, �ּ�, ��հ��� ���ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.13
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.13  v1.0	�����ۼ�
* ������			2022.03.18	v1.1	�л�, ǥ������ �߰�
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>
#define The_Number_Of_Input 10
int main(void)
{
	int matrix[10], i = 0, max = INT_MIN, min = INT_MAX, sum = 0;
	double avg = 0.0, square_sum = 0.0, var = 0.0, std = 0.0;
	printf("input 10 integer data : ");
	for (i = 0; i < The_Number_Of_Input; i++)
		scanf_s("%d", &matrix[i]);
	for (i = 0; i < The_Number_Of_Input; i++)
		printf("%d ", matrix[i]);
	printf("\n");
	for (i = 0; i < The_Number_Of_Input; i++)
	{
		max = (max > matrix[i]) ? max : matrix[i];	//�ִ밪 ����
		min = (min < matrix[i]) ? min : matrix[i];	//�ּҰ� ����
		sum = sum + matrix[i];
	}
	avg = sum / 10.0;
	for (i = 0; i < The_Number_Of_Input; i++)	//�л� ����
	{
		square_sum += pow(matrix[i] - avg, 2.0);
	}
	var = square_sum / The_Number_Of_Input;
	std = sqrt(var);
	printf("number of input data = %d, min = %d, max = %d, avg = %lf, var = %lf, std = %lf", The_Number_Of_Input, min, max, avg, var, std);
	return 0;
}