#pragma once
#include "GameSetting.h"

class CObject;
class CGamePlay
{
public:
	int score = 0;
	int nConsume = 0;
	clock_t runTime;
	clock_t pressTime = 0;
	int timer;
public:
	void PlayingGame();
	void ScoreBoard();
	void GameScreen(CObject* obj, int random);
public:
	CGamePlay();
	~CGamePlay();
};
