#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->FlushKeyQueue();
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output* pO) const
{
	pWind->FlushKeyQueue();
	pWind->FlushMouseQueue();
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / (UI.MenuItemWidth + 10));
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case SELECT:return TO_SELECT;
			case CHANGE_DRAW_COLOR: return TO_CHANGE_DRAW_COLOR;
			case CHANGE_FILL_COLOR: return TO_CHANGE_FILL_COLOR;
			case DELETE_FIGURE: return TO_DELETE;
			case MOVE: return TO_MOVE;
			case UNDO: return TO_UNDO;
			case REDO: return TO_REDO;
			case CLEAR_ALL: return TO_CLEAR_ALL;
			case START_RECORDING: return TO_START_RECORDING;
			case STOP_RECORDING: return TO_STOP_RECORDING;
			case PLAY_RECORDING: return TO_PLAY_RECORDING;
			case SAVE_GRAPH: return TO_SAVE_GRAPH;
			case LOAD_GRAPH: return TO_LOAD_GRAPH;
			case SWITCH_PLAY: return TO_PLAY;
			case SOUND: return TO_SOUND;
			case EXIT: return TO_EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight) 
		{

			int ClickedItemOrder = (x / (UI.MenuItemWidth + 10));
			switch (ClickedItemOrder) {
			case FIG_TYPE: return PICK_FIG_TYPE;
			case FIG_FILL_COLOR: return PICK_FIG_FILL_COLOR;
			case FIG_TYPE_AND_FILL_COLOR: return PICK_FIG_TYPE_AND_FILL_COLOR;
			case SWITCH_DRAW: return TO_DRAW;
			case EXITT: return TO_EXIT;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}

}
ActionType Input::GetcolorAction(window* colorp) const
{
	Point p;
	colorp->WaitMouseClick(p.x, p.y);

	int ClickedItemOrder = p.x / (50);

	switch (ClickedItemOrder) {
	case COLOR_RED: return CHOOSE_COLOR_RED;
	case COLOR_BLUE: return CHOOSE_COLOR_BLUE;
	case COLOR_GREEN: return CHOOSE_COLOR_GREEN;
	case COLOR_ORANGE: return CHOOSE_COLOR_ORANGE;
	case COLOR_YELLOW: return CHOOSE_COLOR_YELLOW;
	case COLOR_BLACK: return CHOOSE_COLOR_BLACK;
	default: return EMPTY;
	}
}
/////////////////////////////////

Input::~Input()
{
}
