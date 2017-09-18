#include "GamePlay.h"
#include "Object.h"
#include "BlueCar.h"
#include "Player.h"
#include "RedCar.h"

CGamePlay::CGamePlay()
{
	PlayingGame();
}
CGamePlay::~CGamePlay()
{

}

void CGamePlay::PlayingGame()
{
	srand((unsigned)time(NULL));
	int random;

	CObject* obj = new CObject;
	CPlayer* player = new CPlayer;

	runTime = clock(); //프로그램 실행시간
	pressTime = runTime; //cf. 초기값 없으면->쓰레기값
	while (true)
	{
		system("cls");
		ScoreBoard();//점수판
		nConsume++;
		random = rand() % 6; //OBJ_RANDOM;//장애물을 랜덤으로 생성.

		if (nConsume >= 7)//일정시간이 지나면 장애물들과 플레이어가 스크롤한다.
		{
			if (player->player_y < 35)
			{
				CGameSetting::gotoxy(player->player_x, player->player_y += 3);
				GameScreen(obj, random);
				cout << random;
			}

			obj->Scroll();
			nConsume = 0;
		}
		CGameSetting::gotoxy(player->player_x, player->player_y);
		player->Draw();

		for (int i = 0; i < OBJ_MAX; ++i)
		{
			if (_kbhit())
			{
				player->key = _getch(); // 화살표키를 입력
				player->move_arrow_key(player->key, &(player->player_x), &(player->player_y), SCREEN_X, SCREEN_Y);

				if (player->key == 72)
				{
					score++;//점수 1점씩 증가
					pressTime = runTime;//runTime-pressTime=0 -> 7초
				}
			}
			obj->Move(player);
			Sleep(80);
		}
		runTime = clock();
	}
}
void CGamePlay::ScoreBoard()
{
	CGameSetting::setcolor(BLACK, WHITE);
	timer = 7 - (runTime - pressTime) / 1000;//타이머
	CGameSetting::gotoxy(50, 2);
	printf("            ");
	CGameSetting::gotoxy(50, 2);
	printf("점수: %d", score);
	CGameSetting::gotoxy(68, 3);
	printf(" %d 초", timer); //현재시각 - (게임시작시간 - 프로그램 실행시간) > (ms) / 1000 = N(sec) 
	if (timer <= 0)
	{
		_getch();
		//화면전환
	}
}
void CGamePlay::GameScreen(CObject* obj, int random)
{
	int blueCar_IntervalX = 0;
	int redCar_IntervalX = 0;

	if (random == BLUECAR)
	{
		for (int i = 0; i < 3; i++)//4는 차의 갯수
		{
			obj->AddObject(new CBlueCar, blueCar_IntervalX, 3);
			blueCar_IntervalX += 20;//간격
		}
	}

	if (random == REDCAR)
	{
		for (int i = 0; i < 2; i++)
		{
			obj->AddObject(new CRedCar, redCar_IntervalX, 3);
			redCar_IntervalX += 30;
		}
	}
}
