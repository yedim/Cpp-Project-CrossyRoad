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
	printf("����������\n");
	CGameSetting::gotoxy(x, y + 1);
	printf("�����ᦢ\n");
	CGameSetting::gotoxy(x, y + 2);
	printf("����������");
	if (x + width >= SCREEN_X){ x = 0; }
}

int CYellowCar::GetX()
{
	return x;
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