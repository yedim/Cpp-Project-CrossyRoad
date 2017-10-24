#pragma once
#include "GameSetting.h"
#include "GamePlay.h"

class CGamePlay;
class CGameOver
{
public:
	int GameOverMenu(int menu_x, int menu_y);
	int Present();
	int Prize(CGamePlay* gameplay);
public:
	CGameOver();
	~CGameOver();
};
