#pragma once
#include "Action.h"
class ChangeFillColorAcion :
    public Action
{
	color UndoColor;
	color Previous_UI_Fill_Color;
	bool UndoState;
	bool Previous_UI_Fill_State;
	color RedoColor;
	CFigure* SelectedFig;
	
public:
	ChangeFillColorAcion(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual bool Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

