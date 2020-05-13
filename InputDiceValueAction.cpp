#include "InputDiceValueAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

InputDiceValueAction::~InputDiceValueAction()
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int input = 0;
	while (input < 1 || input > 6)
	{ 
		pOut->PrintMessage("Input Dice Value: Click to continue ...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		input = pIn->GetInteger(pOut);
	}
	dicevalue = input;
	pOut->ClearStatusBar();
}

void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Player* player = pGrid->GetCurrentPlayer();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("The Game has ended, Click to start a new game");
		pGrid->ResetPlayers();
		return;
	}
	//akram
	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you

	int diceNumber = dicevalue;

	// 3- Get the "current" player from pGrid
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	//check if the casting is done correctly
	Card* cardPointer = dynamic_cast<Card*> (currentPlayer->GetCell()->GetGameObject());//akram

	// 4- Move the currentPlayer using function Move of class player

	//there should be many conditions here for different cards: akram
	if (cardPointer)
	{
		if (cardPointer->GetCardNumber() == 8)
		{
			if ((currentPlayer->GetJustRolled()) != 0)
			{
				pGrid->PrintErrorMessage("You are denied from playing this turn, Click to continue");
				currentPlayer->SetJustRolled(0);
				diceNumber = 0;
			}
		}
	}
	currentPlayer->Move(pGrid, diceNumber);
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Player " + to_string(player->GetPlayerNum()) + " is the winner");
		return;
	}
	// Applying GameObjects if there was any of them

	// 5- Advance the current player number of pGrid

	//Card 7:should not advance the current player unless he moves from the cell having card 7
	cardPointer = dynamic_cast<Card*> (currentPlayer->GetCell()->GetGameObject());
	if (cardPointer)
	{
		if ((cardPointer->GetCardNumber() == 7))
		{
			return;
		}
	}
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).


}