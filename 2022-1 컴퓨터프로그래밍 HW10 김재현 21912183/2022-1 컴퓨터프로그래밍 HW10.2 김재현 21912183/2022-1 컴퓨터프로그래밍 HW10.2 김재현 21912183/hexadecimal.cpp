/*hexadecimal.cpp*/
#include "STD.h"
#include "hexadecimal.h"

unsigned int atox(char* hexStr)
{
	unsigned char uc, hexChar;
	unsigned int hex = 0, hex_sum = 0;
	for (int i = 0; i < MAX_HEX_STR_LEN; i++)
	{
		if (hexStr[i] == NULL) //hexChar == NULL�̸� break
			return hex_sum;
		if ((hexStr[i] >= '0') && (hexStr[i] <= '9')) //0~9
			hex = hexStr[i] - '0';
		else if ((hexStr[i] >= 'A') && (hexStr[i] <= 'F')) //10~15(A~F) ���ڰ� �빮���ΰ��
			hex = hexStr[i] - 'A' + 10;
		else if ((hexStr[i] >= 'a') && (hexStr[i] <= 'f')) //10~15(a~f) ���ڰ� �ҹ����ΰ��
			hex = hexStr[i] - 'a' + 10;	//10���� 1A�̹Ƿ� +10
		else //16������ �ƴѰ��
		{
			printf("Input ERROR!!\n");
			exit(-1);
		}
		hex_sum = (hex_sum << 4) + hex;
	}
	return hex_sum; //10���� �� ��ȯ
}

void xtoa(char* strBuf, int hxd)
{
	char temp = 0;
	char str[MAX_HEX_STR_LEN + 1];	//convert�� character�� �ӽ� ������ �迭
	for (int i = MAX_HEX_STR_LEN - 1; i >= 0; i--)
	{
		temp = (((hxd << (i * 4)) >> 28) & 0xF);	//���ڷ� �ٲ� ��Ʈ 4���� ����� ����
		if (temp < 10 && temp >= 0)	//convert
			temp = temp + '0';
		else if (temp >= 10 && temp <= 15)
			temp = temp + 'A' - 10;
		str[i] = temp;
	}
	for (int i = 0; i < MAX_HEX_STR_LEN; i++)	//�ڸ����� ���� main������ return
	{
		if (str[i] != '0')
		{
			for (int c = 0; c < MAX_HEX_STR_LEN; c++)
			{
				strBuf[c] = str[i];
				i++;
				if (i == MAX_HEX_STR_LEN)	//i�� MAX_HEX_STR_LEN�� �Ǹ� return
					return;
			}
		}
	}
}