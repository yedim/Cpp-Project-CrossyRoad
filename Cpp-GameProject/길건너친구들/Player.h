#include "GameSetting.h"

class CPlayer
{
public:
	char key;
	int player_x = SCREEN_X / 2;
	int player_y = 30;
	int width = 1;
	int height = 1;
public:
	void Draw();
	void move_arrow_key(char key, int *x, int *y, int x_b, int y_b); // 키보드 입력받아 플레이어 움직이기
public:
	CPlayer();
	~CPlayer();
};
