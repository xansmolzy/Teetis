#include <stdio.h>	//enable printing, obsolete by ncurses
#include <string> 	//enable printing, obsolete by ncurses
#include <iostream>
#include <time.h>
#include <unistd.h> //allow usleep to work
#include <ncurses.h>//keyboard input, use "-lcurses" when compiling
#include "block.h"
#include "game.h"
using namespace std;

int main()
{
	timeout(100);
	//Start up a fresh copy of the game
	Game* teetisGame = new Game();
	int ch = 0;
	int counter = 0;
	while(true){
		while(counter < 100) {
			ch = getch();
			if (ch > 0) { //if the first value is esc
				switch(ch) {
					case KEY_DOWN:  teetisGame->dropBlock(); teetisGame->printField(); break; //code for arrow down
					case KEY_RIGHT: teetisGame->moveBlock('R'); teetisGame->printField(); break; //code for arrow right
					case KEY_LEFT:  teetisGame->moveBlock('L'); teetisGame->printField(); break; //code for arrow left
					case ' ': teetisGame->rotateBlock('R'); teetisGame->printField(); break; //code for arrow left
					default: break;
				}
			}
			usleep(10000);
			counter++;
		}
		teetisGame->dropBlock();
		teetisGame->printField();
		counter = 0;
	}
}

//Maybe savefiles
