#include "GameStart.h"
#include "Player.h"

CGameStart::CGameStart()
{

}
CGameStart::~CGameStart()
{

}

void CGameStart::LoadingGame()
{
	system("title ��ǳ� ģ����");
	system("mode con cols=80 lines=35");//�ܼ�â ũ��
	system("color 2F");
}
void CGameStart::DelCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int CGameStart::MainMenu(int menu_x, int menu_y)
{
	system("cls");

	CGameSetting::gotoxy(67, 2);
	CGameSetting::setcolor(DARK_GREEN, WHITE);
	printf("2516 �̿���");

	//��ǳ� ģ���� Ÿ��Ʋ ���
	CGameSetting::setcolor(BLACK, WHITE);
	char* titleArray[23] = {
		"������������������������������������            ����",
		"������������������������������������            ����",
		"        ��������        ������������            ����",
		"        ��������        ������������            ����",
		"        ��������        ������������        ��������",
		"����������������        ������������        ��������",
		"���������������� ����       ��������            ����",
		"���������������� ����           ��������������������",
		"���������������� ����           ��������������������",
		"���������������� ����������������               ����",
		"���������������� ����������������               ����",
		"    ����      ��������������������������������������",
		"����������������������������������������������������",
		"����    ����������            ����������������������",
		"  ��������    ����            ����������������������",
		"  ��������    ����            ����������������������",
		"  ��������    ��������������������������������������",
		" ����         ��������������������������������������",
		" ����                   ����      ������������������",
		" ����                   ����      ������������������",
		" ����                   ����      ������������������",
		" ������������������     ����      ������������������",
		" ������������������     ����      ������������������"
	};

	for (int i = 0; i < 23; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 5, SCREEN_Y / 6 + i);
		cout << titleArray[i] << endl;
		Sleep(10);
	}

	int n;
	int menu_xMax = 47;
	int menu_xSpace = 15;
	CGameSetting::setcolor(BLACK, WHITE);
	CGameSetting::gotoxy(menu_x + 2, menu_y);  cout << "���ӽ���";
	CGameSetting::gotoxy(menu_x + menu_xSpace + 2, menu_y); cout << "���ӹ��";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 2 + 2, menu_y); cout << "���Ӹ���";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 3 + 2, menu_y); cout << "��������";

	n = CGameSetting::MenuSelect(menu_x, menu_y, menu_x, menu_xMax, menu_xSpace);
	system("cls");

	return n;
}
int CGameStart::RulesMenu(int menu_x, int menu_y)
{
	CGameSetting::gotoxy(67, 2);
	CGameSetting::setcolor(DARK_GREEN, WHITE);
	printf("2516 �̿���");
	CGameSetting::setcolor(BLACK, WHITE);
	char* rulesArray[] = {
		"������������������������������������������������������",
		"��                     ���ӹ��                     ��",
		"��                                                  ��",
		"��       �׼� �����̵� ������ ��ǳ� ģ����!        ��",
		"��                                                  ��",
		"��     - ĳ���� �� �� ��,��,��,��� �����Դϴ�.     ��",
		"��     - �־��� �ð� 7�� �ȿ� ������ ���ư���       ��",
		"��       �ʰų� ������ 0�̸� ������ ����˴ϴ�.     ��",
		"��     - ��ֹ��� �ε����� ������ 1�� �����ϰ�      ��",
		"��       ĳ���Ͱ� ���������� �ٲ�� ��� ����       ��",
		"��       ���°� �Ǿ� ��ֹ��� �ε����� ������       ��",
		"��       ������ �پ���� �ʽ��ϴ�.                  ��",
		"��     - �ѹ� ���� �ǳʸ� ������ ������ 1����       ��",
		"��       �����մϴ�                                 ��",
		"��     - ������ ����Ǹ� �����̱⸦ ���� ������     ��",
		"��       �ּ�0 ~ �ִ�10���� ���� �� �ְ�, ��ǰ      ��",
		"��       �̱⸦ ���� ������ ������ �� �ֽ��ϴ�.     ��",
		"��     - ���� ���� �ؿ� �ְ������� �����ֽ��ϴ�     ��",
		"��       �ְ� ������ �Ƿ��� ������ ���� �����ؾ�    ��",
		"��       ����?                                      ��",
		"��                                                  ��",
		"��                                                  ��",
		"������������������������������������������������������",
	};

	for (int i = 0; i < 23; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 5, SCREEN_Y / 6 + i);
		cout << rulesArray[i] << endl;
	}

	int n;
	int menu_xMax = 47;
	int menu_xSpace = 30;
	CGameSetting::setcolor(BLACK, WHITE);
	CGameSetting::gotoxy(menu_x + 2, menu_y);  cout << "���ӽ���";
	CGameSetting::gotoxy(menu_x + menu_xSpace+2, menu_y);  cout << "�ڷΰ���";

	Sleep(100);
	n = CGameSetting::MenuSelect(menu_x, menu_y, menu_x, menu_xMax, menu_xSpace);

	return n;
}



