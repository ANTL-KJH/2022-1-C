#ifndef GaussJordan_H
#define GaussJordan_H
#include "StdH.h"
void getAugmentedMatrixData(FILE* fin, double** augMtrx, int size_N);
void diagonalize_FileOut(FILE* fout, double** augMtrx, int size_N, int* solExist);
void pivoting(double** augMtrx, int size_N, int p, int* piv_found);
#define EPSILON 0.000001
#endif