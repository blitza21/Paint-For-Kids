#pragma once
#include "Action.h"
class ExitAction :public Action
{
public:
	ExitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() {};
	virtual bool Execute();
};

