#include "GameOver.h"

CGameOver::CGameOver()
{
}
CGameOver::~CGameOver()
{
}

int CGameOver::GameOverMenu(int menu_x, int menu_y)
{
	CGameSetting::setcolor(BLACK, WHITE);
	char* titleArray[] = {
		"┏━━━━━┓  ┏━━┓     ┏━┓┏━┓   ┏━━━━━┓",
		"┃          ┃┏┛    ┗┓ ┏┛  ┃┃  ┗┓ ┃          ┃",
		"┃  ┏━━━┛┃   □   ┃ ┃    ┗┛    ┃ ┃  ┏━━━┛",
		"┃  ┃┏━━┓┃  ┏┓  ┃┃  ┏┓  ┏┓  ┃┃  ┗━━━┓",
		"┃  ┃┗┓  ┃┃  ┃┃  ┃┃  ┃┃  ┃┃  ┃┃  ┏━━━┛",
		"┃  ┗━┛  ┃┃  ┃┃  ┃┃  ┃┃  ┃┃  ┃┃  ┗━━━┓",
		"┃          ┃┃  ┃┃  ┃┃  ┃┃  ┃┃  ┃┃          ┃",
		"┗━━━━━┛┗━┛┗━┛┗━┛┗━┛┗━┛┗━━━━━┛",
		"┏━━━━━┓┏━┓  ┏━┓┏━━━━━┓┏━━━━━┓  ",
		"┃          ┃┃  ┃  ┃  ┃┃          ┃┃          ┃  ",
		"┃  ┏━┓  ┃┃  ┃  ┃  ┃┃  ┏━━━┛┃  ┏━┓  ┃  ",
		"┃  ┃  ┃  ┃┃  ┃  ┃  ┃┃  ┗━━━┓┃  ┗━┛  ┃  ",
		"┃  ┃  ┃  ┃┃  ┗━┛  ┃┃  ┏━━━┛┃  ┏━┓  ┃  ",
		"┃  ┗━┛  ┃┗┓      ┏┛┃  ┗━━━┓┃  ┃  ┃  ┃  ",
		"┃          ┃  ┗┓  ┏┛  ┃          ┃┃  ┃  ┗┓┗┓",
		"┗━━━━━┛    ┗━┛    ┗━━━━━┛┗━┛    ┗━┛" };

	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X/6, SCREEN_Y/4 + i);
		cout << titleArray[i] << endl;
	}

	int n;
	int menu_xMax = 47;
	int menu_xSpace = 15;
	CGameSetting::setcolor(BLACK, WHITE);
	CGameSetting::gotoxy(menu_x + 2, menu_y);  cout << "다시시작";
	CGameSetting::gotoxy(menu_x + menu_xSpace + 2, menu_y); cout << "선물뽑기";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 2 + 2, menu_y); cout << "경품뽑기";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 3 + 2, menu_y); cout << "게임종료";

	n = CGameSetting::MenuSelect(menu_x, menu_y, menu_x, menu_xMax, menu_xSpace);

	return n;
}
int CGameOver::Present()
{
	//GameOverTitle 지우기
	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 6, SCREEN_Y / 4 + i);
		cout << "                                                          " << endl;
	}

	//랜덤으로 코인 발생 (0~10코인)
	srand((unsigned)time(NULL));
	int c = 0;
	int countTime = 0;
	
	CGameSetting::gotoxy(SCREEN_X / 2-3, SCREEN_Y / 3-1);
	CGameSetting::setcolor(BLACK, WHITE);
	cout << "코인 생성중";

	do
	{
		for (int i = 0; i <= 10; i++)
		{
			CGameSetting::gotoxy(SCREEN_X / 2, SCREEN_Y / 3);
			cout << i;
			Sleep(100);
			CGameSetting::gotoxy(SCREEN_X / 2, SCREEN_Y / 3);
			cout << "  ";
		}
		countTime++;
	} while (countTime < 4);
	
	c=rand() % 10;
	CGameSetting::gotoxy(SCREEN_X / 2-2, SCREEN_Y / 3);
	cout << c <<"코인 획득";
	Sleep(2000);

	//코인획득 메시지 지우기
	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 6, SCREEN_Y / 4 + i);
		cout << "                                                          " << endl;
	}
	return c;
}
int CGameOver::Prize(CGamePlay* gameplay)
{
	//GameOverTitle 지우기
	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 6, SCREEN_Y / 4 + i);
		cout << "                                                          " << endl;
	}

	//경품뽑기는 100코인 이상 있어야 가능, 랜덤으로 0~2개의 생명 지급.
	srand((unsigned)time(NULL));
	int hp=0;
	int countTime=0;
	if (gameplay->coin < 100)
	{
		CGameSetting::gotoxy(SCREEN_X / 2 - 20, SCREEN_Y / 3 - 1);
		CGameSetting::setcolor(BLACK, WHITE);
		cout << "100코인이 되지 않으므로 경품뽑기가 불가능합니다.";
		Sleep(2000);
	}
	else
	{
		gameplay->coin -= 100;
		CGameSetting::gotoxy(70, 2);
		CGameSetting::setcolor(BLACK, YELLOW);
		printf("Coin %3d", gameplay->coin);

		CGameSetting::gotoxy(SCREEN_X / 2 - 3, SCREEN_Y / 3 - 1);
		CGameSetting::setcolor(BLACK, WHITE);
		cout << "경품뽑기 뽑는 중";
		do
		{
			for (int i = 0; i <= 2; i++)
			{
				CGameSetting::gotoxy(SCREEN_X / 2, SCREEN_Y / 3);
				cout << i;
				Sleep(100);
				CGameSetting::gotoxy(SCREEN_X / 2, SCREEN_Y / 3);
				cout << "  ";
			}
			countTime++;
		} while (countTime < 8);

		hp = rand() % 2;
		CGameSetting::gotoxy(SCREEN_X / 2 - 4, SCREEN_Y / 3);
		cout << "생명"<< hp << "개 획득";
		Sleep(2000);
	}
	return hp;
}