/*
* 파일명 : "21912183 김재현 HW13 13.1.sln"
* 프로그램의 목적 및 기본 기능 :
* -멀티 Thread를 이용하여 우선순위에 따른 FIFO Queue에서 Event를 처리하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.06.03
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.06.03	v1.0	최초작성
*/

#include "STD.h"
#include "Thread.h"
#include "DLL_EvQ.h"
#include "Event.h"
#include "ConsoleDisplay.h"
using namespace std;
int main(void)
{
	FILE* fout;	//변수선언
	DLL_EvQ dll_EvQ_PriH, dll_EvQ_PriL;	//Doubly Linked List Pri High, Pri Low
	Event* pEvent;	//Event Pointer
	int myAddr = 0, event_handler_addr;
	LARGE_INTEGER pc_freq;	//frequency 저장용 변수
	fout = fopen("SimOutput.txt", "w");	//File Open
	if (fout == NULL)
	{
		printf("Error in opening SimOutput.txt file in write mode !!\n");
		exit;
	}
	initDLL_EvQ(&dll_EvQ_PriH, 0);	//PriQ High 초기화
	initDLL_EvQ(&dll_EvQ_PriL, 1);	//PriQ Low 초기화
	srand(time(NULL));	//random seed
	ThreadParam_Ev thrdParam_EventGen[NUM_EVENT_GENERATORS], thrdParam_EventHndlr[NUM_EVENT_HANDLERS];
	thread thread_evHandlers[NUM_EVENT_HANDLERS];	//Multi Thread Event Handler(Event Handler 2개 생성)
	thread thread_evGens[NUM_EVENT_GENERATORS];		//Multo Thread Event Generator(Event Generator 3개 생성)
	mutex cs_main, cs_thrd_mon;	//main critical section, thread monitor critical section
	ThreadStatMon thrdMon;
	HANDLE consHndlr;
	THREAD_FLAG eventThreadFlag = RUN;
	int count, totalEventGenerated, totalEventProcessed;
	Event eventProcessed[TOTAL_NUM_EVENTS];
	consHndlr = initConsoleHandler();	//console Handler Output으로 초기화
	QueryPerformanceFrequency(&pc_freq);	//Frequency Check
	thrdMon.pFlagThreadTerminate = &eventThreadFlag;
	thrdMon.totalEventGen = 0;
	thrdMon.totalEventProc = 0;
	thrdMon.numEventProcs_priH = 0;
	thrdMon.numEventProcs_priL = 0;
	for (int ev = 0; ev < TOTAL_NUM_EVENTS; ev++)	//처리되지 않은 Event mark
	{
		thrdMon.eventProcessed[ev].event_no = -1;
		thrdMon.eventProcessed[ev].event_pri = -1;
	}

	for (int Ev_Hdlr_No = 0; Ev_Hdlr_No < NUM_EVENT_HANDLERS; Ev_Hdlr_No++)	//Event Handler 번호에 맞게 초기화
	{
		thrdMon.eventsProc[Ev_Hdlr_No] = 0;
		thrdParam_EventHndlr[Ev_Hdlr_No].fout = fout;
		thrdParam_EventHndlr[Ev_Hdlr_No].role = EVENT_HANDLER;
		thrdParam_EventHndlr[Ev_Hdlr_No].myAddr = Ev_Hdlr_No;		//Event Handler Address
		thrdParam_EventHndlr[Ev_Hdlr_No].pCS_main = &cs_main;	//main critical section
		thrdParam_EventHndlr[Ev_Hdlr_No].pCS_thrd_mon = &cs_thrd_mon;	//thread_monitor critical section
		thrdParam_EventHndlr[Ev_Hdlr_No].EvQ_PriH = &dll_EvQ_PriH;	//Doubly Linked List PriQ High
		thrdParam_EventHndlr[Ev_Hdlr_No].EvQ_PriL = &dll_EvQ_PriL;	//Doubly Linked List PriQ Low
		thrdParam_EventHndlr[Ev_Hdlr_No].maxRound = MAX_ROUND;
		thrdParam_EventHndlr[Ev_Hdlr_No].pThrdMon = &thrdMon;
		thrdParam_EventHndlr[Ev_Hdlr_No].PC_freq = pc_freq;	//Frequency
		thread_evHandlers[Ev_Hdlr_No] = thread(Thread_EventHandler, &thrdParam_EventHndlr[Ev_Hdlr_No]);
		cs_main.lock();	//main lock(출력 중 다른 Thread의 개입을 막기 위함)
		printf("%d-th thread_EventHandler is created and activated (id: %d)\n", Ev_Hdlr_No, thread_evHandlers[Ev_Hdlr_No].get_id());
		cs_main.unlock();
	}

	for (int Ev_Gen_No = 0; Ev_Gen_No < NUM_EVENT_GENERATORS; Ev_Gen_No++)	//Event Generator 번호에 맞게 초기화
	{
		thrdMon.eventsGen[Ev_Gen_No] = 0;
		thrdParam_EventGen[Ev_Gen_No].role = EVENT_GENERATOR;
		thrdParam_EventGen[Ev_Gen_No].myAddr = Ev_Gen_No; //Event Generator Address
		thrdParam_EventGen[Ev_Gen_No].pCS_main = &cs_main;	//main critical section
		thrdParam_EventGen[Ev_Gen_No].pCS_thrd_mon = &cs_thrd_mon;	//thread_monitor critical section
		thrdParam_EventGen[Ev_Gen_No].EvQ_PriH = &dll_EvQ_PriH;	//Doubly Linked List PriQ High
		thrdParam_EventGen[Ev_Gen_No].EvQ_PriL = &dll_EvQ_PriL;	//Doubly Linked List PriQ Low
		thrdParam_EventGen[Ev_Gen_No].targetEventGen = NUM_EVENTS_PER_GEN;	//한 번 이벤트 생성에 생성할 이벤트 수
		thrdParam_EventGen[Ev_Gen_No].maxRound = MAX_ROUND;	//Maxround
		thrdParam_EventGen[Ev_Gen_No].pThrdMon = &thrdMon;
		thrdParam_EventGen[Ev_Gen_No].PC_freq = pc_freq;	//Frequency
		thread_evGens[Ev_Gen_No] = thread(Thread_EventGenerator, &thrdParam_EventGen[Ev_Gen_No]);
		cs_main.lock();
		printf("%d-th thread_EventGen is created and activated (id: %d)\n", Ev_Gen_No, thread_evGens[Ev_Gen_No].get_id());
		cs_main.unlock();
	}

	for (int round = 0; round < MAX_ROUND; round++)
	{
		cs_main.lock();
		system("cls");
		gotoxy(consHndlr, 0, 0);
		printf("Thread monitoring by main() :: round(%2d): \n", round);
		cs_thrd_mon.lock();
		for (int i = 0; i < NUM_EVENT_GENERATORS; i++)	//i번의 Generator 가 생성한 이벤트의 수 출력
		{
			printf(" Event_Gen[%d] generated %2d events.\n", i, thrdMon.eventsGen[i]);
		}
		printf("Event_Generators have generated total %2d events\n", thrdMon.totalEventGen);	//총 생성된 이벤트수 출력
		totalEventGenerated = thrdMon.totalEventGen;
		printf("\nTotal Generated Events (current total %d events)\n ", totalEventGenerated);
		for (int ev = 0; ev < totalEventGenerated; ev++)	//생성된 이벤트 출력
		{
			pEvent = &thrdMon.eventGenerated[ev];
			if (pEvent != NULL)
			{
				printEvent(pEvent);	//Event 출력
				if (((ev + 1) % EVENT_PER_LINE) == 0)
					printf("\n ");
			}
		}
		printf("\n");
		printf("\nEvent_Handlers have processed total %2d events ", thrdMon.totalEventProc);	//총 처리된 이벤트수 출력
		printf("(event__PriH (%2d), event_PriL (%2d))\n", thrdMon.numEventProcs_priH, thrdMon.numEventProcs_priL);	//PriQ High, PriQ Low에 들어있는 Event의 수 출력
		for (int i = 0; i < NUM_EVENT_HANDLERS; i++)
		{
			printf(" Event_Proc[%d] processed %2d events.\n", i, thrdMon.eventsProc[i]);	//Event Handler 번호에 따라 Processed된 이벤트 출력
		}
		printf("\n");
		printf("DLL_EvQ_PriH (%3d events):\n ", dll_EvQ_PriH.num_event);	//PriQ High에 있는 Event 개수 출력
		printDLL_EvQ(&dll_EvQ_PriH);	//PriQ High 출력
		printf("\n");
		printf("DLL_EvQ_PriL (%3d events):\n ", dll_EvQ_PriL.num_event);	//PriQ Low에 있는 Event 개수 출력
		printDLL_EvQ(&dll_EvQ_PriL);	//PriQ Low 출력
		printf("\n");
		totalEventProcessed = thrdMon.totalEventProc;
		printf("\nTotal Processed Events (current total %d events):\n ", totalEventProcessed);	//처리된 이벤트 수 출력
		count = 0;
		for (int ev = 0; ev < totalEventProcessed; ev++)
		{
			pEvent = &thrdMon.eventProcessed[ev];
			if (pEvent != NULL)
			{
				printEvent(pEvent);	//Print out Event
				if (((ev + 1) % EVENT_PER_LINE) == 0)
					printf("\n ");
			}
		}
		printf("\n");
		cs_thrd_mon.unlock();	//Thread Monitor Unlock
		if (totalEventProcessed >= TOTAL_NUM_EVENTS)
		{
			printf("!!! TotalEventProcessed (%d) is reached to target TOTAL_NUM_EVENTS(% d)\n", totalEventProcessed, TOTAL_NUM_EVENTS);
			eventThreadFlag = TERMINATE; //ThreadFlag에 TERMINATE 입력
			cs_main.unlock();
			break;
		}
		cs_main.unlock();
		Sleep(100);
	}
	for (int p = 0; p < NUM_EVENT_HANDLERS; p++)	//Event Handler join
	{
		thread_evHandlers[p].join();
	}
	printf("All threads of event handlers are terminated !!\n");
	for (int g = 0; g < NUM_EVENT_GENERATORS; g++)	//Event Generator join
	{
		thread_evGens[g].join();
	}
	printf("All threads of event generators are terminated !!\n");
	double min, max, avg, sum;
	int min_event, max_event;
	min = max = sum = thrdMon.eventProcessed[0].t_elapsed;
	min_event = max_event = 0;
	for (int i = 1; i < TOTAL_NUM_EVENTS; i++)	//Find Max, Min time
	{
		sum += thrdMon.eventProcessed[i].t_elapsed;
		if (min > thrdMon.eventProcessed[i].t_elapsed)
		{
			min = thrdMon.eventProcessed[i].t_elapsed;
			min_event = i;
		}
		if (max < thrdMon.eventProcessed[i].t_elapsed)
		{
			max = thrdMon.eventProcessed[i].t_elapsed;
			max_event = i;
		}
	}
	avg = sum / (double)TOTAL_NUM_EVENTS;	//Avg time
	printf("Minimum event processing time: %8.2lf[ms] for ", min * 1000);	//Printout Minimum time
	printEvent_withTime(&thrdMon.eventProcessed[min_event]); printf("\n");
	printf("Maximum event processing time: %8.2lf[ms] for ", max * 1000);	//Printout Maximum time
	printEvent_withTime(&thrdMon.eventProcessed[max_event]); printf("\n");
	printf("Average event processing time: %8.2lf[ms] for total %d events\n", avg * 1000, TOTAL_NUM_EVENTS);
	printf("\n");
	return 0;
}