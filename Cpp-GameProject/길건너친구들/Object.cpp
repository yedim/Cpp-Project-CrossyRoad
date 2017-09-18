#include "Object.h"
#include "Obstacle.h"
#include "Player.h"

CObject::CObject()
{

}
CObject::~CObject()
{

}

void CObject::AddObject(CObstacle* obstacle, int x, int y)
{
	obstacle->Init(x, y);
	obstacle->x = x;
	obstacle->y = y;
	ObstacleList[obstacle->GetType()].push_back(obstacle);
}

void CObject::Move(CPlayer* player)
{
	for (int i = 0; i < OBJ_MAX; ++i)
	{
		for (list<CObstacle*>::iterator iter = ObstacleList[i].begin(); iter != ObstacleList[i].end();)
		{
			(*iter)->Move();

			//�浹���� �� ����
			if ((*iter)->GetX() < player->player_x + player->width &&//����
				(*iter)->GetX() + (*iter)->GetWidth() > player->player_x &&//������
				(*iter)->y + (*iter)->GetHeight() > player->player_y &&//�Ʒ�
				(*iter)->y < player->player_y + player->height)//��
			{
				cout << "�浹!!!";
			}

			//ȭ���� ����� ����Ʈ�� ��ü�� �����
			if ((*iter)->y + (*iter)->GetHeight() >= SCREEN_Y && (*iter)->GetX() + (*iter)->GetWidth() >= SCREEN_X - 1)
			{
				//delete (*iter);
				//(*iter) = NULL;
				iter = ObstacleList[(*iter)->GetType()].erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}

void CObject::Scroll()
{
	for (int i = 0; i < OBJ_MAX; ++i)
	{
		for (list<CObstacle*>::iterator iter = ObstacleList[i].begin(); iter != ObstacleList[i].end(); ++iter)
		{
			//ȭ�� ������ �ڵ����� ������ �ʵ��� ��.
			if ((*iter)->y + (*iter)->GetHeight() < SCREEN_Y)
			{
				(*iter)->Init((*iter)->y += 3);
			}
		}
	}
}
