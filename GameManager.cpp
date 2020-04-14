#include "GameManager.hpp"
#include "Board.hpp"
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

GameManager::GameManager():Board(){
	_isDone = false;};

void GameManager::startGame(){
	clearPlayer();
	setBoardSize();
	playerInput();
	setWinlen();
	playGame();
	
}


void GameManager::playGame(){
	
	_isDone = false;
	int x, y;
	map<string, char> players = getPlayers();
	map<string, char>::iterator end = players.end();
	end--;
	_current = players.begin();
	
	while(!_isDone){
		printBoard();
		cout<<"Player "<<_current->first<<"'s turn"<<endl;
		x = getXCoord();
		y = getYCoord();
		
		if(!placeCurrent(x-1, y-1, _current)){
			cout<<"That spot is occupied!\n";
		}else{
			if(checkForVictory()){
				cout<<"\nPlayer "<<_current->first<<" won"<<endl;
				printBoard();
				return;
			}
			else if(_current == end)
				_current = players.begin();
			else
				_current++;
		}
	}
	
}

void GameManager::setWinlen(){
	bool badInput = true;
	int winLen;
	
	while(badInput){
		if(_n > 3)
			cout<<"Enter required # of similar symbols required to win. (Enter a number between 3 and "<<_n<<"):"<<endl;
		else{
			_winLen = 3;
			return;
		}
		
		cin>>winLen;
		if(winLen < _n)
			badInput = false;
		
		
	}
	_winLen = winLen;
}


int GameManager::getXCoord(){
	int x;
	bool badInput = true;
	while(badInput){
		cout<<"Enter the row you want to place your symbol in: ";
		cin>>x;
		if(x > _n&& x<1){
			cout<<"Enter a valid input"<<endl;
		}else{
			badInput = false;
		}
	}
	return x;
}

int GameManager::getYCoord(){
	int y;
	bool badInput = true;
	while(badInput){
		cout<<"Enter the column you want to place your symbol in: ";
		cin>>y;
	
		if(y > _n || y<1){
			cout<<"Enter a valid input"<<endl;
		}else{
			
			badInput = false;
		}
	}
	return y;;
}

bool GameManager::placeCurrent(int x, int y, map<string,char>::iterator itr){
	if(_board[x][y] != ' ')
		return false;
	_board[x][y] = itr->second;
	
	return true;
}


bool GameManager::checkForVictory(){
		if(checkRows())
			return true;
		else if(checkCols())
			return true;
		else if(checkDiagonals()){
			cout<<34<<endl;
			return true;
			
		}
		return false;
}

bool GameManager::checkRows(){
	
	for(int i = 0; i < _n; i++){
			for(int j = 0; j < _n-(_winLen -1); j++){
				char rep = _board[i][j];
				int count = 0;
				for(int k = 1; k < _winLen; k++){
					if(_board[i][j+k] != rep || _board[i][j+k] ==' ' )
						break;
					else
						count++;
				}
				if(count == _winLen-1){
					
					return true;
					
				}
			}
	}
	return false;
}


bool GameManager::checkCols(){
	for(int i = 0; i < _n-(_winLen-1); i++){
		for(int j = 0; j < _n; j++){
			char rep = _board[i][j];
			int count = 0;
			for(int k = 1; k < _n; k++){
				if(_board[i+k][j] != rep || _board[i+k][j] ==' ' )
					break;
				else
					count++;
			}
			if(count == _winLen-1)
				return true;
		}
	}
	return false;
}


bool GameManager::checkDiagonals(){
	for(int i = 0; i < _n-(_winLen-1); i++){
		for(int j = 0; j < _n-(_winLen-1); j++){
			char rep = _board[i][j];
			int count = 0;
			for(int k = 1; k < _winLen; k++){
				if(_board[i+k][j+k] != rep || _board[i+k][j+k] ==' ' )
					break;
				else
					count++;
			}
			if(count == _winLen-1)
				return true;
		}
	}
	
	for(int i = (_winLen-1); i < _n; i++){
		for(int j = 0; j < _n-(_winLen-1); j++){
			char rep = _board[i][j];
			int count = 0;
			for(int k = 1; k < _winLen; k++){
				if(_board[i-k][j+k] != rep || _board[i-k][j+k] ==' ' )
					break;
				else
					count++;
			}
			if(count == _winLen-1)
				return true;
		}
	}
	for(int i = 0; i < _n-(_winLen-1); i++){
		for(int j = (_winLen-1); j < _n; j++){
			char rep = _board[i][j];
			int count = 0;
			for(int k = 1; k < _winLen; k++){
				if(_board[i+k][j-k] != rep || _board[i+k][j-k] ==' ' )
					break;
				else
					count++;
			}
			if(count == _winLen-1)
				return true;
		}
	}
	return false;
}

