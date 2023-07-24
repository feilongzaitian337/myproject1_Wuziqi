#pragma once
// 定义棋手，主要包括棋手姓名、执棋子的颜色、下棋操作，然后作为基类派生出Human类和AI类
#include<iostream>
#include<string>
#include"Chess.h"
#include"ChessBoard.h"
using namespace std;

class Player {
public:
	Player();
	virtual Chess GiveChess(ChessBoard board) = 0;  // 定义为纯虚函数，抽象类

	string getName() {
		return name;
	}

	int getColor() {
		return color; 
	}

	void setName(string name) {
		this->name = name; 
	}

	void setColor(int color) {
		this->color = color;
	}

private:
	string name;
	int color;
};

