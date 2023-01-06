/*DLL_EvQ.cpp*/
#include "STD.h"
#include "DLL_EvQ.h"

void initDLL_EvQ(DLL_EvQ* pEvQ, int pri)	//Doubly Linked List �ʱ�ȭ
{
	pEvQ->cs_EvQ.lock();
	pEvQ->priority = pri;
	pEvQ->front = pEvQ->back = NULL;
	pEvQ->num_event = 0;
	pEvQ->cs_EvQ.unlock();
}

Event* enDLL_EvQ(DLL_EvQ* pEvQ, Event* pEv)	//Event�� Doubly Linked List PriQ�� �Է�
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
	if (pLN_Ev == NULL)	//���� �޸� �Ҵ��� �ȵ� ���
	{
		printf("Error in enDLL_EvQ :: memory allocation for new DLLN failed !!\n");
		printf("Press any key to continue ...\n");
		getc(stdin);
		return NULL;
	}
	pLN_Ev->pEv = pEv;	//�̺�Ʈ �ּҸ� DLL�� ����
	pEvQ->cs_EvQ.lock();	//Event lock
	if (pEvQ->num_event == 0) //DLL�� ����ִ°��
	{
		pEvQ->front = pEvQ->back = pLN_Ev;	//ó���� ���� �Է��� Event�� ����
		pLN_Ev->prev = pLN_Ev->next = NULL;	//������ ������ ����
		pEvQ->num_event = 1;	//DLL�� �Էµ� �̺�Ʈ�� 1��
	}
	else
	{
		pLN_Ev->prev = pEvQ->back;	//new Event�� prev�� ���� DLL�� back�� ����
		pEvQ->back->next = pLN_Ev;	//���� Event�� back�� new Event�� ����
		pEvQ->back = pLN_Ev;	//back�� new Event�� �缳��
		pLN_Ev->next = NULL;	//back�� next�� NULL
		pEvQ->num_event++;
	}
	pEvQ->cs_EvQ.unlock();	//unlock
	return pLN_Ev->pEv;
}

Event* deDLL_EvQ(DLL_EvQ* pEvQ)	//Event�� Doubly���� �����ϴ� �Լ�
{
	Event* pEv;
	DLLN_Ev* pLN_Ev_OldFront;
	pEvQ->cs_EvQ.lock();
	if (pEvQ->num_event <= 0)	//DLL EventQ�� ����ִ� ���
	{
		pEvQ->cs_EvQ.unlock();
		return NULL;
	}
	else
	{
		pLN_Ev_OldFront = pEvQ->front;
		pEv = pEvQ->front->pEv;	//front Event ����
		pEvQ->front = pEvQ->front->next;	//front�� next�� ������
		if (pEvQ->front != NULL)	//���� front�� �� DLL Event�� prev�� NULL�� ����
			pEvQ->front->prev = NULL;
		pEvQ->num_event--;
		free(pLN_Ev_OldFront); //������ front free
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
	if (pEvQ == NULL)	//EventQ�� ��������� 
	{
		printf("Error in printDLL_EvQ :: DLL_EvQ is NULL !!");
		printf("Press any key to continue ...\n");
		getc(stdin);
	}
	if (pEvQ->num_event <= 0)	//Event�� ������ return
		return;
	pLN_Ev = pEvQ->front;	//DLN�� front����
	count = 0;
	while (pLN_Ev != NULL)
	{
		pEv = pLN_Ev->pEv;
		if (pEv == NULL)
			break;
		printEvent(pEv);	//Event ���
		printf(" ");
		count++;
		if ((count % 5) == 0)
			printf("\n ");
		pLN_Ev = pLN_Ev->next;	//next�� �Ѿ�� ���
	}
}