
#include <map>
#include <string>

#pragma once
using namespace std;
class Player
{
protected:
	Player();
	void addPlayer(string name, char rep);
	void playerInput();
	map<string, char> getPlayers();
	void clearPlayer();

private:
	map<string, char> _players;
	
};

