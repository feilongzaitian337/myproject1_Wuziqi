#include "ChessBoard.h"
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

ChessBoard::ChessBoard(void) {
	Board_Init();
}

void ChessBoard::Board_Init() {
	while (!history.empty()) history.pop();
	last_chess = *new Chess;
	board_state.resize(ROWNUM);
	for (int k = 0; k < ROWNUM; ++k) {
		board_state[k].resize(COLUMN);
	}
	for (int i = 0; i < ROWNUM; i++)
		for (int j = 0; j < COLUMN; j++)
			board_state[i][j] = 0;
}

vector<vector<int> > ChessBoard::getBoardState() const {
	return board_state;
}

void ChessBoard::addChess1(Chess chess) {
	Position p;
	if (!history.empty()) {
		p = last_chess.getPosition();
		board_state[p.row][p.col] = last_chess.getColor() - 2;
	}
	p = chess.getPosition();
	board_state[p.row][p.col] = chess.getColor() + 3;
	last_chess = chess.fuzhiChess(chess.getColor() + 3, p );
	history.push(last_chess);

}
void ChessBoard::addChess2(Chess chess) {
	Position p;
	if (!history.empty()) {
		p = last_chess.getPosition();
		board_state[p.row][p.col] = last_chess.getColor() - 2;
	}
	p = chess.getPosition();
	board_state[p.row][p.col] = chess.getColor() + 4;
	last_chess = chess.fuzhiChess(chess.getColor() + 4, p);
	history.push(last_chess);
}

void ChessBoard::takebackChess(int num) {
	Position p;
	num = 1;
	int num_chess = history.size();
	Chess chess = history.top();
	p = chess.getPosition();
	board_state[p.row][p.col] = 0;
	history.pop();
	if (!history.empty()) {
		last_chess = history.top();
		p = last_chess.getPosition();
		board_state[p.row][p.col] = last_chess.getColor() - 2;
	}
}

Chess ChessBoard::getLastChess() {
	return history.top();
}

Chess ChessBoard::getLast2Chess() {
	if(history.size()>=2){
	history.pop();}
	return history.top();
}

string ChessBoard::getChessSymbol(int color) {
	return chess_symbol[color];
}

string ChessBoard::getBoardSymbol(Position p) {
	if (board_state[p.row][p.col] == 0) {
		return board_symbol[p.row].substr(p.col * 3, 3);
	}
	else {
		return chess_symbol[board_state[p.row][p.col]];
	}
}

int ChessBoard::M2(ChessBoard board , Position p) {
	Position ptr;
	ptr = p;
	int value = 0;
	if ( board_state[p.row][p.col] != 0 ) return 0;
	else {
		Chess last_chess = board.getLast2Chess();
		++ptr.row;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		++ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.row;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		++ptr.row;
		++ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.row;
		++ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		++ptr.row;
		--ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.row;
		--ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
	}	
return value;
}
int ChessBoard::FM2(ChessBoard board, Position p) {
	Position ptr;
	ptr = p;
	int value = 0;
	if (board_state[p.row][p.col] != 0) return 0;
	else {
		++ptr.row;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		++ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.row;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		++ptr.row;
		++ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.row;
		++ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		++ptr.row;
		--ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }
		--ptr.row;
		--ptr.col;
		if (board.getChessState(ptr) == last_chess.getColor() - 2) { value++; }

	}
	return value;
}

int ChessBoard::FM3(ChessBoard board, Position p) {
	Position ptr;
	ptr = p;
	int value = 0;
	if (board_state[p.row][p.col] != 0) return 0;
	else {
		ptr = p;
		++ptr.col;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
		}
		ptr = p;
		--ptr.col;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
		}
		if (value + 1 >= 4)
			return value*5;

		//Y方向
		value = 0;
		ptr = p;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.row;
		}
		ptr = p;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.row;
		}
		if (value + 1 >= 4)
			return value*5;

		//右斜方向
		value = 0;
		ptr = p;
		++ptr.col;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
			++ptr.row;
		}
		ptr = p;
		--ptr.col;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
			--ptr.row;
		}
		if (value + 1 >= 4)return value*5;

		//左斜方向
		value = 0;
		ptr = p;
		--ptr.col;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
			++ptr.row;
		}
		ptr = p;
		++ptr.col;
		--ptr.row;
		while ( last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
			--ptr.row;
		}
		if (value + 1 >= 4)return value*5;
		return 0;
	}
}

