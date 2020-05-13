#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"


NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Game, Click To Start Playing...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void NewGameAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->ResetPlayers();
}