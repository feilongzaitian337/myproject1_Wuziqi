#pragma once
//负责所有的显示任务
#include"ChessBoard.h"
class Displayer {
public:
	void showBoard(ChessBoard board);
	void showMessage(string msg);
};

