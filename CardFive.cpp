#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//pPlayer->Move(pGrid, pPlayer->GetJustRolled());
	CellPosition newcell;
	int newcellnum = pPlayer->GetJustRolled() + pPlayer->GetCell()->GetCellPosition().GetCellNum();
	newcell = newcell.GetCellPositionFromNum(newcellnum);
	pGrid->UpdatePlayerCell(pPlayer, newcell);
	pPlayer->Move(pGrid, 0);
}

int* CardFive::GetCardParameters()
{
	return NULL;
}