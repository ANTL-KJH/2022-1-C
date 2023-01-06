/*
* 파일명 : "21912183 김재현 HW10 10.2.sln"
* 프로그램의 목적 및 기본 기능 :
* -표준입력장치로부터 16진수 문자열을 입력받고 10진수와 16진수로 출력하는 프로그램
* 프로그램 작성자 : 김재현(2191283)
* 최초 프로그램 작성일 : 2022.05.14
* ======================================================================================
* 프로그램 수정 / 보완 이력
* ======================================================================================
* 프로그램 수정자	일자		버전	수정내용
* 김재현			2022.05.14	v1.0	최초작성
* 김재현			2022.05.15	v1.1	xtoa작동문제 해결
*/
#include "STD.h"
#include "hexadecimal.h"
int main(void)
{
	char* hexStr;	//문자열을 입력받을 포인터
	char* hexConvertStr;	//10진수를 16진수 문자열로 변환한 값을 받을 포인터
	unsigned int value_int = 0;
	while (1)
	{
		hexStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));	//Dynamic memory allocation
		hexConvertStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));	//Dynamic memory allocation
		printf("input hexadecimal number : ");
		scanf("%s", hexStr);
		if (strcmp(hexStr, ".") == 0)	//.이 입력되면 break
			break;
		value_int = atox(hexStr);	//16진수 문자열을 10진수로 convert
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int);
		xtoa(hexConvertStr, value_int);	//10진수 숫자를 16진수 문자열로 convert
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re - converted hexadecimal string(%s)\n",hexStr, value_int, value_int, hexConvertStr);
	}
	free(hexStr);
	free(hexConvertStr);
	return 0;
}