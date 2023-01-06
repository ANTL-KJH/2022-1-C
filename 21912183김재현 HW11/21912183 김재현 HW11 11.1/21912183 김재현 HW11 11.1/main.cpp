/*
* 파일명 : "21912183 김재현 HW11 11.1.sln"
* 프로그램의 목적 및 기본 기능 :
* -Cir Queue를 이용하여 최대 128개의 Event를 처리하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.05.22
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.05.22	v1.0	최초작성
*/
#include "STD.h"
#include "CirQ_Event.h"
#include "Event.h"
#include "time.h"
int main()
{
	FILE* fout;
	const char* FIL_O = "output.txt";
	fout = fopen(FIL_O, "w");
	CirQ_Event* pCirQ_Event;
	Event event, * pEv = NULL;
	int max_events_per_round = 5, capa;
	Event processed_events[TOTAL_NUM_EVENTS];	//Matrix 선언
	Event generated_events[TOTAL_NUM_EVENTS];
	int num_generated_events = 0, total_generated_events = 0, num_events = 0, total_processed_events = 0, num_processed_events = 0;	//변수 선언
	while (1)
	{
		printf("Testing Event Handling with FIFO Circular Queue\n");
		printf("Input capacity:");
		scanf("%d", &capa);
		if (capa <= 128 && capa > 0)
			break;
		printf("ERROR : Wrong Input!! Capacity can be in 1~128\n\n");
	}
	pCirQ_Event = (CirQ_Event*)calloc(1, sizeof(CirQ_Event));	//Dynamic memory allocation
	printf("Initializing FIFO_CirQ of capacity (%d)\n", capa);
	pCirQ_Event = initCirQ_Event(pCirQ_Event, capa);	//CirQ Reset
	for (int round = 0; round < TOTAL_NUM_EVENTS; round++)	//Max round는 128
	{
		num_generated_events = 0;
		if (total_generated_events < TOTAL_NUM_EVENTS)	//생성된 이벤트가 최대 이벤트보다 작은경우
		{
			num_events = capa;
			if ((total_generated_events + num_events) > TOTAL_NUM_EVENTS)
				num_events = TOTAL_NUM_EVENTS - total_generated_events;
			for (int i = 0; i < num_events; i++)	//생성된 랜덤 개수에 맞춰 이벤트 생성
			{
				if (isCirQFull(pCirQ_Event))
					break;
				pEv = genEvent(total_generated_events, TOTAL_NUM_EVENTS - total_generated_events - 1);	//이벤트 생성
				if (enCirQ_Event(pCirQ_Event, *pEv) != NULL)
				{
					generated_events[total_generated_events] = *pEv;
					total_generated_events++;
					num_generated_events++;
				}
				free(pEv);
			}
		}
		
		if ((total_processed_events + num_events) > TOTAL_NUM_EVENTS)
			num_events = TOTAL_NUM_EVENTS - total_processed_events;
		num_processed_events = 0;
		for (int i = 0; i < num_events; i++)
		{
			if (isCirQEmpty(pCirQ_Event))	//Queue가 비어있는지 확인
				break;
			pEv = deCirQ_Event(pCirQ_Event);	//Queue에서 먼저 생성된 Event 제거
			if (pEv != NULL)
			{
				processed_events[total_processed_events] = *pEv;
				total_processed_events++;
				num_processed_events++;
			}
		}
		printf("Round(%2d): generated_in_this_round(%3d), total_generated(%3d), processed_in_this_round	(% 3d), total_processed_events(% 3d), events_in_CirQ(% 3d)\n", round, num_generated_events, total_generated_events, num_processed_events, total_processed_events, pCirQ_Event->num_elements);
		if (total_processed_events >= TOTAL_NUM_EVENTS)
			break;
	}
	printf("\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//생성된 이벤트 출력
	{
		printf("Event(id:%3d, pri:%3d), ", generated_events[i].event_no, generated_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	fprintf(fout, "\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//생성된 이벤트 출력
	{
		fprintf(fout, "Event(id:%3d, pri:%3d), ", generated_events[i].event_no, generated_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
	printf("Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//가공된 이벤트 출력
	{
		printf("Event(id:%3d, pri:%3d), ", processed_events[i].event_no, processed_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	fprintf(fout, "\n");

	fprintf(fout, "Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//가공된 이벤트 출력
	{
		fprintf(fout, "Event(id:%3d, pri:%3d), ", processed_events[i].event_no, processed_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	printf("\n");

	delCirQ_Event(pCirQ_Event);	//이벤트 메모리 반납
	free(pCirQ_Event);	//memonry free
	fclose(fout);
	return 0;
}