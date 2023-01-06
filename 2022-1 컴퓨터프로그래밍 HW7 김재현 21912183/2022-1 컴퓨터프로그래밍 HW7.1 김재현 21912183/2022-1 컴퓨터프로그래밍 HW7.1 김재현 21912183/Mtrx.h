#ifndef Test_2D_Dyna_Mtrx_H
#define Test_2D_Dyna_Mtrx_H
#include <stdlib.h>
double** fGetMtrx(FILE* fin, int* row_size, int* col_size);
double** createDoubleMtrx(int row_size, int col_size);
void printMtrx(double** mA, int row_size, int column_size);
void deleteDoubleMtrx(double** ppM, int row_size);
double** addMtrx(double** mA, double** mB, int row_size, int col_size);
double** subMtrx(double** mA, double** mB, int row_size, int col_size);
double** mulMtrx(double** mA, double** mB, int row_size_A, int k_size, int col_size_B);
#endif#pragma once
