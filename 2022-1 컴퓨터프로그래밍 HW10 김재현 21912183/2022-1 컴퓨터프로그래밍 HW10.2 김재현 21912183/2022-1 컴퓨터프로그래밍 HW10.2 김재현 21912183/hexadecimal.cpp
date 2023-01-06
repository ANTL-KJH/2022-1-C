/*hexadecimal.cpp*/
#include "STD.h"
#include "hexadecimal.h"

unsigned int atox(char* hexStr)
{
	unsigned char uc, hexChar;
	unsigned int hex = 0, hex_sum = 0;
	for (int i = 0; i < MAX_HEX_STR_LEN; i++)
	{
		if (hexStr[i] == NULL) //hexChar == NULL이면 break
			return hex_sum;
		if ((hexStr[i] >= '0') && (hexStr[i] <= '9')) //0~9
			hex = hexStr[i] - '0';
		else if ((hexStr[i] >= 'A') && (hexStr[i] <= 'F')) //10~15(A~F) 문자가 대문자인경우
			hex = hexStr[i] - 'A' + 10;
		else if ((hexStr[i] >= 'a') && (hexStr[i] <= 'f')) //10~15(a~f) 문자가 소문자인경우
			hex = hexStr[i] - 'a' + 10;	//10부터 1A이므로 +10
		else //16진수가 아닌경우
		{
			printf("Input ERROR!!\n");
			exit(-1);
		}
		hex_sum = (hex_sum << 4) + hex;
	}
	return hex_sum; //10진수 값 반환
}

void xtoa(char* strBuf, int hxd)
{
	char temp = 0;
	char str[MAX_HEX_STR_LEN + 1];	//convert한 character를 임시 저장할 배열
	for (int i = MAX_HEX_STR_LEN - 1; i >= 0; i--)
	{
		temp = (((hxd << (i * 4)) >> 28) & 0xF);	//문자로 바꿀 비트 4개만 남기고 삭제
		if (temp < 10 && temp >= 0)	//convert
			temp = temp + '0';
		else if (temp >= 10 && temp <= 15)
			temp = temp + 'A' - 10;
		str[i] = temp;
	}
	for (int i = 0; i < MAX_HEX_STR_LEN; i++)	//자리수에 맞춰 main문으로 return
	{
		if (str[i] != '0')
		{
			for (int c = 0; c < MAX_HEX_STR_LEN; c++)
			{
				strBuf[c] = str[i];
				i++;
				if (i == MAX_HEX_STR_LEN)	//i가 MAX_HEX_STR_LEN가 되면 return
					return;
			}
		}
	}
}