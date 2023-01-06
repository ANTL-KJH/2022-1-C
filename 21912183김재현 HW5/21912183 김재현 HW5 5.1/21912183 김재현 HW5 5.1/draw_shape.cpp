/*draw_shape.cpp*/
#include "draw_shape.h"

void draw_rectangle(int width, int length)	//사각형 출력함수
{
	for (int i = 0; i < length; i++)
	{
		for (int p = 0; p < width; p++)
		{
			if (i == 0 || i == length - 1)	//1열과 마지막 열은 전체 별표출력
			{
				printf("*");
			}
			else if (i != 0 && i != length - 1)	//1행, 마지막행에서 *출력
			{
				if (p == 0 || p == width - 1)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void draw_right_triangle(int base)	//삼각형 출력함수
{
	for (int i = 0; i < base; i++)
	{
		for (int q = 0; q < i; q++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void draw_reverse_right_triangle(int base)
{
	for (int i = 0; i < base; i++)
	{
		for (int q = 0; q < i; q++)	//공백 출력
		{
			printf(" ");
		}
		for (int p = 0; p < base - i; p++)	//역삼각형 출력
		{
			printf("*");
		}
		printf("\n");
	}
}

void draw_diamond(int width)
{
	int height = 0, center = 0;
	height = width / 2 + 1;
	center = width / 2;
	for (int i = 0; i < height; i++)	//맨위부터 중간까지 출력
	{
		for (int q = 0; q < width; q++)
		{
			if (((q >= center - i) && (q <= center + i)))	//중간열 출력
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}

	for (int i = height-1; i > 0; i--)	//중간부터 밑까지 출력
	{
		for (int q = 0; q < width; q++)
		{
			
			if ((q >= center - i+1) && (q <= center + i-1))	//중간열 출력
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}