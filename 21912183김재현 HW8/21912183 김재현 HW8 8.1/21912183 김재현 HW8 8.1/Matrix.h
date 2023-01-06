/*Matrix.h*/
#ifndef Matirx_h
#define Matrix_h

void printMtrx(const char* p, double** mA, int row_size, int column_size);
double** createDynamicDoubleMatrix(int row_size, int col_size);
void deleteDynMtrx(double** Mtrx, int row_size, int col_size);
double** fGetMtrx(FILE* fp, int* row_size, int* col_size);
double** addMtrx(double** mA, double** mB, int row_size, int column_size);	//Matrix add
double** subMtrx(double** mA, double** mB, int row_size, int column_size);	//Matrix Sub
double** mulMtrx(double** mA, double** mB, int row_size, int col_size, int n_col_size);	//Matrix Multiply
void fprintMtrx(FILE* fout, double** mA, int row_size, int col_size);   //2차원 배열 출력
#endif