#pragma once
#include "GameSetting.h"

class CGameStart
{
public:
	void LoadingGame();
	void SettingGame();
	void DelCursor();//커서 없애기
	void Title(int titleX, int titleY, bool animation);

public:
	CGameStart();
	~CGameStart();
};
