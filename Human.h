#pragma once
#include "Player.h"
#include<iostream>
#include<string>
#include"Chess.h"
#include"Player.h"
using namespace std;

class Human :
	public Player {
public:
	Chess GiveChess(ChessBoard board) {
		Chess c;
		string input_msg = "";
		cin >> input_msg;
		if (input_msg.size() == 2) {
			c = c.position({ input_msg[0] - 'a' , input_msg[1] - 'a' });
		}
		return c;
	}
};
