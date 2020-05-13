#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	Snake* snak = pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition());
	if (snak)
	{
		pGrid->UpdatePlayerCell(pPlayer, ((GameObject*)snak)->GetPosition());
		pPlayer->Move(pGrid, 0);
	}
}

int* CardFour::GetCardParameters()
{
	return NULL;
}