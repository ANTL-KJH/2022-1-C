/*
* ���ϸ� : "21912183 ������ HW11 11.1.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -Cir Queue�� �̿��Ͽ� �ִ� 128���� Event�� ó���ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.05.22
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.05.22	v1.0	�����ۼ�
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
	Event processed_events[TOTAL_NUM_EVENTS];	//Matrix ����
	Event generated_events[TOTAL_NUM_EVENTS];
	int num_generated_events = 0, total_generated_events = 0, num_events = 0, total_processed_events = 0, num_processed_events = 0;	//���� ����
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
	for (int round = 0; round < TOTAL_NUM_EVENTS; round++)	//Max round�� 128
	{
		num_generated_events = 0;
		if (total_generated_events < TOTAL_NUM_EVENTS)	//������ �̺�Ʈ�� �ִ� �̺�Ʈ���� �������
		{
			num_events = capa;
			if ((total_generated_events + num_events) > TOTAL_NUM_EVENTS)
				num_events = TOTAL_NUM_EVENTS - total_generated_events;
			for (int i = 0; i < num_events; i++)	//������ ���� ������ ���� �̺�Ʈ ����
			{
				if (isCirQFull(pCirQ_Event))
					break;
				pEv = genEvent(total_generated_events, TOTAL_NUM_EVENTS - total_generated_events - 1);	//�̺�Ʈ ����
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
			if (isCirQEmpty(pCirQ_Event))	//Queue�� ����ִ��� Ȯ��
				break;
			pEv = deCirQ_Event(pCirQ_Event);	//Queue���� ���� ������ Event ����
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
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//������ �̺�Ʈ ���
	{
		printf("Event(id:%3d, pri:%3d), ", generated_events[i].event_no, generated_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	fprintf(fout, "\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//������ �̺�Ʈ ���
	{
		fprintf(fout, "Event(id:%3d, pri:%3d), ", generated_events[i].event_no, generated_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
	printf("Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//������ �̺�Ʈ ���
	{
		printf("Event(id:%3d, pri:%3d), ", processed_events[i].event_no, processed_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	fprintf(fout, "\n");

	fprintf(fout, "Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//������ �̺�Ʈ ���
	{
		fprintf(fout, "Event(id:%3d, pri:%3d), ", processed_events[i].event_no, processed_events[i].event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	printf("\n");

	delCirQ_Event(pCirQ_Event);	//�̺�Ʈ �޸� �ݳ�
	free(pCirQ_Event);	//memonry free
	fclose(fout);
	return 0;
}