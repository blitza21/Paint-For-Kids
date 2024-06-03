#include "AddFigureAction.h"
#include "../ApplicationManager.h"

AddFigureAction::AddFigureAction(ApplicationManager* pApp) : Action(pApp)
{
}

void AddFigureAction::UndoExecution()
{
	if (F == pManager->GetSelectedFig())
	{
		F->SetSelected(0);
		pManager->SetSelectedFig(NULL);
	}

	pManager->DeleteFigure(F);
}

void AddFigureAction::RedoExecution()
{
	pManager->AddFigure(F);
}
