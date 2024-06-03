#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle() {
	ShapeType = "Triangle";
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo, int ID) :CFigure(FigureGfxInfo)
{
	id = ID;
	vertex1 = P1;
	vertex2 = P2;
	vertex3 = P3;
	ShapeType = "Triangle";
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	if (!Hidden)
	pOut->DrawTri(vertex1, vertex2, vertex3, FigGfxInfo, Selected);
	//PlaySound(TEXT("triangle.wav"), NULL, SND_SYNC);
}


void CTriangle::Save(ofstream& OutFile) {
	OutFile << "TRIANG\t" << id << "\t" << vertex1.x << "\t" << vertex1.y << "\t" << vertex2.x << "\t" << vertex2.y << "\t" << vertex3.x << "\t" << vertex3.y << "\t" << FigGfxInfo.DrawClr << "\t";
	if (FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr << endl;
	else OutFile << "NOFILL" << endl;
}

void CTriangle::Load(ifstream& InFile) {
	InFile >> id >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> &FigGfxInfo.DrawClr >> &FigGfxInfo.FillClr;
	if (FigGfxInfo.FillClr == NOFILL) FigGfxInfo.isFilled = false;
}

bool CTriangle::IsFound(int x, int y)
{
	int intersections = 0;
	int n = 3;
	Point trianglePoints[] = { vertex1, vertex2, vertex3};
	double x1, y1, x2, y2;

	double intersectionPoint;
	for (int i = 0 , j = n-1; i < n; j = i++)
	{
		x1 = trianglePoints[i].x;
		y1= trianglePoints[i].y;

		x2= trianglePoints[j].x;
		y2= trianglePoints[j].y;

		intersectionPoint = x1 + (y - y1) / (y2 - y1) * (x2 - x1);
		if ((y < y1 != y < y2) && x < intersectionPoint)
			intersections++;
	}
	if (intersections % 2 == 1)
		return true;
	return false;
}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure Type : Triangle     Figure ID : " + to_string(id) + "     Vertex1 : " + to_string(vertex1.x) + "," + to_string(vertex1.y) + "     Vertex2: " + to_string(vertex2.x) + "," + to_string(vertex2.y) + "     Vertex3: " + to_string(vertex3.x) + "," + to_string(vertex3.y));

}

bool CTriangle::MoveFigure(int a, int b , Output* pOut)  // a function that modify the center of the selected figure to the new center 
{
	PreviousVertex1 = vertex1;
	PreviousVertex2 = vertex2;
	PreviousVertex3 = vertex3;
	
	// calculate old centroid coordinates
	int c1x = (vertex1.x + vertex2.x + vertex3.x) / 3;
	int c1y = (vertex1.y + vertex2.y + vertex3.y) / 3;
	// new centroid coordinates
	int c2x = a;
	int c2y = b;
	// set vertex1 coordinates
	vertex1.x = vertex1.x + c2x - c1x;
	vertex1.y = vertex1.y + c2y - c1y;
	// set vertex2 coordinates
	vertex2.x = vertex2.x + c2x - c1x;
	vertex2.y = vertex2.y + c2y - c1y;
	// set vertex3 coordinates
	vertex3.x = vertex3.x + c2x - c1x;
	vertex3.y = vertex3.y + c2y - c1y;
	// calculate max and min for x cord and y cord >> needed for validition
	int MaxX = vertex1.x;
	int MaxY = vertex1.y;
	int MinX = vertex1.x;
	int MinY = vertex1.y;
	if (vertex2.x > MaxX)
		MaxX = vertex2.x;
	else if(vertex2.x < MinX)
		MinX = vertex2.x;
	if (vertex3.x > MaxX)
		MaxX = vertex3.x;
	else if (vertex3.x < MinX)
		MinX = vertex3.x;
	if (vertex2.y > MaxY)
		MaxY = vertex2.y;
	else if (vertex2.y < MinY)
		MinY = vertex2.y;
	if (vertex3.y > MaxY)
		MaxY = vertex3.y;
	else if (vertex3.y < MinY)
		MinY = vertex3.y;

	////////Move validation to check the triangle will move to right position//////
	if (MinY <= UI.ToolBarHeight || MaxY >= UI.height - UI.StatusBarHeight || MinX < 0 || MaxX > UI.width)
	{
		pOut->PrintMessage("Error! Can't move the triangle here!! ");
		vertex1 = PreviousVertex1;
		vertex2 = PreviousVertex2;
		vertex3 = PreviousVertex3;
		return 0;
	}
	return 1;
}

void CTriangle::ReturnFigure()
{
	vertex1 = PreviousVertex1;
	vertex2 = PreviousVertex2;
	vertex3 = PreviousVertex3;
}

CTriangle::~CTriangle()
{
}

