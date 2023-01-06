/*
* 파일명 : "calculator for area and circumference of right triangle.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 직각삼각형의 가로와 세로를 입력받고 넓이와 둘레를 계산하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.04
* =====================================================================================================
* 프로그램 수정/보완 이력
* =====================================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.04  v1.0	최초작성
*/
#include <stdio.h>
#include <math.h>
int main()
{
	double base = 0.0, height = 0.0;
	double area = 0.0, circum = 0.0;	//둘레는 circumference
	double hypo = 0.0;	//빗변은 hypotenuse
	printf("직각삼각형의 밑변(base)과 높이(height)를 입력하시오:");
	scanf_s("%lf %lf", &base, &height);
	area = 0.5 * base * height;
	hypo = sqrt(pow(base, 2) + pow(height, 2));	//sqrt와 pow는 각각 math.h에 포함된 함수로 루트, 제곱 연산을 함
	circum = base + height + hypo;
	printf("직각삼각형의 넓이:%.2lf\n직각삼각형의 둘레:%.2lf\n", area, circum);
	printf("해당 결과는 소수점 셋째 자리에서 반올림되었습니다.");
	return 0;
}