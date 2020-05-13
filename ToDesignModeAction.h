#pragma once

#include "Action.h"

class ToDesignModeAction : public Action
{
	// Always add action parameters as private data members

	// Note: These parameters should be read in ReadActionParameters()

public:

	ToDesignModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads ToDesignModeAction action parameters (startPos, endPos)

	virtual void Execute();

	virtual ~ToDesignModeAction(); // Virtual Destructor

};