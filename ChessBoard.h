#pragma once
//���������Լ����С��ÿ��λ�õ�״̬�������Ӻ�ɾ����,�ṩAI��ȡ������Ӳ���
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
	void addChess1(Chess chess); // �°��庯��
	void addChess2(Chess chess); // �º��� Ϊ��ʹ������ɫ��һ�����ֱ������������
	void takebackChess(int num); 
	Chess getLastChess(); 
	Chess getLast2Chess();
	string getChessSymbol(int color);
	string getBoardSymbol(Position p);
	Position getbestchess(ChessBoard board);
	void initvalue(ChessBoard board);
	int M2(ChessBoard board , Position p); //�������ֺ��� �߶�
	int FM2(ChessBoard board, Position p);  //���ظ��ֺ��� �����߶�
	int FM3(ChessBoard board, Position p);
	int M4(ChessBoard board, Position p);
	int M3(ChessBoard board, Position p);
	
	int getChessNum() {
		return history.size();//����ջ��Ԫ��ȷ�����Ӹ���
	}

	bool BoardEmpty() {
		return history.empty();//ȷ��ջ���Ƿ���Ԫ�أ�����Ϊtrue
	}

	int getChessState(Position p) {
		int b = board_state[p.row][p.col];
		if (b > 2)
			return b - 2;
		else
			return b;
	}

	int getROWNUM() {
		return ROWNUM; //��ȡ����
	}

	int getCOLUMN() {
		return COLUMN; //��ȡ����
	}

	int getboard_state_value(Position p) {
		//cout << p.row <<": "<<p.col<< endl;
		int b = board_state_value[p.row][p.col];
		return b; //��ȡValueֵ
	}

private:
	stack<Chess> history;
	stack<Chess> history1;
	vector<vector<int> > board_state;
	vector<vector<int> > board_state_value;
	static const int ROWNUM = 16;//��������
	static const int COLUMN = 16;//��������
	Chess last_chess;
	const string chess_symbol[5] = { " ","��","��","��","��" }; //
	const vector<string> board_symbol = //һ������ռ�����ֽ�
	{ "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ",
	  "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� " };
};
