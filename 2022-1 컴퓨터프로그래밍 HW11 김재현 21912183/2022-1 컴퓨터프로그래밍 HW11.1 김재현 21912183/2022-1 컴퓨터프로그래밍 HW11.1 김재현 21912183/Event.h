/* Event.h */
#ifndef EVENT_H
#define EVENT_H
#include <stdio.h>
enum EventStatus { GENERATED, ENQUEUED, PROCESSED, UNDEFINED };
typedef struct
{
	int event_no;
	int event_gen_addr;
	int event_handler_addr;
	int event_pri; // event_priority
	EventStatus eventStatus;
} Event;
#define MAX_EVENTS_PER_ROUND 10
#define TOTAL_NUM_EVENTS 128
#define EVENT_PER_LINE 5
#define MAX_ROUND 50
#define CIRQUEUE_CAPACITY 10
void printEvent(Event* ev);
void fprintEvent(FILE* fout, Event* ev);
Event* genEvent(int ev_no, int ev_pri);
#endif
