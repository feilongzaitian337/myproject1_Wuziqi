#pragma once
//定义棋子，棋子包含颜色和位置
#include<stack>

struct Position {
	int row;
	int col; 
};

class Chess {
public:
	Chess() {
		this->color = 0;//构造函数、析构函数
	}

	int getColor() {//成员函数
		return color;
	}

	Position getPosition() {
		Position p;
		p.row = this->row;
		p.col = this->col;
		return p;
	}

	Chess position(Position p) {
		Chess chess;
		chess.row = p.row;
		chess.col = p.col;
		return chess;
	}

	//给棋子的位置和颜色属性进行赋值
	Chess fuzhiChess(int color, Position p) {
		Chess chess;
		chess.color = color;
		chess.row = p.row;
		chess.col = p.col;
		return chess;
	}

private:
	int row, col;
	int color;
};
