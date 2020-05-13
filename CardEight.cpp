#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	if (pPlayer->GetJustRolled() != 0)
	{
		Card::Apply(pGrid, pPlayer);
	}
}

int* CardEight::GetCardParameters()
{
	return NULL;
}
