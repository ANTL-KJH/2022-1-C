/*
* ���ϸ� : "21912183 ������ HW7.1.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -�μ� ���� ��ĺ� ����� ���ϰ� ���������͸� �̿��� ���� �迭�� �����Ͽ�
*  Matrix ������ �ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.04.16
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.04.16	v1.0	�����ۼ�
*/
#include "Test_Call_By.h"
#include "Mtrx.h"
#define Data_Input_File "mtrx_data.txt"	//Matrix�� �ҷ����µ� ����ϴ� ����

void test_call_by_forms(void);
void test_2D_DynamicArray_FileIO(void);
void test_Matrix_Addition_Subtraction_Multiply(void);
int main(void)
{
	int menu = 0;
	while (1)
	{
		printf("Please select a menu\n");
		printf(" 1: Average calculator with testing call-by forms\n");
		printf(" 2: Test 2-D Dynamic Array Creation for Matrix with File Input\n");
		printf(" 3: Test Matrix Addition, Subtraction, Multiply\n");
		printf(" ESC: Quit\n");
		printf("Input menu (-1 to quit) : ");
		scanf_s("%d", &menu);
		getchar();	//���ۺ���
		if (menu == -1)	//-1 �Է½� ����
			break;
		switch (menu)
		{
		case 1:
			test_call_by_forms();
			break;
		case 2:
			test_2D_DynamicArray_FileIO();
			break;
		case 3:
			test_Matrix_Addition_Subtraction_Multiply();
			break;
		default:
			printf("Worng Input!!\n");
			break;
		}
	}
}

void test_call_by_forms(void)	//������ �μ� ȣ�� ����� �̿��Ͽ� �� ���� ����� ���ϴ� �Լ�
{
	double input_num1 = 0.0, input_num2 = 0.0, avg = 0.0;
	printf("Input two number in double form\n");
	scanf("%lf %lf", &input_num1, &input_num2);
	printf("Input num :%.2lf, %.2lf\n", input_num1, input_num2);
	avg = average_value(input_num1, input_num2);	//Call-By-Value
	printf("Call-By-Value Result avg =   %.2lf\n", avg);
	average_pointer(&input_num1, &input_num2, &avg);	//Call-By_Pointer
	printf("Call-By-Pointer Result avg = %.2lf\n", avg);
	average_reference(input_num1, input_num2, avg);	//Call-By-Reference
	printf("Call-By-Value Result avg =   %.2lf\n", avg);
}
void test_2D_DynamicArray_FileIO()
{
	FILE* fin;
	fin = fopen(Data_Input_File, "r");	//���� �б�
	int a_row_size = 0, a_col_size = 0;
	int b_row_size = 0, b_col_size = 0;
	int c_row_size = 0, c_col_size = 0;
	double** dMA = NULL, ** dMB = NULL, ** dMC = NULL;

	if (fin == NULL)
	{
		printf("FILE OPEN ERROR!!\n");
		exit(-1);
	}
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//���Ͽ��� �迭 size �Է�
	dMA = fGetMtrx(fin, &a_row_size, &a_col_size);
	printf("mA = \n");
	printMtrx(dMA, a_row_size, a_col_size);	//Matrix ���

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);	//���Ͽ��� �迭 size �Է�
	dMB = fGetMtrx(fin, &b_row_size, &b_col_size);
	printf("mB = \n");
	printMtrx(dMB, b_row_size, b_col_size);	//Matrix ���

	fscanf(fin, "%d %d", &c_row_size, &c_col_size);	//���Ͽ��� �迭 size �Է�
	dMC = fGetMtrx(fin, &c_row_size, &c_col_size);
	printf("mC = \n");
	printMtrx(dMC, c_row_size, c_col_size);	//Matrix ���

	deleteDoubleMtrx(dMA, a_row_size);	//�޸� �ݳ�
	deleteDoubleMtrx(dMB, b_row_size);
	deleteDoubleMtrx(dMC, c_row_size);
	fclose(fin);
}

void test_Matrix_Addition_Subtraction_Multiply(void)
{
	FILE* fin;
	fin = fopen(Data_Input_File, "r");	//���� �б�
	int a_row_size = 0, a_col_size = 0;
	int b_row_size = 0, b_col_size = 0;
	int c_row_size = 0, c_col_size = 0;
	double** dMA = NULL, ** dMB = NULL, ** dMC = NULL, ** dMD = NULL, ** dME = NULL, ** dMF = NULL;
	if (fin == NULL)
	{
		printf("FILE OPEN ERROR!!\n");
		exit(-1);
	}
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//���Ͽ��� �迭 size �Է�
	dMA = fGetMtrx(fin, &a_row_size, &a_col_size);	//���Ͽ��� �迭�� �о��
	printf("mA = \n");
	printMtrx(dMA, a_row_size, a_col_size);	//Matrix ���

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);
	dMB = fGetMtrx(fin, &b_row_size, &b_col_size);
	printf("mB = \n");
	printMtrx(dMB, b_row_size, b_col_size);

	fscanf(fin, "%d %d", &c_row_size, &c_col_size);
	dMC = fGetMtrx(fin, &c_row_size, &c_col_size);
	printf("mC = \n");
	printMtrx(dMC, c_row_size, c_col_size);

	printf("mD = mA + mB =\n");
	dMD = addMtrx(dMA, dMB, a_row_size, a_col_size);	//Matrix ���� ����
	printMtrx(dMD, a_row_size, a_col_size);
	deleteDoubleMtrx(dMD, a_row_size);

	printf("mE = mA - mB =\n");
	dME = subMtrx(dMA, dMB, a_row_size, a_col_size);	//Matrix ���� ����
	printMtrx(dME, a_row_size, a_col_size);
	deleteDoubleMtrx(dME, a_row_size);

	printf("mF = mA * mC =\n");
	dMF = mulMtrx(dMA, dMC, a_row_size, a_col_size, c_col_size);	//Matrix ��������
	printMtrx(dMF, a_row_size, c_col_size);
	deleteDoubleMtrx(dMF, a_row_size);

	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
}