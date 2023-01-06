/*Cmplx.h*/
#ifndef CMPLX_H
#define CMPLX_H
typedef struct
{
	double real;	//�Ǽ���
	double imag;	//�����
} Cmplx;
Cmplx inputCmplx(void);	//���Ҽ��� �Է¹޴� �Լ�
void printCmplx(const Cmplx c);	//���Ҽ��� ����ϴ� �Լ�
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2);	//���Ҽ��� ����
Cmplx cmplxSub(const Cmplx c1, const Cmplx c2);	//���Ҽ��� ����
Cmplx cmplxMul(const Cmplx c1, const Cmplx c2);	//���Ҽ��� ����
Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2);	//���Ҽ��� ������
double compareCmplx(const Cmplx c1, const Cmplx c2);	//���Ҽ��� ��
void sortCmplx(Cmplx cmplxs[], int size);	//���Ҽ� ����
void _sortCmplx(Cmplx cmplxs[], int size, int left, int right);
int _partition(Cmplx complxs[], int size, int left, int right, int pivotIndex);	//Quick sorting ��Ƽ��
#endif