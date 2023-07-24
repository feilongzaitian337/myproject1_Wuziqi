#pragma once
//定义棋盘以及其大小，每个位置的状态，添棋子和删棋子,提供AI获取最好棋子操作
#include"Chess.h"
#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class ChessBoard {
public:
	ChessBoard();
	void Board_Init();
	vector<vector<int> > getBoardState() const;
	void addChess1(Chess chess); // 下白棋函数
	void addChess2(Chess chess); // 下黑棋 为了使棋子颜色不一样，分别调用两个函数
	void takebackChess(int num); 
	Chess getLastChess(); 
	Chess getLast2Chess();
	string getChessSymbol(int color);
	string getBoardSymbol(Position p);
	Position getbestchess(ChessBoard board);
	void initvalue(ChessBoard board);
	int M2(ChessBoard board , Position p); //进攻赋分函数 眠二
	int FM2(ChessBoard board, Position p);  //防守赋分函数 避免眠二
	int FM3(ChessBoard board, Position p);
	int M4(ChessBoard board, Position p);
	int M3(ChessBoard board, Position p);
	
	int getChessNum() {
		return history.size();//根据栈内元素确定棋子个数
	}

	bool BoardEmpty() {
		return history.empty();//确定栈内是否有元素，有则为true
	}

	int getChessState(Position p) {
		int b = board_state[p.row][p.col];
		if (b > 2)
			return b - 2;
		else
			return b;
	}

	int getROWNUM() {
		return ROWNUM; //获取行数
	}

	int getCOLUMN() {
		return COLUMN; //获取列数
	}

	int getboard_state_value(Position p) {
		//cout << p.row <<": "<<p.col<< endl;
		int b = board_state_value[p.row][p.col];
		return b; //获取Value值
	}

private:
	stack<Chess> history;
	stack<Chess> history1;
	vector<vector<int> > board_state;
	vector<vector<int> > board_state_value;
	static const int ROWNUM = 16;//棋盘行数
	static const int COLUMN = 16;//棋盘列数
	Chess last_chess;
	const string chess_symbol[5] = { " ","●","○","▲","△" }; //
	const vector<string> board_symbol = //一个符号占三个字节
	{ "┏ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┓ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
	  "┗ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┛ " };
};
