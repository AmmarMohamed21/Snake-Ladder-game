#pragma once

#include "Action.h"

class EditCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition cardPosition; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:
	EditCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters

	virtual void Execute();

	virtual ~EditCardAction(); // A Virtual Destructor
};

