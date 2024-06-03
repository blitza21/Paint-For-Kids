#pragma once
#include "AddFigureAction.h"

//Add Rectangle Action class
class AddRectAction: public AddFigureAction
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual bool Execute() ;
	
	virtual void UndoExecution();

	virtual void RedoExecution();
};
