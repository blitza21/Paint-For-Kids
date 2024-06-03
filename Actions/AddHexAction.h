#pragma once
#include "AddFigureAction.h"

//Add Circle Action class
class AddHexAction :
    public AddFigureAction
{
	
	private:
		Point Center; //Center of the hexagon
		GfxInfo HexGfxInfo;
	public:
		AddHexAction(ApplicationManager* pApp);

		//Reads Hexagon parameters
		void ReadActionParameters();

		//Add Hexagon to the ApplicationManager
		virtual bool Execute();

		virtual void UndoExecution();

		virtual void RedoExecution();
};

