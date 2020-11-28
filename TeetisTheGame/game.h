#ifndef BLOCK_H
#define BLOCK_H

class Game
{
public:
	void printField(void);
	void dropBlock(void);
	void getBlock( const Card * newCard ) { hand.addCard( newCard ); }

protected:

private:
	bool scratchArray[10][16];
	bool gameArray[10][16];
	void mergeFields( const Card * newCard ) { hand.addCard( newCard ); }
};

#endif
