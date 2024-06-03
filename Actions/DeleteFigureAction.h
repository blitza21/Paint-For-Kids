#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class DeleteFigureAction : public Action
{

	CFigure* temp;	//A pointer to store the figure temporarily for the undo action
public:
	DeleteFigureAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual bool Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

