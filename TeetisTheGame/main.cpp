#include <stdio.h>
#include <unistd.h>
#include <curses.h>
//#include <conio.h>
#include "game.h"

int main( int argumentCount, char * argumentVector[] )
{
	Game* teetisGame = new Game();
	
	while(true){
		int keyScan = 0;
		while(keyScan < 9) {
			if (getch() == '\033') { //if the first value is esc
				getch(); //skip the [
				switch(getch()) {
					case 'B': teetisGame->moveBlock('D'); break; //code for arrow down
					case 'C': teetisGame->moveBlock('R'); break; //code for arrow right
					case 'D': teetisGame->moveBlock('L'); break; //code for arrow left
				}
			}
			keyScan++;
			usleep(50000);
		}
		teetisGame->dropBlock();
		keyScan = 0;
	}
}

//Maybe savefiles
