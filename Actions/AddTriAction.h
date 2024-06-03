#pragma once
#include "AddFigureAction.h"

//Add Triangle Action class
class AddTriAction :
    public AddFigureAction
{
	
	private:
		Point P1, P2,P3; //Triangle Vertices
		GfxInfo TriGfxInfo;
	public:
		AddTriAction(ApplicationManager* pApp);

		//Reads triangle parameters
		virtual void ReadActionParameters();

		//Add triangle to the ApplicationManager
		virtual bool Execute();

		virtual void UndoExecution();

		virtual void RedoExecution();
};