int ChessBoard::M4(ChessBoard board, Position p) {
	Position ptr;
	ptr = p;
	int value = 0;
	if (board_state[p.row][p.col] != 0) return 0;
	else {
		Chess last_chess = board.getLast2Chess();
		ptr = p;
		++ptr.col;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
		}
		ptr = p;
		--ptr.col;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
		}
		if (value + 1 >= 4)
			return value * 3;

		//Y方向
		value = 0;
		ptr = p;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.row;
		}
		ptr = p;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.row;
		}
		if (value + 1 >= 4)
			return value * 3;

		//右斜方向
		value = 0;
		ptr = p;
		++ptr.col;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
			++ptr.row;
		}
		ptr = p;
		--ptr.col;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
			--ptr.row;
		}
		if (value + 1 >= 4)return value * 3;

		//左斜方向
		value = 0;
		ptr = p;
		--ptr.col;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
			++ptr.row;
		}
		ptr = p;
		++ptr.col;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
			--ptr.row;
		}
		if (value + 1 >= 4)return value * 3;
		return 0;
	}
}
int ChessBoard::M3(ChessBoard board, Position p) {
	Position ptr;
	ptr = p;
	int value = 0;
	if (board_state[p.row][p.col] != 0) return 0;
	else {
		Chess last_chess = board.getLast2Chess();
		ptr = p;
		++ptr.col;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
		}
		ptr = p;
		--ptr.col;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
		}
		if (value + 1 >= 3)
			return value *2;

		//Y方向
		value = 0;
		ptr = p;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.row;
		}
		ptr = p;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.row;
		}
		if (value + 1 >= 3)
			return value * 2;

		//右斜方向
		value = 0;
		ptr = p;
		++ptr.col;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
			++ptr.row;
		}
		ptr = p;
		--ptr.col;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
			--ptr.row;
		}
		if (value + 1 >= 3)return value * 2;

		//左斜方向
		value = 0;
		ptr = p;
		--ptr.col;
		++ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			--ptr.col;
			++ptr.row;
		}
		ptr = p;
		++ptr.col;
		--ptr.row;
		while (last_chess.getColor() - 2 == board.getChessState(ptr)) {
			value++;
			++ptr.col;
			--ptr.row;
		}
		if (value + 1 >= 3)return value * 2;
		return 0;
	}
}

void ChessBoard::initvalue(ChessBoard board) {
	board_state_value.resize(16);
	for (int i = 2; i < 13; i++) {
		board_state_value[i].resize(16);
		for (int j = 2; j < 13; j++) {	
			int value = M2(board, { i,j }) + FM2(board, { i,j })+FM3(board, { i,j }) + M3(board, { i,j }) + M4(board, { i,j });
			this->board_state_value[i][j] = value;
		}
	}
}

Position ChessBoard::getbestchess(ChessBoard board) {
	stack<Position> s;
	Position p;
	board.initvalue(board);
	int a = board.getboard_state_value({2,2});
	p = Position{ 2,2 };
	s.push(p);
	for (int i = 2; i <13; i++) {
		for (int j = 2; j < 13; j++) {
			p = s.top();
			if (board.getboard_state_value({ p.row,p.col }) <= board.getboard_state_value({i,j})) {
				/*int b = board.board_state_value[i][j];*/
				p = Position{ i,j };
				s.push(p);
			}
		}
	}
	return s.top();
}

