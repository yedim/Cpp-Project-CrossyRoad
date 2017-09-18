#include "GameStart.h"
#include "Player.h"

CGameStart::CGameStart()
{
	DelCursor();
	LoadingGame();
	SettingGame();
}
CGameStart::~CGameStart()
{

}

void CGameStart::LoadingGame()
{
	system("title 길건너 친구들");
	system("mode con cols=80 lines=35");//콘솔창 크기
	system("color b0");
	char myInfo[][5] = { "M", "A", "D", "E", " B", "Y", " Y", "E", "R", "I", "M" };

	CGameSetting::gotoxy(30, SCREEN_Y / 2);
	for (int i = 0; i < sizeof(myInfo) / sizeof(myInfo[0]); i++)
	{
		cout << myInfo[i];
		Sleep(50);
	}
	system("cls");
	Title(SCREEN_X / 5, SCREEN_Y / 5, true);
	Sleep(3000);
}

void CGameStart::SettingGame()
{
	system("color 2F");
	//Title(SCREEN_X / 5, SCREEN_Y / 5, false);
	//Sleep(5000);
}

void CGameStart::DelCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void CGameStart::Title(int titleX, int titleY, bool animation)
{
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
		CGameSetting::gotoxy(titleX, titleY + i);
		cout << titleArray[i] << endl;
		if (animation == true) Sleep(50);
	}

}