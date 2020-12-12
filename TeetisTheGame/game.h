#ifndef BLOCK_H
#define BLOCK_H

class Game
{
public:
	char blockIndex[1][1];

	void printField(void);
	void dropBlock(void);
	void getBlock(void);
	void moveBlock(const char input);
protected:
	bool gameArray[10][16];
private:
	void mergeFields(void);
};

#endif
