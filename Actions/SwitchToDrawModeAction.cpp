#include "SwitchToDrawModeAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

SwitchToDrawModeAction::SwitchToDrawModeAction(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToDrawModeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pManager->resetHidden();
	pOut->PrintMessage("Switch to draw mode: Click anywhere");
}

bool SwitchToDrawModeAction::Execute() 
{
	ReadActionParameters();
	(pManager->GetOutput())->CreateDrawToolBar();    //create the draw mode tool bar

	return 1;
}
