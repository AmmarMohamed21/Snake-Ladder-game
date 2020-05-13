#pragma once

#include "Card.h"

class CardTwelve : public Card
{
		int Card_price;
    int Fees_to_pay;      // CardTwelve Parameters:

public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player

	virtual int* GetCardParameters();
	virtual void SetParameters(int* pars);

	virtual ~CardTwelve(); // A Virtual Destructor
};
