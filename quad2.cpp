//quad2.cpp- solves equation of a type ax^2+bx+c=0 taking floating coefficients a, b and c as an input
#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#include <string.h>
#include "quad2_functions.h"

int main(void)
{	
	double Coeffs[nCoeffs]={}; //array meant to contain coefficients a, b an d
	firstreq();
	clearBuffer();
	Input(Coeffs); //assigns the coefficient values received from stdin to Coeffs
	RootsCount rcount; //variable that contains the information about the number of roots
	double Roots[nRoots]={}; //array meant to contain roots x1 and x2
	rcount=TypeEquation(Coeffs, Roots); //deciding whether the equation is linear or quadratic and assigning its number of roots to rcount
	PrintingRoots(rcount, Roots); //print information about roots of the equation
	return 0;
}