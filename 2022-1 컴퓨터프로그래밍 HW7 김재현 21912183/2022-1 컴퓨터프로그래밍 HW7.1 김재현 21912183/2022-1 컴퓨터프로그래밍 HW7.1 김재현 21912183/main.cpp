/*
* 파일명 : "21912183 김재현 HW7.1.sln"
* 프로그램의 목적 및 기본 기능 :
* -인수 전달 방식별 평균을 구하고 이중포인터를 이용한 동적 배열을 생성하여
*  Matrix 연산을 하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.04.16
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.04.16	v1.0	최초작성
*/
#include "Test_Call_By.h"
#include "Mtrx.h"
#define Data_Input_File "mtrx_data.txt"	//Matrix를 불러오는데 사용하는 파일

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
		getchar();	//버퍼비우기
		if (menu == -1)	//-1 입력시 종료
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

void test_call_by_forms(void)	//세가지 인수 호출 방법을 이용하여 두 수의 평균을 구하는 함수
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
	fin = fopen(Data_Input_File, "r");	//파일 읽기
	int a_row_size = 0, a_col_size = 0;
	int b_row_size = 0, b_col_size = 0;
	int c_row_size = 0, c_col_size = 0;
	double** dMA = NULL, ** dMB = NULL, ** dMC = NULL;

	if (fin == NULL)
	{
		printf("FILE OPEN ERROR!!\n");
		exit(-1);
	}
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//파일에서 배열 size 입력
	dMA = fGetMtrx(fin, &a_row_size, &a_col_size);
	printf("mA = \n");
	printMtrx(dMA, a_row_size, a_col_size);	//Matrix 출력

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);	//파일에서 배열 size 입력
	dMB = fGetMtrx(fin, &b_row_size, &b_col_size);
	printf("mB = \n");
	printMtrx(dMB, b_row_size, b_col_size);	//Matrix 출력

	fscanf(fin, "%d %d", &c_row_size, &c_col_size);	//파일에서 배열 size 입력
	dMC = fGetMtrx(fin, &c_row_size, &c_col_size);
	printf("mC = \n");
	printMtrx(dMC, c_row_size, c_col_size);	//Matrix 출력

	deleteDoubleMtrx(dMA, a_row_size);	//메모리 반납
	deleteDoubleMtrx(dMB, b_row_size);
	deleteDoubleMtrx(dMC, c_row_size);
	fclose(fin);
}

void test_Matrix_Addition_Subtraction_Multiply(void)
{
	FILE* fin;
	fin = fopen(Data_Input_File, "r");	//파일 읽기
	int a_row_size = 0, a_col_size = 0;
	int b_row_size = 0, b_col_size = 0;
	int c_row_size = 0, c_col_size = 0;
	double** dMA = NULL, ** dMB = NULL, ** dMC = NULL, ** dMD = NULL, ** dME = NULL, ** dMF = NULL;
	if (fin == NULL)
	{
		printf("FILE OPEN ERROR!!\n");
		exit(-1);
	}
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);	//파일에서 배열 size 입력
	dMA = fGetMtrx(fin, &a_row_size, &a_col_size);	//파일에서 배열을 읽어옴
	printf("mA = \n");
	printMtrx(dMA, a_row_size, a_col_size);	//Matrix 출력

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);
	dMB = fGetMtrx(fin, &b_row_size, &b_col_size);
	printf("mB = \n");
	printMtrx(dMB, b_row_size, b_col_size);

	fscanf(fin, "%d %d", &c_row_size, &c_col_size);
	dMC = fGetMtrx(fin, &c_row_size, &c_col_size);
	printf("mC = \n");
	printMtrx(dMC, c_row_size, c_col_size);

	printf("mD = mA + mB =\n");
	dMD = addMtrx(dMA, dMB, a_row_size, a_col_size);	//Matrix 덧셈 연산
	printMtrx(dMD, a_row_size, a_col_size);
	deleteDoubleMtrx(dMD, a_row_size);

	printf("mE = mA - mB =\n");
	dME = subMtrx(dMA, dMB, a_row_size, a_col_size);	//Matrix 뺄셈 연산
	printMtrx(dME, a_row_size, a_col_size);
	deleteDoubleMtrx(dME, a_row_size);

	printf("mF = mA * mC =\n");
	dMF = mulMtrx(dMA, dMC, a_row_size, a_col_size, c_col_size);	//Matrix 곱셈연산
	printMtrx(dMF, a_row_size, c_col_size);
	deleteDoubleMtrx(dMF, a_row_size);

	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
}