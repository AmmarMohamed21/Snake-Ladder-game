#pragma once

#include "Card.h"

class CardEight : public Card
{
	// CardEight Parameters:

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player

	virtual int* GetCardParameters();
	virtual void SetParameters(int* pars) {}

	virtual ~CardEight(); // A Virtual Destructor
};

