#pragma once
#include "Player.h"
#include<random>
#include <cstdlib> 
#include <ctime>
#include"ChessBoard.h"

class AI :
	public Player {
public:
	Chess GiveChess(ChessBoard board) {
		Chess chess;
		if (board.BoardEmpty() == 1) {
			chess = chess.position({ 7,7}); }
		else {
			Position p;
			p = board.getbestchess(board);
			chess = chess.position({ p.row,p.col });
		}
		return chess;
	}
};

