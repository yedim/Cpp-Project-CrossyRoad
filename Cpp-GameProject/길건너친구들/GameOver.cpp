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
		"��������������  ��������     ������������   ��������������",
		"��          ������    ���� ����  ����  ���� ��          ��",
		"��  ������������   ��   �� ��    ����    �� ��  ����������",
		"��  ������������  ����  ����  ����  ����  ����  ����������",
		"��  ������  ����  ����  ����  ����  ����  ����  ����������",
		"��  ������  ����  ����  ����  ����  ����  ����  ����������",
		"��          ����  ����  ����  ����  ����  ����          ��",
		"����������������������������������������������������������",
		"��������������������  ����������������������������������  ",
		"��          ����  ��  ��  ����          ����          ��  ",
		"��  ������  ����  ��  ��  ����  ������������  ������  ��  ",
		"��  ��  ��  ����  ��  ��  ����  ������������  ������  ��  ",
		"��  ��  ��  ����  ������  ����  ������������  ������  ��  ",
		"��  ������  ������      ������  ������������  ��  ��  ��  ",
		"��          ��  ����  ����  ��          ����  ��  ��������",
		"��������������    ������    ��������������������    ������" };

	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X/6, SCREEN_Y/4 + i);
		cout << titleArray[i] << endl;
	}

	int n;
	int menu_xMax = 47;
	int menu_xSpace = 15;
	CGameSetting::setcolor(BLACK, WHITE);
	CGameSetting::gotoxy(menu_x + 2, menu_y);  cout << "�ٽý���";
	CGameSetting::gotoxy(menu_x + menu_xSpace + 2, menu_y); cout << "�����̱�";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 2 + 2, menu_y); cout << "��ǰ�̱�";
	CGameSetting::gotoxy(menu_x + menu_xSpace * 3 + 2, menu_y); cout << "��������";

	n = CGameSetting::MenuSelect(menu_x, menu_y, menu_x, menu_xMax, menu_xSpace);

	return n;
}
int CGameOver::Present()
{
	//GameOverTitle �����
	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 6, SCREEN_Y / 4 + i);
		cout << "                                                          " << endl;
	}

	//�������� ���� �߻� (0~10����)
	srand((unsigned)time(NULL));
	int c = 0;
	int countTime = 0;
	
	CGameSetting::gotoxy(SCREEN_X / 2-3, SCREEN_Y / 3-1);
	CGameSetting::setcolor(BLACK, WHITE);
	cout << "���� ������";

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
	cout << c <<"���� ȹ��";
	Sleep(2000);

	//����ȹ�� �޽��� �����
	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 6, SCREEN_Y / 4 + i);
		cout << "                                                          " << endl;
	}
	return c;
}
int CGameOver::Prize(CGamePlay* gameplay)
{
	//GameOverTitle �����
	for (int i = 0; i < 16; i++)
	{
		CGameSetting::gotoxy(SCREEN_X / 6, SCREEN_Y / 4 + i);
		cout << "                                                          " << endl;
	}

	//��ǰ�̱�� 100���� �̻� �־�� ����, �������� 0~2���� ���� ����.
	srand((unsigned)time(NULL));
	int hp=0;
	int countTime=0;
	if (gameplay->coin < 100)
	{
		CGameSetting::gotoxy(SCREEN_X / 2 - 20, SCREEN_Y / 3 - 1);
		CGameSetting::setcolor(BLACK, WHITE);
		cout << "100������ ���� �����Ƿ� ��ǰ�̱Ⱑ �Ұ����մϴ�.";
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
		cout << "��ǰ�̱� �̴� ��";
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
		cout << "����"<< hp << "�� ȹ��";
		Sleep(2000);
	}
	return hp;
}