#include "CFigure.h"

CFigure::CFigure() {
	Selected = false;
	Hidden = 0;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Hidden = 0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
		FigGfxInfo.FillClr = Fclr;
}

void CFigure::ChngFillState(bool state)
{
	FigGfxInfo.isFilled = state;
}

color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

bool CFigure::GetFillState()
{
	return FigGfxInfo.isFilled;
}


string CFigure::convertFillColorToString() const {

	if(!FigGfxInfo.isFilled) return"NO FILL";
	if (FigGfxInfo.FillClr == BLUE) return "BLUE";
	else if (FigGfxInfo.FillClr == GREEN) return "GREEN";
	else if (FigGfxInfo.FillClr == RED) return "RED";
	else if (FigGfxInfo.FillClr == YELLOW) return "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE) return "ORANGE";
    if (FigGfxInfo.FillClr == BLACK) return "BLACK";
}
void CFigure::SetHidden(bool x)
{
	Hidden = x;
}

bool CFigure::IsHidden()
{
	return Hidden;
}

string CFigure::getShapeType()
{
	return ShapeType;
}

CFigure::~CFigure()
{
}
