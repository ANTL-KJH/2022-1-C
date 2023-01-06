/*Event.cpp*/
#include "STD.h"
#include "Event.h"

void printEvent(Event* pEvent)	//print Event
{
	printf("Ev(no:%3d, pri:%2d) ", pEvent->event_no, pEvent->event_pri);
}
void fprintEvent(FILE* fout, Event* pEvent)	//printout Event at File
{
	fprintf(fout, "Ev(no:%3d, pri:%2d) ", pEvent->event_no, pEvent->event_pri);
}
Event* genEvent(int event_no, int event_pri)	//generate Event
{
	Event* GenEvent;
	GenEvent = (Event*)malloc(sizeof(Event));
	if (GenEvent == NULL)
		return NULL;
	GenEvent->event_no = event_no;	//이벤트 번호
	GenEvent->event_pri = event_pri;	//이벤트 우선순위
	return GenEvent;
}