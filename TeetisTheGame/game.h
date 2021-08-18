#ifndef GAME_H
#define GAME_H
#include <string>
using namespace std;

class Game
{
	public:
		Game();
		Game(const unsigned char, const unsigned char);
		~Game();
		void printInit();
		void printField();
		void dropBlock();
		void moveBlock(const char);
		void rotateBlock(const char);
		inline void setName(char* &nameOfPlayer) { playerNameFlag = true; playerName = nameOfPlayer; };
		inline bool isFinished() {return finishedGame;};
		//[]() {};
	protected:
		Block currentBlock;
		Block nextBlock;
		char gameArray[10][16];
		char printGameArray[10][16];
	private:
		bool finishedGame = false;
		bool playerNameFlag = false;
		string playerName = "";
		unsigned int score;
		bool isGameOver();
		Block newBlock();
		void getBlock();
		unsigned int checkFullLine();
	    unsigned char xFieldSize;
		unsigned char yFieldSize;
		char checkLine();
		void clearLine(char input = '0'); //Default define to pass if none is given, should never happen though
		void mergeFields(void);
};
#endif
