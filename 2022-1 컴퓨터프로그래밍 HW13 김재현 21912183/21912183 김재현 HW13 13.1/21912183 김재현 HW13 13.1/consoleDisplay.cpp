/* ConsoleDisplay.cpp */
#include "STD.h"
#include "ConsoleDisplay.h"

HANDLE consoleHandler;	//HANDLE 변수
HANDLE initConsoleHandler()	//HANDLE을 STD_OUTPUT_HANDLE로 초기화
{
	HANDLE stdCnslHndlr;
	stdCnslHndlr = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleHandler = stdCnslHndlr;
	return consoleHandler;
}
void closeConsoleHandler(HANDLE hndlr)	//Close HANDLER
{
	CloseHandle(hndlr);
}
int gotoxy(HANDLE consHndlr, int x, int y)	//콘솔화면 커서 위치 수정
{
	if (consHndlr == INVALID_HANDLE_VALUE)
		return 0;
	COORD coords = { static_cast<short>(x),
	static_cast<short>(y) };
	SetConsoleCursorPosition(consHndlr, coords);
}