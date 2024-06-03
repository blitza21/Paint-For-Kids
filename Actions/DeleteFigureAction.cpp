#include "DeleteFigureAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selected Figure is deleted");
}

bool DeleteFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	temp = pManager->GetSelectedFig();
	if (temp == NULL)
	{
		pOut->PrintMessage(" Error : Please select a figure first ");
		return 0;
	}
	ReadActionParameters();
	
	temp->SetSelected(0);
	pManager->SetSelectedFig(NULL);
	pManager->DeleteFigure(temp);
	return 1;
}


	
void DeleteFigureAction::UndoExecution()
{
	pManager->AddFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Undone");
}

void DeleteFigureAction::RedoExecution()
{
	pManager->DeleteFigure(temp);
	pManager->GetOutput()->PrintMessage("Delete Figure Action Redone");
}