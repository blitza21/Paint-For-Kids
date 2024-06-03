#include "AddTriAction.h"
#include"../Figures/CTriangle.h"
#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"
#include<Windows.h>
#include<MMSystem.h>
AddTriAction::AddTriAction(ApplicationManager* pApp):AddFigureAction(pApp)
{
}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first Vertex");

	//Read 1st Vertex and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second Vertex");

	//Read 2nd Vertex and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third Vertex");

	//Read 3rd Vertex and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.isFilled = pOut->getCrntFillStatus();


	pOut->ClearStatusBar();

}
bool AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (P1.y <= UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P2.y <= UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P3.y <= UI.ToolBarHeight || P3.y > UI.height - UI.StatusBarHeight) //Draw validation
	{
		pManager->GetOutput()->PrintMessage("Error :Can't draw here ");
		return 0;
	}
	

	//Create a Triangle with the parameters read from the user
	F = new CTriangle(P1, P2,P3, TriGfxInfo, (pManager->GetFigCount()) + 1);

	//Add the Triangle to the list of figures
	pManager->AddFigure(F);
	//display figure`s sound if the sound is enabled
	if (pManager->getEnableSound())             // check if the sound is enabled 
	PlaySound(TEXT("Recordings/triangle.wav"), NULL, SND_ASYNC);
	return 1;
}

void AddTriAction::UndoExecution()
{
	AddFigureAction::UndoExecution();
	pManager->GetOutput()->PrintMessage("Draw Triangle Action Undone");
}

void AddTriAction::RedoExecution()
{
	AddFigureAction::RedoExecution();
	pManager->GetOutput()->PrintMessage("Draw Triangle Action Redone");
}
