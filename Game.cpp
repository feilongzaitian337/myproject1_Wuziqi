#include "Game.h"

Game::Game() {
	mode = 0;
	current_player = NULL;
	board.Board_Init(); // ��ʼ������
}

void Game::ChooseMode() {
	do {
		system("cls");
		displayer.showBoard(board);
		displayer.showMessage("ѡ��ģʽ(�˻�ģʽ����\"1\",˫�˶�սģʽ����\"2\"):");
		cin >> mode;
	} while (!(mode == 1 || mode == 2));
}

void Game::InitPlayer() {
	string s;
	if ( mode == 2 ) {
		player1 = &human1;
		player2 = &human2;
		displayer.showMessage("�������һ���֣�");
		cin >> s;
		player1->setName(s);
		displayer.showMessage("������Ҷ����֣�");
		cin >> s;
		player2->setName(s);
	}
	else if ( mode == 1 ) {
		player1 = &human1;
		player2 = &ai;
		displayer.showMessage("����������֣�");
		cin >> s;
		player1->setName(s);
		player2->setName("����");
	}
}

void Game::ChooseOrder() {
	int first = 0;
	do {
		displayer.showMessage("ѡ������ (" + player1->getName() + "��������\"1\"��" + player2->getName() + "��������\"2\")��");
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
		//ԭ������Ƿ����¾�
		if (restart) {
			system("cls");
			ChooseOrder();//ѡ������
			TakeBack = false;
			input_msg = "";
			win = false;
			restart = false;
			board.Board_Init();
			displayer.showBoard(board);
		}
		// �������
		if (TakeBack && board.getChessNum() >= 2) {
			system("cls");
			displayer.showBoard(board);
			if (mode == 2) {
				displayer.showMessage(current_player->getName()+"�Ƿ����? y/n :");
				cin >> input_msg;
				if (input_msg == "y") {
					string input_msg1;
					displayer.showMessage(" �Ƿ�ͬ�����? y/n :");
					cin >> input_msg1;
					//�Է�ͬ�����
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
					displayer.showMessage("�Ƿ����? y/n :");
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
		//��ǰ�������
		displayer.showMessage("��"+current_player->getName() + "��");
		displayer.showMessage("���������ӵ�λ��:");
		//�ж����ӺϷ�
		bool chess_legal = true;
		while (chess_legal) {
			chess = current_player->GiveChess(board);
			chess_legal = judge.CheckChessLegal(chess, board);
			if (chess_legal) {//����Ϸ���ˢ������
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
			else {//����Ƿ�����������
				system("cls");
				displayer.showBoard(board);
				displayer.showMessage("��" + current_player->getName() + "��");
				displayer.showMessage("���Ϸ����룬����������:");
				chess_legal = true;
			}
		}
		TakeBack = true;
		win = judge.CheckWin(board);
		if (win) {
			displayer.showMessage(current_player->getName() + " Ӯ��!");
			displayer.showMessage("�Ƿ����¿�ʼ��Ϸ? y/n:");
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
		//�л���ǰ����
		if (current_player->getName() == player1->getName())
			current_player = player2;
		else
			current_player = player1;
	}
}
