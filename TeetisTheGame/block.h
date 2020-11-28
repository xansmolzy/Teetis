class Block
{
	friend class Game;

public:
	Block();
	void rotateBlock(void);
	void setBlock(void);
	//PokerRank getCommunityRank( void ) const			{ return( hand.getCommunityRank() ); } //This is public, because everybody can see the table !
	//PlayerID getID() const								{ return( ID ); }

protected:
	//PokerRank getRank( void ) const						{ return( hand.getMyRank() ); } //This is protected, because only the player should see this
	//virtual int willYouRaise( unsigned int totalBet )	= 0;//{ return 0; }
	//const Game * getGame( void ) const					{ return( game ); }

private:
	bool blockArray[4][4];
};
