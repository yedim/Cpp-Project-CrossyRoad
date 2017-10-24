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
	system("title 길건너 친구들");
	system("mode con cols=80 lines=35");//콘솔창 크기
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
	printf("2516 이예림");

	//길건너 친구들 타이틀 출력
	CGameSetting::setcolor(BLACK, WHITE);
	char* titleArray[23] = {
		"┏━━━━┓┏┓┏━━━━┓┏┓┏┓            ┏┓",
		"┗━━━┓┃┃┃┗━━━┓┃┃┃┃┃            ┃┃",
		"        ┃┃┃┃        ┃┗┛┃┃┃            ┃┃",
		"        ┃┃┃┃        ┃┏┓┃┃┃            ┃┃",
		"        ┗┛┗┛        ┃┃┃┃┃┃        ┏━┛┃",
		"┏━━━━━━┓        ┗┛┃┃┃┃        ┗━┓┃",
		"┗━━━━━┓┃ ┏┓       ┗┛┃┃            ┃┃",
		"┏━━━━━┛┃ ┃┃           ┃┗━━━━━┓┃┃",
		"┃┏━━━━━┛ ┃┃           ┗━━━━━━┛┃┃",
		"┃┗━━━━━┓ ┃┗━━━━━┓               ┃┃",
		"┗━━━━━━┛ ┗━━━━━━┛               ┗┛",
		"    ┏┓      ┏┓┏━━━━━━┓┏━━━━━━━┓",
		"┏━┛┗━━┓┃┃┗━━━━━┓┃┃┏━━━━━━┛",
		"┗┓    ┏━┛┃┃            ┃┃┃┗━━━━━━┓",
		"  ┃┏┓┃    ┃┃            ┃┃┗━━━━━━━┛",
		"  ┃┃┃┃    ┃┃            ┗┛┏━━━━━━━┓",
		"  ┗┛┗┛    ┃┃┏━━━━━━┓┗━━━━━━━┛",
		" ┏┓         ┗┛┗━━┓┏━━┛┏━━━━━━━┓",
		" ┃┃                   ┃┃      ┗━━━━━━┓┃",
		" ┃┃                   ┃┃      ┏━━━━━━┛┃",
		" ┃┃                   ┃┃      ┃┏━━━━━━┛",
		" ┃┗━━━━━━┓     ┃┃      ┃┗━━━━━━┓",
		" ┗━━━━━━━┛     ┗┛      ┗━━━━━━━┛"
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
	CGameSetting::gotoxy(menu_x + 2, menu_y);  cout << "게임시작";
	CGameSetting::gotoxy(menu_x + menu_xSpace + 2, menu_y); cout << "게임방법";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 2 + 2, menu_y); cout << "게임리셋";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 3 + 2, menu_y); cout << "게임종료";

	n = CGameSetting::MenuSelect(menu_x, menu_y, menu_x, menu_xMax, menu_xSpace);
	system("cls");

	return n;
}
int CGameStart::RulesMenu(int menu_x, int menu_y)
{
	CGameSetting::gotoxy(67, 2);
	CGameSetting::setcolor(DARK_GREEN, WHITE);
	printf("2516 이예림");
	CGameSetting::setcolor(BLACK, WHITE);
	char* rulesArray[] = {
		"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓",
		"┃                     게임방법                     ┃",
		"┃                                                  ┃",
		"┃       액션 아케이드 런게임 길건너 친구들!        ┃",
		"┃                                                  ┃",
		"┃     - 캐릭터 ■ 는 전,후,좌,우로 움직입니다.     ┃",
		"┃     - 주어진 시간 7초 안에 앞으로 나아가지       ┃",
		"┃       않거나 생명이 0이면 게임이 종료됩니다.     ┃",
		"┃     - 장애물에 부딪히면 생명이 1개 감소하고      ┃",
		"┃       캐릭터가 빨간색으로 바뀌어 잠시 무적       ┃",
		"┃       상태가 되어 장애물에 부딪혀도 생명이       ┃",
		"┃       생명이 줄어들지 않습니다.                  ┃",
		"┃     - 한번 길을 건너면 점수와 코인이 1개씩       ┃",
		"┃       증가합니다                                 ┃",
		"┃     - 게임이 종료되면 선물뽑기를 통해 코인을     ┃",
		"┃       최소0 ~ 최대10코인 받을 수 있고, 경품      ┃",
		"┃       뽑기를 통해 생명을 구매할 수 있습니다.     ┃",
		"┃     - 현재 점수 밑에 최고점수가 써져있습니다     ┃",
		"┃       최고 점수가 되려면 생명을 많이 구매해야    ┃",
		"┃       겠죠?                                      ┃",
		"┃                                                  ┃",
		"┃                                                  ┃",
		"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛",
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
	CGameSetting::gotoxy(menu_x + 2, menu_y);  cout << "게임시작";
	CGameSetting::gotoxy(menu_x + menu_xSpace+2, menu_y);  cout << "뒤로가기";

	Sleep(100);
	n = CGameSetting::MenuSelect(menu_x, menu_y, menu_x, menu_xMax, menu_xSpace);

	return n;
}



