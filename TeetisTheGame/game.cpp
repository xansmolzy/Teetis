#include "block.h"
#include "game.h"
#include <ncurses.h>//keyboard input, use "-lcurses" when compiling
#include <unistd.h> //allow usleep to work
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
using namespace std;

Game::~Game(void)
{	clear();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("-----GAME-----\n");
	printw("-----OVER-----\n");
	string s = "";
	if(playerNameFlag) { s += playerName; } 
	s += " Score: ";
	s += to_string(score);
	printw(s.c_str());
	attroff(COLOR_PAIR(1));
	refresh();
	sleep(3);
	string filename("scores.txt");
    ofstream file_out;
    file_out.open(filename, std::ios_base::app);
    file_out << s << endl;
    file_out.close();
    endwin();
}

Game::Game(void) {
	//start ncurses and print splashscreen
	initscr();
	nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
	printInit();
	refresh();
	sleep(2);
	clear();
	//Set array sizes
	xFieldSize = 10;
	yFieldSize = 16;
	//init game array
	for(char x = 0; x < 10; x++) {
		for(char y = 0; y < 16; y++) {
			gameArray[x][y] = '.';
		}
	}
	//start the first block
	srand(time(nullptr)); //Nullptr
	nextBlock = newBlock();
	nextBlock = newBlock();
}

Game::Game(const unsigned char xFieldSizeIn = 10,const unsigned char yFieldSizeIn = 16) {
	//start ncurses and print splashscreen
	initscr();
	nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
	printInit();
	refresh();
	sleep(2);
	clear();
	//Set array sizes
	xFieldSize = xFieldSizeIn;
	yFieldSize = yFieldSizeIn;
	
	//init game array
	for(char x = 0; x < xFieldSize; x++) {
		for(char y = 0; y < yFieldSize; y++) {
			gameArray[x][y] = '.';
		}
	}
	//start the first block
	srand(time(nullptr)); //Nullptr
	nextBlock = newBlock();
	nextBlock = newBlock();
}
/*Prints the current gamefield*/
void Game::printField(void) {
	clear();
	memcpy(printGameArray, gameArray, yFieldSize*xFieldSize*sizeof(char));
	
	for(char y = 0; y < 4; y++) {
		for(char x = 0; x < 4; x++) {
			if(currentBlock.blockArray[x][y] == true) { printGameArray[currentBlock.x+x][currentBlock.y+y] = '#'; }
		}
	}
	for(char y = 0; y < yFieldSize; y++) {
		string s;
		for(char x = 0; x < xFieldSize; x++) {
			if(x == currentBlock.x && y == currentBlock.y) { s += "*"; }
			else { s += printGameArray[x][y]; }
		}
		s += '\n';
		printw(s.c_str());
	}
	string s = "Score: ";
	s += to_string(score);
	s+= "\n";
	printw(s.c_str());
	refresh();
}

void Game::dropBlock(void)
{
	for(char y = 0; y < 4; y++) {
		for(char x = 0; x < 4; x++) {
			if((currentBlock.blockArray[x][y] == true && currentBlock.y+y == yFieldSize-1) ||
			  (currentBlock.blockArray[x][y] == true && gameArray[currentBlock.x+x][currentBlock.y+y+1] == '#')) 
			{ mergeFields(); return; }
		}
	}
	currentBlock.y++;
}

void Game::mergeFields(void)
{
	memcpy(gameArray, printGameArray, yFieldSize*xFieldSize*sizeof(char));
	score = checkFullLine();
	if(isGameOver()) { finishedGame = true; }
	else { nextBlock = newBlock(); printField();}
}

void Game::clearLine(char input)
{
	for(char y = input; y > 1; y--) {
		for(char x = 0; x < xFieldSize; x++) { gameArray[x][y] = gameArray[x][y-1]; }
	}
	for(char x = 0; x < xFieldSize; x++) { gameArray[x][0] = '.'; }
}

unsigned int Game::checkFullLine(void)
{
	static int scoreCount = 0;
	char totalLineCount = 0;
	for(int y = 0; y < yFieldSize; y++) {
		char lineCount = 0;
		for(int x = 0; x < xFieldSize; x++) {
			if(gameArray[x][y] == '#') { lineCount++; }
		}
		if(lineCount >= xFieldSize) { totalLineCount++; clearLine(y); y--;}
	}
	
	switch(totalLineCount) {
		case 0: break;
		case 1: scoreCount += 40; break;
		case 2: scoreCount += 100; break;
		case 3: scoreCount += 300; break;
		case 4: scoreCount += 1200; break;
	}

	return scoreCount;
}

void Game::moveBlock(const char input) {
	switch(input) {
		case 'L': currentBlock.x--; break; //code for arrow right
		case 'R': currentBlock.x++; break; //code for arrow left
	}
	if(currentBlock.x <= -3) { currentBlock.x++; } 
	if(currentBlock.x >= xFieldSize-3) { currentBlock.x--; } 
}

void Game::rotateBlock(const char input)
{	
	bool tmpblockArray[4][4];
	for(char y = 0; y < 4; y++) {
		for(char x = 0; x < 4; x++) {
			tmpblockArray[y][x] = currentBlock.blockArray[x][y];
		}
	}
	memcpy(currentBlock.blockArray, tmpblockArray, 4*4*sizeof(bool));
}
Block Game::newBlock()
{
	Block blockRet;
	currentBlock = nextBlock;
	switch(rand()%6) {
		case 0: blockRet = TetrominoI(); break;
		case 1: blockRet = TetrominoJ(); break;
		case 2: blockRet = TetrominoL(); break;
		case 3: blockRet = TetrominoO(); break;
		case 4: blockRet = TetrominoS(); break;
		case 5: blockRet = TetrominoT(); break;
		case 6: blockRet = TetrominoZ(); break;
		default: blockRet = Block();
	}
	return blockRet;
}

void Game::printInit()
{	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("----Teetis----\n");
	printw("--###       --\n");
	printw("--  #       --\n");
	printw("--      ##  --\n");
	printw("--      ##  --\n");
	printw("--  #       --\n");
	printw("--  #       --\n");
	printw("--  #       --\n");
	printw("--  #       --\n");
	printw("--          --\n");
    printw("--          --\n");
    printw("--          --\n");
	printw("--      ##  --\n");
	printw("--     # ## --\n");
	printw("--     #    --\n");
	printw("--  ######  --\n");
	printw("--###### ## --\n");
	printw("--By  Xand0r--\n");
	attroff(COLOR_PAIR(1));
}

bool Game::isGameOver() {
	for(unsigned char i = 0; i < xFieldSize; i++) { if(gameArray[i][0] == '#'){ return true; } }
	return false;
}
