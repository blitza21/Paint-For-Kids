#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxActions = 100 };	//Max no of figures , Max no of Actions

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure


	Action* UndoList[MaxActions];		//List of all actions (Array of pointers)
	int ActionsToUndoCount;					//Actual number of actions
	
	bool isRecording;
	image RecordingList[20];
	int RecordCount;

	bool EnableSound;


	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	
	

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int GetFigCount();						// Getter for figure count


	// -- Deleting Figures
	void DeleteFigure(CFigure* pFig);
	void DeleteAllFigures();



	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window



	// -- Play mode Functions
	void resetHidden();
	int getFigFillCount(string x);
	string getFigFillColor(int I);
	string getFigType(int I);
	int getFigCountByFillAndType(string Type, string fill);
	int GetTypeCount(string P);

	// -- Undo & Redo Functions
	Action** GetUndoList();		// Getter for undo list
	int& GetActionsToUndoCount();			// Getter for number of actions that can be undone 
	bool CheckUndoCondition(ActionType action); // checks whether the action is an undo/redo action

	// -- Select Functions
	void SetSelectedFig(CFigure*);			// Setter for Selected Figure
	CFigure* GetSelectedFig();				// Getter for Selected Figure
	

	// -- Recording Functions
	image* GetRecordingList();
	int& GetRecordCount();
	void setRecording(bool);
	bool IsRecording();
	bool CheckRecordCondition(ActionType);

	// -- Save Function
	void SaveAll(ofstream& OutFile); // saves all figures in the figlist

	// -- Sound Functions (Bonus)
	bool getEnableSound();
	void setEnableSound(bool s);

};
#endif