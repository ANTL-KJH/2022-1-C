/*
* ���ϸ� : "main.cpp"
* ���α׷��� ���� �� �⺻ ���:
* -���߼ҽ��� ��������� �̿��Ͽ� �پ��� ������ �׸��� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.04.03
* ======================================================================================
* ���α׷� ����/���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.04.03  v1.0	�����ۼ�
*/
#include "draw_shape.h"
int main(void)
{
	int width = 20;
	int length = 10;
	printf("Drawing a rectangle of width = %d, length = %d\n", width, length);
	draw_rectangle(width, length);	//�簢�� ����Լ�
	int base = 10;
	printf("Drawing a right triangle of base = %d\n", base);
	draw_right_triangle(base);	//�����ﰢ�� ����Լ�
	printf("Drawing a reversed right triangle of base = %d\n", base);
	draw_reverse_right_triangle(base);	//�� �����ﰢ�� ����Լ�
	width = 21;
	printf("Drawing a diamond of width = %d\n", width);
	draw_diamond(width);	//���̾� ����Լ�
	return 0;
}