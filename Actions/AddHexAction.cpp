#include "AddHexAction.h"
#include"../Figures/CHexagon.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
#include<Windows.h>
#include<MMSystem.h>
AddHexAction::AddHexAction(ApplicationManager* pApp):AddFigureAction(pApp)
{
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);


	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	HexGfxInfo.isFilled = pOut->getCrntFillStatus();

	pOut->ClearStatusBar();
}

//Execute the action
bool AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (Center.y - 86 < UI.ToolBarHeight || Center.y + 86 > UI.height - UI.StatusBarHeight) //Draw Validation
	{
		pManager->GetOutput()->PrintMessage("Error :Can't draw here ");
		return 0;
	}

	//Create a hexagon with the parameters read from the user
	F = new CHexagon(Center, HexGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the hexagon to the list of figures
	pManager->AddFigure(F);
	//display figure`s sound if the sound is enabled
	if(pManager->getEnableSound())          // check if the sound is enabled 
	PlaySound(TEXT("Recordings/hexagon.wav"), NULL, SND_ASYNC);
	return 1;
}

void AddHexAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Hexagon Action Undone");
}

void AddHexAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Hexagon Action Redone");
}

