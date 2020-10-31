#ifndef BLOCK_H
#define BLOCK_H

class Block
{
	friend class Tournament;
	friend class Game;

public:
	PokerRank getCommunityRank( void ) const			{ return( hand.getCommunityRank() ); } //This is public, because everybody can see the table !
	PlayerID getID() const								{ return( ID ); }

protected:
	PokerRank getRank( void ) const						{ return( hand.getMyRank() ); } //This is protected, because only the player should see this
	virtual int willYouRaise( unsigned int totalBet )	= 0;//{ return 0; }
	const Game * getGame( void ) const					{ return( game ); }

private:
	void setID( const PlayerID ID )						{ this->ID = ID; }
	void addCard( const Card * newCard )				{ hand.addCard( newCard ); }
};

#endif
