#include "YellowCar.h"

CYellowCar::CYellowCar()
{

}
CYellowCar::~CYellowCar()
{

}
void CYellowCar::Init(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CYellowCar::Init(int y)
{
	this->y = y;
}

void CYellowCar::Move()
{
	CGameSetting::setcolor(DARK_GREEN, YELLOW);
	CGameSetting::gotoxy(x += speed, y);
	CGameSetting::draw_shape(3); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(4); cout << endl;

	CGameSetting::gotoxy(x, y + 1);
	CGameSetting::draw_shape(2); cout << "¡á¡á¡á¡á"; CGameSetting::draw_shape(2); cout << endl;

	CGameSetting::gotoxy(x, y + 2);
	CGameSetting::draw_shape(6); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(5);

	if (x + width >= SCREEN_X){ x = 0; }
}

int CYellowCar::GetX()
{
	return x;
}
int CYellowCar::GetY()
{
	return y;
}
int CYellowCar::GetWidth()
{
	return width;
}
int CYellowCar::GetHeight()
{
	return height;
}
OBSTACLE_TYPE CYellowCar::GetType()
{
	return Type;
}