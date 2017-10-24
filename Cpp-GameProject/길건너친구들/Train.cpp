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
	printf("忙式式式式式式式式忖\n");
	CGameSetting::gotoxy(x, y + 1);
	printf("弛﹥﹥﹥﹥﹥﹥﹥﹥弛\n");
	CGameSetting::gotoxy(x, y + 2);
	printf("戌式式式式式式式式戎");
	if (x + width >= SCREEN_X){ x = 0; }
}

int CTrain::GetX()
{
	return x;
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
