/*
* ���ϸ� : "Real number calculator.cpp"
* ���α׷��� ���� �� �⺻ ���:
*	-ǥ�� �Է���ġ(key board)�κ��� double ������ �Ǽ� 2���� �Է¹ް�
	 ����, ����, ����, �������� ����� ����ϴ� ���α׷�
* ���α׷� �ۼ���:������(2191283)
* ���� ���α׷� �ۼ���:2022.03.09
* =====================================================================================================
* ���α׷� ����/���� �̷�
* =====================================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.03.09  v1.0	�����ۼ�
*/
#include <stdio.h>
int main()
{
	double input_number_1 = 0.0;
	double input_number_2 = 0.0;
	double sum = 0.0, minus = 0.0;
	double multiplication = 0.0, division = 0.0;
	printf("ù ��° �Ǽ��� �Է��Ͻÿ� : ");	//�Ǽ� 1 �Է�
	scanf_s("%lf", &input_number_1);
	printf("�� ��° �Ǽ��� �Է��Ͻÿ� : ");	//�Ǽ� 2 �Է�
	scanf_s("%lf", &input_number_2);

	sum = input_number_1 + input_number_2;
	minus = input_number_1 - input_number_2;
	multiplication = input_number_1 * input_number_2;
	division = input_number_1 / input_number_2;

	printf("��갪 ���(�Ҽ��� ��° �ڸ� ���� ����)\n");	//��� ����
	printf("���� : %lf + %lf = %.2lf\n", input_number_1, input_number_2, sum);
	printf("���� : %lf - %lf = %.2lf\n", input_number_1, input_number_2, minus);
	printf("���� : %lf * %lf = %.2lf\n", input_number_1, input_number_2, multiplication);
	printf("������ : %lf / %lf = %.2lf\n", input_number_1, input_number_2, division);
	return 0;
}