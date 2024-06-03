#pragma once
#include "Action.h"
class SaveAction : public Action
{
private:
	string filename; //file name of the saved file
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //Read Parameters

	virtual bool Execute(); //Saves the figures
};

