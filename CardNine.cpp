#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
		
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardNine: Enter its cell to move to...");
	cellToMoveTo = pIn->GetInteger(pOut);

	
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
/*
void CardNine::moveToCell(Grid* pGrid, Player* pPlayer,int aimedCell)
{//modified from move function of player class



}
*/
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);//akram
	CellPosition aimedCellPosition=pPlayer->GetCell()->GetCellPosition().GetCellPositionFromNum(cellToMoveTo);
	pGrid->UpdatePlayerCell(pPlayer,aimedCellPosition);
	//it will be just like move player but the problem is in justRolled and in the -ve dice number
}

int* CardNine::GetCardParameters()
{
	int* pars = &cellToMoveTo;
	return pars;
}

void CardNine::SetParameters(int* pars)
{
	cellToMoveTo = pars[0];
}