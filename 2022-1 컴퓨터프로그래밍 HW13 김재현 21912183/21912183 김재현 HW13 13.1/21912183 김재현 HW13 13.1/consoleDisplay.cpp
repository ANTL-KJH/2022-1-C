/* ConsoleDisplay.cpp */
#include "STD.h"
#include "ConsoleDisplay.h"

HANDLE consoleHandler;	//HANDLE ����
HANDLE initConsoleHandler()	//HANDLE�� STD_OUTPUT_HANDLE�� �ʱ�ȭ
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
int gotoxy(HANDLE consHndlr, int x, int y)	//�ܼ�ȭ�� Ŀ�� ��ġ ����
{
	if (consHndlr == INVALID_HANDLE_VALUE)
		return 0;
	COORD coords = { static_cast<short>(x),
	static_cast<short>(y) };
	SetConsoleCursorPosition(consHndlr, coords);
}