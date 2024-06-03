#include "SaveAction.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <iostream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) {

}

void SaveAction::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file you want to save in: " + filename);


	filename = pIn->GetString(pOut);	//Get Filename from the user
	pOut->ClearStatusBar();
}

bool SaveAction::Execute() 
{
	ReadActionParameters();

	ofstream OutFile;
	OutFile.open("Saved Data/"+filename+".txt");
	if(OutFile.fail())
	{ 
		pManager->GetOutput()->PrintMessage("An error has occured! Please try again!");		//Just in case an error occurs
		return 0;
	}

	OutFile << UI.DrawColor << "\t" << UI.FillColor << endl;	//Saving the draw color and fill color

	pManager->SaveAll(OutFile);									// Application manager saves all figures
	pManager->GetOutput()->PrintMessage("Your file has been saved successfully!");
	OutFile.close();
}