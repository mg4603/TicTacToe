#include <iostream>
#include "Board.hpp"
#include "GameManager.hpp"

using namespace std;

int main(){
	
	
	cout<<"			TicTacToe		"<<endl;
	GameManager gm;
	bool end = false;
	char choice;
	while(!end){
		
		gm.startGame();
		
		cout<<"Do you want to play another game? (Y/N)"<<endl;
		cin>>choice;
		bool badInput = true;
		while(badInput){
			if(tolower(choice) == 'n'){
				end = true;
				badInput = false;
			}
			else if(tolower(choice) == 'y'){
				cout<<choice<<endl;
				end = false;
				badInput = false;
			}
			else{
				cout<<"Enter a valid input\n";
				cin>>choice;
			}
		}
	}
	
	
	
	return 0;
}