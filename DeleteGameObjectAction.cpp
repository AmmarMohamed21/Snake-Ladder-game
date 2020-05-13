#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete Game Object: Click on the object cell ...");
	CelltoDelete = pIn->GetCellClicked();
	pOut->ClearStatusBar();
	//TODO
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	//TODO
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(CelltoDelete);
}
