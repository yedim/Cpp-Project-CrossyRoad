#pragma once
#include "GameSetting.h"
#include "Obstacle.h"

class CYellowCar :public CObstacle
{
public:
	int x;
	int y;
	int speed = 1;
	int width = 8;
	int height = 3;
	OBSTACLE_TYPE Type = YELLOWCAR;

public:
	virtual void Init(int x, int y);
	virtual void Init(int y);
	virtual void Move();
	virtual int GetX();
	virtual int GetWidth();
	virtual int GetHeight();
	virtual OBSTACLE_TYPE GetType();
public:
	CYellowCar();
	virtual~CYellowCar();
};