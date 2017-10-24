#pragma once
#include "GameSetting.h"

class CGameStart
{
public:
	void LoadingGame();
	void DelCursor();//커서 없애기
	int MainMenu(int menu_x, int menu_y);
	int RulesMenu(int menu_x, int menu_y);

public:
	CGameStart();
	~CGameStart();
};
