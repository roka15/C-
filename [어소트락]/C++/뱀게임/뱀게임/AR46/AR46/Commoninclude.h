#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#define GOTO_XY(x,y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),COORD{(short)x,(short)y})
#define SET_COLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color) 
#define EnumToInt(_enum) (unsigned int)_enum
using std::cout;
using std::endl;
using std::cin;

enum class eSceneType
{
	Title,
	Play,
	End,
	Max,
};

enum class COLOR
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
enum class KeyDir
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

struct Vector2
{
	int x;
	int y;
};

const int offsetX = 40;
const int offsetY = 20;

struct Node
{
	Node* next;
	Node* prev;
	wchar_t ch;
};