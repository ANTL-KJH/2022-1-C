/*Sorting_Algorithms.cpp*/
#include "Sorting_Algorithms.h"

void _mergeSort(int* array, int* tmp_array, int left, int right);
int _partition(int* array, int size, int left, int right, int pivotIndex);
void _quickSort(int* array, int size, int left, int right);
void _hybridQuickSelectionSort(int* bigArray, int size, int left, int right);

void selectionSort(int* array, int left, int right)	//Selection Sort �������� �Լ�
{
	int index_min; //�ּҰ� index
	int minElement; //�ּҰ�
	for (int round = 0; round < right - 1; round++)
	{
		index_min = round;
		minElement = array[round];
		for (int j = round + 1; j < right - 1; j++) //array[round+1]~array[right-1]���� �ּҰ� Ž��
		{
			if (array[j] < minElement)	//array[j]�� �ּҰ����� ������ idx = j, �ּҰ��� array[j]
			{
				index_min = j;
				minElement = array[j];
			}
		}
		if (index_min != round) //�ּҰ����� ���� ���� ã�Ҵٸ� 
		{
			array[index_min] = array[round];
			array[round] = minElement;
		}
	}
}

void _mergeSort(int* array, int* tmp_array, int left, int right)	//Mergesort �Լ�
{
	if (left >= right)
		return;
	int i, j, k, mid = (left + right) / 2;
	_mergeSort(array, tmp_array, left, mid);	//mid�� �������� left�� partition
	_mergeSort(array, tmp_array, mid + 1, right);

	for (i = mid; i >= left; i--)	//array���� tmp_array�� ����
		tmp_array[i] = array[i];
	for (j = 1; j <= right - mid; j++)
		tmp_array[right - j + 1] = array[j + mid];

	for (i = left, j = right, k = left; k <= right; k++)	//value�� ���� array�� ����
	{
		if (tmp_array[i] < tmp_array[j])
			array[k] = tmp_array[i++];
		else
			array[k] = tmp_array[j--];
	}
}

void mergeSort(int* array, int size)
{
	int* tmp_array = (int*)calloc(size, sizeof(int));	//tmp_array dynamic memory allocation
	if (tmp_array == NULL)
	{
		printf("Error in creation of tmp_array (size = %d) in mergeSort() !!!\n", size);
		exit;
	}
	_mergeSort(array, tmp_array, 0, size - 1);
	free(tmp_array);
}

int _partition(int* array, int size, int left, int right, int pivotIndex)
{
	int pivotValue; //pivotValue
	int newPI; //new pivot index
	int temp, i;
	pivotValue = array[pivotIndex];
	array[pivotIndex] = array[right];
	array[right] = pivotValue; //�迭 �� ������ pivotValue �̵�
	newPI = left;
	for (i = left; i <= (right - 1); i++)
	{
		if (array[i] <= pivotValue)	//pivotvalue���� ������ 0�������� ����� newPI�� ��ġ����
		{
			temp = array[i];
			array[i] = array[newPI];
			array[newPI] = temp;
			newPI++;
		}
	}

	pivotValue = array[right];
	array[right] = array[newPI];	//array�� ���� newPI�� ����
	array[newPI] = pivotValue;
	return newPI;
}

void _quickSort(int* array, int size, int left, int right)
{
	int pI, newPI; //pivot index
	if (left >= right)	//left�� right�� ������ return
	{
		return;
	}
	else if (left < right)
	{
		pI = (left + right) / 2;
	}

	newPI = _partition(array, size, left, right, pI);	//newPI�� ��������ġ

	if (left < (newPI - 1))
	{
		_quickSort(array, size, left, newPI - 1); //quicksort ���
	}
	if ((newPI + 1) < right)
	{
		_quickSort(array, size, newPI + 1, right);	//quicksort ���
	}
}
void quickSort(int* array, int size)
{
	_quickSort(array, size, 0, size - 1);
}


void suffleBigArray(int* array, int size)	//�ΰ��� ������ �̾� ���� ��ġ�� �ִ� ���� �ٲٴ� �Լ�
{
	int i1, i2, d;
	srand((unsigned)time(NULL));
	for (int i = 0; i < size / 2; i++)
	{
		i1 = (((unsigned int)rand() << 15) | rand()) % size;
		i2 = (((unsigned int)rand() << 15) | rand()) % size;
		d = array[i1];
		array[i1] = array[i2];
		array[i2] = d;
	}
}

void hybridQuickSelectionSort(int* bigArray, int size)	//quickSort�� selectionsort�� ���� �������� sort
{
	_hybridQuickSelectionSort(bigArray, size, 0, size - 1);
}

void _hybridQuickSelectionSort(int* array, int size, int left, int right)
{
	int pI, newPI; //pivot index
	int pivotValue; //pivotValue
	int temp, i;
	if (right - left < QUICK_SELECTION_THRESHOLD)
	{
		selectionSort(array, left, right);
		return;
	}
	if (left >= right)	//left�� right�� ������ return
	{
		return;
	}
	else if (left < right)
	{
		pI = (left + right) / 2;
	}

	pivotValue = array[pI];	//partition ���� start
	array[pI] = array[right];
	array[right] = pivotValue; //�迭 �� ������ pivotValue �̵�
	newPI = left;
	for (i = left; i <= (right - 1); i++)
	{
		if (array[i] <= pivotValue)	//pivotvalue���� ������ 0�������� ����� newPI�� ��ġ����
		{
			temp = array[i];
			array[i] = array[newPI];
			array[newPI] = temp;
			newPI++;
		}
	}

	pivotValue = array[right];
	array[right] = array[newPI];	//array�� ���� newPI�� ����
	array[newPI] = pivotValue;	//partition���� end

	if (left < (newPI - 1))
	{
		_quickSort(array, size, left, newPI - 1);	//quicksort ���
	}
	if ((newPI + 1) < right)
	{
		_quickSort(array, size, newPI + 1, right);	//quicksort ���
	}
}