#pragma once
#include "CFigure.h"
class CHexagon :
    public CFigure
{
private:
    Point Center , PreviousCenter;
    Point Vertex1, Vertex2, Vertex3, Vertex4, Vertex5, Vertex6;
public:
    CHexagon();
    CHexagon(Point, GfxInfo FigureGfxInfo, int ID);
    virtual void Draw(Output* pOut) const;
    virtual void Save(ofstream& OutFile);
    virtual void Load(ifstream& InFile);
    virtual bool IsFound(int x, int y);

    virtual void PrintInfo(Output* pOut);


    virtual bool MoveFigure(int, int, Output*);
    virtual void ReturnFigure();
    virtual ~CHexagon();
};

