#pragma once
#include "Action.h"
class SelectAction : public Action
{
private:
	Point point;	//Point to get input for Select
	CFigure* SelectedFig;	//Pointer to Selected Figure
public:
	SelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute();
	
};

