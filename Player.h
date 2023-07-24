#pragma once
// �������֣���Ҫ��������������ִ���ӵ���ɫ�����������Ȼ����Ϊ����������Human���AI��
#include<iostream>
#include<string>
#include"Chess.h"
#include"ChessBoard.h"
using namespace std;

class Player {
public:
	Player();
	virtual Chess GiveChess(ChessBoard board) = 0;  // ����Ϊ���麯����������

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

