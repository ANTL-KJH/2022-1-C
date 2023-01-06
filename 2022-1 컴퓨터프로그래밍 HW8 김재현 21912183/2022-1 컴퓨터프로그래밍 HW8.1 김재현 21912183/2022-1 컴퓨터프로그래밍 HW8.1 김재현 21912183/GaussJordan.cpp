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
		mAUG[i] = (double*)calloc(size_N * 2, sizeof(double));	//2D Dynamic Matrix create, 행은 원본 그대로 열은 2배만큼 생성
	for (j = 0; j < size_N; j++) {
		for (k = 0; k < size_N; k++)	//Matrix Copy
			mAUG[j][k] = mA[j][k];
		for (k = size_N; k < size_N * 2; k++)	//Size_N 이후에 단위행렬 생성
			mAUG[j][k] = (k == (j + size_N)) ? 1.0 : 0.0;
	}
	for (p = 0; p < size_N; p++) {
		if (mAUG[p][p] != 1.0)
		{
			pivWeight = mAUG[p][p];	//weight 값 추출
			mAUG[p][p] = 1.0; //pivot row, pivot col scaling 스케일링
			for (k = p + 1; k < size_N * 2; k++)
			{
				mAUG[p][k] /= pivWeight; //나머지 열 scaling
			}
		}
		for (j = 0; j < size_N; j++)
		{
			if ((j != p) && (mAUG[j][p] != 0.0))
			{
				w = mAUG[j][p]; // weight
				mAUG[j][p] = 0.0;  //소거 연산, pivot row의 연산 col 값에 weight를 곱해서 빼기 연산
				for (k = p + 1; k < 2 * size_N; k++) {
					mAUG[j][k] -= w * mAUG[p][k];
				}
			}
		}
	}
	for (j = 0; j < size_N; j++)	//Inverse Matrix에 값 저장
	{
		for (k = 0; k < size_N; k++) {
			mInvF[j][k] = mAUG[j][k + size_N];
		}
	}
	free(mAUG);
	return mInvF;
}