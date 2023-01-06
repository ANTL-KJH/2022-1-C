/*Sorting_Algorithms.h*/
#ifndef Sorting_Algorithms_H
#define Sorting_Algorithms_H
#include <stdio.h>
#include <Stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)
#define QUICK_SELECTION_THRESHOLD 20
#define ITEMS_PER_LINE 10
#define NUM_SAMPLE_LINES 2
void selectionSort(int* array, int left, int right);
void mergeSort(int* array, int size);
void quickSort(int* array, int size);
void hybridQuickSelectionSort(int* array, int size);
void suffleBigArray(int* array, int size);
#endif