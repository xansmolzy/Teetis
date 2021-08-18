#include "block.h"
#include <cstring>
using namespace std;

Block::Block()
{
	bool tmpblockArray[4][4] = {{false,false,false,false},
							   {false,false,false,false},
							   {false,false,false,false},
			                   {false,false,false,false}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}

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
	bool tmpblockArray[4][4] = {{false,false,false,false},
							   {false,false,false,false},
							   {false,false,false,false},
			                   {true,true,true,true}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
TetrominoJ::TetrominoJ() {
	bool tmpblockArray[4][4] = {{false,false,false,true},
							   {false,false,false,true},
							   {false,false,false,true},
			                   {false,false,true,true}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
TetrominoL::TetrominoL() {
	bool tmpblockArray[4][4] = {{true,false,false,false},
							   {true,false,false,false},
							   {true,false,false,false},
			                   {true,true,false,false}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
TetrominoO::TetrominoO() {
	bool tmpblockArray[4][4] = {{false,false,false,false},
							   {false,false,false,false},
							   {false,true,true,false},
			                   {false,true,true,false}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
TetrominoS::TetrominoS() {
	bool tmpblockArray[4][4] = {{false,false,false,false},
							   {false,false,false,false},
							   {true,true,false,false},
			                   {false,true,true,false}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
TetrominoT::TetrominoT() {
	bool tmpblockArray[4][4] = {{false,false,false,false},
							   {false,false,false,false},
							   {false,true,false,false},
			                   {true,true,true,false}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
TetrominoZ::TetrominoZ() {
	bool tmpblockArray[4][4] = {{false,false,false,false},
							   {false,false,false,false},
							   {false,true,true,false},
			                   {true,true,false,false}};
			                   
	memcpy(blockArray, tmpblockArray, 4*4*sizeof(bool));
}
