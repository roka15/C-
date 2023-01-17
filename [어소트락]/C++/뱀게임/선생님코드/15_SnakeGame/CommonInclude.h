#pragma once
#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>


#define GOTO_XY(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{(short)x, (short)y})
#define SET_COLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)


enum class eSceneType
{
	Title,
	Play,
	End,
	Max,
};

enum COLOR
{
	BLACK, /* 0 : ��� */
	DARK_BLUE, /* 1 : ��ο� �Ķ� */
	DARK_GREEN, /* 2 : ��ο� �ʷ� */
	DARK_SKY_BLUE, /* 3 : ��ο� �ϴ� */
	DARK_RED, /* 4 : ��ο� ���� */
	DARK_VIOLET, /* 5 : ��ο� ���� */
	DARK_YELLOW, /* 6 : ��ο� ��� */
	GRAY, /* 7 : ȸ�� */
	DARK_GRAY, /* 8 : ��ο� ȸ�� */
	BLUE, /* 9 : �Ķ� */
	GREEN, /* 10 : �ʷ� */
	SKY_BLUE, /* 11 : �ϴ� */
	RED, /* 12 : ���� */
	VIOLET, /* 13 : ���� */
	YELLOW, /* 14 : ��� */
	WHITE, /* 15 : �Ͼ� */
};

struct Vector2
{
	int x;
	int y;


};