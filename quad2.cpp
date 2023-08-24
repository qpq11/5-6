#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#include <string.h>
#include "quad2_functions.h"

int main(void)
{	
	double Coeffs[nCoeffs]={};
	firstreq();
	clearBuffer();
	Input(Coeffs);
	RootsCount rcount;
	double Roots[nRoots]={};
	rcount=TypeEquation(Coeffs, Roots);
	PrintingRoots(rcount, Roots);
	//printf("E");
	return 0;
}