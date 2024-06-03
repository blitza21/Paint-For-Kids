#pragma once
#include"../ApplicationManager.h"

//#include "Action.h"
class SoundAction :public Action
{
public :
	SoundAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute();
};

