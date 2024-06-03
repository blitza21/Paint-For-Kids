#include "Output.h"
#include "Input.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 50;
	UI.wy = 50;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 45;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.IsFilled = false;
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[CHANGE_DRAW_COLOR] = "images\\MenuItems\\drawing color.jpg";
	MenuItemImages[CHANGE_FILL_COLOR] = "images\\MenuItems\\filling color.jpg";
	MenuItemImages[DELETE_FIGURE] = "images\\MenuItems\\delete figure.jpg";
	MenuItemImages[MOVE] = "images\\MenuItems\\move figure.jpg";
	MenuItemImages[UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[CLEAR_ALL] = "images\\MenuItems\\clear all.jpg";
	MenuItemImages[START_RECORDING] = "images\\MenuItems\\start recording.jpg";
	MenuItemImages[STOP_RECORDING] = "images\\MenuItems\\stop recording.jpg";
	MenuItemImages[PLAY_RECORDING] = "images\\MenuItems\\play recording.jpg";
	MenuItemImages[SAVE_GRAPH] = "images\\MenuItems\\save graph.jpg";
	MenuItemImages[LOAD_GRAPH] = "images\\MenuItems\\load graph.jpg";
	MenuItemImages[SWITCH_PLAY] = "images\\MenuItems\\switch to play mode.jpg";
	MenuItemImages[SOUND] = "images\\MenuItems\\sound.jpg";
	MenuItemImages[EXIT] = "images\\MenuItems\\exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time


	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], UI.MenuItemWidth * i + 10 * i, 0, UI.MenuItemWidth, UI.ToolBarHeight - 5);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

window* Output::colorpalette() {
	int menulength = 310;
	int menuwidth = 60;
	int iconwidth = 40;
	int iconlength = 40;
	colorp = new window(menulength, menuwidth, 350, 140);
	colorp->ChangeTitle("Choose Color");

	string Menucolor[COLOR_ITM_COUNT];
	Menucolor[COLOR_RED] = "images\\MenuItems\\red.jpg";
	Menucolor[COLOR_BLUE] = "images\\MenuItems\\blue.jpg";
	Menucolor[COLOR_GREEN] = "images\\MenuItems\\green.jpg";
	Menucolor[COLOR_ORANGE] = "images\\MenuItems\\orange.jpg";
	Menucolor[COLOR_YELLOW] = "images\\MenuItems\\yellow.jpg";
	Menucolor[COLOR_BLACK] = "images\\MenuItems\\black.jpg";
	colorp->SetPen(WHITE, 1);
	colorp->SetBrush(WHITE);
	colorp->DrawRectangle(0, menuwidth, menuwidth, menulength);

	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		colorp->DrawImage(Menucolor[i], i * iconlength + 10 * i, 0, iconlength, iconwidth);
	return colorp;

}

void Output::closeColorMenu() {
	delete colorp;
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::screenshotWindow(image& img) {
	pWind->StoreImage(img, 0, 0, 1250, 600);
}

void Output::redrawWindow(image img) {
	pWind->DrawImage(img, 0, 0, 1250, 600);
}

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[FIG_TYPE] = "images\\MenuItems\\figure type.jpg"; \
		MenuItemImages[FIG_FILL_COLOR] = "images\\MenuItems\\figures fill color.jpg";
	MenuItemImages[FIG_TYPE_AND_FILL_COLOR] = "images\\MenuItems\\figures type and color.jpg";
	MenuItemImages[SWITCH_DRAW] = "images\\MenuItems\\switch to draw mode.jpg";
	MenuItemImages[EXITT] = "images\\MenuItems\\exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth + 10 * i, 0, UI.MenuItemWidth, UI.ToolBarHeight - 5);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

bool Output::getCrntFillStatus() const
{
	return UI.IsFilled;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(const Point P1,const Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}

void Output::DrawSqr(const Point& P1, GfxInfo SqrGfxInfo, bool selected) const
{
	int Dim = 75;
	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;


		int x[4] = { P1.x - Dim,P1.x + Dim, P1.x + Dim,P1.x - Dim };//x cord.

		int y[4] = { P1.y + Dim,P1.y + Dim, P1.y - Dim,P1.y - Dim };//y cord.

	pWind->DrawPolygon(x, y, 4, style);

}

void Output::DrawTri(const Point& P1, const Point& P2, const Point& P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}



void Output::DrawHex(const Point& P1, GfxInfo HexGfxInfo, bool selected) const
{
	
	int dim3 = 100;//length hexagon side
	int dim1 = (dim3/2)*sqrt(3);//distance from center to any vertex
	int dim2 = dim3/2;//perp. distance from center to sides
	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;


	int x[6] = { P1.x,       P1.x + dim1,   P1.x + dim1,    P1.x ,      P1.x - dim1 ,  P1.x - dim1 };//x cord.

	int y[6] = { P1.y + dim3, P1.y + dim2,   P1.y - dim2 ,   P1.y - dim3 ,P1.y - dim2 ,  P1.y + dim2 };//y cord.

	pWind->DrawPolygon(x, y ,6, style);
}

void Output::DrawCirc(const Point& P1, const Point& P2, GfxInfo CircGfxInfo, bool selected) const
{
	int Radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
		
	pWind->DrawCircle(P1.x, P1.y, Radius, style);
}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

