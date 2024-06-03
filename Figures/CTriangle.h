#pragma once
#include "CFigure.h"
class CTriangle :
    public CFigure
{
private:
    Point vertex1, PreviousVertex1;
    Point vertex2, PreviousVertex2;
    Point vertex3, PreviousVertex3;
public:
    CTriangle();
    CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo,int ID);

    virtual void Draw(Output* pOut) const;

    virtual void Save(ofstream& OutFile);
    virtual void Load(ifstream& InFile);
    virtual bool IsFound(int x, int y);

    virtual void PrintInfo(Output* pOut);


    virtual bool MoveFigure(int, int, Output*);

    virtual void ReturnFigure();

    virtual ~CTriangle();
};

