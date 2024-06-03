#include "RedoAction.h"
#include "../ApplicationManager.h"
#include "AddFigureAction.h"
#include "DeleteFigureAction.h"
#include "ChangeFigColorAction.h"
#include "ChangeFillColorAcion.h"
#include "MoveFigureAction.h"
#include "AddCircAction.h"

int RedoAction::RedoCount = 0;	// Initialized to zero
RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{
}

bool RedoAction::Execute()
{
	RedoCount++;
	if (RedoCount > UndoAction::UndoCount)	// Checks if there are any more actions to redo
	{
		pManager->GetOutput()->PrintMessage("No more Actions to redo!");
		RedoCount--;
		return 0;
	}


	Action** UndoList = pManager->GetUndoList();
	int &ActionsToUndoCount = pManager->GetActionsToUndoCount();

	UndoList[ActionsToUndoCount]->RedoExecution();
	ActionsToUndoCount++;


	return 1;
}
