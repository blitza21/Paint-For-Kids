#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<stdlib.h>
#include<Windows.h>
#include<cstring>

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp) :Action(pApp)
{
	NoOfCorrectPicks = 0;
	NoOfWrongPicks = 0;
	pManager->resetHidden();
	pManager->UpdateInterface();
	restart = false;
}

void PickByTypeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(p.x, p.y);
	if ((p.y<=UI.ToolBarHeight)) {
		switch (p.x / (UI.MenuItemWidth + 10)) {
		case FIG_TYPE:
			pManager->ExecuteAction(PICK_FIG_TYPE);
			break;
		case FIG_FILL_COLOR:
			pManager->ExecuteAction(PICK_FIG_FILL_COLOR);
			break;
		case FIG_TYPE_AND_FILL_COLOR:
			pManager->ExecuteAction(PICK_FIG_TYPE_AND_FILL_COLOR);
			break;
		case SWITCH_DRAW:
			pManager->ExecuteAction(TO_DRAW);
			break;

		}
		restart = true;
	}
}
bool PickByTypeAction::Execute() {
	Output* pOut = pManager->GetOutput();
		srand(time(0));//// This lines to random a shape
		FigureType = pManager->getFigType((rand() % pManager->GetFigCount()));//Random a shape idx and get its Type to make sure it will no random a shape not drawn
		
	pOut->PrintMessage("Pick By figure type : "+ FigureType);
	////////////////////////////////////
	TypeCount = pManager->GetTypeCount(FigureType);

	do {
		ReadActionParameters();
		if (restart)return 0;//Close Current game if i choose another
		choosedFig = pManager->GetFigure(p.x, p.y);

		if (choosedFig != NULL) {
			if (FigureType == (choosedFig->getShapeType())) {
				NoOfCorrectPicks++;
			}
			else
				NoOfWrongPicks++;

			choosedFig->SetHidden(1);//Hide the Shape Picked
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
			pOut->PrintMessage("Pick By figure type : " + FigureType+ "  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
		}

	} while (NoOfCorrectPicks != TypeCount);
	pOut->PrintMessage( "Final Grade:  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
}
	
