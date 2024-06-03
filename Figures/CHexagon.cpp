#include "CHexagon.h"
#include <fstream>


CHexagon::CHexagon() {
	ShapeType = "Hexagon";
}

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo, int ID):CFigure(FigureGfxInfo)
{
	id = ID;
	Center = P;
	ShapeType = "Hexagon";
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen
	if (!Hidden)
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& OutFile) {
	OutFile << "HEX\t" << id << "\t" << Center.x << "\t" << Center.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CHexagon::Load(ifstream& InFile) {
	InFile >> id >> Center.x >> Center.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == NOFILL) FigGfxInfo.isFilled = false;
}

bool CHexagon::IsFound(int x, int y)
{
	int p[6] = { Center.x,       Center.x + 87,   Center.x + 87,    Center.x ,       Center.x - 87 ,  Center.x - 87 };//x cord.

	int a[6] = { Center.y + 100, Center.y + 50,   Center.y - 50 ,   Center.y - 100 , Center.y - 50 ,  Center.y + 50 };//y cord.


	Point HexagonPoints[] = { Vertex1, Vertex2, Vertex3, Vertex4, Vertex5, Vertex6 };
	for (int i = 0; i < 6; i++)
	{
		HexagonPoints[i].x = p[i];
		HexagonPoints[i].y = a[i];
	}
	int intersections = 0;
	int n = 6;
	
	double x1, y1, x2, y2;

	double intersectionPoint;
	for (int i = 0, j = n - 1; i < n; j = i++)
	{
		x1 = HexagonPoints[i].x;
		y1 = HexagonPoints[i].y;

		x2 = HexagonPoints[j].x;
		y2 = HexagonPoints[j].y;

		intersectionPoint = x1 + (y - y1) / (y2 - y1) * (x2 - x1);
		if ((y < y1 != y < y2) && x < intersectionPoint)
			intersections++;
	}
	if (intersections % 2 == 1)
		return true;
	return false;
}

void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Hexagon     Figure ID : " + to_string(id) + "     Center : " + to_string(Center.x) + "," + to_string(Center.y) );

}


bool CHexagon::MoveFigure(int a, int b , Output* pOut)  // a function that modify the center of the selected figure to the new center 
{
	PreviousCenter = Center;
	Center.x = a;
	Center.y = b;

	////////Move validation to check the hexagon will move to right position//////
	if (Center.y - 100 <= UI.ToolBarHeight || Center.y + 100 >= UI.height - UI.StatusBarHeight || Center.x - 87 < 0 || Center.x + 87 > UI.width)
	{
		pOut->PrintMessage("Error! Can't move the hexagon here!! ");
		Center = PreviousCenter;
		return 0;
	}
	return 1;

}
void CHexagon::ReturnFigure()
{
	Center = PreviousCenter;
}
CHexagon::~CHexagon()
{
}
