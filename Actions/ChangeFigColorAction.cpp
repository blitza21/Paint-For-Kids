#include "ChangeFigColorAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFigColorAction::ChangeFigColorAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChangeFigColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Draw Color");

	switch (pIn->GetcolorAction(pOut->colorpalette())) //Get Selected Color from pallete
	{
	case CHOOSE_COLOR_RED:
		UI.DrawColor =  RED;
		pOut->PrintMessage("Selected Color : RED ");
		break;
	case CHOOSE_COLOR_BLUE:
		UI.DrawColor = BLUE;
		pOut->PrintMessage("Selected Color : BLUE");
		break;
	case CHOOSE_COLOR_GREEN:
		UI.DrawColor = GREEN;
		pOut->PrintMessage("Selected Color : GREEN ");
		break;
	case CHOOSE_COLOR_ORANGE:
		UI.DrawColor = ORANGE;
		pOut->PrintMessage("Selected Color : ORANGE ");
		break;
	case CHOOSE_COLOR_YELLOW:
		UI.DrawColor = YELLOW;
		pOut->PrintMessage("Selected Color : YELLOW ");
		break;
	case CHOOSE_COLOR_BLACK:
		UI.DrawColor = BLACK;
		pOut->PrintMessage("Selected Color : BLACK ");
		break;
	}

	RedoColor = UI.DrawColor;
	pOut->closeColorMenu();

}

bool ChangeFigColorAction::Execute()
{
	SelectedFig = pManager->GetSelectedFig();
	
	if (SelectedFig == NULL)
		return 0;

	UndoColor = SelectedFig->GetDrawClr();
	Previous_UI_Draw_Color = UI.DrawColor;
	ReadActionParameters();//This action needs to read some parameters first

	SelectedFig->ChngDrawClr(UI.DrawColor);
	SelectedFig->SetSelected(0);
	pManager->SetSelectedFig(NULL);

	return 1;
}

void ChangeFigColorAction::UndoExecution()
{

	SelectedFig->ChngDrawClr(UndoColor);	// Changes the fig draw color to the previous color

	UI.DrawColor = Previous_UI_Draw_Color;	// Changes the UI.draw color to the previous one

	pManager->GetOutput()->PrintMessage("Change Draw Color Action Undone");
}


void ChangeFigColorAction::RedoExecution()
{

	SelectedFig->ChngDrawClr(RedoColor);	// Reverts the fig draw color
	SelectedFig->SetSelected(0);

	UI.DrawColor = RedoColor;				// Reverts the UI.draw color

	pManager->GetOutput()->PrintMessage("Change Draw Color Action Redone");
}
