#pragma once
#include "Action.h"
#include "UndoAction.h"
class RedoAction : public Action
{
public:
	static int RedoCount;	// Number of redo clicks in a row
	RedoAction(ApplicationManager* pApp);

	void ReadActionParameters() {};

	virtual bool Execute();
};

