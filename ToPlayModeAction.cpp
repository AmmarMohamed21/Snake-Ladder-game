#include "ToPlayModeAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

ToPlayModeAction::~ToPlayModeAction()
{
}

void ToPlayModeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	
	
}


// Execute the action
void ToPlayModeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
	pGrid->ResetPlayers();

}

