/* 
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#include "colors.h"

bool operator==(color a, color b) {

  return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

  return !(a == b);
  
}

ostream& operator << (ostream& output, color a) {
	if (a.ucRed == 255 && a.ucBlue == 0 && a.ucGreen == 0) return output << "RED";
	else if (a.ucRed == 0 && a.ucBlue == 255 && a.ucGreen == 0) return output << "BLUE";
	else if (a.ucRed == 0 && a.ucBlue == 0 && a.ucGreen == 255) return output << "GREEN";
	else if (a.ucRed == 0 && a.ucBlue == 0 && a.ucGreen == 0) return output << "BLACK";
	else if (a.ucRed == 255 && a.ucBlue == 0 && a.ucGreen == 255) return output << "YELLOW";
	else if (a.ucRed == 255 && a.ucBlue == 0 && a.ucGreen == 165) return output << "ORANGE";
}

istream& operator >> (istream& input, color* a) {
	string clr;
	input >> clr;
	if (clr == "RED") {
		a->ucRed = 255; a->ucBlue = 0; a->ucGreen = 0;
	}
	else if (clr == "BLUE") {
		a->ucRed = 0; a->ucBlue = 255; a->ucGreen = 0;
	}
	else if (clr == "GREEN") {
		a->ucRed = 0; a->ucBlue = 0; a->ucGreen = 255;
	}
	else if (clr == "BLACK") {
		a->ucRed = 0; a->ucBlue = 0; a->ucGreen = 0;
	}
	else if (clr == "YELLOW") {
		a->ucRed = 255; a->ucBlue = 0; a->ucGreen = 255;
	}
	else if (clr == "ORANGE") {
		a->ucRed = 255; a->ucBlue = 0; a->ucGreen = 165;
	}
	else if (clr == "NOFILL") {
		a->ucRed = -1; a->ucBlue = -1; a->ucGreen = -1;
	}
	return input;
}

