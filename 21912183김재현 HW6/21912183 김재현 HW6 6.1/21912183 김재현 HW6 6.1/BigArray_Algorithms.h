/*BigArray_Algorithms.h*/
#ifndef BigArray_Algorithms_H
#define BigArray_Algorithms_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define LINE_SIZE 10
#define SAMPLE_LINE 2
#pragma warning(disable: 4996)
void genBigRandArray(int array[], int bigRandSize, int offset);
void printBigArraySample(int* array, int size, int line_size, int num_sample_lines);
void suffleArray(int* array, int size);
#endif