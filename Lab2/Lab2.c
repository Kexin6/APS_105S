#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	//Declare different variables using char and double
	double band1, band2, multiplier;
	double answer;
	char *multiplierUnit =""; char *tolerance ="";
	char *resistor1 = ""; char *resistor2 = ""; char *resistor3 = ""; char *resistor4 = "";
	char cBand1, cBand2, cMultiplier, cTolerance;
	
	//Ask the user to input the 1st, 2nd, multiplier, and tolerance bands
	printf ("Please enter the 1st band:\n");
	scanf (" %c", &cBand1);
	printf ("Please enter the 2nd band:\n");
	scanf (" %c", &cBand2);
	printf ("Please enter the multiplier band:\n");
	scanf (" %c", &cMultiplier);
	printf ("Please enter the tolerance band:\n");
	scanf (" %c", &cTolerance);
	
	//Compare the user's input with the output of 1st band and its color
	if (cBand1 == 'K' || cBand1 == 'k'){
		resistor1 = "Black";
		band1 = 0;
	} else if (cBand1 == 'B' || cBand1 == 'b') {
		resistor1 = "Brown";
		band1 = 1;
	} else if (cBand1 == 'R' || cBand1 == 'r') {
		resistor1 = "Red";
		band1 = 2;
	} else if (cBand1 == 'O' || cBand1 == 'o') {
		resistor1 = "Orange";
		band1 = 3;
	} else if (cBand1 == 'E' || cBand1 == 'e') {
		resistor1 = "Yellow";
		band1 = 4;
	} else if (cBand1 == 'G' || cBand1 == 'g') {
		resistor1 = "Green";
		band1 = 5;
	} else if (cBand1 == 'U' || cBand1 == 'u') {
		resistor1 = "Blue";
		band1 = 6;
	} else if (cBand1 == 'V' || cBand1 == 'v') {
		resistor1 = "Violet";
		band1 = 7;
	} else if (cBand1 == 'Y' || cBand1 == 'y') {
		resistor1 = "Grey";
		band1 = 8;
	} else if (cBand1 == 'W' || cBand1 == 'w') {
		resistor1 = "White";
		band1 = 9;
	}
	
	//Compare the user's input with the output of 2nd band and its color
	if (cBand2 == 'K' || cBand2 == 'k') {
		resistor2 = "Black";
		band2 = 0;
	} else if (cBand2 == 'B' || cBand2 == 'b') {
		resistor2 = "Brown";
		band2 = 1;
	} else if (cBand2 == 'R' || cBand2 == 'r') {
		resistor2 = "Red";
		band2 = 2;
	} else if (cBand2 == 'O' || cBand2 == 'o') {
		resistor2 = "Orange";
		band2 = 3;
	} else if (cBand2 == 'E' || cBand2 == 'e') {
		resistor2 = "Yellow";
		band2 = 4;
	} else if (cBand2 == 'G' || cBand2 == 'g') {
		resistor2 = "Green";
		band2 = 5;
	} else if (cBand2 == 'U' || cBand2 == 'u') {
		resistor2 = "Blue";
		band2 = 6;
	} else if (cBand2 == 'V' || cBand2 == 'v') {
		resistor2 = "Violet";
		band2 = 7;
	} else if (cBand2 == 'Y' || cBand2 == 'y') {
		resistor2 = "Grey";
		band2 = 8;
	} else if (cBand2 == 'W' || cBand2 == 'w') {
		resistor2 = "White";
		band2 = 9;
	}
	
	//Compare the user's input with the output of multiplier band and its color
	if (cMultiplier == 'K' || cMultiplier == 'k') {
		resistor3 = "Black";
		multiplier = 1;
		multiplierUnit = "Ohms";
	} else if (cMultiplier == 'B' || cMultiplier == 'b') {
		resistor3 = "Brown";
		multiplier = 10;
		multiplierUnit = "Ohms";
	} else if (cMultiplier == 'R' || cMultiplier == 'r') {
		resistor3 = "Red";
		multiplier = 100;
		multiplierUnit = "Ohms";
	} else if (cMultiplier == 'O' || cMultiplier == 'o') {
		resistor3 = "Orange";
		multiplier = 1;
		multiplierUnit = "KOhms";
	} else if (cMultiplier == 'E' || cMultiplier == 'e') {
		resistor3 = "Yellow";
		multiplier = 10;
		multiplierUnit = "KOhms";
	} else if (cMultiplier == 'G' || cMultiplier == 'g') {
		resistor3 = "Green";
		multiplier = 100;
		multiplierUnit = "KOhms";
	} else if (cMultiplier == 'U' || cMultiplier == 'u') {
		resistor3 = "Blue";
		multiplier = 1;
		multiplierUnit = "MOhms";
	} else if (cMultiplier == 'V' || cMultiplier == 'v') {
		resistor3 = "Violet";
		multiplier = 10;
		multiplierUnit = "MOhms";
	} else if (cMultiplier == 'L' || cMultiplier == 'l') {
		resistor3 = "Gold";
		multiplier = 0.1;
		multiplierUnit = "Ohms";
	} else if (cMultiplier == 'S' || cMultiplier == 's') {
		resistor3 = "Silver";
		multiplier = 0.01;
		multiplierUnit = "Ohms";
	}
	
	//Compare the tolerance with the input from the user
	if (cTolerance == 'B' || cTolerance == 'b') {
		resistor4 = "Brown";
		tolerance = "+/- 1.00%";
	} else if (cTolerance == 'R' || cTolerance == 'r') {
		resistor4 = "Red";
		tolerance = "+/- 2.00%";
	} else if (cTolerance == 'G' || cTolerance == 'g') {
		resistor4 = "Green";
		tolerance = "+/- 0.50%";
	} else if (cTolerance == 'U' || cTolerance == 'u') {
		resistor4 = "Blue";
		tolerance = "+/- 0.25%";
	} else if (cTolerance == 'V' || cTolerance == 'v') {
		resistor4 = "Violet";
		tolerance = "+/- 0.10%";
	} else if (cTolerance == 'Y' || cTolerance == 'y') {
		resistor4 = "Grey";
		tolerance = "+/- 0.05%";
	} else if (cTolerance == 'L' || cTolerance == 'l') {
		resistor4 = "Gold";
		tolerance = "+/- 5.00%";
	} else if (cTolerance == 'S' || cTolerance == 's') {
		resistor4 = "Silver";
		tolerance = "+/- 10.00%";
	}
	
	//Determine whether the units should change from "Ohms" to "KOhms" or from "KOhms" to "MOhms"
	if (cBand1 != 'K' && cBand1 != 'k') {
		if (cMultiplier == 'R' || cMultiplier == 'r' ) {
			multiplier=multiplier/1000;
			multiplierUnit = "KOhms";
		} else if (cMultiplier == 'G' || cMultiplier == 'g' ) {
			multiplier=multiplier/1000;
			multiplierUnit = "MOhms";
		}
	}
	
	//declare the numerical answer of the results
	answer=(10*band1+band2)*multiplier;
	//The first line of the result
	printf ("Resistor bands: %s %s %s %s\n", resistor1, resistor2, resistor3, resistor4);
	//The second line of the result
	printf ("Resistance: %.2lf %s %s\n", answer, multiplierUnit, tolerance);
	return 0;
}
