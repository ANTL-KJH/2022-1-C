/*
* 파일명 : "calculator for volume and surface area of cylinder.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 원기둥의 반지름, 높이를 입력받고 체적과 표면적을 계산하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.05
* =====================================================================================================
* 프로그램 수정/보완 이력
* =====================================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.05  v1.0	최초작성
*/

#include <stdio.h>
#define PI 3.141592
int main(void)
{
	double radius = 0.0, height = 0.0;
	double volume = 0.0, surface = 0.0;
	printf("원기둥의 반지름(radius)과 높이(height)를 입력하시오:");
	scanf_s("%lf %lf", &radius, &height);
	volume = PI * radius * radius * height;
	surface = 2 * PI * radius * radius + 2 * PI * radius * height;
	printf("원기둥의 체적:%.2lf\n원기둥의 표면적:%.2lf\n", volume, surface);	//결과값은 소수점 둘째 자리까지 출력
	printf("해당 결과는 소수점 셋째 자리에서 반올림되었습니다.");
	return 0;
}