/*draw_shape.cpp*/
#include "draw_shape.h"

void draw_rectangle(int width, int length)	//�簢�� ����Լ�
{
	for (int i = 0; i < length; i++)
	{
		for (int p = 0; p < width; p++)
		{
			if (i == 0 || i == length - 1)	//1���� ������ ���� ��ü ��ǥ���
			{
				printf("*");
			}
			else if (i != 0 && i != length - 1)	//1��, �������࿡�� *���
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

void draw_right_triangle(int base)	//�ﰢ�� ����Լ�
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
		for (int q = 0; q < i; q++)	//���� ���
		{
			printf(" ");
		}
		for (int p = 0; p < base - i; p++)	//���ﰢ�� ���
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
	for (int i = 0; i < height; i++)	//�������� �߰����� ���
	{
		for (int q = 0; q < width; q++)
		{
			if (((q >= center - i) && (q <= center + i)))	//�߰��� ���
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}

	for (int i = height-1; i > 0; i--)	//�߰����� �ر��� ���
	{
		for (int q = 0; q < width; q++)
		{
			
			if ((q >= center - i+1) && (q <= center + i-1))	//�߰��� ���
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}