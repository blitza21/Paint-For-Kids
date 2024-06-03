#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class PickByFillColorAction :
    public Action
{
    Point p;
    int NoOfCorrectPicks;
    int NoOfWrongPicks;
    string Fill;
    CFigure* choosedFig;
    int TypeCount;//No of this Type in Application manager array;
    bool restart;


public:
    PickByFillColorAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual bool Execute();
};

