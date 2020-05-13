#include "EditCardAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"


EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{
}

void EditCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Edit card: Click on the source cell to edit ...");
	//TODO
	cardPosition=pIn->GetCellClicked();
	Card* CellCard = pGrid->CellHasCard(cardPosition);
	if(CellCard)
		cardNumber=pGrid->CellHasCard(cardPosition)->GetCardNumber();
	pOut->ClearStatusBar();
}

void EditCardAction::Execute()
{
	ReadActionParameters();
	//TODO
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	int cardParameterArr[8]={1,2,9,10,11,12,13,14};
	for(int i=0;i<8;i++)
	{
		if (cardNumber==cardParameterArr[i])
			{
				pOut->PrintMessage("Edit card: Enter new Parameters, Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pGrid->CellHasCard(cardPosition)->ReadCardParameters(pGrid);
				
				return;
			}	
	}
	pOut->PrintMessage("This Card has no parameters, Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
