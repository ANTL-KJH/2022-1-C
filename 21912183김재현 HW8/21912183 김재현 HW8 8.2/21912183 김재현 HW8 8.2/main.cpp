/*
* ���ϸ� : "21912183 ������ HW8 8.2.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -GaussJordan �ҰŹ��� �̿��Ͽ� ����� �����ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.04.27
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.04.27	v1.0	�����ۼ�
*/

#include "Matrix.h"
#include "GaussJordan.h"
const char* augMtrx_file = "ElectronicCircuit_B_5x6.txt";	//�Է�����
const char* linearSystem_inputFile = "ElectronicCircuit_B_5x5.txt";	//�������
int main(void)
{
	FILE* fin;
	FILE* fout;
	int size_N;
	double* solution;
	double** augMtrx = NULL;
	int i, solExist = 1, error = 0;
	fin = fopen(augMtrx_file, "r");	//File Open
	if (fin == NULL)
	{
		printf("Error in opening input.txt file (%s)!!\n", augMtrx_file);
		exit(-1);
	}
	fout = fopen("Output.txt", "w");
	if (fout == NULL)
	{
		printf("Error in creation of output.txt file !!\n");
		exit(-1);
	}
	augMtrx = fGetAugMtrx(fin, &size_N);	//2D Dynamic Allocation
	fprintMtrx(fout, (const char*)"Augmented Matrix\n", augMtrx, size_N, size_N + 1);
	printMtrx((const char*)"Augmented Matrix\n", augMtrx, size_N, size_N + 1);
	solution = (double*)calloc(size_N, sizeof(double));
	diagonalize_FileOut(fout, (double**)augMtrx, size_N, &solExist);	//GaussJordan calculate
	if (solExist) {
		fprintf(fout, "The solution of the given linear system:\n");
		for (i = 0; i < size_N; i++) {
			solution[i] = augMtrx[i][size_N];
			fprintf(fout, " x[%d] : %4f\n", i, solution[i]);
			printf(" x[%d] : %4f\n", i, solution[i]);
		}
	}
	else {
		printf("No unique solution\n");
		fprintf(fout, "No unique solution\n");
	}
	for (int i = 0; i < size_N; i++)
	free(augMtrx[i]);
	free(augMtrx); free(solution);
	fclose(fin); fclose(fout);
	return 0;
}