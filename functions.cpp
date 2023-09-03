//quad2_functions.cpp- contains all the functions required to solve an equation
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "header.h"
#include <windows.h>

void SetColour(Colour colourname)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(hConsole, colourname);
}


RootsCount EqSolver(const double coeffs[], double roots[])
{		
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(roots != NULL);
	assert(isfinite(*(coeffs)));			
	assert(isfinite(*(coeffs+1)));
	assert(isfinite(*(coeffs+2)));
	
	if (IsEqual(coeffs[0], 0))
	{ 	
		return LnSolve(coeffs, roots);
	}
	return QdSolve(coeffs, roots);
}

void ClearBuffer(void)
{
	int ch;
	while(((ch = getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}

void Input(double coeffs[] = {})
{	
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	
	SetColour(ClrGreen);
	printf("Enter coefficients a, b and c of the equation of type a*x^2+b*x+c=0\n");
	for(int i = 0; i < NCOEFFS; i++){
		while (scanf("%lf", &coeffs[i]) != 1){
			puts("Incorrect input! Try again\n");
			ClearBuffer();
			i = 0;
		}
	}
	for(int i = 0; i < NCOEFFS; i++)
		printf("%lf ", coeffs[i]);
	printf("\n");
}

void LaunchTests(int argc, const char str[])
{	
	assert(str);
	FILE * fp = NULL;
	fp = fopen(str, "r");
	assert(fp);
	
	int PassedTests = 0;
	int TestsCount = 0;
	double coeffsT [NCOEFFS] = {};
	double rootsT [NROOTS] = {};
	int rcountt = 0;
	while(fscanf(fp, "%lf %lf %lf %lf %lf %d", &coeffsT[0], &coeffsT[1], &coeffsT[2], &rootsT[0], &rootsT[1], &rcountt) != EOF) {
		PassedTests += TestQuad(coeffsT, rootsT, rcountt);
		TestsCount++;
		printf("\nPassed tests: %d out of %d \n\n", PassedTests, TestsCount);
		fgetc(fp);
	}
	fclose(fp);
}

int TestQuad(const double coeffs[], const double refroots[], int rcountref)
{	
	assert(isfinite(coeffs[0]));
	assert(isfinite(coeffs[1]));
	assert(isfinite(coeffs[2]));
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(refroots != NULL);
	
	double roots[NROOTS] = {};
	int rcount = Infiniteroots;
	rcount = (int) EqSolver(coeffs, roots);
	printf("Coefficients: a=%lf, b=%lf, c=%lf\nExpected Roots[] values: %lf and %lf\n Amount of roots(-1 means infinte roots): %d\n\n", *coeffs, *(coeffs+1), *(coeffs+2), *refroots, *(refroots+1), rcountref);
	if (IsEqual(*(roots), *(refroots)) && IsEqual(*(roots+1), *(refroots+1)) && IsEqual(rcount,rcountref))
	{
		printf("All right!\n\n");
		return 1;
	}
	else
	{
		printf("Failed test detected! \n\n Checking the data: \n x1 = %lf, expected %lf\n x2 = %lf, expected %lf\n number of roots = %d (-1 means infinite roots), expected %d\n\n", *roots, *refroots, *(roots+1), *(refroots+1), rcount, rcountref);
		return 0;
	}
}

void PrintingRoots(RootsCount rcount, const double roots[])
{	
	assert(roots != NULL);
	switch(rcount)
	{
		case Infiniteroots:  
			puts("Infinite roots");
			SetColour(ClrDefault);
			break;
		case Noroots:
			puts("No roots");
			SetColour(ClrDefault);
			break;
		case OneRoot:
			printf("One root: %lf", *roots);
			SetColour(ClrDefault);
			break;
		case Tworoots:
			printf("Two roots: %lf and %lf", *roots, *(roots+1));
			SetColour(ClrDefault);
			break;
		default:
			printf("Something went wrong, try checking the input");
			SetColour(ClrDefault);
			break;
	}
}

RootsCount LnSolve(const double coeffs[], double roots[])
{	
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(isfinite(*(coeffs+1)));
	assert(isfinite(*(coeffs+2)));
	
	printf("\nEquation is not quadratic\n");
	if (IsEqual(coeffs[1], 0) && IsEqual(coeffs[2], 0))
		return (RootsCount) -1;
	else if (IsEqual(coeffs[1], 0))
		return (RootsCount) 0;
	else
	{
		roots[0] =- (coeffs[2]/coeffs[1]);
		return (RootsCount) 1;
	}
}

double DiscrSquareRoot(const double coeffs[])
{
	assert(isfinite(coeffs[0]));
	assert(isfinite(coeffs[1]));
	assert(isfinite(coeffs[2]));
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	
	double d = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
	if (d >= 0)
		return sqrt(d);
	else
		return -1;
}
	
RootsCount QdSolve(const double coeffs[], double roots[])
{	
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(roots != NULL);
	assert(isfinite(*(coeffs)));			
	assert(isfinite(*(coeffs+1)));
	assert(isfinite(*(coeffs+2)));
	
	const double sqd = DiscrSquareRoot(coeffs);
	printf("\nThe discriminant of the equation is %lf\n", coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2]);
	if (sqd < 0)
	{
		return (RootsCount) 0;
	}
	else if (IsEqual(sqd, 0))
	{
		roots[0] = -coeffs[1] / (2.0 * coeffs[0]);
		return (RootsCount) 1;
	}
	else
	{
		roots[0] = (-coeffs[1] + sqd) / (2.0 * coeffs[0]); 
		roots[1] = (-coeffs[1] - sqd) / (2.0 * coeffs[0]);
		return (RootsCount) 2;
	}
}

int IsEqual(double n1, double n2)
{
	if (fabs(n1)-fabs(n2) < EPS)
		return 1;
	return 0;
}

void ArgvCount(int argc, const char** argv){
	SetColour(ClrCyan);
	if (argc == 2 && !(strcmp("--test", argv[1])))
	{
		LaunchTests(argc, "tests.txt");
		return;
	}
	if (argc == 3 && !(strcmp("--test", argv[1])))
	{
		LaunchTests(argc, argv[2]);
		return;
	}
}