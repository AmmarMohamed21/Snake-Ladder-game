#pragma once

#include "Action.h"

class ToPlayModeAction : public Action
{
	// Always add action parameters as private data members

	// Note: These parameters should be read in ReadActionParameters()

public:

	ToPlayModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads ToPlayModeAction action parameters (startPos, endPos)

	virtual void Execute();

	virtual ~ToPlayModeAction(); // Virtual Destructor

};