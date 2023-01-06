/*Event.cpp*/
#include "STD.h"
#include "Event.h"

void printEvent(Event* pEvent)	//print Event
{
	printf("Ev(no:%3d, pri:%2d) ", pEvent->Event_no, pEvent->Event_pri);
}
void fprintEvent(FILE* fout, Event* pEvent)	//printout Event at File
{
	fprintf(fout, "Ev(no:%3d, pri:%2d) ", pEvent->Event_no, pEvent->Event_pri);
}
Event* genEvent(int event_no, int event_pri)	//generate Event
{
	Event* pEvent;
	pEvent = (Event*)malloc(sizeof(Event));
	pEvent->Event_no = event_no;	//�̺�Ʈ ��ȣ
	pEvent->Event_pri = event_pri;	//�̺�Ʈ �켱����
	return pEvent;
}