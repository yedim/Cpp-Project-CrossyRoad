#pragma once
#include "GameSetting.h"

class CObstacle
{
public:
	int x;
	int y;
	int speed;
	int width;
	int height;
	OBSTACLE_TYPE Type;
public:
	virtual void Init(int x, int y);
	virtual void Init(int y);
	virtual void Move();
	virtual int GetX();
	virtual int GetWidth();
	virtual int GetHeight();
	virtual OBSTACLE_TYPE GetType();

public:
	CObstacle();
	~CObstacle();
};