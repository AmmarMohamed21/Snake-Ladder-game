#include "CardEleven.h"

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number
}

CardEleven::~CardEleven(void)
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->GetCard(11))
	{
		SetParameters(pGrid->GetCard(11)->GetCardParameters());
		return;
	}
	int input1 = 0;
	while (input1 <= 0)
	{
		pOut->PrintMessage("CardEleven: Enter its Card price ...");
		input1 = pIn->GetInteger(pOut);
	}
	Card_price = input1;

	int input2 = 0;
	while (input2 <= 0)
	{
		pOut->PrintMessage("CardEleven: Enter its fees to pay  ...");
		input2 = pIn->GetInteger(pOut);
	}
	Fees_to_pay = input2;

	pOut->ClearStatusBar();

}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	
	Input* pIn = pGrid->GetInput();
	
	if (pGrid->GetCardOwner(11))
	{
		if(pPlayer != pGrid->GetCardOwner(11))
		{
			pGrid->PrintErrorMessage("You have reached a bought station, Click to continue...");
			pPlayer->SetWallet(pPlayer->GetWallet()-Fees_to_pay);
			pGrid->GetCardOwner(11)->SetWallet(pGrid->GetCardOwner(11)->GetWallet()+Fees_to_pay);
		}
	}
	else
	{
		pOut->PrintMessage("You have reached a station. Do you want to buy it? y/n");

		char ans = pIn->GetString(pOut)[0];
		pOut->ClearStatusBar();
		if (ans == 'y' || ans == 'Y')
		{
			if (pPlayer->GetWallet() > Card_price)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - Card_price);
				int* cards = pPlayer->GetCardsOwned();
				cards[1] = 11;
				pPlayer->SetCardsOwned(cards);
			}
		}
	}

}

int* CardEleven::GetCardParameters()
{
	int* pars = &Card_price;
	pars[1] = Fees_to_pay;
	return pars;
}

void CardEleven::SetParameters(int* pars)
{
	Card_price = pars[0];
	Fees_to_pay = pars[1];
}