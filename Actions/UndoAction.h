#pragma once
#include "Action.h"
class UndoAction : public Action
{
	enum { MaxActionsToUndo = 5 };


public:
	static int UndoCount;	//Number of undo clicks in a row
	UndoAction(ApplicationManager* pApp);

	void ReadActionParameters() {};

	virtual bool Execute();
};
