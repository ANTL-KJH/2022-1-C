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

void calc_elapsed_time(Event* pEv, LARGE_INTEGER freq)	//Event ������ ó���� �ɸ��� �ð��� �����ϴ� �Լ�
{
	double t_diff_LL, t_elapsed;
	t_diff_LL = pEv->t_proc.QuadPart - pEv->t_gen.QuadPart;	//ó���ð� - �����ð�
	t_elapsed = t_diff_LL / (double)freq.QuadPart;
	pEv->t_elapsed = t_elapsed;
}