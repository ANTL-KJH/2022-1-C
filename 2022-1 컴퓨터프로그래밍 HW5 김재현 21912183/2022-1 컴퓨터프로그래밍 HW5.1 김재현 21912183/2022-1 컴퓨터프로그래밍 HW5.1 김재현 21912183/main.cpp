/*
* 파일명 : "main.cpp"
* 프로그램의 목적 및 기본 기능:
* -다중소스와 헤더파일을 이용하여 다양한 도형을 그리는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.04.03
* ======================================================================================
* 프로그램 수정/보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.04.03  v1.0	최초작성
*/
#include "draw_shape.h"
int main(void)
{
	int width = 20;
	int length = 10;
	printf("Drawing a rectangle of width = %d, length = %d\n", width, length);
	draw_rectangle(width, length);	//사각형 출력함수
	int base = 10;
	printf("Drawing a right triangle of base = %d\n", base);
	draw_right_triangle(base);	//직각삼각형 출력함수
	printf("Drawing a reversed right triangle of base = %d\n", base);
	draw_reverse_right_triangle(base);	//역 직각삼각형 출력함수
	width = 21;
	printf("Drawing a diamond of width = %d\n", width);
	draw_diamond(width);	//다이아 출력함수
	return 0;
}