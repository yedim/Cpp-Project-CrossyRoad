#include "RedCar.h"

CRedCar::CRedCar()
{

}
CRedCar::~CRedCar()
{

}
void CRedCar::Init(int  x, int y)
{
	this->x = x;
	this->y = y;
}
void CRedCar::Init(int y)
{
	this->y = y;
}
void CRedCar::Move()
{
	CGameSetting::setcolor(DARK_GREEN, RED);

	CGameSetting::gotoxy(x += speed, y);
	CGameSetting::draw_shape(3); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(4); cout << endl;

	CGameSetting::gotoxy(x, y + 1);
	CGameSetting::draw_shape(2); cout << "бсбс"; CGameSetting::draw_shape(2); cout << endl;

	CGameSetting::gotoxy(x, y + 2);
	CGameSetting::draw_shape(6); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(5);

	if (x + width >= SCREEN_X){ x = 0; }
}
int CRedCar::GetX()
{
	return x;
}
int CRedCar::GetY()
{
	return y;
}
int CRedCar::GetWidth()
{
	return width;
}
int CRedCar::GetHeight()
{
	return height;
}
OBSTACLE_TYPE CRedCar::GetType()
{
	return Type;
}

