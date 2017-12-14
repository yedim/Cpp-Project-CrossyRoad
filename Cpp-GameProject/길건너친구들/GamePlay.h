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
	int topScore = score;  //최고점수
	int coin = 0;          //코인
	int random;           //장애물의 랜덤값    
	int unbeatableTime = 0;//무적상태시간
	int fcoin;
	int fscore;
	int hp;

public:
	int PlayingGame(int h);                               //게임 실행화면
	int ScoreBoard(CPlayer* player);                 //점수판(점수, 코인, 시간, 생명)
	void CreateObstacle(CObject* obj, int random);   //장애물 랜덤 생성
	void SetScoreFile(int score);                    //파일에 점수입력(쓰기)
	void SetCoinFile(int score);                     //파일에 코인입력(쓰기)
	void GetScoreFile();                             //파일에서 점수출력(읽기)
	void GetCoinFile();                              //파일에서 코인출력(읽기)
	void ResetFile();

public:
	CGamePlay();
	~CGamePlay();
};
