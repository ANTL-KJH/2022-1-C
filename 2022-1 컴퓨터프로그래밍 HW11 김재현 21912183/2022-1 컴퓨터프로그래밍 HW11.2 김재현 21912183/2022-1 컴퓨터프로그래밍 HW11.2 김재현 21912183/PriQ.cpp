/*PriQ.cpp*/
#include "STD.h"
#include "PriQ_Event.h"

PriQ_Event* initPriQ_Event(PriQ_Event* pPriQ_Event, const char* name, int capacity)	//PriQ를 초가화하는 함수
{
	strcpy(pPriQ_Event->PriQ_name, name);
	pPriQ_Event->priQ_capacity = capacity;
	pPriQ_Event->pCBT_Event = (CBTN_Event*)calloc((capacity + 1), sizeof(CBTN_Event));	//Dynamic memory allocation
	pPriQ_Event->priQ_size = 0;	//size 초기화
	pPriQ_Event->pos_last = 0;	//last 초기화
	return pPriQ_Event;
}

int enPriQ_Event(PriQ_Event* pPriQ_Event, Event* pEvent)
{
	int pos, pos_parent, pos_last;
	CBTN_Event CBTN_Event_Temp;
	if (pPriQ_Event->priQ_size >= pPriQ_Event->priQ_capacity)	//PriQueue Event가 용량보다 큰 경우
	{
		CBTN_Event* newCBT_Event;
		int newCapacity;
		newCapacity = 2 * pPriQ_Event->priQ_capacity;
		newCBT_Event = (CBTN_Event*)malloc((newCapacity + 1) * sizeof(CBTN_Event));	//Dynamic memory allocation
		if (newCBT_Event == NULL)
		{
			printf("Error in expanding CompleteBinaryTree for Priority Queue !!\n");
			exit(-1);
		}
		for (int pos = 1; pos <= pPriQ_Event->priQ_size; pos++)	//element 0 비워놓고 1번부터 Event입력
		{
			newCBT_Event[pos] = pPriQ_Event->pCBT_Event[pos];
		}
		free(pPriQ_Event->pCBT_Event);
		pPriQ_Event->pCBT_Event = newCBT_Event;
		pPriQ_Event->priQ_capacity = newCapacity;
	}
	pos = pos_last = ++pPriQ_Event->priQ_size;
	pPriQ_Event->pCBT_Event[pos].priority = pEvent->Event_pri;	//우선순위 입력
	pPriQ_Event->pCBT_Event[pos].pEvent = pEvent; //이벤트 주소 입력
	while (pos != POS_ROOT)
	{
		pos_parent = pos / 2;	//부모 위치는 child 위치/2
		if (pPriQ_Event->pCBT_Event[pos].priority >= pPriQ_Event->pCBT_Event[pos_parent].priority)	//부모와 우선순위 비교
		{
			break;
		}
		else
		{
			CBTN_Event_Temp = pPriQ_Event->pCBT_Event[pos_parent];	//Swap
			pPriQ_Event->pCBT_Event[pos_parent] = pPriQ_Event->pCBT_Event[pos];
			pPriQ_Event->pCBT_Event[pos] = CBTN_Event_Temp;
			pos = pos_parent;
		}
	}
}

Event* dePriQ_Event(PriQ_Event* pPriQ_Event)	//PriQueue에 있는 Event를 제거 하는 함수
{
	Event* pEv;
	CBTN_Event CBTN_Event_temp;
	int pos, pos_last, pos_child;
	if (pPriQ_Event->priQ_size <= 0)	//PriQ가 비어있는 경우
		return NULL;
	pEv = pPriQ_Event->pCBT_Event[1].pEvent; //현재 최상단 주소
	pos_last = pPriQ_Event->priQ_size;
	--pPriQ_Event->priQ_size;
	if (pPriQ_Event->priQ_size > 0)	//down bubbling start
	{
		pPriQ_Event->pCBT_Event[POS_ROOT] = pPriQ_Event->pCBT_Event[pos_last];	//마지막에 있는 child를 root로 가져옴(최상단 부모 delete)
		pos_last--;
		pos = POS_ROOT;
		while (hasLeftChild(pos, pPriQ_Event))	//최상단 기준 왼쪽 chlid 확인
		{
			pos_child = pos * 2;
			if (hasRightChild(pos, pPriQ_Event))	//오른쪽 child 존재 확인
			{
				if (pPriQ_Event->pCBT_Event[pos_child].priority > pPriQ_Event->pCBT_Event[pos_child + 1].priority)	//왼쪽 child와 오른쪽 child 우선순위 check
					pos_child = pos * 2 + 1;	//오른쪽 child의 우선순위가 더 높은경우 오른쪽 child로 위치 변경
			}
			if (pPriQ_Event->pCBT_Event[pos_child].priority < pPriQ_Event->pCBT_Event[pos].priority)	//우선순위가 높은 child와 swap
			{
				CBTN_Event_temp = pPriQ_Event->pCBT_Event[pos];
				pPriQ_Event->pCBT_Event[pos] = pPriQ_Event->pCBT_Event[pos_child];
				pPriQ_Event->pCBT_Event[pos_child] = CBTN_Event_temp;
			}
			else //부모의 우선순위가 높다면 break
				break;
			pos = pos_child;	//변경된 child의 위치에서 다시 down bubbling
		}
	}
	return pEv;
}

