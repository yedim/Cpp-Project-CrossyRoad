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
	printf("¦£¦¡¦¤\n");
	CGameSetting::gotoxy(x, y + 1);
	printf("¦¢¡á¦¢\n");
	CGameSetting::gotoxy(x, y + 2);
	printf("¦¦¦¡¦¥");
	
	if (x + width >= SCREEN_X){ x = 0; }
}

int CBlueCar::GetX()
{
	return x;
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
