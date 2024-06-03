#pragma once
#include "AddFigureAction.h"
#include "../Figures/CCircle.h"

//Add Circle Action class
class AddCircAction :
	public AddFigureAction

{
private:
	Point Center, PointOnRadius; //Center and Radius of the circle
	GfxInfo CircGfxInfo;
	
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual bool Execute();

	virtual void UndoExecution();

	virtual void RedoExecution();
};

