#pragma once
#include "GameSetting.h"

class CObject;
class CPlayer;
class CGamePlay
{
public:
	CObject* obj; 
	CPlayer* player;
	clock_t runTime;       //프로그램 실행시간
	clock_t pressTime = 0; //키를 눌렀을 때 시간
	int timer;             //타이머
	int scrollTime = 7;    //스크롤하는 시간
	int score = 0;         //점수
	int topScore = 0;      //최고점수
	int coin = 0;          //코인
	int random;          //장애물의 랜덤값    
	int unbeatableTime = 0;//무적상태시간

public:
	int PlayingGame();                               //게임 실행화면
	int ScoreBoard(CPlayer* player);                 //점수판(점수, 코인, 시간, 생명)
	void CreateObstacle(CObject* obj, int random);   //장애물 랜덤 생성
	void SetFile();                                  //파일에 값 저장
	void GetFile();                                  //파일에서 값 가져오기

public:
	CGamePlay();
	~CGamePlay();
};
