/*GaussJordan.cpp*/
#include "StandardH.h"
#include "GaussJordan.h"
#include "Matrix.h"
double** invMtrxGaussJordanElim(double** mA, int size_N)
{
	int j, k, p = 0; // pivot index
	double pivWeight, w;
	double** mAUG, ** mInvF;
	mInvF = (double**)calloc(size_N, sizeof(double*));
	for (int i = 0; i < size_N; i++)
		mInvF[i] = (double*)calloc(size_N, sizeof(double));
	mAUG = (double**)calloc(size_N, sizeof(double*));
	for (int i = 0; i < size_N; i++)
		mAUG[i] = (double*)calloc(size_N * 2, sizeof(double));	//2D Dynamic Matrix create, ���� ���� �״�� ���� 2�踸ŭ ����
	for (j = 0; j < size_N; j++) {
		for (k = 0; k < size_N; k++)	//Matrix Copy
			mAUG[j][k] = mA[j][k];
		for (k = size_N; k < size_N * 2; k++)	//Size_N ���Ŀ� ������� ����
			mAUG[j][k] = (k == (j + size_N)) ? 1.0 : 0.0;
	}
	for (p = 0; p < size_N; p++) {
		if (mAUG[p][p] != 1.0)
		{
			pivWeight = mAUG[p][p];	//weight �� ����
			mAUG[p][p] = 1.0; //pivot row, pivot col scaling �����ϸ�
			for (k = p + 1; k < size_N * 2; k++)
			{
				mAUG[p][k] /= pivWeight; //������ �� scaling
			}
		}
		for (j = 0; j < size_N; j++)
		{
			if ((j != p) && (mAUG[j][p] != 0.0))
			{
				w = mAUG[j][p]; // weight
				mAUG[j][p] = 0.0;  //�Ұ� ����, pivot row�� ���� col ���� weight�� ���ؼ� ���� ����
				for (k = p + 1; k < 2 * size_N; k++) {
					mAUG[j][k] -= w * mAUG[p][k];
				}
			}
		}
	}
	for (j = 0; j < size_N; j++)	//Inverse Matrix�� �� ����
	{
		for (k = 0; k < size_N; k++) {
			mInvF[j][k] = mAUG[j][k + size_N];
		}
	}
	free(mAUG);
	return mInvF;
}