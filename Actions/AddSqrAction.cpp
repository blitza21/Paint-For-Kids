#include "AddSqrAction.h"
#include"../Figures/CSquare.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
#include<Windows.h>
#include<MMSystem.h>
AddSqrAction::AddSqrAction(ApplicationManager* pApp):AddFigureAction(pApp)
{
}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Square center");

	//Read center of square
	pIn->GetPointClicked(Center.x, Center.y);


	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();
	SqrGfxInfo.isFilled = pOut->getCrntFillStatus();

	pOut->ClearStatusBar();
}
//Execute the action
bool AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (Center.y - 75 < UI.ToolBarHeight || Center.y + 75 > UI.height - UI.StatusBarHeight) //Draw Validation
	{
		pManager->GetOutput()->PrintMessage("Error :Can't draw here ");
			return 0;
	}

	//Create a Square with the parameters read from the user
	F = new CSquare(Center,  SqrGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the Square to the list of figures
	pManager->AddFigure(F);
	//display figure`s sound if the sound is enabled
	if (pManager->getEnableSound())           // check if the sound is enabled 
	PlaySound(TEXT("Recordings/square.wav"), NULL, SND_ASYNC);
	return 1;
}

void AddSqrAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Square Action Undone");
}

void AddSqrAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Square Action Redone");
}
