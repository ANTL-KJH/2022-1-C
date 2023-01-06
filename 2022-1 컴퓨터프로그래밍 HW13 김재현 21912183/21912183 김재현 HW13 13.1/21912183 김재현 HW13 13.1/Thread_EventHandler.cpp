/*Thread_EventHandler.cpp*/
#include "STD.h"
#include "Thread.h"
#include "DLL_EvQ.h"
#include "Event.h"
using namespace std;

void Thread_EventHandler(ThreadParam_Ev* pThrdParam)	//Multi Thread Event Generator
{
	int myRole = pThrdParam->role;	//role을 Hanldler로 설정
	int myProcAddr = pThrdParam->myAddr;	//Handler Address 설정
	Event* pEv;
	DLL_EvQ* pEvQ;
	DLL_EvQ* priH_EvQ = pThrdParam->EvQ_PriH;	//PriQ High 전달
	DLL_EvQ* priL_EvQ = pThrdParam->EvQ_PriL;	//PriQ Low 전달
	ThreadStatMon* pThrdMon = pThrdParam->pThrdMon;
	int maxRound = pThrdParam->maxRound;
	Event* evProc = pThrdParam->pThrdMon->eventProcessed;
	int targetEventGen = pThrdParam->targetEventGen;
	LARGE_INTEGER PC_freq = pThrdParam->PC_freq;
	pThrdParam->pCS_main->lock();
	printf("Thread_EventHandler(%d): targetEventGen(%d)₩n", myProcAddr, targetEventGen);
	pThrdParam->pCS_main->unlock();
	for (int round = 0; round < maxRound; round++)
	{
		if (*pThrdMon->pFlagThreadTerminate == TERMINATE)	//모든 Event가 Processed된 경우 break
			break;
		while ((pEv = deDLL_EvQ(priH_EvQ)) != NULL)	//Pri High 우선 처리
		{
			pThrdParam->pCS_thrd_mon->lock();	//thread monitor lock
			pEv->event_handler_addr = myProcAddr;
			QueryPerformanceCounter(&pEv->t_proc);	//processed time check
			calc_elapsed_time(pEv, PC_freq);	//calculate time
			pThrdMon->eventProcessed[pThrdMon->totalEventProc] = *pEv;	//처리한 Event 입력
			pThrdMon->eventsProc[myProcAddr]++;	//processed ++
			pThrdMon->totalEventProc++;	//total processed ++
			pThrdMon->numEventProcs_priH++;	//processed ++
			free(pEv);	//free
			pThrdParam->pCS_thrd_mon->unlock();
			Sleep(300 + rand() % 500);
		}
		if ((pEv = deDLL_EvQ(priL_EvQ)) != NULL)	//Pri LowQ
		{
			pThrdParam->pCS_thrd_mon->lock();	//thread monitor lock
			pEv->event_handler_addr = myProcAddr;	//Address 입략
			QueryPerformanceCounter(&pEv->t_proc);	//processed time check
			calc_elapsed_time(pEv, PC_freq);	//calculate time
			pThrdMon->eventProcessed[pThrdMon->totalEventProc] = *pEv;
			pThrdMon->eventsProc[myProcAddr]++;	//processed ++
			pThrdMon->totalEventProc++;	//total processed ++
			pThrdMon->numEventProcs_priL++;
			pThrdParam->pCS_thrd_mon->unlock();
		}
		Sleep(100 + rand() % 100);
	}
}