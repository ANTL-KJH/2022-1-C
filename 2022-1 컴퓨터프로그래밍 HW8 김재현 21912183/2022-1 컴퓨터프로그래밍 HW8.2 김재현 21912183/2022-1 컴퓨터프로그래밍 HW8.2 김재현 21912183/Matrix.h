/*Matrix.h*/
#ifndef Matirx_h
#define Matrix_h
#include "StdH.h"
void printMtrx(const char* p, double** mA, int row_size, int column_size);
double** fGetAugMtrx(FILE* fin, int* size);
void fprintMtrx(FILE* fout, const char* p, double** mA, int row_size, int col_size);   //2차원 배열 출력
#endif