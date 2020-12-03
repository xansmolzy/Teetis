#ifndef BLOCK_H
#define BLOCK_H

class Game
{
public:
	char blockIndex[1][1];

	void printField(void);
	void dropBlock(void);
	void getBlock( const Card * newCard ) { hand.addCard( newCard ); }
	void moveBlock(const char input);
protected:
	bool gameArray[10][16];
private:
	void mergeFields( const Card * newCard ) { hand.addCard( newCard ); }
};

#endif
