/*
* 파일명 : "Real number calculator.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 double 형태의 실수 2개를 입력받고
	 덧셈, 뺄셈, 곱셈, 나눗셈의 결과를 출력하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.09
* =====================================================================================================
* 프로그램 수정/보완 이력
* =====================================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.09  v1.0	최초작성
*/
#include <stdio.h>
int main()
{
	double input_number_1 = 0.0;
	double input_number_2 = 0.0;
	double sum = 0.0, minus = 0.0;
	double multiplication = 0.0, division = 0.0;
	printf("첫 번째 실수를 입력하시오 : ");	//실수 1 입력
	scanf_s("%lf", &input_number_1);
	printf("두 번째 실수를 입력하시오 : ");	//실수 2 입력
	scanf_s("%lf", &input_number_2);

	sum = input_number_1 + input_number_2;
	minus = input_number_1 - input_number_2;
	multiplication = input_number_1 * input_number_2;
	division = input_number_1 / input_number_2;

	printf("계산값 출력(소수점 둘째 자리 이하 생략)\n");	//출력 시작
	printf("덧셈 : %lf + %lf = %.2lf\n", input_number_1, input_number_2, sum);
	printf("뺄셈 : %lf - %lf = %.2lf\n", input_number_1, input_number_2, minus);
	printf("곱셈 : %lf * %lf = %.2lf\n", input_number_1, input_number_2, multiplication);
	printf("나눗셈 : %lf / %lf = %.2lf\n", input_number_1, input_number_2, division);
	return 0;
}