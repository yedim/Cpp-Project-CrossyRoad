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
	printf("��������\n");
	CGameSetting::gotoxy(x, y + 1);
	printf("����ᦢ\n");
	CGameSetting::gotoxy(x, y + 2);
	printf("��������");
	if (x + width >= SCREEN_X){ x = 0; }
}
int CRedCar::GetX()
{
	return x;
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

