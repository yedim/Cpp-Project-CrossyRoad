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
	int topScore = score;  //�ְ�����
	int coin = 0;          //����
	int random;           //��ֹ��� ������    
	int unbeatableTime = 0;//�������½ð�
	int fcoin;
	int fscore;
	int hp;

public:
	int PlayingGame(int h);                               //���� ����ȭ��
	int ScoreBoard(CPlayer* player);                 //������(����, ����, �ð�, ����)
	void CreateObstacle(CObject* obj, int random);   //��ֹ� ���� ����
	void SetScoreFile(int score);                    //���Ͽ� �����Է�(����)
	void SetCoinFile(int score);                     //���Ͽ� �����Է�(����)
	void GetScoreFile();                             //���Ͽ��� �������(�б�)
	void GetCoinFile();                              //���Ͽ��� �������(�б�)
	void ResetFile();

public:
	CGamePlay();
	~CGamePlay();
};
