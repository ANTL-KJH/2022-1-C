/*Cmplx_C.cpp*/
#include "StdH.h"
#include "Cmplx.h"

Cmplx inputCmplx(void)	//���Ҽ��� �Է¹޴� �Լ�
{
	Cmplx c;
	printf("Input complex number (rrr.ddd iii.ddd) : ");
	scanf("%lf %lf", &c.real, &c.imag);
	return c;
}

void printCmplx(const Cmplx c)	//���Ҽ��� ����ϴ� �Լ�
{
	double magnitude;
	magnitude = sqrt(pow(c.real, 2.0) + pow(c.imag, 2.0));	//magnitude�� �����Ͽ� �Բ� ���
	if (c.imag >= 0.0)
	{
		printf("(%.3lf + j%.3lf (magnitude %.3lf))", c.real, c.imag, magnitude);
	}
	else
	{
		printf("(%.3lf - j%.3lf (magnitude %.3lf))", c.real, fabs(c.imag), magnitude);
	}

}


Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2)	//���Ҽ� ���� ���� �Լ�
{
	Cmplx res;
	res.real = c1.real + c2.real;
	res.imag = c1.imag + c2.imag;
	return res;
}

Cmplx cmplxSub(const Cmplx c1, const Cmplx c2)	//���Ҽ� ���� ���� �Լ�
{
	Cmplx res;
	res.real = c1.real - c2.real;
	res.imag = c1.imag - c2.imag;
	return res;
}

Cmplx cmplxMul(const Cmplx c1, const Cmplx c2)	//���Ҽ� ���� ���� �Լ�
{
	Cmplx res;
	res.real = (c1.real * c2.real) - (c1.imag * c2.imag);	//a+bi, c+di => ac - bd +i(ad+bc)
	res.imag = (c1.imag * c2.real) + (c1.real * c2.imag);	
	return res;
}

Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2)	//���Ҽ� ������ ���� �Լ�
{
	Cmplx res;
	res.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / (pow(c2.real, 2.0) + pow(c2.imag, 2.0));	//a+bi, c+di => (ac+bd)/(c^2+d^2), ����ȭ
	res.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / (pow(c2.real, 2.0) + pow(c2.imag, 2.0));	//a+bi, c+di => (bc-ad)/(c^2+d^2), ����ȭ
	return res;
}

double compareCmplx(const Cmplx c1, const Cmplx c2)	//���Ҽ� ��
{
	double mag_1, mag_2;
	mag_1 = sqrt(pow(c1.real, 2.0) + pow(c1.imag, 2.0));	//mag���·� ��ȯ
	mag_2 = sqrt(pow(c2.real, 2.0) + pow(c2.imag, 2.0));
	if (mag_1 > mag_2)	//mag_1�� ū ��� 1 return
	{
		return 1;
	}
	else if (mag_1 == mag_2)	//ũ�Ⱑ ������ 0
	{
		return 0;
	}
	else	//mag_1�� ������ -1 return
		return -1;
}

void sortCmplx(Cmplx cmplxs[], int size)
{
	_sortCmplx(cmplxs, size, 0, size - 1);
}

void _sortCmplx(Cmplx cmplxs[], int size, int left, int right)
{
	int pI, newPI; //pivot index
	if (left >= right)	//left�� right�� ������ return
	{
		return;
	}
	else if (left < right)
	{
		pI = (left + right) / 2;
	}

	newPI = _partition(cmplxs, size, left, right, pI);	//newPI�� ��������ġ

	if (left < (newPI - 1))
	{
		_sortCmplx(cmplxs, size, left, newPI - 1); //quicksort ���
	}
	if ((newPI + 1) < right)
	{
		_sortCmplx(cmplxs, size, newPI + 1, right);	//quicksort ���
	}
}

int _partition(Cmplx complxs[], int size, int left, int right, int pivotIndex)
{
	Cmplx pivotValue; //pivotValue
	int newPI, i; //new pivot index
	Cmplx temp;
	pivotValue = complxs[pivotIndex];
	complxs[pivotIndex] = complxs[right];
	complxs[right] = pivotValue; //�迭 �� ������ pivotValue �̵�
	newPI = left;
	for (i = left; i <= (right - 1); i++)
	{
		if (compareCmplx(complxs[i], pivotValue) < 0)	//pivotvalue���� ������ 0�������� ����� newPI�� ��ġ����
		{
			temp = complxs[i];
			complxs[i] = complxs[newPI];
			complxs[newPI] = temp;
			newPI++;
		}
	}

	pivotValue = complxs[right];
	complxs[right] = complxs[newPI];	//array�� ���� newPI�� ����
	complxs[newPI] = pivotValue;
	return newPI;
}

