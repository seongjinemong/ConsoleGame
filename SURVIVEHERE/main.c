#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define kbhit _kbhit
#define getch _getch

#define MAX_X 150
#define MAX_Y 50

#define RIGHT_CLICK 1
#define LEFT_CLICK 2
#define DRAG 3

int map[300][100];

INPUT_RECORD rec;
DWORD        dwNOER;

int * getInput() {
	int x = 0, y = 0;
	int * a = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
		a[0] = 0;
	keybd_event(0, 0x88, 0, 0);
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER);
	if (rec.EventType == MOUSE_EVENT) {
		if ((GetKeyState(VK_RBUTTON) & 0x100) != 0) {         //우클릭 눌렀을 때
			x = rec.Event.MouseEvent.dwMousePosition.X;
			y = rec.Event.MouseEvent.dwMousePosition.Y;
			a[0] = RIGHT_CLICK, a[1] = x, a[2] = y;
			return a;
		}
		else if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {    //좌클릭 눌렀을 때
			x = rec.Event.MouseEvent.dwMousePosition.X;
			y = rec.Event.MouseEvent.dwMousePosition.Y;
			a[0] = LEFT_CLICK, a[1] = x, a[2] = y;
			return a;
		}
		else {
			a[0] = 99;
			return a;
		}
	}
	else if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {    //지금 누른건 아닌데 누르고 있을떄 && 가만히 있을 때
		a[0] = DRAG;
		return a;
	}
	else {
		a[0] = -1;
		return a;
	}
}

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

void spawnCharacter(int x, int y)
{
	map[x][y] = 1;
}

void moveCharacter(int ox, int x, int y)
{
	if (ox == 0)
		map[x][y] = 0;
	else
		map[x][y] = 1;
}

void spawnMonster(int x, int y)
{
	map[x][y] = 2;
}

void moveMonster(int x, int y)
{
	map[x][y] = 2;
}

void printMap(int px, int py)
{
	int x = px - 75; 
	int y = py - 25;

	gotoxy(0, 0);
	
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			if (map[j + x][i + y] == 0)
				printf(" ");
			else
			{
				printf("%d", map[j + x][i + y]);
			}

		}
		gotoxy(0, i);
	}
}

int main()
{
	int x = 150;
	int y = 50;

	initCursor();
	resizeConsole();

	displayStart();

	spawnCharacter(x, y);
	spawnMonster(x + 20, y + 10);
	printMap(x, y);

	while (1)
	{
		moveCharacter(0, x, y);

		x++;
		y++;

		moveCharacter(1, x, y);
		printMap(x, y);
	}
}