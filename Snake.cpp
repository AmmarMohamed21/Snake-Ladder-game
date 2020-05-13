#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake::IsOverlapping(GameObject* newobj) const
{
	Snake* newsnake = (Snake*)newobj;
	if (newsnake)
	{
		if (position.HCell() == newsnake->GetPosition().HCell())
			for (int i = endCellPos.VCell(); i >= position.VCell(); i--)
			{
				if (i >= newsnake->GetPosition().VCell() && i <= newsnake->GetEndPosition().VCell())
				{
					return true;
				}
			}
	}
	return false;
}

void Snake::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
	return;
}

GameObject* Snake::Load(ifstream& Infile, int type)
{
	if (type == 2)
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
		Snake* newsnake = new Snake(cell1, cell2);
		return newsnake;
	}
	return NULL;
}

Snake::~Snake()
{
}