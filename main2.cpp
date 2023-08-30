//quad2.cpp- solves equation of a type ax^2+bx+c=0 taking floating coefficients a, b and c as an input
#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#include <string.h>
#include "header2.h"
#include <windows.h>

int main(int argc, const char **argv)
{	
	
	double coeffs[NCOEFFS] = {}; 
	
#ifdef TEST	

	ArgvCount(argc, argv);
	
#endif
	
	
	Input(coeffs);
	
	RootsCount rcount; 
	
	double roots[NROOTS] = {}; 
	
	rcount = EqSolver(coeffs, roots); 
	
	PrintingRoots(rcount, roots); 
	
	return 0;
}