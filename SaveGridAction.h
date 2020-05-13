#pragma once

#include "Action.h"

class SaveGridAction : public Action
{
	// [Action Parameters]

	// Note: These parameters should be read in ReadActionParameters()
	string filename;

public:
	SaveGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters

	virtual void Execute();

	virtual ~SaveGridAction(); // A Virtual Destructor
};


