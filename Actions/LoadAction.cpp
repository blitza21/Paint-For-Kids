#include "LoadAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CSquare.h"
#include <fstream>
#include <iostream>
#include "ClearAllAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{

}

void LoadAction::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file you want to load from: " + filename);


	filename = pIn->GetString(pOut);	//Get the filename from the user
	pOut->ClearStatusBar();
	
}

bool LoadAction::Execute()
{
	ReadActionParameters();

	Action* ClearAction = new ClearAllAction(pManager);		//Clearing 
	ClearAction->Execute();									// everything
	delete ClearAction;										// before
	ClearAction = NULL;										// loading

	int num;	// number of figures
	ifstream InFile;
	InFile.open("Saved Data/" + filename + ".txt");
	if (InFile.fail())
	{ 
		pManager->GetOutput()->PrintMessage("No such file to load. Enter a valid file!");		//File not found
		return 0;
	}
	InFile >> &UI.DrawColor >> &UI.FillColor >> num;
	while (num--) {
		string shape;	// Figure type
		CFigure* fig;	
		InFile >> shape;
		if (shape == "RECT") fig = new CRectangle;
		else if (shape == "SQUARE") fig = new CSquare;
		else if (shape == "TRIANG") fig = new CTriangle;
		else if (shape == "HEX") fig = new CHexagon;
		else  fig = new CCircle;
		fig->Load(InFile);	// Every Figure loads itself
		pManager->AddFigure(fig);	// Adding the figure to figlist
	}
}