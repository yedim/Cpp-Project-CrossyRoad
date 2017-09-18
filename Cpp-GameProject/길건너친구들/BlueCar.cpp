#include "BlueCar.h"

CBlueCar::CBlueCar()
{

}
CBlueCar::~CBlueCar()
{

}
void CBlueCar::Init(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CBlueCar::Init(int y)
{
	this->y = y;
}

void CBlueCar::Move()
{
	CGameSetting::setcolor(DARK_GREEN, BLUE);
	CGameSetting::gotoxy(x += speed, y);
	CGameSetting::draw_shape(3); CGameSetting::draw_shape(1); CGameSetting::draw_shape(4);  cout << endl;

	CGameSetting::gotoxy(x, y + 1);
	CGameSetting::draw_shape(2); cout << "бс"; CGameSetting::draw_shape(2); cout << endl;

	CGameSetting::gotoxy(x, y + 2);
	CGameSetting::draw_shape(6); CGameSetting::draw_shape(1); CGameSetting::draw_shape(5);

	if (x + width >= SCREEN_X){ x = 0; }
}

int CBlueCar::GetX()
{
	return x;
}
int CBlueCar::GetY()
{
	return y;
}
int CBlueCar::GetWidth()
{
	return width;
}
int CBlueCar::GetHeight()
{
	return height;
}
OBSTACLE_TYPE CBlueCar::GetType()
{
	return Type;
}
