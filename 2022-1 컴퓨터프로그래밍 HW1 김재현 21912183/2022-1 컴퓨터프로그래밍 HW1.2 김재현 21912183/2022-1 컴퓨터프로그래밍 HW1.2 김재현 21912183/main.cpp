/*
* ���ϸ� : "calculator for area and circumference of right triangle.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� �����ﰢ���� ���ο� ���θ� �Է¹ް� ���̿� �ѷ��� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.04
* =====================================================================================================
* ���α׷� ����/���� �̷�
* =====================================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.04  v1.0	�����ۼ�
*/
#include <stdio.h>
#include <math.h>
int main()
{
	double base = 0.0, height = 0.0;
	double area = 0.0, circum = 0.0;	//�ѷ��� circumference
	double hypo = 0.0;	//������ hypotenuse
	printf("�����ﰢ���� �غ�(base)�� ����(height)�� �Է��Ͻÿ�:");
	scanf_s("%lf %lf", &base, &height);
	area = 0.5 * base * height;
	hypo = sqrt(pow(base, 2) + pow(height, 2));	//sqrt�� pow�� ���� math.h�� ���Ե� �Լ��� ��Ʈ, ���� ������ ��
	circum = base + height + hypo;
	printf("�����ﰢ���� ����:%.2lf\n�����ﰢ���� �ѷ�:%.2lf\n", area, circum);
	printf("�ش� ����� �Ҽ��� ��° �ڸ����� �ݿø��Ǿ����ϴ�.");
	return 0;
}