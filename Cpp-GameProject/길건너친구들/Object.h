#pragma once
#include "GameSetting.h"

class CObstacle;
class CPlayer;
class CObject
{
public:
	list<CObstacle*> ObstacleList[OBJ_MAX]; // ��ֹ����� ��� �ִ� list
	void AddObject(CObstacle* obstacle, int x, int y); //list�� ��ֹ���ü�� �߰�
	void Move(CPlayer* player); //��ֹ����� �����̰�, �÷��̾���� �浹�� üũ�ϰ�, ȭ���� ����� ��ü�� ����,
	void Scroll(); //��ֹ��� �÷��̾ ��ũ����.

public:
	CObject();
	~CObject();
};