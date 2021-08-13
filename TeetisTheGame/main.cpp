#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
//#include <conio.h>
#include "game.h"
using namespace std;

int main( int argumentCount, char * argumentVector[] )
{
	Game* teetisGame = new Game();
	teetisGame->printInit();
	while(true){
		int keyScan = 0;
		while(keyScan < 9) {
		 	char ch = '';
			if (ch = getch() != '#') { //if the first value is esc
				switch(ch) {
					case KEY_DOWN:  teetisGame->moveBlock('D'); break; //code for arrow down
					case KEY_RIGHT: teetisGame->moveBlock('R'); break; //code for arrow right
					case KEY_LEFT:  teetisGame->moveBlock('L'); break; //code for arrow left
				}
			}
			keyScan++;
			usleep(50000);
		}
		teetisGame->dropBlock();
		keyScan = 0;
		cout << "meep";
	}
}

//Maybe savefiles
