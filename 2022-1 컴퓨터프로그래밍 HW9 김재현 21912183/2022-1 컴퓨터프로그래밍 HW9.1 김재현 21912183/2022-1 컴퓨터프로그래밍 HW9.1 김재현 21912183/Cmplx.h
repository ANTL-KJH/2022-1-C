/*Cmplx.h*/
#ifndef CMPLX_H
#define CMPLX_H
typedef struct
{
	double real;	//실수부
	double imag;	//허수부
} Cmplx;
Cmplx inputCmplx(void);	//복소수를 입력받는 함수
void printCmplx(const Cmplx c);	//복소수를 출력하는 함수
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2);	//복소수의 덧셈
Cmplx cmplxSub(const Cmplx c1, const Cmplx c2);	//복소수의 뺄셈
Cmplx cmplxMul(const Cmplx c1, const Cmplx c2);	//복소수의 곱셈
Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2);	//복소수의 나눗셈
double compareCmplx(const Cmplx c1, const Cmplx c2);	//복소수의 비교
void sortCmplx(Cmplx cmplxs[], int size);	//복소수 정렬
void _sortCmplx(Cmplx cmplxs[], int size, int left, int right);
int _partition(Cmplx complxs[], int size, int left, int right, int pivotIndex);	//Quick sorting 파티션
#endif