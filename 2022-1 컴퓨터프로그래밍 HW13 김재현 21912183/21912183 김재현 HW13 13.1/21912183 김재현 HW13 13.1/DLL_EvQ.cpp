/*DLL_EvQ.cpp*/
#include "STD.h"
#include "DLL_EvQ.h"

void initDLL_EvQ(DLL_EvQ* pEvQ, int pri)	//Doubly Linked List 초기화
{
	pEvQ->cs_EvQ.lock();
	pEvQ->priority = pri;
	pEvQ->front = pEvQ->back = NULL;
	pEvQ->num_event = 0;
	pEvQ->cs_EvQ.unlock();
}

Event* enDLL_EvQ(DLL_EvQ* pEvQ, Event* pEv)	//Event를 Doubly Linked List PriQ에 입력
{
	DLLN_Ev* pLN_Ev;
	if (pEv == NULL)
	{
		printf("Error in enDLL_EvQ :: DLL_EvQ is NULL !!\n");
		printf("Press any key to continue ...\n");
		getc(stdin);
		return NULL;
	}
	pLN_Ev = (DLLN_Ev*)calloc(1, sizeof(DLLN_Ev));	//Doubly Linked List Event Dynamic memory Allocation
	if (pLN_Ev == NULL)	//동적 메모리 할당이 안된 경우
	{
		printf("Error in enDLL_EvQ :: memory allocation for new DLLN failed !!\n");
		printf("Press any key to continue ...\n");
		getc(stdin);
		return NULL;
	}
	pLN_Ev->pEv = pEv;	//이벤트 주소를 DLL에 전달
	pEvQ->cs_EvQ.lock();	//Event lock
	if (pEvQ->num_event == 0) //DLL가 비어있는경우
	{
		pEvQ->front = pEvQ->back = pLN_Ev;	//처음과 끝을 입력한 Event로 설정
		pLN_Ev->prev = pLN_Ev->next = NULL;	//이전과 다음은 없음
		pEvQ->num_event = 1;	//DLL에 입력된 이벤트는 1개
	}
	else
	{
		pLN_Ev->prev = pEvQ->back;	//new Event의 prev를 기존 DLL의 back과 연결
		pEvQ->back->next = pLN_Ev;	//기존 Event의 back을 new Event로 연결
		pEvQ->back = pLN_Ev;	//back을 new Event로 재설정
		pLN_Ev->next = NULL;	//back의 next는 NULL
		pEvQ->num_event++;
	}
	pEvQ->cs_EvQ.unlock();	//unlock
	return pLN_Ev->pEv;
}

Event* deDLL_EvQ(DLL_EvQ* pEvQ)	//Event를 Doubly에서 제거하는 함수
{
	Event* pEv;
	DLLN_Ev* pLN_Ev_OldFront;
	pEvQ->cs_EvQ.lock();
	if (pEvQ->num_event <= 0)	//DLL EventQ가 비어있는 경우
	{
		pEvQ->cs_EvQ.unlock();
		return NULL;
	}
	else
	{
		pLN_Ev_OldFront = pEvQ->front;
		pEv = pEvQ->front->pEv;	//front Event 전달
		pEvQ->front = pEvQ->front->next;	//front를 next로 설정함
		if (pEvQ->front != NULL)	//새로 front가 된 DLL Event의 prev를 NULL로 설정
			pEvQ->front->prev = NULL;
		pEvQ->num_event--;
		free(pLN_Ev_OldFront); //기존의 front free
		pEvQ->cs_EvQ.unlock();
		return pEv;
	}
}

void printDLL_EvQ(DLL_EvQ* pEvQ)	//Printout Doubly Linked List
{
	int index = 0;
	int count;
	Event* pEv;
	DLLN_Ev* pLN_Ev;
	if (pEvQ == NULL)	//EventQ가 비어있으면 
	{
		printf("Error in printDLL_EvQ :: DLL_EvQ is NULL !!");
		printf("Press any key to continue ...\n");
		getc(stdin);
	}
	if (pEvQ->num_event <= 0)	//Event가 없으면 return
		return;
	pLN_Ev = pEvQ->front;	//DLN에 front전달
	count = 0;
	while (pLN_Ev != NULL)
	{
		pEv = pLN_Ev->pEv;
		if (pEv == NULL)
			break;
		printEvent(pEv);	//Event 출력
		printf(" ");
		count++;
		if ((count % 5) == 0)
			printf("\n ");
		pLN_Ev = pLN_Ev->next;	//next로 넘어가며 출력
	}
}