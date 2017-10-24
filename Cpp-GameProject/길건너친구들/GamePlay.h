#pragma once
#include "GameSetting.h"

class CObject;
class CPlayer;
class CGamePlay
{
public:
	CObject* obj; 
	CPlayer* player;
	clock_t runTime;       //���α׷� ����ð�
	clock_t pressTime = 0; //Ű�� ������ �� �ð�
	int timer;             //Ÿ�̸�
	int scrollTime = 7;    //��ũ���ϴ� �ð�
	int score = 0;         //����
	int topScore = 0;      //�ְ�����
	int coin = 0;          //����
	int random;          //��ֹ��� ������    
	int unbeatableTime = 0;//�������½ð�

public:
	int PlayingGame();                               //���� ����ȭ��
	int ScoreBoard(CPlayer* player);                 //������(����, ����, �ð�, ����)
	void CreateObstacle(CObject* obj, int random);   //��ֹ� ���� ����
	void SetFile();                                  //���Ͽ� �� ����
	void GetFile();                                  //���Ͽ��� �� ��������

public:
	CGamePlay();
	~CGamePlay();
};
