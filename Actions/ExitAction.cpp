#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
ExitAction::ExitAction(ApplicationManager* pApp):Action(pApp)
{
}
bool ExitAction::Execute()
{
	return 1;
}

