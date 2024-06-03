#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	DRAW_CIRCLE,

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode

	TO_SELECT,		//select one of the figures
	TO_CHANGE_DRAW_COLOR, // change drawing color
	TO_CHANGE_FILL_COLOR,	// change fill color
	CHOOSE_COLOR_RED,		// choose red color
	CHOOSE_COLOR_BLUE,		// choose blue color
	CHOOSE_COLOR_GREEN,		// choose green color
	CHOOSE_COLOR_ORANGE,	// choose orange color
	CHOOSE_COLOR_YELLOW,	// choose yellow color
	CHOOSE_COLOR_BLACK,		// choose black color

	TO_DELETE,				// delete selected figure
	TO_MOVE,				// move selected figure
	TO_UNDO,				// undo the last performed operation
	TO_REDO,				// redo the undone operation
	TO_CLEAR_ALL,			// clears all actions
	TO_START_RECORDING,		// starts recording all user actions
	TO_STOP_RECORDING,		// stops recording
	TO_PLAY_RECORDING,		// plays recording
	TO_SAVE_GRAPH,			// saves the information of the drawn graph to a file
	TO_LOAD_GRAPH,			// load an existing graph



	PICK_FIG_TYPE,
	PICK_FIG_FILL_COLOR,
	PICK_FIG_TYPE_AND_FILL_COLOR,

	TO_SOUND,
	TO_EXIT,			//Exit
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif