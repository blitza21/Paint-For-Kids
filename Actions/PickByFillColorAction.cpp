#include"PickByFillColorAction.h"

PickByFillColorAction::PickByFillColorAction(ApplicationManager* pApp):Action(pApp)
{
	NoOfCorrectPicks = 0;
	NoOfWrongPicks = 0;
	pManager->resetHidden();
	pManager->UpdateInterface();
	restart = 0;
}

void PickByFillColorAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(p.x, p.y);
	if ((p.y <= UI.ToolBarHeight)) {
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

bool PickByFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	srand(time(0));//// This lines to random a shape
	Fill = pManager->getFigFillColor((rand() % pManager->GetFigCount()));//Random a shape idx and get its Fill color to make sure it will not random a shape not drawn
	TypeCount = pManager->getFigFillCount(Fill);
	
		pOut->PrintMessage("Pick By figure fill color : "+ Fill);
	////////////////////////////////////

	do {
		ReadActionParameters();
		if (restart)return 0;
		choosedFig = pManager->GetFigure(p.x, p.y);
		if (choosedFig != NULL) {
			if (Fill == (choosedFig->convertFillColorToString())) {
				NoOfCorrectPicks++;
			}
			else
				NoOfWrongPicks++;

			choosedFig->SetHidden(1);
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
			pOut->PrintMessage("Pick By figure fill color : " + Fill+ "  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
		}

	} while (NoOfCorrectPicks != TypeCount);
	pOut->PrintMessage("Final Grade:  Correct Picks : " + to_string(NoOfCorrectPicks) + "   ""Wrong Picks : " + to_string(NoOfWrongPicks));
}
