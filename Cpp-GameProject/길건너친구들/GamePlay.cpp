#include "GamePlay.h"
#include "Object.h"
#include "BlueCar.h"
#include "Player.h"
#include "RedCar.h"
#include "YellowCar.h"
#include "Train.h"
#include "GameOver.h"

CGamePlay::CGamePlay()
{
}
CGamePlay::~CGamePlay()
{
	delete obj;
	delete player;
}

int CGamePlay::PlayingGame()
{
	srand((unsigned)time(NULL));

	obj = new CObject;
	player = new CPlayer;

	runTime = clock();
	pressTime = runTime; //cf. 초기값 없으면->쓰레기값
	while (true)
	{
		system("cls");
		if (ScoreBoard(player) == 1) { return 1; }
		scrollTime++;
		unbeatableTime++;

		random = rand() % OBJ_MAX;//장애물을 랜덤으로 생성.

		if (scrollTime >= 7)//일정시간이 지나면 장애물들과 플레이어를 스크롤한다.
		{
			if (player->player_y <= 32)
			{
				CGameSetting::gotoxy(player->player_x, player->player_y += 3);
				CreateObstacle(obj, random);
			}
			obj->Scroll();
			scrollTime = 0;
		}

		CGameSetting::gotoxy(player->player_x, player->player_y);
		if (unbeatableTime <= 5)
		{
			player->Draw(DARK_GREEN, RED);//무적상태 일 때 캐릭터는 빨간색.
		}
		else
		{
			player->Draw(DARK_GREEN, WHITE);//무적상태 아닐 때 캐릭터는 흰색.
		}

		for (int i = 0; i < OBJ_MAX; ++i)
		{
			if (_kbhit())
			{
				player->key = _getch(); // 화살표키를 입력
				player->move_arrow_key(player->key, &(player->player_x), &(player->player_y), SCREEN_X, SCREEN_Y);

				if (player->key == 72)
				{
					score++;//점수 1점씩 증가
					if (score >= 1000){ score = 1000; return 1; } //최대 1000까지만 전진가능하다. 
					coin++;
					pressTime = runTime; //runTime-pressTime=0 -> 7초
				}
			}
			if (obj->Move(player) == 1)
			{
				if (unbeatableTime > 5)
				{
					--player->hp;
				}
				unbeatableTime = 0;
			}
			Sleep(50);
		}
		runTime = clock();
	}
	return 0;

}

//점수와 생명과 코인을 출력
int CGamePlay::ScoreBoard(CPlayer* player)
{
	CGameSetting::setcolor(BLACK, WHITE);
	timer = 7 - (runTime - pressTime) / 1000;//타이머
	CGameSetting::gotoxy(1, 0);
	printf("                                                                                ");
	CGameSetting::gotoxy(2, 0);
	printf("                                                                                ");
	CGameSetting::gotoxy(3, 0);
	printf("                                                                                ");
	CGameSetting::gotoxy(4, 0);
	printf("                                                                  2516 이예림   ");

	CGameSetting::gotoxy(5, 2);
	printf("Score %d", score);
	CGameSetting::gotoxy(47, 2);
	printf("Timer ");
	for (int i = 0; i < timer; i++)
	{
		printf("■");
	}
	//printf("Timer  %d초", timer); //현재시각 - (게임시작시간 - 프로그램 실행시간) > (ms) / 1000 = N(sec) 
	CGameSetting::gotoxy(70, 2);
	CGameSetting::setcolor(BLACK, YELLOW);
	printf("Coin %3d", coin); 

	CGameSetting::gotoxy(33, 2);
	for (int i = 0; i < player->hp; i++)
	{
		CGameSetting::setcolor(BLACK,RED); printf("♥");
	}
	if (timer <= 0 || player->hp<=0)
	{
		return 1;
	}
	return 0;
}
void CGamePlay::CreateObstacle(CObject* obj, int random)
{
	int blueCar_intervalX = 0;
	int redCar_intervalX = 0;
	int yellowCar_intervalX = 0;
	int train_intervalX = 0;
	int river_IntervalX = 0;

	if (random == BLUECAR)
		for (int i = 0; i < 3; i++)
		{
			obj->AddObject(new CBlueCar, blueCar_intervalX, 2);
			blueCar_intervalX += 20;
		}

	if (random == REDCAR)
		for (int i = 0; i < 2; i++)
		{
			obj->AddObject(new CRedCar, redCar_intervalX, 2);
			redCar_intervalX += 30;
		}

	if (random == YELLOWCAR)
		for (int i = 0; i < 2; i++)
		{
			obj->AddObject(new CYellowCar, yellowCar_intervalX, 2);
			yellowCar_intervalX += 25;
		}

	if (random == TRAIN)
		for (int i = 0; i < 1; i++)
		{
			obj->AddObject(new CTrain, train_intervalX, 2);
		}
}
void CGamePlay::SetFile()
{
	
}
void CGamePlay::GetFile()
{
	

}


