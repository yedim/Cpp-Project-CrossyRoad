#pragma once
#include "GameSetting.h"
#include "Obstacle.h"

class CBlueCar :public CObstacle
{
public:
	int x;
	int y;
	int speed = 1;
	int width = 4;
	int height = 3;
	OBSTACLE_TYPE Type = BLUECAR;
public:
	virtual void Init(int x, int y);
	virtual void Init(int y);
	virtual void Move();
	virtual int GetX();
	virtual int GetY();
	virtual int GetWidth();
	virtual int GetHeight();
	virtual OBSTACLE_TYPE GetType();

public:
	CBlueCar();
	virtual~CBlueCar();
};