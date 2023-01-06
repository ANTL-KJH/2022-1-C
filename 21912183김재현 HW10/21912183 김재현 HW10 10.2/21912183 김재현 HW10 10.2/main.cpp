/*
* ���ϸ� : "21912183 ������ HW10 10.2.sln"
* ���α׷��� ���� �� �⺻ ��� :
* -ǥ���Է���ġ�κ��� 16���� ���ڿ��� �Է¹ް� 10������ 16������ ����ϴ� ���α׷�
* ���α׷� �ۼ��� : ������(2191283)
* ���� ���α׷� �ۼ��� : 2022.05.14
* ======================================================================================
* ���α׷� ���� / ���� �̷�
* ======================================================================================
* ���α׷� ������	����		����	��������
* ������			2022.05.14	v1.0	�����ۼ�
* ������			2022.05.15	v1.1	xtoa�۵����� �ذ�
*/
#include "STD.h"
#include "hexadecimal.h"
int main(void)
{
	char* hexStr;	//���ڿ��� �Է¹��� ������
	char* hexConvertStr;	//10������ 16���� ���ڿ��� ��ȯ�� ���� ���� ������
	unsigned int value_int = 0;
	while (1)
	{
		hexStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));	//Dynamic memory allocation
		hexConvertStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));	//Dynamic memory allocation
		printf("input hexadecimal number : ");
		scanf("%s", hexStr);
		if (strcmp(hexStr, ".") == 0)	//.�� �ԷµǸ� break
			break;
		value_int = atox(hexStr);	//16���� ���ڿ��� 10������ convert
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int);
		xtoa(hexConvertStr, value_int);	//10���� ���ڸ� 16���� ���ڿ��� convert
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re - converted hexadecimal string(%s)\n",hexStr, value_int, value_int, hexConvertStr);
	}
	free(hexStr);
	free(hexConvertStr);
	return 0;
}