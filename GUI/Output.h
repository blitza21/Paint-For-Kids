#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	window* colorp;
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	window* colorpalette();      //create color palette
	void closeColorMenu();

	void screenshotWindow(image&);	//Saves the current window as an image
	void redrawWindow(image);		// Draws the saved image
		
	//void CreateColorToolBar() const; //creates Color mode toolbar & menu

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(const Point P1, const Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle

	void DrawSqr(const Point& P1, GfxInfo SqrGfxInfo, bool selected = false) const;//Draw a square


	void DrawTri(const Point& P1, const Point& P2, const Point& P3, GfxInfo TriGfxInfo, bool selected = false) const; //Draw a triangle


	void DrawHex(const Point& P1, GfxInfo HexGfxInfo, bool selected = false) const;//Draw a hexagon

	void DrawCirc(const Point& P1, const Point& P2, GfxInfo CircGfxInfo, bool selected = false) const; //Draw a circle

	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	bool getCrntFillStatus() const;


	~Output();
};

#endif