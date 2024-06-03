#pragma once
#include "Action.h"
class ChangeFigColorAction :
	public Action
{
	color UndoColor;	// Fig Color before changes
	color RedoColor;	// Fig Color after changes
	color Previous_UI_Draw_Color;	//Previous UI.Draw Color
	CFigure* SelectedFig;	

public:
	ChangeFigColorAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual bool Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

