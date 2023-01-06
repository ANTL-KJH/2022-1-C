/*CirQ.cpp*/
#include "STD.h"
#include "CirQ_Event.h"
#include "Event.h"

CirQ_Event* initCirQ_Event(CirQ_Event* pCirQ, int capacity)	//cirQ �ʱ�ȭ
{
	Event* pEv;
	pEv = (Event*)calloc(capacity, sizeof(Event));	//dynamic memnory allocation
	if (pEv == NULL)
	{
		printf("Error in memory allocation for Event array of size (%d)\n", capacity);
		exit;
	}
	pCirQ->CirBuff_Ev = pEv;	//pEv �ּ� ����
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
	if (isCirQEmpty(cirQ))	//Queue�� ����ִ� ���
	{
		printf("pCirQ_Event is Empty");
	}
	else
	{
		for (int i = 0; i < cirQ->num_elements; i++)	//��� ������ ���� event ��ü ���
		{
			index = cirQ->front + i;
			if (index >= cirQ->capacity)
				index = index % cirQ->capacity;
			ev = cirQ->CirBuff_Ev[index];
			printEvent(&ev);	//Event ���
			if ((((i + 1) % EVENT_PER_LINE) == 0) && ((i + 1) != cirQ->num_elements))
				printf("\n ");
		}
	}
	printf("\n");
}

bool isCirQFull(CirQ_Event* cirQ)	//Queue�� Full ���� Check
{
	if (cirQ->num_elements == cirQ->capacity)
		return true;
	else
		return false;
}
bool isCirQEmpty(CirQ_Event* cirQ)	//Queue�� ������� Check
{
	if (cirQ->num_elements == 0)
		return true;
	else
		return false;
}
Event* enCirQ_Event(CirQ_Event* cirQ, Event ev)	//Queue�� Event�� �ִ� �Լ�
{
	if (isCirQFull(cirQ))
	{
		return NULL;
	}
	cirQ->CirBuff_Ev[cirQ->end] = ev;
	cirQ->num_elements++;
	cirQ->end++;
	if (cirQ->end >= cirQ->capacity)	//end�� �뷮�� ������ ������ ���ư���.
		cirQ->end = cirQ->end % cirQ->capacity;
	return &(cirQ->CirBuff_Ev[cirQ->end]);
}
Event* deCirQ_Event(CirQ_Event* cirQ)	//Queue���� Event�� out�ϴ� �ϼ�
{
	if (isCirQEmpty(cirQ))
		return NULL;
	Event* pEv = &(cirQ->CirBuff_Ev[cirQ->front]);	//event ��ġ ��ȯ
	cirQ->front++;	//front ����
	if (cirQ->front >= cirQ->capacity)	//front�� �뷮 ���� ������ ������ ���ư���.
		cirQ->front = cirQ->front % cirQ->capacity;
	cirQ->num_elements--;	//���� ����
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