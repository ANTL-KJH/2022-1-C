/*
* 파일명 : "21912183 김재현 HW11 11.2.sln"
* 프로그램의 목적 및 기본 기능 :
* -128개의 이벤트를 우선순위큐(PriQ)로 처리하는 하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.05.22
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.05.22	v1.0	최초작성
*/

#include "STD.h"
#include "Event.h"
#include "PriQ_Event.h"

int main()
{
	const char* FIL_O = "output.txt";
	FILE* fout;
	fout = fopen(FIL_O, "w");
	int max_Events_per_round, num_generated_round, total_generated_Events, total_processed_Events, num_processed_round, num_Events;	//변수선언
	srand(time(0));
	total_processed_Events = 0;	//이벤트 가공횟수 초기화
	total_generated_Events = 0;	//이벤트 생성횟수 초기화
	while (1)
	{
		printf("[Testing Priorty Queue]\n");
		printf("Input num_Events per round(1~128):");
		scanf("%d", &max_Events_per_round);	//round 입력
		if (max_Events_per_round <= 128 && max_Events_per_round >= 1)
			break;
	}

	PriQ_Event* pPriQ_Event;
	Event* pEvent = NULL;
	Event generated_Events[TOTAL_NUM_EVENTS];	//matrix 선언
	Event processed_Events[TOTAL_NUM_EVENTS];
	pPriQ_Event = (PriQ_Event*)malloc(sizeof(PriQ_Event));	//Event memory 생성
	if (pPriQ_Event == NULL)
	{
		printf("Error in malloc() for PriQ_Event !\n");
		exit(-1);
	}
	printf("Initializing PriQ_Event of capacity (%d)\n", INIT_PriQ_SIZE);	//PriQ용량 출력
	initPriQ_Event(pPriQ_Event, "PriQ_Event", INIT_PriQ_SIZE);	//PriQ 초기화
	for (int round = 0; round < MAX_ROUND; round++)
	{
		num_generated_round = 0;
		if (total_generated_Events < TOTAL_NUM_EVENTS)	//생성된 이벤트가 최대 이벤트보다 작은경우
		{
			num_Events = max_Events_per_round;
			if ((total_generated_Events + num_Events) > TOTAL_NUM_EVENTS)
				num_Events = TOTAL_NUM_EVENTS - total_generated_Events;
			for (int i = 0; i < num_Events; i++)
			{
				pEvent = genEvent(total_generated_Events, TOTAL_NUM_EVENTS - total_generated_Events - 1);	//이벤트 생성
				if (pEvent == NULL)
				{
					printf("Error in generation of event !!\n");
					exit(-1);
				}
				enPriQ_Event(pPriQ_Event, pEvent);	//Queue에 이벤트 입력
				generated_Events[total_generated_Events] = *pEvent;
				total_generated_Events++;
				num_generated_round++;
			}
		}
		num_Events = max_Events_per_round;
		if ((total_processed_Events + num_Events) > TOTAL_NUM_EVENTS)
			num_Events = TOTAL_NUM_EVENTS - total_processed_Events;
		num_processed_round = 0;
		for (int i = 0; i < num_Events; i++)
		{
			pEvent = dePriQ_Event(pPriQ_Event);
			if (pEvent == NULL)
			{
				break;
			}
			processed_Events[total_processed_Events] = *pEvent;	//배열에 이벤트 입력
			free(pEvent);	//memory free
			total_processed_Events++;
			num_processed_round++;
		}
		printf("Round(%2d): generated_in_this_round(%3d), total_generated_events (%3d),	processed_in_this_round(% 3d), total_processed_Events(% 3d), events_in_PriQ_Event(% 3d)\n", round, num_generated_round, total_generated_Events, num_processed_round, total_processed_Events, pPriQ_Event->priQ_size);
		if (total_processed_Events >= TOTAL_NUM_EVENTS)	//최대 이벤트보다 많이 생성된 경우 중단
			break;
	}
	printf("\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//이벤트 출력
	{
		printf("Event(id:%3d, pri:%3d), ", generated_Events[i].Event_no, generated_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	fprintf(fout, "\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//파일에 이벤트 출력
	{
		fprintf(fout, "Event(id:%3d, pri:%3d), ", generated_Events[i].Event_no, generated_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");

	printf("Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//가공된 이벤트 출력
	{
		printf("Event(id:%3d, pri:%3d), ", processed_Events[i].Event_no, processed_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	fprintf(fout, "Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//가공된 이벤트 출력
	{
		fprintf(fout,  "Event(id:%3d, pri:%3d), ", processed_Events[i].Event_no, processed_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");

	deletePriQ_Event(pPriQ_Event);
	free(pPriQ_Event);
	return 0;
}