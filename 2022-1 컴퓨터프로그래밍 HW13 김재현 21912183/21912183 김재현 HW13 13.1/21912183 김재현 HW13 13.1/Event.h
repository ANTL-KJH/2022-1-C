/* Event.h */
#ifndef EVENT_H
#define EVENT_H
#include "ConsoleDisplay.h"
#include "SimParams.h"
enum EventStatus { GENERATED, ENQUEUED, PROCESSED, UNDEFINED };
extern const char* strEventStatus[];
typedef struct
{
	int event_no;
	int event_gen_addr;	//Multi Thread Generator Address
	int event_handler_addr;	//Multi Thread Hnadler Address
	int event_pri; //event_priority
	LARGE_INTEGER t_gen;
	LARGE_INTEGER t_proc;
	double t_elapsed; //elapsed time for event processing
	EventStatus eventStatus;
} Event;
void printEvent(Event* pEvt);
void printEvent_withTime(Event* pEv);
void calc_elapsed_time(Event* pEv, LARGE_INTEGER freq);
#endif