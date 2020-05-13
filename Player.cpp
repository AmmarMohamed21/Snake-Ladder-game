#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	// Make all the needed initialization or validations
	CardsOwned = new int[5];
	for (int i = 0; i < 5; i++)
	{
		CardsOwned[i] = 0;
	}

}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

int Player::GetPlayerNum()const//akram
{
	return playerNum;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
int Player::GetJustRolled() const
{
	return justRolledDiceNum;
}

void Player::SetJustRolled(int num)
{
	justRolledDiceNum = num;
}
int* Player::GetCardsOwned() const
{
	return CardsOwned;
}
void Player::SetCardsOwned(int cardsowned[])
{
	CardsOwned = cardsowned;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3)
	{
		wallet = wallet + diceNumber * 10;
		turnCount = 0;
		return;
	}
	if (wallet < 1)
	{
		pGrid->PrintErrorMessage("You don't have enough money to move, Click to continue...");
		return;
	}
		
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = pCell->GetCellPosition();
	int p = pos.GetCellNumFromPosition(pos) + diceNumber;
	pos = pos.GetCellPositionFromNum(p);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	
	if (p<100)
		pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject())
	{
		pCell->GetGameObject()->Apply(pGrid, this);
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	
	if (p == 100)
	{
		pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::Reset(Grid* pGrid)
{
	wallet = 100;
	for (int i = 0; i < 5; i++)
	{
		CardsOwned[i] = 0;
	}
	turnCount = 0;
	CellPosition pos(8, 0);
	pGrid->UpdatePlayerCell(this, pos);
}