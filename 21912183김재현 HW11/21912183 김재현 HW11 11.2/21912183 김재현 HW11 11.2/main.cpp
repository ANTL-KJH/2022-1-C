/*
* ���ϸ� : "21912183 ������ HW11 11.2.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -128���� �̺�Ʈ�� �켱����ť(PriQ)�� ó���ϴ� �ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.05.22
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.05.22	v1.0	�����ۼ�
*/

#include "STD.h"
#include "Event.h"
#include "PriQ_Event.h"

int main()
{
	const char* FIL_O = "output.txt";
	FILE* fout;
	fout = fopen(FIL_O, "w");
	int max_Events_per_round, num_generated_round, total_generated_Events, total_processed_Events, num_processed_round, num_Events;	//��������
	srand(time(0));
	total_processed_Events = 0;	//�̺�Ʈ ����Ƚ�� �ʱ�ȭ
	total_generated_Events = 0;	//�̺�Ʈ ����Ƚ�� �ʱ�ȭ
	while (1)
	{
		printf("[Testing Priorty Queue]\n");
		printf("Input num_Events per round(1~128):");
		scanf("%d", &max_Events_per_round);	//round �Է�
		if (max_Events_per_round <= 128 && max_Events_per_round >= 1)
			break;
	}

	PriQ_Event* pPriQ_Event;
	Event* pEvent = NULL;
	Event generated_Events[TOTAL_NUM_EVENTS];	//matrix ����
	Event processed_Events[TOTAL_NUM_EVENTS];
	pPriQ_Event = (PriQ_Event*)malloc(sizeof(PriQ_Event));	//Event memory ����
	if (pPriQ_Event == NULL)
	{
		printf("Error in malloc() for PriQ_Event !\n");
		exit(-1);
	}
	printf("Initializing PriQ_Event of capacity (%d)\n", INIT_PriQ_SIZE);	//PriQ�뷮 ���
	initPriQ_Event(pPriQ_Event, "PriQ_Event", INIT_PriQ_SIZE);	//PriQ �ʱ�ȭ
	for (int round = 0; round < MAX_ROUND; round++)
	{
		num_generated_round = 0;
		if (total_generated_Events < TOTAL_NUM_EVENTS)	//������ �̺�Ʈ�� �ִ� �̺�Ʈ���� �������
		{
			num_Events = max_Events_per_round;
			if ((total_generated_Events + num_Events) > TOTAL_NUM_EVENTS)
				num_Events = TOTAL_NUM_EVENTS - total_generated_Events;
			for (int i = 0; i < num_Events; i++)
			{
				pEvent = genEvent(total_generated_Events, TOTAL_NUM_EVENTS - total_generated_Events - 1);	//�̺�Ʈ ����
				if (pEvent == NULL)
				{
					printf("Error in generation of event !!\n");
					exit(-1);
				}
				enPriQ_Event(pPriQ_Event, pEvent);	//Queue�� �̺�Ʈ �Է�
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
			processed_Events[total_processed_Events] = *pEvent;	//�迭�� �̺�Ʈ �Է�
			free(pEvent);	//memory free
			total_processed_Events++;
			num_processed_round++;
		}
		printf("Round(%2d): generated_in_this_round(%3d), total_generated_events (%3d),	processed_in_this_round(% 3d), total_processed_Events(% 3d), events_in_PriQ_Event(% 3d)\n", round, num_generated_round, total_generated_Events, num_processed_round, total_processed_Events, pPriQ_Event->priQ_size);
		if (total_processed_Events >= TOTAL_NUM_EVENTS)	//�ִ� �̺�Ʈ���� ���� ������ ��� �ߴ�
			break;
	}
	printf("\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//�̺�Ʈ ���
	{
		printf("Event(id:%3d, pri:%3d), ", generated_Events[i].Event_no, generated_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	fprintf(fout, "\nGenerated Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//���Ͽ� �̺�Ʈ ���
	{
		fprintf(fout, "Event(id:%3d, pri:%3d), ", generated_Events[i].Event_no, generated_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			fprintf(fout, "\n");
	}
	fprintf(fout, "\n");

	printf("Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//������ �̺�Ʈ ���
	{
		printf("Event(id:%3d, pri:%3d), ", processed_Events[i].Event_no, processed_Events[i].Event_pri);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	fprintf(fout, "Processed Events :\n");
	for (int i = 0; i < TOTAL_NUM_EVENTS; i++)	//������ �̺�Ʈ ���
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