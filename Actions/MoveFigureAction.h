#pragma once
#include "Action.h"
class MoveFigureAction :public Action
{
private:
	int x, y;
	CFigure* SelectedFig;
public:
	MoveFigureAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};