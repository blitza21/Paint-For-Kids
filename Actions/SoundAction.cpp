#include "SoundAction.h"

SoundAction::SoundAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SoundAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getEnableSound())
	{
		pOut->PrintMessage("Sound has been disabled");
		Sleep(1500);
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage("Sound has been enabled");
		Sleep(1500);
		pOut->ClearStatusBar();
	}
}

bool SoundAction::Execute()
{
	ReadActionParameters();

	pManager->setEnableSound(!pManager->getEnableSound());
	return 1;
}
