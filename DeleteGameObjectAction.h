#pragma once

#include "Action.h"

class DeleteGameObjectAction : public Action
{
	// [Action Parameters]

	// Note: These parameters should be read in ReadActionParameters()
	CellPosition CelltoDelete;

public:
	DeleteGameObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters

	virtual void Execute();

	virtual ~DeleteGameObjectAction(); // A Virtual Destructor
};


