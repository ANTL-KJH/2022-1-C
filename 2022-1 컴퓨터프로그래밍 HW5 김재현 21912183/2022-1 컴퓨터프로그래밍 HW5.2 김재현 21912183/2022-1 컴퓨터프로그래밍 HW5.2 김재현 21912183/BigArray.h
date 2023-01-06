/*BigArray.h*/
#ifndef BigArray_H
#define BigArray_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable: 4996)
#define LINE_SIZE 10
#define SAMPLE_LINE_SIZE 2
void genBigRandArray(int* array, int bigRandSize);
void suffleBigArray(int* array, int size);
void printBigArraySample(int* array, int size, int line_size = 10, int num_sample_lines = 2);
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines);
#endif
