#include "CutCardAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"


CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Cut card: Click on the source cell ...");
	//TODO
	cardPosition=pIn->GetCellClicked();
	Card* CellCard = pGrid->CellHasCard(cardPosition);
	if(CellCard)
		cardNumber=pGrid->CellHasCard(cardPosition)->GetCardNumber();
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	//TODO
	Grid* pGrid = pManager->GetGrid();
	Card* CellCard=pGrid->CellHasCard(cardPosition);
	if(!CellCard)
		return;
	pGrid->SetClipboard(CellCard);
	//delete card from cell
	pGrid->RemoveObjectFromCell(cardPosition);
}
