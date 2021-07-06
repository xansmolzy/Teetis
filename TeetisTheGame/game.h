#ifndef BLOCK_H
#define BLOCK_H
//Use member var block_H
#include <iostream>
#include <stdint.h> //So I can ret more efficiently since every place I'll be ret'ing mostly 0

class Game
{
	public:
		Game();
		char blockIndex[2]; //[0] x, [1] y

		void printField(void);
		void dropBlock(void);
		void getBlock(void);
		void moveBlock(const char input);
	protected:
		char gameArray[10][16];
	private:
		uint_fast16_t checkLine(void);
		void clearLine(char input = '0'); //Default define to pass
		void mergeFields(void);
};

#endif
