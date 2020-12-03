Block blockArray[4];

int main( int argumentCount, char * argumentVector[] )
{
	LOOP:do {
		int keyScan = 0;
		while(keyScan < 9) {
			if (getch() == '\033') { //if the first value is esc
				getch(); //skip the [
				switch(getch()) {
					case 'B': moveBlock('D'); break; //code for arrow down
					case 'C': moveBlock('R'); break; //code for arrow right
					case 'D': moveBlock('L'); break; //code for arrow left
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
