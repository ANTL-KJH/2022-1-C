/*ConsoleDisplay.h*/
#ifndef ConDis
#define ConDis

HANDLE initConsoleHandler();
void closeConsoleHandler(HANDLE hndlr);
int gotoxy(HANDLE consHndlr, int x, int y);
#endif