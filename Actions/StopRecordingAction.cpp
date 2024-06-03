#include "StopRecordingAction.h"
#include "../ApplicationManager.h"
#include <iostream>

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp) {

}

void StopRecordingAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Recording stopped!");
}

bool StopRecordingAction::Execute() {
	ReadActionParameters();
	pManager->setRecording(false);

	return 1;
}