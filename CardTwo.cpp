#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("CardTwo: Enter its wallet amount ...");
	walletAmount = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);

}

int* CardTwo::GetCardParameters()
{
	int* pars = &walletAmount;
	return pars;
}

void CardTwo::SetParameters(int* pars)
{
	walletAmount = pars[0];
}