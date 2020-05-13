#include "ToDesignModeAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

ToDesignModeAction::~ToDesignModeAction()
{
}

void ToDesignModeAction::ReadActionParameters()
{

}


// Execute the action
void ToDesignModeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
	pGrid->ResetPlayers();

}