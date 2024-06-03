#pragma once

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int id;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphics info
	bool Hidden;	// true if the figure is hidden
	string ShapeType;	//stores the figure type

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	// select/unselect the figure

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//Changes the figure's drawing color
	void ChngFillClr(color Fclr);	//Changes the figure's filling color
	void ChngFillState(bool state); //Changes the figure's fill state
	color GetDrawClr();				//Getter for the drawing color
	color GetFillClr();				//Getter for the fill color
	bool GetFillState();			//Getter for the fill state

	virtual void PrintInfo(Output* pOut) = 0 ;	//print all figure info on the status bar

	virtual bool IsFound(int x, int y) = 0;		//Checks wheter the point selected is inside a drawn figure


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	string convertFillColorToString() const;	//Converts the fill color to a string
	void SetHidden(bool x);	
	bool IsHidden();
	string getShapeType();

	virtual bool MoveFigure(int, int , Output*) = 0;
	virtual void ReturnFigure() {};			//needed for undo operation

	virtual ~CFigure() = 0;

};
