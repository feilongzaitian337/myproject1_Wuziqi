#include "Displayer.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

void Displayer::showBoard(ChessBoard board) {
	vector<vector<int> >state = board.getBoardState();
	cout << "  a b c d e f g h i j k l m n o p" << endl;
	for (int i = 0; i < state.size(); i++) {
		cout << char('a' + i);
		for (int j = 0; j < state[0].size(); j++) {
			cout << board.getBoardSymbol({ i,j });
		}
		cout << endl;
	}
}

void Displayer::showMessage(string msg) {
	cout<<msg<<endl;
}