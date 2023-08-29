#include "TXLib.h"
#include "quad_functions.h"

int main(void)
{	
	double a = 0.0, b = 0.0, c = 0.0;
	firstreq();
	clearBuffer();
	Input(&a, &b, &c);
	RootsCount rcount;
	double x1=0.0, x2=0.0;
	rcount=TypeEquation(a, b, c, &x1, &x2);
	PrintingRoots(rcount, x1, x2);
	return 0;
}