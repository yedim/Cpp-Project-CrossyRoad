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

	runTime = clock(); //���α׷� ����ð�
	pressTime = runTime; //cf. �ʱⰪ ������->�����Ⱚ
	while (true)
	{
		system("cls");
		ScoreBoard();//������
		nConsume++;
		random = rand() % 6; //OBJ_RANDOM;//��ֹ��� �������� ����.

		if (nConsume >= 7)//�����ð��� ������ ��ֹ���� �÷��̾ ��ũ���Ѵ�.
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
				player->key = _getch(); // ȭ��ǥŰ�� �Է�
				player->move_arrow_key(player->key, &(player->player_x), &(player->player_y), SCREEN_X, SCREEN_Y);

				if (player->key == 72)
				{
					score++;//���� 1���� ����
					pressTime = runTime;//runTime-pressTime=0 -> 7��
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
	timer = 7 - (runTime - pressTime) / 1000;//Ÿ�̸�
	CGameSetting::gotoxy(50, 2);
	printf("            ");
	CGameSetting::gotoxy(50, 2);
	printf("����: %d", score);
	CGameSetting::gotoxy(68, 3);
	printf(" %d ��", timer); //����ð� - (���ӽ��۽ð� - ���α׷� ����ð�) > (ms) / 1000 = N(sec) 
	if (timer <= 0)
	{
		_getch();
		//ȭ����ȯ
	}
}
void CGamePlay::GameScreen(CObject* obj, int random)
{
	int blueCar_IntervalX = 0;
	int redCar_IntervalX = 0;

	if (random == BLUECAR)
	{
		for (int i = 0; i < 3; i++)//4�� ���� ����
		{
			obj->AddObject(new CBlueCar, blueCar_IntervalX, 3);
			blueCar_IntervalX += 20;//����
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
