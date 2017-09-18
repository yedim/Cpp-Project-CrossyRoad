#include "GameSetting.h"

CGameSetting::CGameSetting()
{

}
CGameSetting::~CGameSetting()
{

}

void CGameSetting::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CGameSetting::setcolor(COLOR_TYPE backcolor, COLOR_TYPE fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor * 16 + fontcolor);
}

void CGameSetting::draw_shape(int num)
{
	unsigned char a = 0xa6, b[7];
	b[num] = 0xa0 + num;
	printf("%c%c", a, b[num]);
}
