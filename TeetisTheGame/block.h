class Block
{
	friend class Game;

public:
	Block();
	void rotateBlock(void);
	void setBlock(void);
protected:
	bool checkBottomedOut(Game* game);
private:
	bool blockArray[4][4];
};
