/*CirQ.cpp*/
#include "STD.h"
#include "CirQ_Event.h"
#include "Event.h"

CirQ_Event* initCirQ_Event(CirQ_Event* pCirQ, int capacity)	//cirQ 초기화
{
	Event* pEv;
	pEv = (Event*)calloc(capacity, sizeof(Event));	//dynamic memnory allocation
	if (pEv == NULL)
	{
		printf("Error in memory allocation for Event array of size (%d)\n", capacity);
		exit;
	}
	pCirQ->CirBuff_Ev = pEv;	//pEv 주소 전달
	pCirQ->capacity = capacity;
	pCirQ->front = pCirQ->end = 0;
	pCirQ->num_elements = 0;
	return pCirQ;
}

void printCirQ_Event(CirQ_Event* cirQ)
{
	Event ev;
	int index;
	if ((cirQ == NULL) || (cirQ->CirBuff_Ev == NULL))
	{
		printf("Error in printArrayQueue: pCirQ is NULL or pCirQ->array is NULL");
		exit;
	}
	printf(" %2d Elements in CirQ_Event (index_front:%2d) :\n ", cirQ->num_elements, cirQ->front);
	if (isCirQEmpty(cirQ))	//Queue가 비어있는 경우
	{
		printf("pCirQ_Event is Empty");
	}
	else
	{
		for (int i = 0; i < cirQ->num_elements; i++)	//요소 개수에 따라 event 전체 출력
		{
			index = cirQ->front + i;
			if (index >= cirQ->capacity)
				index = index % cirQ->capacity;
			ev = cirQ->CirBuff_Ev[index];
			printEvent(&ev);	//Event 출력
			if ((((i + 1) % EVENT_PER_LINE) == 0) && ((i + 1) != cirQ->num_elements))
				printf("\n ");
		}
	}
	printf("\n");
}

bool isCirQFull(CirQ_Event* cirQ)	//Queue가 Full 인지 Check
{
	if (cirQ->num_elements == cirQ->capacity)
		return true;
	else
		return false;
}
bool isCirQEmpty(CirQ_Event* cirQ)	//Queue가 비었는지 Check
{
	if (cirQ->num_elements == 0)
		return true;
	else
		return false;
}
Event* enCirQ_Event(CirQ_Event* cirQ, Event ev)	//Queue에 Event를 넣는 함수
{
	if (isCirQFull(cirQ))
	{
		return NULL;
	}
	cirQ->CirBuff_Ev[cirQ->end] = ev;
	cirQ->num_elements++;
	cirQ->end++;
	if (cirQ->end >= cirQ->capacity)	//end가 용량을 넘으면 앞으로 돌아간다.
		cirQ->end = cirQ->end % cirQ->capacity;
	return &(cirQ->CirBuff_Ev[cirQ->end]);
}
Event* deCirQ_Event(CirQ_Event* cirQ)	//Queue에서 Event를 out하는 하수
{
	if (isCirQEmpty(cirQ))
		return NULL;
	Event* pEv = &(cirQ->CirBuff_Ev[cirQ->front]);	//event 위치 반환
	cirQ->front++;	//front 증가
	if (cirQ->front >= cirQ->capacity)	//front가 용량 끝에 닿으면 앞으로 돌아간다.
		cirQ->front = cirQ->front % cirQ->capacity;
	cirQ->num_elements--;	//개수 감소
	return pEv;
}
void delCirQ_Event(CirQ_Event* cirQ)	//Queue Free
{
	if (cirQ->CirBuff_Ev != NULL)
		free(cirQ->CirBuff_Ev);
	cirQ->CirBuff_Ev = NULL;
	cirQ->capacity = 0;
	cirQ->front = cirQ->end = 0;
	cirQ->num_elements = 0;
}