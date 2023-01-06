/*
* ���ϸ� : "main.c"
* ���α׷��� ���� �� �⺻ ��� :
* -Array Size�� ����Quick Sort, Merge Sort, Selection Sort�� ����ӵ��� ���ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.04.04
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.04.04	v1.0	�����ۼ�
* ������			2022.04.06	v1.1	�ۼ��Ϸ�
*/

#include "BigArray_Algorithms.h"
#include "Sorting_Algorithms.h"
void Compare_Sorting_Algorithms_SmallIntArray(void);
void testBigRandArray(void);
void Compare_Sorting_Algorithms_BigIntArray(void);

int main(void)
{
	int menu;
	srand(0);
	while (1)
	{
		printf("\nTest Array Algorithms :\n");
		printf(" 1: Performance Comparison of Selection Sort and Quick Sort for Small Integer Array\n");
		printf(" 2: Test bigRandArray (Array_size : 1,000,000 ~ 50,000,000)\n");
		printf(" 3: Performance Comparison of Selection Sort and Quick Sort for Big Integer Array\n");
		printf("Input menu (0 to terminate) : ");
		scanf_s("%d", &menu);
		if (menu == 0)
			break;
		switch (menu)
		{
		case 1:
			Compare_Sorting_Algorithms_SmallIntArray();	//�� sorting����� ����ð� ��
			break;
		case 2:
			testBigRandArray();	//bigRand�� �����ϰ� shuffle�ѵ� hybirdsorting
			break;
		case 3:
			Compare_Sorting_Algorithms_BigIntArray();	//quick sorting�� hybridsorting ��
			break;
		default:
			break;
		}
	} return 0;
}

void Compare_Sorting_Algorithms_SmallIntArray(void)
{
	int* array, * array_tmp, * array_tmp_2;
	int base = 0;
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time_us;
	double elps_time_quickSort_us, elps_time_selectSort_us, elps_time_mergeSort_us;
	QueryPerformanceFrequency(&freq);	//CPU Clock Check
	printf("Compare the performance of sorting algorithms for small array\n");
	printf("==================================================================\n");
	printf("    Array size   QuickSort[us]   MergeSort[us]  SelectionSort[us]\n");
	printf("------------------------------------------------------------------\n");
	for (int size = 10; size <= 100; size += 5)	//�ּ� 10������ 5�������� �÷����� �ִ� 100������ ����
	{
		array = (int*)calloc(size, sizeof(int));
		array_tmp = (int*)calloc(size, sizeof(int));
		array_tmp_2 = (int*)calloc(size, sizeof(int));
		genBigRandArray(array, size, 0);	//bigrand ����
		QueryPerformanceCounter(&t_before);
		quickSort(array, size);	//Quick Sorting
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); // in micro-second
		elps_time_quickSort_us = elapsed_time_us;


		QueryPerformanceCounter(&t_before);
		mergeSort(array_tmp, size);	//Merge Sorting
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); // in micro-second
		elps_time_mergeSort_us = elapsed_time_us;

		QueryPerformanceCounter(&t_before);
		selectionSort(array_tmp_2, 0, size - 1);	//Selection Sorting
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); // in micro-second
		elps_time_selectSort_us = elapsed_time_us;

		printf("%10d %15.2lf %15.2lf %15.2lf\n", size, elps_time_quickSort_us, elps_time_mergeSort_us, elps_time_selectSort_us);
		free(array);
		free(array_tmp);
		free(array_tmp_2);

	}
	printf("------------------------------------------------------------------\n");
}

void testBigRandArray(void)
{
	int offset = 0, size = 0;
	int* array;
	while (1)
	{
		printf("Input bigRandArray_size (0 to quit) and offset : ");
		scanf_s("%d %d", &size, &offset);
		if (size == 0)
		{
			return;
		}
		else if (size < 1000000 || size > 50000000)		//rage of size
		{
			printf("Wrong Input\n");
			continue;
		}
		else
			break;
	}

	array = (int*)calloc(size, sizeof(int));	//dynamic memory allocation
	printf("Generated non-duplicated random array : \n");
	genBigRandArray(array, size, offset);	//bigrand ����
	printBigArraySample(array, size, LINE_SIZE, SAMPLE_LINE);	//printout bigrand sample
	printf("Sorted array : \n");
	hybridQuickSelectionSort(array, size);
	printBigArraySample(array, size, LINE_SIZE, SAMPLE_LINE);
	free(array);
}
void Compare_Sorting_Algorithms_BigIntArray(void)
{
	int* array, * array_tmp, * array_tmp_2;
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time_us;
	double elps_time_quickSort_us, elps_time_selectSort_us, elps_time_mergeSort_us;
	printf("Compare the performance of sorting algorithms for Big array\n");
	printf("==================================================================\n");
	printf("    Array size   QuickSort[ms]   MergeSort[ms]  SelectionSort[ms]\n");
	printf("------------------------------------------------------------------\n");
	for (int size = 10000; size <= 40960000; size = size * 2)	//�ּ� 10������ 5�������� �÷����� �ִ� 100������ ����
	{
		array = (int*)calloc(size, sizeof(int));
		array_tmp = (int*)calloc(size, sizeof(int));
		array_tmp_2 = (int*)calloc(size, sizeof(int));
		QueryPerformanceFrequency(&freq);
		genBigRandArray(array, size, 0);	//bigrand ����
		QueryPerformanceCounter(&t_before);
		quickSort(array, size);	//Quick Sorting
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000 / freq.QuadPart); // in micro-second
		elps_time_quickSort_us = elapsed_time_us;
		for (int i = 0; i < size; i++)
		{
			array_tmp[i] = array[i];
			array_tmp_2[i] = array[i];
		}

		QueryPerformanceCounter(&t_before);
		mergeSort(array_tmp, size);	//Merge Sorting
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000 / freq.QuadPart); // in micro-second
		elps_time_mergeSort_us = elapsed_time_us;

		suffleArray(array, size);	//array shuffle
		if (size <= 640000)
		{
			if (size <= 320000)
			{
				QueryPerformanceCounter(&t_before);
				selectionSort(array_tmp_2, 0, size - 1);	//Selection Sorting
				QueryPerformanceCounter(&t_after);
				t_diff = t_after.QuadPart - t_before.QuadPart;
				elapsed_time_us = ((double)t_diff * 1000 / freq.QuadPart); // in micro-second
				elps_time_selectSort_us = elapsed_time_us;
				printf("%10d %15.2lf %15.2lf %15.2lf\n", size, elps_time_quickSort_us, elps_time_mergeSort_us, elps_time_selectSort_us);
			}
		}
		else
			printf("%10d %15.2lf %15.2lf               -\n", size, elps_time_quickSort_us, elps_time_mergeSort_us);
		free(array);
		free(array_tmp);
		free(array_tmp_2);
	}
	printf("------------------------------------------------------------------\n");
}