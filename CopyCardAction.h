#pragma once

#include "Action.h"

class CopyCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition cardPosition; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:
	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters

	virtual void Execute(); 

	virtual ~CopyCardAction(); // A Virtual Destructor
};

