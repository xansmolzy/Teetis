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
	//initscr();
	while(true){
		int keyScan = 0;
		/*while(keyScan < 9) {
			//if (getch() == '\033') { //if the first value is esc
				getch(); //skip the [
				switch(getch()) {
					case 'B': teetisGame->moveBlock('D'); break; //code for arrow down
					case 'C': teetisGame->moveBlock('R'); break; //code for arrow right
					case 'D': teetisGame->moveBlock('L'); break; //code for arrow left
				}
			}
			keyScan++;
			usleep(50000);
		}*/
		teetisGame->dropBlock();
		keyScan = 0;
		cout << "meep";
	}
}

//Maybe savefiles
