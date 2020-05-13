#pragma once

#include "Card.h"

class CardFour : public Card
{
	// CardFour Parameters:

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFour

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	virtual int* GetCardParameters();
	virtual void SetParameters(int* pars) {}

	virtual ~CardFour(); // A Virtual Destructor
};
