#ifndef Test_Call_By_H
#define Test_Call_By_H
#include <stdio.h>
#pragma warning(disable: 4996)	//scanf���� ���Ȱ�� ����
double average_value(double x, double y); // call-by-value
void average_pointer(double* px, double* py, double* pavg); // call-by-pointer
void average_reference(double& x, double& y, double& avg); // call-by-reference
#endif