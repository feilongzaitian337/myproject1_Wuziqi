#pragma once
//�������ӣ����Ӱ�����ɫ��λ��
#include<stack>

struct Position {
	int row;
	int col; 
};

class Chess {
public:
	Chess() {
		this->color = 0;//���캯������������
	}

	int getColor() {//��Ա����
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

	//�����ӵ�λ�ú���ɫ���Խ��и�ֵ
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
