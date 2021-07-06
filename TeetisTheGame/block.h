class Block
{
	friend class Game;

	public:
		void rotateBlock(char);
	protected:
		//bool checkBottomedOut(Game* game);
	private:
		bool blockArray[4][4];
		uint8_t x;
		uint8_t y;
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
