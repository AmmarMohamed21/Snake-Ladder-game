#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	Ladder* lad = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	if (lad)
	{
		pGrid->UpdatePlayerCell(pPlayer, ((GameObject*)lad)->GetPosition());
		pPlayer->Move(pGrid, 0);
	}

}

int* CardThree::GetCardParameters()
{
	return NULL;
}
