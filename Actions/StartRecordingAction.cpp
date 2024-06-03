#include "StartRecordingAction.h"
#include "../ApplicationManager.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp) {

}

void StartRecordingAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Started Recording!");
}

bool StartRecordingAction::Execute() 
{
	ReadActionParameters();
	pManager->setRecording(true);
	Output* pOut = pManager->GetOutput();
	int FigCount = pManager->GetFigCount();
	if (!RecordCount || FigCount) {
		pOut->PrintMessage("Error! Can only record after a clear all or at the start of the program.");
		pManager->setRecording(false);
		return 0;
	}
}

void StartRecordingAction::Record() 
{
	image* recordList = pManager->GetRecordingList();
	image img;
	Output* pOut = pManager->GetOutput();
	RecordCount = pManager->GetRecordCount();
	pOut->screenshotWindow(img);	
	recordList[RecordCount++] = img;	// Adds the screenshotted image to the record list
}