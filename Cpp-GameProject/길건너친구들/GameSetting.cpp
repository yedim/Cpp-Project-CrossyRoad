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

int CGameSetting::MenuSelect(int x, int y, int Min, int Max, int Space)
{
	CGameSetting::setcolor(DARK_GREEN, BLACK);
	CGameSetting::gotoxy(x, y);
	printf("��");

	while (1)
	{	
		if (GetAsyncKeyState(VK_LEFT) < 0 && Min < x){// ȭ��ǥ ���� Ű�� ������ �� 
			CGameSetting::gotoxy(x, y);
			printf(" ");
			CGameSetting::gotoxy(x -= Space, y);
			printf("��");
		}
		if (GetAsyncKeyState(VK_RIGHT) < 0 && Max > x){// ȭ��ǥ �Ʒ��� Ű�� ������ �� 
			CGameSetting::gotoxy(x, y);
			printf(" ");
			CGameSetting::gotoxy(x += Space, y);
			printf("��");
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000){
			CGameSetting::gotoxy(x, y);
			CGameSetting::setcolor(DARK_GREEN, RED);
			printf("��");
			Sleep(500);
			CGameSetting::gotoxy(x, y);
			CGameSetting::setcolor(DARK_GREEN, BLACK);
			printf("  ");
			return (x  / Min);
		}
		Sleep(100);
	}
}