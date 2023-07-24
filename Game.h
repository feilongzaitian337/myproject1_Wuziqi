#pragma once
//��Ϸ�ฺ��������Ϸ������
#include<iostream>
#include<string>
#include"Displayer.h"
#include"Player.h"
#include"Human.h"
#include"AI.h"
#include"Judge.h"

class Game {
public:
	Game();
	void ChooseMode(); 
	void InitPlayer(); 
	void ChooseOrder(); 
	void InitGame(); 
	void StartGame(); //��ʼ��Ϸ

private:
	Human human1;
	Human human2; 
	AI ai; 
	Player *player1, *player2;
	Player *current_player; 
	Player *first_player; 
	Judge judge; 
	ChessBoard board;
	Displayer displayer; 
	int mode; //ѡ����Ϸģʽ������/�˻�

};

