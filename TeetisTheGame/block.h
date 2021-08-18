#ifndef BLOCK_H
#define BLOCK_H
#include <cstring>
using namespace std;
class Block
{
	friend class Game; //https://youtu.be/ZyhrYis509A?t=58
	protected:
		Block();
		inline Block(bool customBlock[4][4]) { memcpy(blockArray, customBlock, 4*4*sizeof(bool)); };
		void rotateBlock(char);
		char x = 0;
		char y = 0;
		bool blockArray[4][4];
};

class TetrominoI: public Block {
  public:
	TetrominoI();
};
class TetrominoJ: public Block {
  public:
	TetrominoJ();
};
class TetrominoL: public Block {
  public:
	TetrominoL();
};
class TetrominoO: public Block {
  public:
	TetrominoO();
};
class TetrominoS: public Block {
  public:
	TetrominoS();
};
class TetrominoT: public Block {
  public:
	TetrominoT();
};
class TetrominoZ: public Block {
  public:
	TetrominoZ();
};
#endif
