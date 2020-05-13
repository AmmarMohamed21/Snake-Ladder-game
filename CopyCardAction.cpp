#include "CopyCardAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"


CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Copy card: Click on the source cell ...");
	//TODO
	cardPosition=pIn->GetCellClicked();
	Card* CellCard = pGrid->CellHasCard(cardPosition);
	if(CellCard)
		cardNumber=pGrid->CellHasCard(cardPosition)->GetCardNumber();
	pOut->ClearStatusBar();

}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	//TODO
	//here is a condition 
	// if there was a card in the copied cell,execute
	// if there was not a card in the copied cell, return
	Grid* pGrid = pManager->GetGrid();
	Card* CellCard=pGrid->CellHasCard(cardPosition);
	if(!CellCard)
		return;
	pGrid->SetClipboard(CellCard);
}