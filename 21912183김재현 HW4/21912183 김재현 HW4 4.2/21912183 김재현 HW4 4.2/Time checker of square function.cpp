/*
* 파일명 : "Time checker of square function.cpp"
* 프로그램의 목적 및 기본 기능:
*	-반복문, 재귀함수 두가지 방법으로 제곱 연산하는 함수의 실행시간을 확인하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.23
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.23  v1.0	최초작성
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
	double base = 1.015; //밑은 1.015

	QueryPerformanceFrequency(&freq); //frequency 체크
	for (int expo = 1000; expo <= 4000; expo += 1000)
	{
		time(&time_before);	//함수 실행 전 시간측정
		QueryPerformanceCounter(&t1); //CPU 연산횟수 측정
		result_i = powerIter(base, expo);	//반복문을 사용한 제곱연산
		QueryPerformanceCounter(&t2);	//함수 종료후 연산횟수 측정
		time(&time_after);	//함수 실행 후 시간측정

		t_diff = difftime(time_after, time_before);	//시간 차이 연산
		t_diff_pc = t2.QuadPart - t1.QuadPart;	//정확한 연산을 위해 QuadPart사용,
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 1000000;	//cpu 연산횟수 차 / frequency = 연산 시간(sec) micro second 단위
		printf("PowerItera(1.015, %d) by iterative = %40.5lf, took (%3d) sec, (% 10.2lf) micro - second\n", expo, result_i, t_diff, t_elapse_ms);
		
		time(&time_before);	//함수 실행 전 시간측정
		QueryPerformanceCounter(&t1);
		result_r = powerRecur(base, expo);	//재귀함수를 사용한 제곱연산
		QueryPerformanceCounter(&t2);//함수 실행 후 시간측정
		time(&time_after);
		t_diff = difftime(time_after, time_before);
		t_diff_pc = t2.QuadPart - t1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / freq.QuadPart) * 1000000;
		printf("PowerRecur(1.015, %d) by recursive = %40.5lf, took (%3d) sec, (% 10.2lf) micro - second\n", expo, result_r, t_diff, t_elapse_ms);
	}
	return 0;
}

double powerIter(double base, int exponent)	//반복문을 사용한 거듭제곱 연산
{
	double result = 1;
	double stor = 0;
	for (int i = 0; i < exponent; i++)
	{
		stor = result;
		result = stor * base; //result에 base를 곱하고 저장
	}

	return result;
}

double powerRecur(double base, int exponent) //재귀함수를 사용한 거듭제곱 연산
{
	if (exponent == 0) // 지수가 0이면 연산 결과는 1
		return 1;

	return base * powerRecur(base, exponent - 1); //재귀함수 사용(exponent를 1씩 줄임)
}