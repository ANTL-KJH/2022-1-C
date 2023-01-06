/*Thread_EventGenerator.cpp*/
#include "STD.h"
#include "Thread.h"
#include "DLL_EvQ.h"
#include "Event.h"
using namespace std;
void Thread_EventGenerator(ThreadParam_Ev* pThrdParam)	//Multi Thread Event Generator
{
	Event* pEv;	//Event Pointer
	int event_no = 0;	//변수 initialize
	int event_pri = 0;
	int event_gen_count = 0;
	int myRole = pThrdParam->role;	//role 입력
	int myGenAddr = pThrdParam->myAddr;	//Thread Address 입력
	int targetEventGen = pThrdParam->targetEventGen;	//생성할 Event수 입력
	DLL_EvQ* pEvQ;	//Doubly Linked List
	DLL_EvQ* priH_EvQ = pThrdParam->EvQ_PriH;	//PriQ High 전달
	DLL_EvQ* priL_EvQ = pThrdParam->EvQ_PriL;	//PriQ Low 전달
	ThreadStatMon* pThrdMon = pThrdParam->pThrdMon;
	int maxRound = pThrdParam->maxRound;	//Maxround 전달
	pThrdParam->pCS_main->lock();	//Main lock(출력 겹침 방지)
	printf("Thread_EventGenerator(%d): targetEventGen(%d)₩n", myGenAddr, targetEventGen);	//Printout Thread Address, TargetEventGen
	pThrdParam->pCS_main->unlock();
	for (int round = 0; round < maxRound; round++)
	{
		if (event_gen_count < targetEventGen)	//생성된 이벤트가 목표 Event의 수보다 작을때
		{
			pEv = (Event*)calloc(1, sizeof(Event));	//Dynamic Memory Allocation
			pEv->event_gen_addr = myGenAddr;	//Event Generator Thread's Address 입력
			pEv->event_no = event_no = event_gen_count + (NUM_EVENTS_PER_GEN * myGenAddr);	//Event Generator Thread에 따른 Event_no 입력
			pEv->event_pri = event_pri = rand() % NUM_PRIORITY;	//Random으로 Event Priority입력
			pEv->event_handler_addr = -1;	//Event is't Processed
			QueryPerformanceCounter(&pEv->t_gen);	//Event Generate Time Check
			pEvQ = (event_pri < PRIORITY_THRESHOLD) ? priH_EvQ : priL_EvQ;	//우선순위에 따른 Event
			while (enDLL_EvQ(pEvQ, pEv) == NULL)
			{
				Sleep(100);
			}
			pThrdParam->pCS_thrd_mon->lock();	//Thread Monitor Lock
			pThrdMon->eventsGen[myGenAddr]++;	//gen Event ++
			pThrdMon->eventGenerated[pThrdMon->totalEventGen] = *pEv;	//생성한 Event 입력
			pThrdMon->totalEventGen++;	//총 생성된 Event ++
			pThrdParam->pCS_thrd_mon->unlock();
			event_gen_count++;
		}
		else	//Event 생성이 종료된 경우
		{
			if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
				break;
		}
		Sleep(100 + rand() % 100);
	}
}