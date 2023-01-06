/*PriQ.cpp*/
#include "STD.h"
#include "PriQ_Event.h"

PriQ_Event* initPriQ_Event(PriQ_Event* pPriQ_Event, const char* name, int capacity)	//PriQ�� �ʰ�ȭ�ϴ� �Լ�
{
	strcpy(pPriQ_Event->PriQ_name, name);
	pPriQ_Event->priQ_capacity = capacity;
	pPriQ_Event->pCBT_Event = (CBTN_Event*)calloc((capacity + 1), sizeof(CBTN_Event));	//Dynamic memory allocation
	pPriQ_Event->priQ_size = 0;	//size �ʱ�ȭ
	pPriQ_Event->pos_last = 0;	//last �ʱ�ȭ
	return pPriQ_Event;
}

int enPriQ_Event(PriQ_Event* pPriQ_Event, Event* pEvent)
{
	int pos, pos_parent, pos_last;
	CBTN_Event CBTN_Event_Temp;
	if (pPriQ_Event->priQ_size >= pPriQ_Event->priQ_capacity)	//PriQueue Event�� �뷮���� ū ���
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
		for (int pos = 1; pos <= pPriQ_Event->priQ_size; pos++)	//element 0 ������� 1������ Event�Է�
		{
			newCBT_Event[pos] = pPriQ_Event->pCBT_Event[pos];
		}
		free(pPriQ_Event->pCBT_Event);
		pPriQ_Event->pCBT_Event = newCBT_Event;
		pPriQ_Event->priQ_capacity = newCapacity;
	}
	pos = pos_last = ++pPriQ_Event->priQ_size;
	pPriQ_Event->pCBT_Event[pos].priority = pEvent->Event_pri;	//�켱���� �Է�
	pPriQ_Event->pCBT_Event[pos].pEvent = pEvent; //�̺�Ʈ �ּ� �Է�
	while (pos != POS_ROOT)
	{
		pos_parent = pos / 2;	//�θ� ��ġ�� child ��ġ/2
		if (pPriQ_Event->pCBT_Event[pos].priority >= pPriQ_Event->pCBT_Event[pos_parent].priority)	//�θ�� �켱���� ��
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

Event* dePriQ_Event(PriQ_Event* pPriQ_Event)	//PriQueue�� �ִ� Event�� ���� �ϴ� �Լ�
{
	Event* pEv;
	CBTN_Event CBTN_Event_temp;
	int pos, pos_last, pos_child;
	if (pPriQ_Event->priQ_size <= 0)	//PriQ�� ����ִ� ���
		return NULL;
	pEv = pPriQ_Event->pCBT_Event[1].pEvent; //���� �ֻ�� �ּ�
	pos_last = pPriQ_Event->priQ_size;
	--pPriQ_Event->priQ_size;
	if (pPriQ_Event->priQ_size > 0)	//down bubbling start
	{
		pPriQ_Event->pCBT_Event[POS_ROOT] = pPriQ_Event->pCBT_Event[pos_last];	//�������� �ִ� child�� root�� ������(�ֻ�� �θ� delete)
		pos_last--;
		pos = POS_ROOT;
		while (hasLeftChild(pos, pPriQ_Event))	//�ֻ�� ���� ���� chlid Ȯ��
		{
			pos_child = pos * 2;
			if (hasRightChild(pos, pPriQ_Event))	//������ child ���� Ȯ��
			{
				if (pPriQ_Event->pCBT_Event[pos_child].priority > pPriQ_Event->pCBT_Event[pos_child + 1].priority)	//���� child�� ������ child �켱���� check
					pos_child = pos * 2 + 1;	//������ child�� �켱������ �� ������� ������ child�� ��ġ ����
			}
			if (pPriQ_Event->pCBT_Event[pos_child].priority < pPriQ_Event->pCBT_Event[pos].priority)	//�켱������ ���� child�� swap
			{
				CBTN_Event_temp = pPriQ_Event->pCBT_Event[pos];
				pPriQ_Event->pCBT_Event[pos] = pPriQ_Event->pCBT_Event[pos_child];
				pPriQ_Event->pCBT_Event[pos_child] = CBTN_Event_temp;
			}
			else //�θ��� �켱������ ���ٸ� break
				break;
			pos = pos_child;	//����� child�� ��ġ���� �ٽ� down bubbling
		}
	}
	return pEv;
}

void printPriQ_Event(PriQ_Event* pPriQ_Event)	//PriQueue�� �ִ� Event�� ����ϴ� �Լ�
{
	int pos, count, count_per_line;
	int eventPriority;
	int level = 0, level_count = 1;
	Event* pEv;
	if (pPriQ_Event->priQ_size == 0)	//Queue size�� 0�̸� return
	{
		printf("PriorityQueue_Event is empty !!\n");
		return;
	}
	pos = 1;
	count = 1;
	level = 0;
	level_count = 1;
	printf("\n CompBinTree :\n", level);
	while (count <= pPriQ_Event->priQ_size)	//count�� size���� ���� ��
	{
		printf(" level%2d : ", level);
		count_per_line = 0;
		while (count_per_line < level_count)
		{
			pEv = pPriQ_Event->pCBT_Event[pos].pEvent;	//Event ��ġ ����
			eventPriority = pPriQ_Event->pCBT_Event[pos].priority;	//�켱���� ����
			printEvent(pEv);	//Event ���
			pos++;
			count++;
			if (count > pPriQ_Event->priQ_size)		//count�� size�� �ʰ��ϸ� break
				break;
			count_per_line++;
			if ((count_per_line % EVENT_PER_LINE) == 0)	//���ٿ� 5�� ����ϰ� �ٹٲ�
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

void fprintPriQ_Event(FILE* fout, PriQ_Event* pPriQ_Event)	//PriQueue�� �ִ� Event�� ���Ͽ� ����ϴ� �Լ�
{
	int pos, count, count_per_line;
	int eventPriority;
	int level = 0, level_count = 1;
	Event* pEv;
	if (pPriQ_Event->priQ_size == 0)	//Queue size�� 0�̸� return
	{
		fprintf(fout, "PriorityQueue_Event is empty !!\n");
		return;
	}
	pos = 1;
	count = 1;
	level = 0;
	level_count = 1;
	fprintf(fout, "\n CompBinTree :\n", level);
	while (count <= pPriQ_Event->priQ_size)	//count�� size���� ���� ��
	{
		fprintf(fout, " level%2d : ", level);
		count_per_line = 0;
		while (count_per_line < level_count)
		{
			pEv = pPriQ_Event->pCBT_Event[pos].pEvent;	//Event ��ġ ����
			eventPriority = pPriQ_Event->pCBT_Event[pos].priority;	//�켱���� ����
			fprintEvent(fout, pEv);	//Event ���
			pos++;
			count++;
			if (count > pPriQ_Event->priQ_size)	//count�� size�� �ʰ��ϸ� break
				break;
			count_per_line++;
			if ((count_per_line % EVENT_PER_LINE) == 0)	//���ٿ� 5�� ����ϰ� �ٹٲ�
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

void deletePriQ_Event(PriQ_Event* pPriQ_Event)	//memory return�ϴ� �Լ�
{
	CBTN_Event* pCBTN_Ev;
	for (int i = 0; i < pPriQ_Event->priQ_size; i++)
	{
		pCBTN_Ev = &(pPriQ_Event->pCBT_Event)[i];
		if (pCBTN_Ev != NULL)	//pCBTN_Ev�� ����ְ�
		{
			if (pCBTN_Ev->pEvent != NULL)	//pEvent�� ��������� memory �ݳ�
				free(pCBTN_Ev->pEvent);
			free(pCBTN_Ev);
		}
	}
}

bool hasLeftChild(int pos, PriQ_Event* pPriQ_Ev)	//���� child�� ���� ���� Ȯ��
{
	if (pos * 2 <= pPriQ_Ev->priQ_size) //���� child ���� Ȯ��
		return TRUE;
	else
		return FALSE;
}
bool hasRightChild(int pos, PriQ_Event* pPriQ_Ev)	//������ child ���� ���� Ȯ��
{
	if (pos * 2 + 1 <= pPriQ_Ev->priQ_size)	//������ child ���� Ȯ��
		return TRUE;
	else
		return FALSE;
}