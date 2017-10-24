#include "Player.h"
CPlayer::CPlayer()
{
}
CPlayer::~CPlayer()
{
}
void CPlayer::Draw(COLOR_TYPE bgcolor, COLOR_TYPE fontcolor)
{
	CGameSetting::setcolor(bgcolor, fontcolor);
	printf("бс"); // Player Character
}
void CPlayer::move_arrow_key(char key, int *x, int *y, int x_b, int y_b){
	switch (key){
	case 72:
		*y = *y - 1;//UP
		if (*y<5) *y = 5;
		break;
	case 75://LEFT
		*x = *x - 1;
		if (*x<1) *x = 1;
		break;
	case 77://RIGHT
		(*x)++;
		if (*x > x_b)  *x = x_b;
		break;
	case 80://DOWN
		(*y)++;
		if (*y > y_b)*y = y_b;
		break;
	default:
		return;
	}
}
