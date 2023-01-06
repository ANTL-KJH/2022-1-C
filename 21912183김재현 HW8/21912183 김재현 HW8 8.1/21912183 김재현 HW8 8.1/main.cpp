/*
* 파일명 : "21912183 김재현 HW8 8.1.sln"
* 프로그램의 목적 및 기본 기능 :
* -2차원 동적배열을 이용한 행렬 연산과 Inverse Matrix 연산을 하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.04.27
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.05.02	v1.0	최초작성
*/
#include "StandardH.h"
#include "Matrix.h"
#include "GaussJordan.h"
int main(void)
{
	FILE* fin_ABC, * fout;
	const char* input_file_ABC = "mtrx_AB_6x7_C_7x6.txt";
	double** mA, ** mB, ** mC, ** mD, ** mE, ** mF, ** inv_mF, ** mI;
	int a_row_size, a_col_size, b_row_size, b_col_size, c_row_size, c_col_size;
	int d_row_size, d_col_size, e_row_size, e_col_size, k_size, f_row_size, f_col_size;
	fin_ABC = fopen(input_file_ABC, "r");
	if (fin_ABC == NULL)
	{
		printf("Error in opening input data file (%s) !!", input_file_ABC);
		exit;
	}
	mA = fGetMtrx(fin_ABC, &a_row_size, &a_col_size);
	printMtrx((const char*)"mA", mA, a_row_size, a_col_size);
	mB = fGetMtrx(fin_ABC, &b_row_size, &b_col_size);
	printMtrx((const char*)"mB", mB, b_row_size, b_col_size);
	mC = fGetMtrx(fin_ABC, &c_row_size, &c_col_size);
	printMtrx((const char*)"mC", mC, c_row_size, c_col_size);
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	mD = addMtrx(mA, mB, a_row_size, a_col_size);
	printMtrx((const char*)"mD = mA + mB", mD, d_row_size, d_col_size);
	e_row_size = a_row_size;	e_col_size = b_col_size;
	mE = subMtrx(mA, mB, e_row_size, e_col_size);
	printMtrx((const char*)"mE = mA - mB", mE, e_row_size, e_col_size);
	f_row_size = a_row_size;	f_col_size = c_col_size;	k_size = a_col_size;
	mF = mulMtrx(mA, mC, f_row_size, f_col_size, k_size);
	printMtrx((const char*)"mF = mA * mC", mF, f_row_size, f_col_size);
	inv_mF = invMtrxGaussJordanElim(mF, f_row_size);
	printMtrx((const char*)"inv_mF", inv_mF, f_row_size, f_col_size);
	mI = mulMtrx(mF, inv_mF, f_row_size, f_col_size, f_col_size);
	printMtrx((const char*)"mI = mF * inv_mF", mI, f_row_size, f_col_size);
	deleteDynMtrx(mA, a_row_size, a_col_size);	deleteDynMtrx(mB, b_row_size, b_col_size);	deleteDynMtrx(mC, c_row_size, c_col_size);
	deleteDynMtrx(mD, a_row_size, a_col_size);	deleteDynMtrx(mE, e_row_size, e_col_size);	deleteDynMtrx(mF, f_row_size, f_col_size);
	deleteDynMtrx(mI, f_row_size, f_col_size);
	fclose(fin_ABC);
	return 0;
}