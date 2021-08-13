#include "game.h"

Game::Game(void) {  }

void Game::printField(void) {
	for(char x = 0; x < 10; x++) {
		for(char y = 0; y < 16; y++) {
			gameArray[10][16];
		}
		std::cout << "\n";
	}
}

void Game::dropBlock(void)
{
	blockIndex[1] = blockIndex[1]-1;
}

void Game::moveBlock(const char input) {
	switch(input) {
		case 77: if(blockIndex[0] != 0) { blockIndex[0] = blockIndex[0]-1; } break; //Right
		case 75: if(blockIndex[0] != 9) { blockIndex[0] = blockIndex[0]+1; } break; //Left
		case 80:
			if(blockIndex[1] != 0) {
				if (gameArray[blockIndex[0]][blockIndex[1]-1] == ' ') { blockIndex[1] = blockIndex[1]-1; } 
			}
			break; //Down
	}
}

void Game::mergeFields(void)
{
	for(char y = 0; y < 3; y++) {
		for(char x = 0; x < 3; x++) {
			gameArray[x + blockIndex[0]][y + blockIndex[1]] = blockArray[x][y];
		}
	}
}

uint_fast16_t Game::checkLine(void)
{
	uint_fast16_t scoreCount = 0;
	char totalLineCount = 0;
	for(char y = 0; y < 15; y++) {
		char lineCount = 0;
		for(char x = 0; x < 9; x++) {
			//if(gameArray[x][y] != NULL) { lineCount++; }
		}
		if(lineCount == 10) { totalLineCount++; clearLine(y);}
	}
	
	switch(totalLineCount) {
		case 0: break;
		case 1: scoreCount = 40;
		case 2: scoreCount = 100;
		case 3: scoreCount = 300;
		case 4: scoreCount = 1200;
	}

	return scoreCount;
}

void Game::clearLine(char input)
{
	//for(char x = 0; x < 9; x++) { gameArray[x][input] = ' '; }
}

void Game::printInit()
{
	cout << "----Teetis----";
	cout << "--■■■       --";
	cout << "--  ■       --";
	cout << "--      ■■  --";
	cout << "--      ■■  --";
	cout << "--  ■       --";
	cout << "--  ■       --";
	cout << "--  ■       --";
	cout << "--  ■       --";
	cout << "--          --";
    cout << "--          --";
    cout << "--          --";
	cout << "--      ■■  --";
	cout << "--     ■ ■■ --";
	cout << "--     ■    --";
	cout << "--  ■■■■■■  --";
	cout << "--■■■■■■ ■■ --";
	cout << "--By  Xand0r--";
}
