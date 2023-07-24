#pragma once
// 裁判类：判断棋子是否合法，是否有人获胜、执行悔棋，是否禁手操作
#include"Chess.h"
#include"ChessBoard.h"
class Judge {
public:
	bool CheckChessLegal(Chess chess, ChessBoard &board); // 判断棋子是否合法
	bool CheckWin(ChessBoard &board); 
	void TakeBack(ChessBoard &board); 
};

