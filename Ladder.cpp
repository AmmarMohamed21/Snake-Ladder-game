#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

bool Ladder::IsOverlapping(GameObject* newobj) const
{
	Ladder* newlad = (Ladder*)newobj;
	if (newlad)
	{
		if (position.HCell()==newlad->GetPosition().HCell())
			for (int i = endCellPos.VCell(); i <= position.VCell(); i++)
			{
				if (i <= newlad->GetPosition().VCell() && i >= newlad->GetEndPosition().VCell())
				{
					return true;
				}
			}
	}
	return false;
}

void Ladder::Save(ofstream& OutFile, int type)
{
	if (type == 1)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
	return;
}


GameObject* Ladder::Load(ifstream& Infile, int type)
{
	if (type == 1)
	{
		int cells[2];
		for (int i = 0; i < 2; i++)
		{
			Infile >> cells[i];
		}
		CellPosition cell1;
		CellPosition cell2;
		cell1 = cell1.GetCellPositionFromNum(cells[0]);
		cell2 = cell2.GetCellPositionFromNum(cells[1]);
		Ladder* newlad = new Ladder(cell1, cell2);
		return newlad;
	}
	return NULL;
}

Ladder::~Ladder()
{
}
