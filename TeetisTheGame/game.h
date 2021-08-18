#ifndef GAME_H
#define GAME_H

class Game
{
	public:
		Game();
		Game(const unsigned char, const unsigned char);
		void printInit();
		void printField(void);
		void dropBlock(void);
		void moveBlock(const char);
		void rotateBlock(const char);
		//[]() {};
		
		Block newBlock();
	protected:
		//inline bool isGameOver(void) { for(unsigned char i = 0; i < playFieldX; i++) {this->gameArray[i][0]} };
		Block currentBlock;
		Block nextBlock;
		char gameArray[10][16];
		char printGameArray[10][16];
	private:
		void getBlock(void);
		unsigned int checkFullLine();
	    unsigned char xFieldSize = 10;
		unsigned char yFieldSize = 16;
		char checkLine(void);
		void clearLine(char input = '0'); //Default define to pass
		void mergeFields(void);
};
#endif
