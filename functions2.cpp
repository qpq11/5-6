//quad2_functions.cpp- contains all the functions required to solve an equation
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "header2.h"
#include <windows.h>

/*this function checks whether the absolute value of a (referred as coeffs[0]) is negligibly small;
if it is, solve equation as linear; else solve as quadratic. returns the number of roots 
in format of RootsCount*/
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

RootsCount EqSolver(const double coeffs[], double roots[])
{		
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(roots != roots+1);
	assert(roots != NULL);
	assert(roots+1 != NULL);
	assert(isfinite(*(coeffs)));			
	assert(isfinite(*(coeffs+1)));               /*checking whether a, b and c are finite numbers*/
	assert(isfinite(*(coeffs+2)));
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	if (IsEqual(coeffs[0], 0))
	{ 	
		return LnSolve(coeffs, roots);
	}
	return QdSolve(coeffs, roots);
}

/*function that clears the input buffer when called*/

void ClearBuffer(void)
{
	int ch;
	while(((ch = getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}

/*function that assigns entered double-type values to the elements of array coeffs[] 
(described in quad2.cpp). if an incorrect input occurs, user has to enter ALL the 
values again; can be fixed by commenting/deleting line 45*/

void Input(double coeffs[]={})
{	
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
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

/*function that asks the user whether they want to test a program on values from
a text file tests.txt; if "yes", it tests the file and tells how many tests 
were successful; if no, finishes. It will not end until a user types in either "yes"
or "no", warning them that nothing else is accepted*/

void LaunchTests(int argc, const char str[])
{
	char answer[]= "";
	puts("Would you like to test the program first?");
	scanf("%s", answer);
	if (strcmp(answer, "yes") == 0){		
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
	else if (strcmp(answer, "no") == 0){
		return;
	}
	else
	{
			puts("Type in \"yes\" or \"no\"  or else nothing's gonna work(((");
			LaunchTests(argc, str);
	}
}

/*function that takes an array of coefficients coeffs[], an array of expected VALUES that roots[]
will have if such coeffs[] are given to Input() function and rcountref, and an expected value of NROOTS
in format int. Finds the roots of equation with coefficients of coeffs; if both roots and their amount 
are equal to expected values, returns 1 as a sign that the test has passed, otherwise returns 0 to 
warn user about a failed test*/

int TestQuad(const double coeffs[], const double refroots[], int rcountref)
{	
	assert(isfinite(coeffs[0]));
	assert(isfinite(coeffs[1]));
	assert(isfinite(coeffs[2]));
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(refroots != refroots+1);
	assert(refroots != NULL);
	assert(refroots+1 != NULL);
	
	double roots[NROOTS] = {};
	int rcount = Infiniteroots;
	rcount = (int) EqSolver(coeffs, roots);
	//if ((fabs((*(roots)-*(refroots))<EPS)) && (fabs(*(roots+1)-*(refroots+1)<EPS)) && (fabs(rcount-rcountref)<EPS))
	if (IsEqual(*(roots), *(refroots)) && IsEqual(*(roots+1), *(refroots+1)) && IsEqual(rcount,rcountref))
	{
		printf("All right!\n");
		return 1;
	}
	else
	{
		printf("Failed test detected! \n\n Checking the data: \n x1 = %lf, expected %lf\n x2 = %lf, expected %lf\n number of roots = %d (-1 means infinite roots), expected %d\n", *roots, *refroots, *(roots+1), *(refroots+1), rcount, rcountref);
		return 0;
	}
}

/*function that takes rcount (information about how many roots an equation has) and array with 
computed equation roots roots[]. prints information about how many roots an equation has and 
prints these roots themselves, but only in case there is a finite amount of them*/

void PrintingRoots(RootsCount rcount, const double roots[])
{	
	assert(roots != roots+1);
	assert(roots != NULL);
	assert(roots+1 != NULL);
	switch(rcount)
	{
		case Infiniteroots:  
			puts("Infinite roots");
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			break;
		case Noroots:
			puts("No roots");
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			break;
		case OneRoot:
			printf("One root: %lf", *roots);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			break;
		case Tworoots:
			printf("Two roots: %lf and %lf", *roots, *(roots+1));
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			break;
		default:
			printf("Something went wrong, try checking the input");
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			break;
	}
}

/*function that solves equation as a linear; assigns the root to roots[0] if there is only one 
root. returns information about how many roots an equation has in format of RootsCount*/

RootsCount LnSolve(const double coeffs[], double roots[])
{	
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(isfinite(*(coeffs+1)));
	assert(isfinite(*(coeffs+2)));
	
	printf("\nEquation is not quadratic\n");
	if (IsEqual(coeffs[1], 0) && IsEqual(coeffs[2], 0))
		return (RootsCount) -1;
			//FIX
	else if (fabs(coeffs[1]) < fabs(EPS))
		return (RootsCount) 0;
	else
	{
		roots[0] =- (coeffs[2]/coeffs[1]);
		return (RootsCount) 1;
	}
}

/*function that calculates discriminant of a quadratic equation. returns its square root if
discriminant is larger or equals to zero, else returns -1*/

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

/*function that solves equation as quadratic. prints its discriminant and returns information 
about how many roots an equation has in format of RootsCount*/
	
RootsCount QdSolve(const double coeffs[], double roots[])
{	
	assert(!isnan(*(coeffs)));
	assert(!isnan(*(coeffs+1)));
	assert(!isnan(*(coeffs+2)));
	assert(roots != roots+1);
	assert(roots != NULL);
	assert(roots+1 != NULL);
	assert(isfinite(*(coeffs)));			
	assert(isfinite(*(coeffs+1)));
	assert(isfinite(*(coeffs+2)));
	
	const double sqd = DiscrSquareRoot(coeffs);
	printf("\nThe discriminant of the equation is %lf\n", coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2]);
	if (sqd < -EPS)
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
	if (fabs(n1)-fabs(n2)<EPS)
		return 1;
	return 0;
}

void ArgvCount(int argc, const char** argv){
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);
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
	if (argc == 2)
	{
		LaunchTests(argc, argv[1]);
		return;
	}
	if (argc == 1)
		return;
}