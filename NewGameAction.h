#pragma once

#include "Action.h"

class NewGameAction : public Action
{
	// [Action Parameters]
	// Note: These parameters should be read in ReadActionParameters()

public:
	NewGameAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters

	virtual void Execute();

	virtual ~NewGameAction(); // A Virtual Destructor
};

