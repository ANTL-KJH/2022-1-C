/*
* 파일명 : "calculator for area and circumference of square.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 직사각형의 가로와 세로를 입력받고 을 계산하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.04
* =====================================================================================================
* 프로그램 수정/보완 이력
* =====================================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.04  v1.0	최초작성
*/
#include <stdio.h>
int main()
{
	double width = 0.0, length = 0.0;
	double circum = 0.0, area = 0.0;	//circum은 둘레를 뜻함
	printf("직사각형의 가로(width)와 세로(length)를 입력하시오:");
	scanf_s("%lf %lf", &width, &length);
	area = width * length;	//area 연산
	circum = 2.0 * width + 2.0 * length;	//circum 연산
	printf("직사각형의 넓이:%.2lf\n직사각형의 둘레:%.2lf\n", area, circum);
	printf("해당 결과는 소수점 셋째 자리에서 반올림되었습니다.");
	return 0;
}