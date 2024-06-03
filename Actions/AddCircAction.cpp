#include "AddCircAction.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
#include<Windows.h>
#include<MMSystem.h>
#include<cmath>

AddCircAction::AddCircAction(ApplicationManager* pApp) :AddFigureAction(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read Center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at Radius");

	//Read Radius and store in Radius
	pIn->GetPointClicked(PointOnRadius.x, PointOnRadius.y);

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.isFilled= pOut->getCrntFillStatus();

	pOut->ClearStatusBar();
}

//Execute the action
bool AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if(Center.y-(sqrt(pow(Center.x - PointOnRadius.x, 2) + pow(Center.y - PointOnRadius.y, 2)))<UI.ToolBarHeight|| Center.y + (sqrt(pow(Center.x - PointOnRadius.x, 2) + pow(Center.y - PointOnRadius.y, 2))) > UI.height - UI.StatusBarHeight)//Draw Validation
	{
		pManager->GetOutput()->PrintMessage("Error :Can't draw here ");
		return 0;
	}

	//Create a circle with the parameters read from the user
	 F = new CCircle(Center, PointOnRadius, CircGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the cirlce to the list of figures
	pManager->AddFigure(F);
	//display figure`s sound if the sound is enabled
	if (pManager->getEnableSound())          // check if the sound is enabled 
	PlaySound(TEXT("Recordings/circle.wav"), NULL, SND_ASYNC);
	return 1;
}

void AddCircAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Circle Action Undone");
}

void AddCircAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Circle Action Redone");
}
