//quad2.cpp- solves equation of a type ax^2+bx+c=0 taking floating coefficients a, b and c as an input
#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#include <string.h>
#include "header2.h"
#include <windows.h>

int main(int argc, const char **argv)
{	
	
	printf("%d\n", argc);

	puts("You entered:");

	for (int i = 0; i < argc; i++) printf("%s\n", argv[i]);

	double coeffs[NCOEFFS] = {}; //array meant to contain coefficients a, b an d
	
	ArgvCount(argc, argv);
	
	ClearBuffer();
	
	Input(coeffs); //assigns the coefficient values received from stdin to coeffs
	
	RootsCount rcount; //variable that contains the information about the number of roots
	
	double roots[NROOTS] = {}; //array meant to contain roots x1 and x2
	
	rcount = EqSolver(coeffs, roots); //deciding whether the equation is linear or quadratic and assigning its number of roots to rcount
	
	PrintingRoots(rcount, roots); //print information about roots of the equation
	
	return 0;
}