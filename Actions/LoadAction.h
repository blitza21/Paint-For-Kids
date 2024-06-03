#pragma once
#include "Action.h"
class LoadAction : public Action
{
private:
	string filename; //file name of the load file
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //Read Parameters

	virtual bool Execute(); //Loads the figures
};

