#include "Player.hpp"
#include <map>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


Player::Player()
{
	
}


void Player::addPlayer(string name, char rep){
	_players.insert(pair<string, char>(name,rep));

}


map<string, char> Player::getPlayers(){
	return _players;
}


void Player::clearPlayer(){
	_players.clear();
}

void Player::playerInput(){
	string name;
	char rep;
	bool addAnother = true;
	char choice;
	while(addAnother){
		cout<<"Player "<<_players.size()+1<<" name:"<<endl;
		cin>>name;
		cout<<"Player "<<_players.size() + 1 <<" symbol:"<<endl;
		cin>>rep;
		
		addPlayer(name, rep);
		cout<<"Add another player? (Y/N)";
		cin>>choice;
		bool badInput = true;
		while(badInput){
			if(tolower(choice) == 'n'){
				addAnother = false;
				badInput = false;
			}
			else if(tolower(choice) == 'y'){
				addAnother = true;
				badInput = false;
			}
			else
			{	cout<<"Enter a valid input\n";
				cin>>choice;
			}	
		}
	}
}