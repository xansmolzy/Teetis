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

TetrominoI::TetrominoI() {
	blockArray = {{false,false,false,false},
			     {false,false,false,false},
			     {false,false,false,false},
			     {true,true,true,true}};
}
TetrominoJ::TetrominoJ() {
	blockArray = {{false,false,false,true},
			     {false,false,false,true},
			     {false,false,false,true},
			     {false,false,true,true}};
}
TetrominoL::TetrominoL() {
	blockArray = {{true,false,false,false},
			     {true,false,false,false},
			     {true,false,false,false},
			     {true,true,false,false}};
}
TetrominoO::TetrominoO() {
	blockArray = {{false,false,false,false},
			     {false,false,false,false},
			     {false,false,true,true},
			     {false,false,true,true}};
}
TetrominoS::TetrominoS() {
	blockArray = {{false,false,false,true},
			     {false,false,false,true},
			     {false,false,false,true},
			     {false,false,true,true}};
}
TetrominoT::TetrominoT() {
	blockArray = {{false,false,false,false},
			     {false,false,false,false},
			     {false,false,false,false},
			     {true,true,true,true}};
}
TetrominoZ::TetrominoZ() {
	blockArray = {{false,false,false,true},
			     {false,false,false,true},
			     {false,false,false,true},
			     {false,false,true,true}};
}
