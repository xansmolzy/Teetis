#ifndef BLOCK_H
#define BLOCK_H

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

void TetrominoI::TetrominoI() {
	blockArray = [false,false,false,false],
			     [false,false,false,false],
			     [false,false,false,false],
			     [true,true,true,true];
}

void TetrominoJ::TetrominoJ() {
	blockArray = [false,false,false,true],
			     [false,false,false,true],
			     [false,false,false,true],
			     [false,false,true,true];
}

void TetrominoL::TetrominoL() {
	blockArray = [true,false,false,false],
			     [true,false,false,false],
			     [true,false,false,false],
			     [true,true,false,false];
}

void TetrominoO::TetrominoO() {
	blockArray = [false,false,false,false],
			     [false,false,false,false],
			     [false,false,true,true],
			     [false,false,true,true];
}

void TetrominoS::TetrominoS() {
	blockArray = [false,false,false,true],
			     [false,false,false,true],
			     [false,false,false,true],
			     [false,false,true,true];
}

void TetrominoT::TetrominoT() {
	blockArray = [false,false,false,false],
			     [false,false,false,false],
			     [false,false,false,false],
			     [true,true,true,true];
}

void TetrominoZ::TetrominoZ() {
	blockArray = [false,false,false,true],
			     [false,false,false,true],
			     [false,false,false,true],
			     [false,false,true,true];
}
