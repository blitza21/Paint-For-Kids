#ifndef _Play_Recording_Action_H
#define  _Play_Recording_Action_H
//#include "Action.h"
#include"../ApplicationManager.h"

class PlayRecordingAction : public Action
{
public:

	PlayRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //Read Parameters

	virtual bool Execute();
};
#endif
