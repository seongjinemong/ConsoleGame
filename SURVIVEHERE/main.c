#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define MAX_X 150
#define MAX_Y 50

int map[300][100] = { 0 };

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
	gotoxy(MAX_X / 2 - 3, MAX_Y / 2);
	printf("Tetris");
	Sleep(300);

	gotoxy(MAX_X / 2 - 3, MAX_Y / 2);
	printf("Tetris");
	Sleep(300);

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

void initMap()
{
	map[150][50] = 1;
}

void printMap(int x, int y)
{
	gotoxy(0, 0);
	
	for (int i=0; i<150; i++)
}

int main()
{
	initCursor();
	resizeConsole();

	displayStart();

	initMap();
}