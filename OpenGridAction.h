#pragma once

#include "Action.h"

class OpenGridAction : public Action
{
	// [Action Parameters]

	// Note: These parameters should be read in ReadActionParameters()
	string filename;

public:
	OpenGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters

	virtual void Execute();

	virtual ~OpenGridAction(); // A Virtual Destructor
};
