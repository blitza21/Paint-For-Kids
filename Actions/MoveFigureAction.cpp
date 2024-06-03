#include "MoveFigureAction.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(" Move Figure: Please click at a point ");
	pIn->GetPointClicked(x, y);

}

bool MoveFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	SelectedFig = pManager->GetSelectedFig();
	if (SelectedFig == NULL) {
		pOut->PrintMessage(" Error! Please select a figure first ");
		return 0;
	}
	ReadActionParameters();
	
	if (!SelectedFig->MoveFigure(x, y, pOut))
		return 0;

	pManager->GetOutput()->PrintMessage("Figure Moved");

	SelectedFig->SetSelected(0);
	pManager->SetSelectedFig(NULL);

	return 1;
}

void MoveFigureAction::UndoExecution()
{
	SelectedFig->ReturnFigure();

	pManager->GetOutput()->PrintMessage("Move Figure Action Undone");
}

void MoveFigureAction::RedoExecution()
{
	SelectedFig->MoveFigure(x, y , pManager->GetOutput());

	pManager->GetOutput()->PrintMessage("Move Figure Action Redone");
}
