#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board()
{
}


void Board::setBoardSize(){
	cout<<"Enter the width of the board (between 3 and 10 both inclusive): \n";
	int n;
	bool badInput = true;
	while(badInput){
		cin>>n;
		if(n <3 || n > 10)
			cout<<"Invalid Input\n";
		else
			badInput = false;
	}
	_n = n;
	createBoard();
}

void Board::printBoard(){
	cout<<"  ";
	for(int i = 0; i < _n; i++){
		cout<<" | "<< i+1;
	}
	cout<<" |"<<endl;
	cout<<"--";
	for(int j = 0; j < _n; j++){
			cout<<"----";
		}
	cout<<"--"<<endl;
	for(int i = 0; i < _n; i++){
		cout<< i+1<<" ";
		for(int j = 0; j < _n; j++){
			cout<<" | "<<_board[i][j];
		}
		cout<<" |"<<endl<<"--";
		for(int j = 0; j < _n; j++){
			cout<<"----";
		}
		cout<<"--"<<endl;
	}
	cout<<endl;
}


void Board::clearBoard(){
	for(int i = 0; i < _n; i++){
		for(int j = 0; j < _n; j++){
			_board[i][j] = ' ';
		}
	}
}


void Board::createBoard(){
	_board = new char*[_n];
	for(int i = 0; i < _n; i++){
		_board[i] = new char[_n];
	}
	clearBoard();
}