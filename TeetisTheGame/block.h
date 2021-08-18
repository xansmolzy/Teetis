#ifndef BLOCK_H
#define BLOCK_H

class Block
{
	friend class Game;

	public:
		Block();
		void rotateBlock(char);
	    int x = 0;
		int y = 0;
	protected:
		//bool checkBottomedOut(Game* game);
		bool blockArray[4][4];

	private:
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
