#pragma once
#include "GameSetting.h"

class CGameStart
{
public:
	void LoadingGame();
	void SettingGame();
	void DelCursor();//Ŀ�� ���ֱ�
	void Title(int titleX, int titleY, bool animation);

public:
	CGameStart();
	~CGameStart();
};
