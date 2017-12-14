#include "GameSetting.h"
#include "Player.h"
#include "GameStart.h"
#include "GamePlay.h"
#include "GameOver.h"
#include "Player.h"

int main()
{
	CGameStart* gamestart = new CGameStart;
	CGamePlay* gameplay = new CGamePlay;
	CGameOver* gameover = new CGameOver;

	int start_n;
	int rules_n;
	int over_n;
	int hp = 2;

	while (1)
	{
		gamestart->DelCursor();
		gamestart->LoadingGame();

		while (1)
		{
			start_n = gamestart->MainMenu(12, 30);

			if (start_n == 1){ break;}       //���ӽ���
			else if (start_n == 2)           //���ӹ��
			{ 
				rules_n = gamestart->RulesMenu(20, 30);
				if (rules_n == 1){ break; }
				else if (rules_n == 2){}//�ڷΰ���
			}
			else if (start_n == 3){}          //���Ӹ���
			else if (start_n == 4){ exit(0);} //��������
		}

		while (1)
		{
			gameplay->GetScoreFile();
			gameplay->GetCoinFile();

			if (gameplay->PlayingGame(hp) == 1)
			{
				gameplay->score = 0;
				hp = 2;
				gameplay->SetScoreFile(gameplay->topScore);
				gameplay->SetCoinFile(gameplay->coin);
				Sleep(1000);

				while (1)
				{
					over_n = gameover->GameOverMenu(12, 30) - 1;
					if (over_n == 0){ break; }
					else if (over_n == 1){
						gameplay->coin += gameover->Present();
						CGameSetting::gotoxy(70, 2);
						CGameSetting::setcolor(BLACK, YELLOW);
						printf("Coin %3d", gameplay->coin);
					}
					else if (over_n == 2){
						hp += gameover->Prize(gameplay);
						
						CGameSetting::gotoxy(33, 2);
						
						for (int i = 0; i < hp; i++)
						{
							CGameSetting::setcolor(BLACK, RED); printf("��");
						}
						gameplay->SetCoinFile(gameplay->coin);

					}
					else if (over_n == 3){ exit(0); }//��������
				}

			}
		}
	}
	
}