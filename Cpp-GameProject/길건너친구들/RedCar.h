#pragma once
#include "GameSetting.h"
#include "Obstacle.h"

class CRedCar :public CObstacle
{
public:
	int x;
	int y;
	int speed = 1;
	int width = 6;
	int height = 3;
	OBSTACLE_TYPE Type = REDCAR;

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
	CRedCar();
	virtual~CRedCar();
};