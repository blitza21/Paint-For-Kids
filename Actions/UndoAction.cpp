#include "UndoAction.h"
#include"../ApplicationManager.h"
#include "AddFigureAction.h"
#include "DeleteFigureAction.h"
#include "ChangeFigColorAction.h"
#include "ChangeFillColorAcion.h"
#include "MoveFigureAction.h"

int UndoAction::UndoCount = 0;
UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
}

bool UndoAction::Execute()
{

	Action** UndoList = pManager->GetUndoList();
	int &ActionsToUndoCount = pManager->GetActionsToUndoCount();

	if (ActionsToUndoCount > MaxActionsToUndo)
	{
		for (int i = 0; i < ActionsToUndoCount - MaxActionsToUndo; i++)
			delete UndoList[i];

		for (int i = 0; i < MaxActionsToUndo; i++)
		{
			UndoList[i] = UndoList[ActionsToUndoCount - MaxActionsToUndo + i];
		}
		ActionsToUndoCount = MaxActionsToUndo;
	}

	if (ActionsToUndoCount == 0)
	{
		pManager->GetOutput()->PrintMessage("No more Actions to Undo!");
		return 0;
	}
	UndoList[ActionsToUndoCount - 1]->UndoExecution();
	ActionsToUndoCount--;
	UndoCount++;

	return 1;
}
