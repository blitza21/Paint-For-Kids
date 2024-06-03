#include "SelectAction.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{

}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on a figure:");
	pIn->GetPointClicked(point.x, point.y);
	SelectedFig = pManager->GetFigure(point.x, point.y);		// Get the selected figure by the user
	
}

bool SelectAction::Execute()
{
	ReadActionParameters();

	if (SelectedFig == NULL)					//User clicks on an empty area
	{
		pManager->GetOutput()->PrintMessage("A click on an empty area");
		return 0;
	}


	if (pManager->GetSelectedFig() != NULL)			//This means that there is a figure previously selected
	{
		if (SelectedFig == pManager->GetSelectedFig())	//Case 1: User clicks on the same selected figure
		{
			SelectedFig->SetSelected(0);
			pManager->SetSelectedFig(NULL);
			pManager->GetOutput()->PrintMessage("Figure unselected");
		}
		else											//Case 2: User clicks on a different figure
		{
			pManager->GetSelectedFig()->SetSelected(0);
			SelectedFig->SetSelected(1);
			pManager->SetSelectedFig(SelectedFig);
			SelectedFig->PrintInfo(pManager->GetOutput());
		}
	}
	else												// This means that this is the first time the user selects a figure
		{
			SelectedFig->SetSelected(1);
			pManager->SetSelectedFig(SelectedFig);
			SelectedFig->PrintInfo(pManager->GetOutput());
		}


	return 1;
}

