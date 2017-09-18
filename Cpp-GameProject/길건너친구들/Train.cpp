#include "Train.h"

CTrain::CTrain()
{

}
CTrain::~CTrain()
{

}

void CTrain::Init(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CTrain::Init(int y)
{
	this->y = y;
}

void CTrain::Move()
{
	CGameSetting::setcolor(DARK_GREEN, PURPLE);
	CGameSetting::gotoxy(x += speed, y);
	CGameSetting::draw_shape(3); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(4);
	cout << endl;

	CGameSetting::gotoxy(x, y + 1);
	CGameSetting::draw_shape(2);
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	CGameSetting::draw_shape(2);
	cout << endl;

	CGameSetting::gotoxy(x, y + 2);
	CGameSetting::draw_shape(6); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(5);

	if (x + width >= SCREEN_X){ x = 0; }
}

int CTrain::GetX()
{
	return x;
}
int CTrain::GetY()
{
	return y;
}
int CTrain::GetWidth()
{
	return width;
}
int CTrain::GetHeight()
{
	return height;
}
OBSTACLE_TYPE CTrain::GetType()
{
	return Type;
}
