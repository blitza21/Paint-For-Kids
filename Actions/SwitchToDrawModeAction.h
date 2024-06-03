#pragma once
#include "Action.h"
class SwitchToDrawModeAction :public Action
{

public:
	SwitchToDrawModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute();
};

