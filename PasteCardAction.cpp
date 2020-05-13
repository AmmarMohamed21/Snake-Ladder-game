#include "PasteCardAction.h"


#include "Input.h"
#include "Output.h"
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

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Paste card: Click on the destination cell ...");
	// TODO
	cardPosition=pIn->GetCellClicked();
	cardNumber=pGrid->GetClipboard()->GetCardNumber();
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	// TODO
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	
	if(pGrid->CellHasObject(cardPosition))
	return;
	switch (cardNumber)
	{
	case 1:
	{
		CardOne* pasteCard = new CardOne(cardPosition);
		*pasteCard = *(CardOne*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 2:
	{
		CardTwo* pasteCard = new CardTwo(cardPosition);
		*pasteCard = *(CardTwo*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 3:
	{
		CardThree* pasteCard = new CardThree(cardPosition);
		*pasteCard = *(CardThree*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 4:
	{
		CardFour * pasteCard = new CardFour(cardPosition);
		*pasteCard = *(CardFour*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 5:
	{
		CardFive* pasteCard = new CardFive(cardPosition);
		*pasteCard = *(CardFive*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 6:
	{
		CardSix * pasteCard = new CardSix(cardPosition);
		*pasteCard = *(CardSix*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 7:
	{
		CardSeven* pasteCard = new CardSeven(cardPosition);
		*pasteCard = *(CardSeven*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 8:
	{
		CardEight* pasteCard = new CardEight(cardPosition);
		*pasteCard = *(CardEight*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 9:
	{
		CardNine* pasteCard = new CardNine(cardPosition);
		*pasteCard = *(CardNine*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 10:
	{
		CardTen* pasteCard = new CardTen(cardPosition);
		*pasteCard = *(CardTen*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 11:
	{
		CardEleven * pasteCard = new CardEleven(cardPosition);
		*pasteCard = *(CardEleven*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 12:
	{
		CardTwelve * pasteCard = new CardTwelve(cardPosition);
		*pasteCard = *(CardTwelve*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 13:
	{
		CardThirteen* pasteCard = new CardThirteen(cardPosition);
		*pasteCard = *(CardThirteen*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}
	case 14:
	{
		CardFourteen* pasteCard = new CardFourteen(cardPosition);
		*pasteCard = *(CardFourteen*)pGrid->GetClipboard();
		pasteCard->setPosition(cardPosition);
		pGrid->AddObjectToCell(pasteCard);
		break;
	}

	}
	
}