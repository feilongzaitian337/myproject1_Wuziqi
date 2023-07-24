#pragma once
//游戏类负责整个游戏的流程
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
	void StartGame(); //开始游戏

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
	int mode; //选择游戏模式：人人/人机

};

