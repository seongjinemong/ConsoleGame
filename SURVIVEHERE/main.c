#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define MAX_X 150
#define MAX_Y 50

void initCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void resizeConsole()
{
	char Temp[50];
	sprintf(Temp, "Mode con cols=%d lines=%d", MAX_X, MAX_Y);
	system(Temp);
}

void displayStart()
{
	while (1)
	{
		gotoxy(MAX_X / 2 - 3, MAX_Y / 2);
		printf("Tetris");
		Sleep(300);
		if (kbhit())
			break;
		gotoxy(MAX_X / 2 - 3, MAX_Y / 2);
		printf("      ");
		Sleep(300);
	}
	system("cls");
}

int main()
{
	initCursor();
	resizeConsole();

	displayStart();
}