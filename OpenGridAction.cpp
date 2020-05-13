#include "OpenGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "fstream"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

OpenGridAction::~OpenGridAction()
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Open Grid: Enter the file name, click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	filename = pIn->GetString(pOut);
	pOut->ClearStatusBar();
	
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//TODO
	ifstream inputFile;
	inputFile.open(filename, ios::in);
	if (!(inputFile.is_open()))
	{
		pGrid->PrintErrorMessage("File not found");
		return;
	}
	
	for (int type = 1; type < 4; type++)
	{
		int objectsnum = 0;
		inputFile >> objectsnum;
		for (int i = 0; i < objectsnum; i++)
		{
			if (type == 1)
			{
				CellPosition cell1;
				CellPosition cell2;
				Ladder* newobj = new Ladder(cell1, cell2);
				newobj = dynamic_cast<Ladder*>(newobj->Load(inputFile, type));
				bool added = pGrid->AddObjectToCell(newobj);
			}
			if (type == 2)
			{
				CellPosition cell1;
				CellPosition cell2;
				Snake* newobj = new Snake(cell1, cell2);
				newobj = dynamic_cast<Snake*>(newobj->Load(inputFile, type));
				bool added = pGrid->AddObjectToCell(newobj);
			}
			if (type == 3)
			{
				CellPosition cell1;
				Card* newobj = new CardOne(cell1);
				newobj = dynamic_cast<Card*>(newobj->Load(inputFile, type));
				bool added = pGrid->AddObjectToCell(newobj);
			}
			
		}
	}
	

}
