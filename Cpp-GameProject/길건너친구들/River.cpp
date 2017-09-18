#include "River.h"
CRiver::CRiver()
{

}
CRiver::~CRiver()
{

}

void CRiver::Init(int  x, int y)
{
	this->x = x;
	this->y = y;
}

void CRiver::Init(int y)
{
	this->y = y;
}

void CRiver::Move()
{
	CGameSetting::setcolor(DARK_GREEN, SKYBLUE);
	CGameSetting::gotoxy(x += speed, y);
	CGameSetting::draw_shape(3); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	 CGameSetting::draw_shape(4); cout << endl;

	CGameSetting::gotoxy(x, y + 1);
	CGameSetting::draw_shape(2);
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	CGameSetting::draw_shape(2); cout << endl;

	CGameSetting::gotoxy(x, y + 2);
	CGameSetting::draw_shape(6); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(1); CGameSetting::draw_shape(1); CGameSetting::draw_shape(1);
	CGameSetting::draw_shape(5);

	if (x + width >= SCREEN_X){ x = 0; }
}

int CRiver::GetX()
{
	return x;
}
int CRiver::GetY()
{
	return y;
}
int CRiver::GetWidth()
{
	return width;
}
int CRiver::GetHeight()
{
	return height;
}
OBSTACLE_TYPE CRiver::GetType()
{
	return Type;
}
