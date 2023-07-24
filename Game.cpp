#include "Game.h"

Game::Game() {
	mode = 0;
	current_player = NULL;
	board.Board_Init(); // 初始化棋盘
}

void Game::ChooseMode() {
	do {
		system("cls");
		displayer.showBoard(board);
		displayer.showMessage("选择模式(人机模式输入\"1\",双人对战模式输入\"2\"):");
		cin >> mode;
	} while (!(mode == 1 || mode == 2));
}

void Game::InitPlayer() {
	string s;
	if ( mode == 2 ) {
		player1 = &human1;
		player2 = &human2;
		displayer.showMessage("输入玩家一名字：");
		cin >> s;
		player1->setName(s);
		displayer.showMessage("输入玩家二名字：");
		cin >> s;
		player2->setName(s);
	}
	else if ( mode == 1 ) {
		player1 = &human1;
		player2 = &ai;
		displayer.showMessage("输入玩家名字：");
		cin >> s;
		player1->setName(s);
		player2->setName("电脑");
	}
}

void Game::ChooseOrder() {
	int first = 0;
	do {
		displayer.showMessage("选择先手 (" + player1->getName() + "先手输入\"1\"，" + player2->getName() + "先手输入\"2\")：");
		cin >> first;
	} while (!(first == 1 || first == 2));
	if (first == 1) {
		current_player = player1;
		first_player = player1;
	}
	else {
		current_player = player2;
		first_player = player2;
	}
}

void Game::InitGame() {
	ChooseMode();
	InitPlayer();
	ChooseOrder();
}

void Game::StartGame() {
	Chess chess;
	bool TakeBack = false;
	string input_msg;
	bool win = false;
	bool restart = false;
	system("cls");
	displayer.showBoard(board);

	while (true) {
		//原有玩家是否开设新局
		if (restart) {
			system("cls");
			ChooseOrder();//选择先手
			TakeBack = false;
			input_msg = "";
			win = false;
			restart = false;
			board.Board_Init();
			displayer.showBoard(board);
		}
		// 申请悔棋
		if (TakeBack && board.getChessNum() >= 2) {
			system("cls");
			displayer.showBoard(board);
			if (mode == 2) {
				displayer.showMessage(current_player->getName()+"是否悔棋? y/n :");
				cin >> input_msg;
				if (input_msg == "y") {
					string input_msg1;
					displayer.showMessage(" 是否同意悔棋? y/n :");
					cin >> input_msg1;
					//对方同意悔棋
					if (input_msg1 == "y") {
						judge.TakeBack(board);
						TakeBack = false;
						system("cls");
						displayer.showBoard(board);
						system("cls");
						displayer.showBoard(board);
						if (current_player->getName() == player1->getName())
							current_player = player2;
						else
							current_player = player1;
					}
				}
			}
			if (mode == 1 && typeid(*current_player).name() == typeid(AI).name()) {
					displayer.showMessage("是否悔棋? y/n :");
					cin >> input_msg;
					if (input_msg == "y") {
						judge.TakeBack(board);
						TakeBack = false;
						system("cls");
						displayer.showBoard(board);
						system("cls");
						displayer.showBoard(board);
						if (current_player->getName() == player1->getName())
							current_player = player2;
						else
							current_player = player1;
					}
			}
		}
		system("cls");
		displayer.showBoard(board);
		//当前玩家落子
		displayer.showMessage("到"+current_player->getName() + "了");
		displayer.showMessage("请输入棋子的位置:");
		//判断棋子合法
		bool chess_legal = true;
		while (chess_legal) {
			chess = current_player->GiveChess(board);
			chess_legal = judge.CheckChessLegal(chess, board);
			if (chess_legal) {//输入合法，刷新棋盘
				if (current_player == player1) {
					board.addChess1(chess);
				}
				else {
					board.addChess2(chess);
				}
				system("cls");
				displayer.showBoard(board);
				break;
			}
			else {//输入非法，重新输入
				system("cls");
				displayer.showBoard(board);
				displayer.showMessage("到" + current_player->getName() + "了");
				displayer.showMessage("不合法输入，请重新输入:");
				chess_legal = true;
			}
		}
		TakeBack = true;
		win = judge.CheckWin(board);
		if (win) {
			displayer.showMessage(current_player->getName() + " 赢了!");
			displayer.showMessage("是否重新开始游戏? y/n:");
			do {
				cin >> input_msg;
			} while (!(input_msg == "y" || input_msg == "n"));
			if (input_msg == "y") {
				restart = true;
				continue;
			}
			else if (input_msg == "n") {
				restart = false;
				break;
			}

		}
		//切换当前棋手
		if (current_player->getName() == player1->getName())
			current_player = player2;
		else
			current_player = player1;
	}
}
