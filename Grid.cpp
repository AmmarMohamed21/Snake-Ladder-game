#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Player.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder())
				return dynamic_cast<Ladder*>(CellList[i][j]->GetGameObject());

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake())
				return dynamic_cast<Snake*>(CellList[i][j]->GetGameObject());

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Player* Grid::GetCardOwner(int cardnum) const
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (PlayerList[i]->GetCardsOwned()[j] == cardnum)
			{
				return PlayerList[i];
			}
		}

	}
	return NULL;
}


Card* Grid::GetCard(int cardnum)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasCard())
			{
				if (CellList[i][j]->HasCard()->GetCardNumber() == cardnum)
					return CellList[i][j]->HasCard();
			}
		}
	}
	return NULL;
}
// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}

bool Grid::IsOverlapping(GameObject* newobj) const
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->GetGameObject())
				if(CellList[i][j]->GetGameObject()->IsOverlapping(newobj))
					return true;
		}
	}
	return false;
}

bool Grid::SnakeLadderOverlapping(GameObject* newObj) const
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->GetGameObject())
			{ 
				if (dynamic_cast<Snake*>(newObj) && dynamic_cast<Ladder*>(CellList[i][j]->GetGameObject()))
				{
					Snake* Snak = (Snake*)newObj;
					Ladder* Lad = (Ladder*)CellList[i][j]->GetGameObject();
					if (Snak->GetEndPosition().GetCellNum() == Lad->GetPosition().GetCellNum())
						return true;
					else if (Snak->GetPosition().GetCellNum() == Lad->GetEndPosition().GetCellNum())
						return true;
				}
				else if(dynamic_cast<Ladder*>(newObj) && dynamic_cast<Snake*>(CellList[i][j]->GetGameObject()))
				{
					Ladder* Lad = (Ladder*)newObj;
					Snake* Snak = (Snake*)CellList[i][j]->GetGameObject();
					if (Lad->GetEndPosition().GetCellNum() == Snak->GetPosition().GetCellNum())
						return true;
					else if (Lad->GetPosition().GetCellNum() == Snak->GetEndPosition().GetCellNum())
						return true;
				}
		    }
		}
	}
	return false;
}

bool Grid::FirstCellObject(GameObject* newObj) const
{
	if (newObj->GetPosition().GetCellNum() == 1)
		return true;
	return false;
}

bool Grid::LastCellObject(GameObject* newObj) const
{
	if (newObj->GetPosition().GetCellNum() == 99)
		return true;
	return false;
}

void Grid::SaveAll(ofstream& OutFile, int type)
{
	int n=0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->GetGameObject())
			{
				if (type == 1)
				{
					if (dynamic_cast<Ladder*>(CellList[i][j]->GetGameObject()))
						n++;
				}
				if (type == 2)
				{
					if (dynamic_cast<Snake*>(CellList[i][j]->GetGameObject()))
						n++;
				}
				if (type == 3)
				{
					if (dynamic_cast<Card*>(CellList[i][j]->GetGameObject()))
						n++;
				}
				
			}

		}
	}
	OutFile << n << endl;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->GetGameObject())
			{
				CellList[i][j]->GetGameObject()->Save(OutFile, type);
			}
			
		}
	}
	
}

Card* Grid::CellHasCard(CellPosition& pos)
{
	return CellList[pos.VCell()][pos.HCell()]->HasCard();

}

bool Grid::CellHasObject(CellPosition& pos)
{
	Card* card = CellList[pos.VCell()][pos.HCell()]->HasCard();
	Snake* snake = CellList[pos.VCell()][pos.HCell()]->HasSnake();
	Ladder* ladder = CellList[pos.VCell()][pos.HCell()]->HasLadder();

	if (card || snake || ladder)
		return 1;
	else return 0;
}
void Grid::ResetPlayers()
{
	for (int i = 0; i < 4; i++)
	{
		PlayerList[i]->Reset(this);
	}
	currPlayerNumber = 0;
}