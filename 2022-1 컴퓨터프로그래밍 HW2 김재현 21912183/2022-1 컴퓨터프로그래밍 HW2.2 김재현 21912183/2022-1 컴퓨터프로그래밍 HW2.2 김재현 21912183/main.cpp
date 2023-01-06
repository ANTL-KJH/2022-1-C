/*
* 파일명 : "Time converter.cpp"
* 프로그램의 목적 및 기본 기능:
*	-표준 입력장치(key board)로부터 초(sec)단위의 시간을 입력받고 시간, 분, 초 형태로 변환하는 프로그램
* 프로그램 작성자:김재현(2191283)
* 최초 프로그램 작성일:2022.03.09
* =====================================================================================================
* 프로그램 수정/보완 이력
* =====================================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.03.09  v1.0	최초작성
* 김재현			2022.03.11	v1.1	변수 수정
*/
#include <stdio.h>
#define HOUR_3600 3600
#define MINUTE_60 60
int main()
{
	int input_second = 0;
	int time_sec = 0;
	int time_min = 0;
	int time_hour = 0;
	printf("초(sec)단위로 시간을 입력하시오:");
	scanf_s("%d", &input_second);
	time_sec = input_second % MINUTE_60;	//주어진 시간을 60으로 남은 나머지는 초에 해당함
	time_hour = input_second / 3600;	//주어진 시간을 3600으로 나눈 몫은 시간에 해당함
	time_min = (input_second - (time_hour * HOUR_3600)) / MINUTE_60;	//주어진 시간에서 시간을 빼고 60으로 나눈 몫은 분에 해당함
	printf("%d초는 %d시간 %d분 %d초입니다.", input_second, time_hour, time_min, time_sec);
	return 0;
}