/*
* 파일명 : "21912183김재현 HW9 9.2.sln"
* 프로그램의 목적 및 기본 기능 :
* -시간, 분, 초로 나누어진 시간을 입력받고 증가하는 시간 연산과 정렬을 하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.05.09
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.05.09	v1.0	최초작성
*/
#include "StdH.h"
#include "Time.h"

int main(void)
{
	Time t1, t2;
	Time times[NUM_TIMES];	//Time 구조체 배열 선언
	int incr_secs, diff_sec;
	t1 = t2 = inputTime();	//time 입력
	printf("Input time t1 = "); printTime(&t1); printf("\n");
	printf("input seconds to increment : ");
	scanf("%d", &incr_secs);	//증가시킬 sec 입력
	incrementTime(&t2, incr_secs);	//시간 증가 및 연산
	printf("After incrementing %d secs, t2 = ", incr_secs); printTime(&t2); printf("\n");
	diff_sec = compareTime(&t1, &t2);	//t1과 t2 비교
	printf("Difference between t1 and t2 is %d secs\n", diff_sec);	//시간 차이 출력
	times[0] = initTime(23, 59, 59);	//times 배열 입력
	times[1] = initTime(9, 0, 5);
	times[2] = initTime(13, 30, 0);
	times[3] = initTime(3, 59, 59);
	times[4] = initTime(0, 0, 0);
	printf("\nBefore sorting times : \n");
	for (int i = 0; i < NUM_TIMES; i++)
	{
		printf("times[%d] = ", i); printTime(&times[i]); printf("\n");
	}
	selectSortTime(times, NUM_TIMES);	//times 정렬
	printf("After selection sorting of times : \n");
	for (int i = 0; i < NUM_TIMES; i++)
	{
		printf("times[%d] = ", i); printTime(&times[i]); printf("\n");
	}
	return 0;
}