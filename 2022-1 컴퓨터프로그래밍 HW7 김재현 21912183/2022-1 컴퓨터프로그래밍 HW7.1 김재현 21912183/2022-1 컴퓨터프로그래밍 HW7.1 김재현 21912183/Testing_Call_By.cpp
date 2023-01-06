#include "Test_Call_By.h"

double average_value(double x, double y) //Call-By-Value
{
	double avg = 0.0;
	avg = (x + y) / 2.0;
	return avg;
}
void average_pointer(double* px, double* py, double* pavg)	//Call-By-Pointer
{
	double avg = 0.0;
	*pavg = (*px + *py) / 2.0;
}
void average_reference(double& x, double& y, double& avg)	//Call-By-Reference
{
	avg = (x + y) / 2.0;
}