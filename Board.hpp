#pragma once

class Board
{
protected:
	
	Board();
	void setBoardSize();
	void printBoard();
	void clearBoard();
	void createBoard();
	int _n;
	char **_board;
};

