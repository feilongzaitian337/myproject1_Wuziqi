#pragma once
// �����ࣺ�ж������Ƿ�Ϸ����Ƿ����˻�ʤ��ִ�л��壬�Ƿ���ֲ���
#include"Chess.h"
#include"ChessBoard.h"
class Judge {
public:
	bool CheckChessLegal(Chess chess, ChessBoard &board); // �ж������Ƿ�Ϸ�
	bool CheckWin(ChessBoard &board); 
	void TakeBack(ChessBoard &board); 
};

