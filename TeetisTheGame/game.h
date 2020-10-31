#ifndef BLOCK_H
#define BLOCK_H

class Block
{
	//EXAMPLE friend class Tournament;
	//EXAMPLE friend class Game;

public:
	//EXAMPLE PokerRank getCommunityRank( void ) const			{ return( hand.getCommunityRank() ); } //This is public, because everybody can see the table !
	//EXAMPLE PlayerID getID() const								{ return( ID ); }

protected:
	int * playingField();
	int * activePlayingField();

private:
	//EXAMPLE void setID( const PlayerID ID )						{ this->ID = ID; }
	//EXAMPLE void addCard( const Card * newCard )				{ hand.addCard( newCard ); }
};

#endif
