//Block blockArray[4];
#include "game.h"

int main( int argumentCount, char * argumentVector[] )
{
	Game* teetisGame = new Game();
	LOOP:do {
		int keyScan = 0;
		while(keyScan < 9) {
			if (getch() == '\033') { //if the first value is esc
				getch(); //skip the [
				switch(getch()) {
					case 'B': teetisGame.moveBlock('D'); break; //code for arrow down
					case 'C': teetisGame.moveBlock('R'); break; //code for arrow right
					case 'D': teetisGame.moveBlock('L'); break; //code for arrow left
				}
			}
			keyScan++;
			delay(50);
		}
		dropBlock();
		keyScan = 0;
	}
	goto LOOP;
}

//Maybe savefiles
