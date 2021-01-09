#include "block.h"

void Block::rotateBlock(char input)
{
	if(input = 'R') {
		for(char x = 0; x < 3; x++) { 
			for(char y = 0; y < 3; y++) {
				blockArray[x][y] = blockArray[3-y][3-x];
			}
		}
	}
	if(input = 'L') {
		for(char x = 0; x < 3; x++) { 
			for(char y = 0; y < 3; y++) {
				blockArray[x][y] = blockArray[3-y][x];
			}
		}
	}
}

