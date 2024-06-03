#include "CCircle.h"
#include <fstream>
#include <iostream>

using namespace std;

CCircle::CCircle() {
	ShapeType = "Circle";
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Center =  P1;
	PointOnRadius = P2;
	ShapeType = "Circle";
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	if(!Hidden)
	pOut->DrawCirc(Center, PointOnRadius, FigGfxInfo, Selected);

}

void CCircle::Save(ofstream& OutFile) {
	OutFile << "CIRCLE\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << PointOnRadius.x << "\t" << PointOnRadius.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CCircle::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> PointOnRadius.x >> PointOnRadius.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == NOFILL) FigGfxInfo.isFilled = false;
}

bool CCircle::IsFound(int x, int y)
{
	int Radius = CalcRadius();

	int distanceFromCenter = sqrt(pow(x - Center.x, 2) + pow(y - Center.y, 2));

	if (distanceFromCenter <= Radius)
		return 1;
	return 0;
}

void CCircle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Circle     Figure ID : " + to_string(id) + "     Center : " + to_string(Center.x) + "," + to_string(Center.y) + "     Radius = " + to_string(CalcRadius()));

}

int CCircle::CalcRadius()
{
	int Radius = sqrt(pow(PointOnRadius.x - Center.x, 2) + pow(PointOnRadius.y - Center.y, 2));
	return Radius;
}


bool CCircle::MoveFigure(int a, int b , Output* pOut)  // a function that modify the center of the selected figure to the new center 
{
	PreviousCenter = Center;
	PreviousPointOnRadius = PointOnRadius;


	// calculate the radius of the circle
	int Radius = CalcRadius();
	// set the old center to the new center 
	Center.x = a;
	Center.y = b;
	// set the old radius to the new radius
	PointOnRadius.x = Center.x;
	PointOnRadius.y = Center.y + Radius;

	////////Move validation to check the circle will move to right position//////
	if (Center.y - Radius <= UI.ToolBarHeight || Center.y + Radius >= UI.height - UI.StatusBarHeight || Center.x - Radius < 0 || Center.x + Radius > UI.width)
	{
		pOut->PrintMessage("Error! Can't move the circle here!! ");
		Center = PreviousCenter;
		PointOnRadius = PreviousPointOnRadius;
		return 0;
	}
	return 1;
}

void CCircle::ReturnFigure()
{
	Center = PreviousCenter;
	PointOnRadius = PreviousPointOnRadius;
}

CCircle::~CCircle()
{
}
