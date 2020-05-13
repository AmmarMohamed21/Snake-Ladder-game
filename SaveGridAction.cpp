#include "SaveGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "fstream"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Save Grid: Enter the file name, click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	filename = pIn->GetString(pOut);
	pOut->ClearStatusBar();
	//TODO
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	//TODO
	ofstream outputFile;
	outputFile.open(filename, ios::out);
	Grid* pGrid = pManager->GetGrid();
	for (int i = 1; i < 4; i++)
	{
		pGrid->SaveAll(outputFile, i);
	}
	outputFile.close();
}
