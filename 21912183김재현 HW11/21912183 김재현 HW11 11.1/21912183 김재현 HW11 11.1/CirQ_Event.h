/* CirQ_Event.h */
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include "Event.h"#pragma once
typedef struct
{
	Event* CirBuff_Ev; // circular queue for events
	int capacity;
	int front;
	int end;
	int num_elements;
} CirQ_Event;
CirQ_Event* initCirQ_Event(CirQ_Event* pCirQ, int capacity);
void printCirQ_Event(CirQ_Event* cirQ);
bool isCirQFull(CirQ_Event* cirQ);
bool isCirQEmpty(CirQ_Event* cirQ);
Event* enCirQ_Event(CirQ_Event* cirQ, Event ev);
Event* deCirQ_Event(CirQ_Event* cirQ);
void delCirQ_Event(CirQ_Event* cirQ);
#endif