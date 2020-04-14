#ifndef Board_HPP_INCLUDED
#ifndef Player_HPP_INCLUDED
#define Player_HPP_INCLUDED
#define Board_HPP_INCLUDED
#include "Board.hpp"
#include "Player.hpp"
#include <string>
#include <unordered_map>
#include <iterator>
#pragma once

class GameManager: public Board, public Player
{
public:
	GameManager(int n);
	GameManager();
	void startGame();
	void playGame();
	

protected:
	void setWinlen();
	int getXCoord();
	int getYCoord();
	bool placeCurrent(int x, int y, map<string, char>::iterator _current);
	bool checkForVictory();
	bool checkRows();
	bool checkCols();
	bool checkDiagonals();

private:
	bool _isDone;
	map<string, char>::iterator _current;
	int _winLen;

	
};

#endif
#endif