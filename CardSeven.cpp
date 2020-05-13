#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply( pGrid, pPlayer);
	
	//it will be done only in the RollDiceAction
	pGrid->PrintErrorMessage("It is Player "+to_string(pPlayer->GetPlayerNum())+" turn again . Click to continue ...");
}
//dice exexute

int* CardSeven::GetCardParameters()
{
	return NULL;
}