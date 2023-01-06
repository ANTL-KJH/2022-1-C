/*Event.h*/
#ifndef EVENT_H
#define EVENT_H
#include <stdio.h>
#define EVENT_PER_LINE 5
extern const char* strEventStatus[];
enum EventStatus { GENERATED, ENQUEUED, PROCESSED, UNDEFINED };
typedef struct
{
	int Event_no;
	int Event_pri; // event_priority
	EventStatus eventStatus;
}Event;
void printEvent(Event* pEvt);
void fprintEvent(FILE* fout, Event* pEvent);
Event* genEvent(int event_no, int event_pri);
#endif