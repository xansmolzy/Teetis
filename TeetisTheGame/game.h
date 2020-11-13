#ifndef BLOCK_H
#define BLOCK_H

class Game
{

public:
	void printField() const { return( ID ); }
	void dropBlock( const Card * newCard ) { hand.addCard( newCard ); }
	void getBlock( const Card * newCard ) { hand.addCard( newCard ); }

protected:

private:
	void mergeFields( const Card * newCard ) { hand.addCard( newCard ); }
};

#endif
