#include "Card.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}
bool Card::IsOverlapping(GameObject* newobj) const
{
	return false;
}

void Card::Save(ofstream& OutFile, int type)
{
	if (type == 3)
	{
		int* cardparameters;
		if (cardNumber == 1 || cardNumber == 2 || cardNumber == 9)
		{
			cardparameters = GetCardParameters();
			OutFile << cardNumber <<" "<< position.GetCellNum() << " "  << cardparameters[0] << endl;
		}
		else if (cardNumber == 10 || cardNumber == 11 || cardNumber == 12 || cardNumber == 13 || cardNumber == 14)
		{
			cardparameters = GetCardParameters();
			OutFile << cardNumber << " "<< position.GetCellNum() << " " << cardparameters[0] << " " << cardparameters[1] << endl;
		}
		else
			OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
	return;
	
}

GameObject* Card::Load(ifstream& Infile, int type)
{
	if (type == 3)
	{
		Card* newcard;
		int cardtype;
		int cellnum;
		Infile >> cardtype >>cellnum;
		CellPosition cellpos;
		cellpos = cellpos.GetCellPositionFromNum(cellnum);
		int pars[2];
		if (cardtype == 1)
		{
			Infile >> pars[0];
			newcard = new CardOne(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 2)
		{
			Infile >> pars[0];
			newcard = new CardTwo(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 3)
		{
			newcard = new CardThree(cellpos);
		}
		if (cardtype == 4)
		{
			newcard = new CardFour(cellpos);
		}
		if (cardtype == 5)
		{
			newcard = new CardFive(cellpos);
		}
		if (cardtype == 6)
		{
			newcard = new CardSix(cellpos);
		}
		if (cardtype == 7)
		{
			newcard = new CardSeven(cellpos);
		}
		if (cardtype == 8)
		{
			newcard = new CardEight(cellpos);
		}
		if (cardtype == 9)
		{
			Infile >> pars[0];
			newcard = new CardNine(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 10)
		{
			Infile >> pars[0] >> pars[1];
			newcard = new CardTen(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 11)
		{
			Infile >> pars[0] >> pars[1];
			newcard = new CardEleven(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 12)
		{
			Infile >> pars[0] >> pars[1];
			newcard = new CardTwelve(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 13)
		{
			Infile >> pars[0] >> pars[1];
			newcard = new CardThirteen(cellpos);
			newcard->SetParameters(pars);
		}
		if (cardtype == 14)
		{
			Infile >> pars[0] >> pars[1];
			newcard = new CardFourteen(cellpos);
			newcard->SetParameters(pars);
		}

		return newcard;
	}
	return NULL;
}

Card::~Card()
{
}