void printPriQ_Event(PriQ_Event* pPriQ_Event)	//PriQueue에 있는 Event를 출력하는 함수
{
	int pos, count, count_per_line;
	int eventPriority;
	int level = 0, level_count = 1;
	Event* pEv;
	if (pPriQ_Event->priQ_size == 0)	//Queue size가 0이면 return
	{
		printf("PriorityQueue_Event is empty !!\n");
		return;
	}
	pos = 1;
	count = 1;
	level = 0;
	level_count = 1;
	printf("\n CompBinTree :\n", level);
	while (count <= pPriQ_Event->priQ_size)	//count가 size보다 작을 때
	{
		printf(" level%2d : ", level);
		count_per_line = 0;
		while (count_per_line < level_count)
		{
			pEv = pPriQ_Event->pCBT_Event[pos].pEvent;	//Event 위치 전달
			eventPriority = pPriQ_Event->pCBT_Event[pos].priority;	//우선순위 전달
			printEvent(pEv);	//Event 출력
			pos++;
			count++;
			if (count > pPriQ_Event->priQ_size)		//count가 size를 초과하면 break
				break;
			count_per_line++;
			if ((count_per_line % EVENT_PER_LINE) == 0)	//한줄에 5개 출력하고 줄바꿈
			{
				printf("\n");
			}
		}
		if ((count_per_line % EVENT_PER_LINE) != 0)
			printf("\n");
		level++;
		level_count *= 2;
	}
	printf("\n");
}

void fprintPriQ_Event(FILE* fout, PriQ_Event* pPriQ_Event)	//PriQueue에 있는 Event를 파일에 출력하는 함수
{
	int pos, count, count_per_line;
	int eventPriority;
	int level = 0, level_count = 1;
	Event* pEv;
	if (pPriQ_Event->priQ_size == 0)	//Queue size가 0이면 return
	{
		fprintf(fout, "PriorityQueue_Event is empty !!\n");
		return;
	}
	pos = 1;
	count = 1;
	level = 0;
	level_count = 1;
	fprintf(fout, "\n CompBinTree :\n", level);
	while (count <= pPriQ_Event->priQ_size)	//count가 size보다 작을 때
	{
		fprintf(fout, " level%2d : ", level);
		count_per_line = 0;
		while (count_per_line < level_count)
		{
			pEv = pPriQ_Event->pCBT_Event[pos].pEvent;	//Event 위치 전달
			eventPriority = pPriQ_Event->pCBT_Event[pos].priority;	//우선순위 전달
			fprintEvent(fout, pEv);	//Event 출력
			pos++;
			count++;
			if (count > pPriQ_Event->priQ_size)	//count가 size를 초과하면 break
				break;
			count_per_line++;
			if ((count_per_line % EVENT_PER_LINE) == 0)	//한줄에 5개 출력하고 줄바꿈
			{
				fprintf(fout, "\n");
			}
		}
		if ((count_per_line % EVENT_PER_LINE) != 0)
			fprintf(fout, "\n");
		level++;
		level_count *= 2;
	}
	fprintf(fout, "\n");
}

void deletePriQ_Event(PriQ_Event* pPriQ_Event)	//memory return하는 함수
{
	CBTN_Event* pCBTN_Ev;
	for (int i = 0; i < pPriQ_Event->priQ_size; i++)
	{
		pCBTN_Ev = &(pPriQ_Event->pCBT_Event)[i];
		if (pCBTN_Ev != NULL)	//pCBTN_Ev가 비어있고
		{
			if (pCBTN_Ev->pEvent != NULL)	//pEvent가 비어있으면 memory 반납
				free(pCBTN_Ev->pEvent);
			free(pCBTN_Ev);
		}
	}
}

bool hasLeftChild(int pos, PriQ_Event* pPriQ_Ev)	//왼쪽 child의 존재 유무 확인
{
	if (pos * 2 <= pPriQ_Ev->priQ_size) //왼쪽 child 존재 확인
		return TRUE;
	else
		return FALSE;
}
bool hasRightChild(int pos, PriQ_Event* pPriQ_Ev)	//오른쪽 child 존재 유무 확인
{
	if (pos * 2 + 1 <= pPriQ_Ev->priQ_size)	//오른쪽 child 존재 확인
		return TRUE;
	else
		return FALSE;
}