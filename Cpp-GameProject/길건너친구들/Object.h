#pragma once
#include "GameSetting.h"

class CObstacle;
class CPlayer;
class CObject
{
public:
	list<CObstacle*> ObstacleList[OBJ_MAX]; // 장애물들을 담고 있는 list
	void AddObject(CObstacle* obstacle, int x, int y); //list에 장애물객체를 추가
	void Move(CPlayer* player); //장애물들을 움직이고, 플레이어와의 충돌을 체크하고, 화면을 벗어나면 객체를 지움,
	void Scroll(); //장애물과 플레이어를 스크롤함.

public:
	CObject();
	~CObject();
};