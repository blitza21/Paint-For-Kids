#include "CSquare.h"
#include <fstream>
#include<conio.h>

CSquare::CSquare() {
	ShapeType = "Square";
}

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Center = P;
	ShapeType = "Square";
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on the screen
	if (!Hidden)
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
	
}

void CSquare::Save(ofstream& OutFile) {
	OutFile << "SQUARE\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CSquare::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == NOFILL) FigGfxInfo.isFilled = false;
}

bool CSquare::IsFound(int x, int y)
{
	if (abs(x-Center.x) <=75 && abs(y-Center.y) <=75)
		return 1;
	return 0;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Square     Figure ID : " + to_string(id) + "     Center : " + to_string(Center.x) + "," + to_string(Center.y));
}


bool CSquare::MoveFigure(int a, int b , Output* pOut)  // a function that modify the center of the selected figure to the new center 
{
	PreviousCenter = Center;
	Center.x = a;
	Center.y = b;

	////////Move validation to check the square will move to right position//////
	if (Center.y - 100 <= UI.ToolBarHeight || Center.y + 100 >= UI.height - UI.StatusBarHeight || Center.x - 100 < 0 || Center.x + 100 > UI.width)
	{
		pOut->PrintMessage("Error! Can't move the square here!! ");
		Center = PreviousCenter;
		return 0;
	}
	return 1;
}

void CSquare::ReturnFigure()
{
	Center = PreviousCenter;
}

CSquare::~CSquare()
{
	PlaySound(0, 0, 0);
}

