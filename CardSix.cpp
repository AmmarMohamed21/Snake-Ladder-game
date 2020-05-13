#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{

}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, -1*pPlayer->GetJustRolled());
}

int* CardSix::GetCardParameters()
{
	return NULL;
}