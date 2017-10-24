#include "Object.h"
#include "Obstacle.h"
#include "Player.h"

CObject::CObject()
{

}
CObject::~CObject()
{
	delete[] &ObstacleList;
}

void CObject::AddObject(CObstacle* obstacle, int x, int y)
{
	obstacle->Init(x, y); //초기화
	obstacle->x = x;
	obstacle->y = y;
	ObstacleList[obstacle->GetType()].push_back(obstacle);
}

int CObject::Move(CPlayer* player)
{
	for (int i = 0; i < OBJ_MAX; ++i)
	{
		for (list<CObstacle*>::iterator iter = ObstacleList[i].begin(); iter != ObstacleList[i].end();)
		{
			(*iter)->Move();

				//충돌했을 때 조건
			if ((*iter)->GetX() < player->player_x + player->width &&//왼쪽
				(*iter)->GetX() + (*iter)->GetWidth() > player->player_x &&//오른쪽
				(*iter)->y + (*iter)->GetHeight() > player->player_y &&//아래
					(*iter)->y < player->player_y + player->height)//위
				{
					cout << " -♥";	
					return 1;
				}			
			

			//화면을 벗어나면 리스트의 객체를 지운다
			if ((*iter)->y + (*iter)->GetHeight() >= SCREEN_Y && (*iter)->GetX() + (*iter)->GetWidth() >= SCREEN_X-1)
			{
				iter = ObstacleList[(*iter)->GetType()].erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
	return 0;
}

void CObject::Scroll()
{
	for (int i = 0; i < OBJ_MAX; ++i)
	{
		for (list<CObstacle*>::iterator iter = ObstacleList[i].begin(); iter != ObstacleList[i].end(); ++iter)
		{
			//화면 밖으로 장애물들이 나가지 않도록 함.
			if ((*iter)->y + (*iter)->GetHeight() < SCREEN_Y)
			{
				(*iter)->Init((*iter)->y += 3);
			}
		}
	}
}
