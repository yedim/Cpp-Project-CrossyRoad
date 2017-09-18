#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <list>
#include <stdio.h>

using namespace std;
#define SCREEN_X 79
#define SCREEN_Y 35

enum COLOR_TYPE
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBULE,
	DARK_RED,
	DARK_PURPLE,
	DARK_YELLOW,
	GREY,
	DARK_GREY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
};

enum OBSTACLE_TYPE
{
	BLUECAR,
	REDCAR,
	YELLOWCAR,
	TRAIN,
	RIVER,
	LOG,
	OBJ_MAX,
	OBJ_RANDOM = 20
};

class CGameSetting{
public:
	static void gotoxy(int x, int y);//커서 위치 변경
	static void setcolor(COLOR_TYPE backcolor, COLOR_TYPE fontcolor);//색상 변경
	static void draw_shape(int num);//모양 그리기

public:
	CGameSetting();
	~CGameSetting();
};
