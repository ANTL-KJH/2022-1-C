/*
* 파일명 : "Find max, min, avg with matrix.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 정수를 입력받고 최대, 최소, 평균값을 구하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.13
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.13  v1.0	최초작성
* 김재현			2022.03.18	v1.1	분산, 표준편차 추가
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
		max = (max > matrix[i]) ? max : matrix[i];	//최대값 연산
		min = (min < matrix[i]) ? min : matrix[i];	//최소값 연산
		sum = sum + matrix[i];
	}
	avg = sum / 10.0;
	for (i = 0; i < The_Number_Of_Input; i++)	//분산 연산
	{
		square_sum += pow(matrix[i] - avg, 2.0);
	}
	var = square_sum / The_Number_Of_Input;
	std = sqrt(var);
	printf("number of input data = %d, min = %d, max = %d, avg = %lf, var = %lf, std = %lf", The_Number_Of_Input, min, max, avg, var, std);
	return 0;
}