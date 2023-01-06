/* Event.cpp */
#include "STD.h"
#include "Event.h"

void printEvent(Event* pEvent)	//printout Event
{
	printf("Ev(no:%3d, pri:%2d) ", pEvent->event_no, pEvent->event_pri);
}

void printEvent_withTime(Event* pEv)	//printout Event with time
{
	printf("Ev(no:%3d, pri:%2d, %6.0lf[ms]) ", pEv->event_no, pEv->event_pri, pEv->t_elapsed * 1000);
}

void calc_elapsed_time(Event* pEv, LARGE_INTEGER freq)	//Event 생성과 처리에 걸리는 시간을 연산하는 함수
{
	double t_diff_LL, t_elapsed;
	t_diff_LL = pEv->t_proc.QuadPart - pEv->t_gen.QuadPart;	//처리시간 - 생성시간
	t_elapsed = t_diff_LL / (double)freq.QuadPart;
	pEv->t_elapsed = t_elapsed;
}