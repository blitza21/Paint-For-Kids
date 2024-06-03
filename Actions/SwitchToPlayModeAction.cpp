#include "SwitchToPlayModeAction.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
//constructor
SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp):Action(pApp)
{
}

 void SwitchToPlayModeAction::ReadActionParameters() 
 {
	 Output* pOut = pManager->GetOutput();
	 pOut->PrintMessage("Switch to play mode: Click anywhere");

 }
 bool SwitchToPlayModeAction::Execute()
{
	if (pManager->GetFigCount() == 0)
	{
		(pManager->GetOutput())->PrintMessage("Draw Figures before switching to play mode: Click anywhere");
		return 0;
	}
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();  //create the play mode tool bar
}
