#pragma once

#include "Card.h"

// [ CardTwo ] Summary:
// Its Apply() Function: Increases the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to Increase --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo : public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to Increase to the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by Incrementing the player's wallet by the walletAmount data member
	virtual int* GetCardParameters();
	virtual void SetParameters(int* pars);

	virtual ~CardTwo(); // A Virtual Destructor
};


