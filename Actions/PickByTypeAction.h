#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class PickByTypeAction :
    public Action
{
    Point p;//
    int NoOfCorrectPicks;
    int NoOfWrongPicks;
    string FigureType;//Fgure Type To Pick
    CFigure* choosedFig;
    int TypeCount;//No of this Type in Application manager Figlist;
    bool restart;//Condition for Is the game closed while playing or not


public:
    PickByTypeAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual bool Execute();
};