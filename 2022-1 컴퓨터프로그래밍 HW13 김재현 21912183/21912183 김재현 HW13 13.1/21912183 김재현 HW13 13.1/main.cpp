/*
* ���ϸ� : "21912183 ������ HW13 13.1.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -��Ƽ Thread�� �̿��Ͽ� �켱������ ���� FIFO Queue���� Event�� ó���ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.06.03
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.06.03	v1.0	�����ۼ�
*/

#include "STD.h"
#include "Thread.h"
#include "DLL_EvQ.h"
#include "Event.h"
#include "ConsoleDisplay.h"
using namespace std;
int main(void)
{
	FILE* fout;	//��������
	DLL_EvQ dll_EvQ_PriH, dll_EvQ_PriL;	//Doubly Linked List Pri High, Pri Low
	Event* pEvent;	//Event Pointer
	int myAddr = 0, event_handler_addr;
	LARGE_INTEGER pc_freq;	//frequency ����� ����
	fout = fopen("SimOutput.txt", "w");	//File Open
	if (fout == NULL)
	{
		printf("Error in opening SimOutput.txt file in write mode !!\n");
		exit;
	}
	initDLL_EvQ(&dll_EvQ_PriH, 0);	//PriQ High �ʱ�ȭ
	initDLL_EvQ(&dll_EvQ_PriL, 1);	//PriQ Low �ʱ�ȭ
	srand(time(NULL));	//random seed
	ThreadParam_Ev thrdParam_EventGen[NUM_EVENT_GENERATORS], thrdParam_EventHndlr[NUM_EVENT_HANDLERS];
	thread thread_evHandlers[NUM_EVENT_HANDLERS];	//Multi Thread Event Handler(Event Handler 2�� ����)
	thread thread_evGens[NUM_EVENT_GENERATORS];		//Multo Thread Event Generator(Event Generator 3�� ����)
	mutex cs_main, cs_thrd_mon;	//main critical section, thread monitor critical section
	ThreadStatMon thrdMon;
	HANDLE consHndlr;
	THREAD_FLAG eventThreadFlag = RUN;
	int count, totalEventGenerated, totalEventProcessed;
	Event eventProcessed[TOTAL_NUM_EVENTS];
	consHndlr = initConsoleHandler();	//console Handler Output���� �ʱ�ȭ
	QueryPerformanceFrequency(&pc_freq);	//Frequency Check
	thrdMon.pFlagThreadTerminate = &eventThreadFlag;
	thrdMon.totalEventGen = 0;
	thrdMon.totalEventProc = 0;
	thrdMon.numEventProcs_priH = 0;
	thrdMon.numEventProcs_priL = 0;
	for (int ev = 0; ev < TOTAL_NUM_EVENTS; ev++)	//ó������ ���� Event mark
	{
		thrdMon.eventProcessed[ev].event_no = -1;
		thrdMon.eventProcessed[ev].event_pri = -1;
	}

	for (int Ev_Hdlr_No = 0; Ev_Hdlr_No < NUM_EVENT_HANDLERS; Ev_Hdlr_No++)	//Event Handler ��ȣ�� �°� �ʱ�ȭ
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
		cs_main.lock();	//main lock(��� �� �ٸ� Thread�� ������ ���� ����)
		printf("%d-th thread_EventHandler is created and activated (id: %d)\n", Ev_Hdlr_No, thread_evHandlers[Ev_Hdlr_No].get_id());
		cs_main.unlock();
	}

	for (int Ev_Gen_No = 0; Ev_Gen_No < NUM_EVENT_GENERATORS; Ev_Gen_No++)	//Event Generator ��ȣ�� �°� �ʱ�ȭ
	{
		thrdMon.eventsGen[Ev_Gen_No] = 0;
		thrdParam_EventGen[Ev_Gen_No].role = EVENT_GENERATOR;
		thrdParam_EventGen[Ev_Gen_No].myAddr = Ev_Gen_No; //Event Generator Address
		thrdParam_EventGen[Ev_Gen_No].pCS_main = &cs_main;	//main critical section
		thrdParam_EventGen[Ev_Gen_No].pCS_thrd_mon = &cs_thrd_mon;	//thread_monitor critical section
		thrdParam_EventGen[Ev_Gen_No].EvQ_PriH = &dll_EvQ_PriH;	//Doubly Linked List PriQ High
		thrdParam_EventGen[Ev_Gen_No].EvQ_PriL = &dll_EvQ_PriL;	//Doubly Linked List PriQ Low
		thrdParam_EventGen[Ev_Gen_No].targetEventGen = NUM_EVENTS_PER_GEN;	//�� �� �̺�Ʈ ������ ������ �̺�Ʈ ��
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
		for (int i = 0; i < NUM_EVENT_GENERATORS; i++)	//i���� Generator �� ������ �̺�Ʈ�� �� ���
		{
			printf(" Event_Gen[%d] generated %2d events.\n", i, thrdMon.eventsGen[i]);
		}
		printf("Event_Generators have generated total %2d events\n", thrdMon.totalEventGen);	//�� ������ �̺�Ʈ�� ���
		totalEventGenerated = thrdMon.totalEventGen;
		printf("\nTotal Generated Events (current total %d events)\n ", totalEventGenerated);
		for (int ev = 0; ev < totalEventGenerated; ev++)	//������ �̺�Ʈ ���
		{
			pEvent = &thrdMon.eventGenerated[ev];
			if (pEvent != NULL)
			{
				printEvent(pEvent);	//Event ���
				if (((ev + 1) % EVENT_PER_LINE) == 0)
					printf("\n ");
			}
		}
		printf("\n");
		printf("\nEvent_Handlers have processed total %2d events ", thrdMon.totalEventProc);	//�� ó���� �̺�Ʈ�� ���
		printf("(event__PriH (%2d), event_PriL (%2d))\n", thrdMon.numEventProcs_priH, thrdMon.numEventProcs_priL);	//PriQ High, PriQ Low�� ����ִ� Event�� �� ���
		for (int i = 0; i < NUM_EVENT_HANDLERS; i++)
		{
			printf(" Event_Proc[%d] processed %2d events.\n", i, thrdMon.eventsProc[i]);	//Event Handler ��ȣ�� ���� Processed�� �̺�Ʈ ���
		}
		printf("\n");
		printf("DLL_EvQ_PriH (%3d events):\n ", dll_EvQ_PriH.num_event);	//PriQ High�� �ִ� Event ���� ���
		printDLL_EvQ(&dll_EvQ_PriH);	//PriQ High ���
		printf("\n");
		printf("DLL_EvQ_PriL (%3d events):\n ", dll_EvQ_PriL.num_event);	//PriQ Low�� �ִ� Event ���� ���
		printDLL_EvQ(&dll_EvQ_PriL);	//PriQ Low ���
		printf("\n");
		totalEventProcessed = thrdMon.totalEventProc;
		printf("\nTotal Processed Events (current total %d events):\n ", totalEventProcessed);	//ó���� �̺�Ʈ �� ���
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
			eventThreadFlag = TERMINATE; //ThreadFlag�� TERMINATE �Է�
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