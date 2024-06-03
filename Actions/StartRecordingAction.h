#pragma once
#include "Action.h"
class StartRecordingAction : public Action
{
private:
	int RecordCount;
public:
	StartRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //Read Parameters

	virtual bool Execute();

	void Record();	//Records each action
};

