//quad2_functions.cpp- contains all the functions required to solve an equation
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "quad2_functions.h"

/*this function checks whether the absolute value of a (referred as Coeffs[0]) is negligibly small;
if it is, solve equation as linear; else solve as quadratic. returns the number of roots 
in format of RootsCount*/

RootsCount TypeEquation(double Coeffs[], double Roots[])
{		
	assert(!isnan(*(Coeffs)));
	assert(!isnan(*(Coeffs+1)));
	assert(!isnan(*(Coeffs+2)));
	assert(Roots != Roots+1);
	assert(Roots != NULL);
	assert(Roots+1 != NULL);
	assert(isfinite(*(Coeffs)));			
	assert(isfinite(*(Coeffs+1)));               /*checking whether a, b and c are finite numbers*/
	assert(isfinite(*(Coeffs+2)));
	if (fabs(Coeffs[0]) < fabs(EPS))
	{	
		return LnSolve(Coeffs, Roots);
	}
	return QdSolve(Coeffs, Roots);
}

/*function that clears the input buffer when called*/

void clearBuffer(void)
{
	int ch;
	while(((ch=getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}

/*function that assigns entered double-type values to the elements of array Coeffs[] 
(described in quad2.cpp). if an incorrect input occurs, user has to enter ALL the 
values again; can be fixed by commenting/deleting line 45*/

void Input(double Coeffs[]={})
{	
	assert(!isnan(*(Coeffs)));
	assert(!isnan(*(Coeffs+1)));
	assert(!isnan(*(Coeffs+2)));
	printf("Enter coefficients a, b and c of the equation of type a*x^2+b*x+c=0\n");
	for(int i=0; i<nCoeffs; i++){
		while (scanf("%lf", &Coeffs[i]) != 1){
			puts("Incorrect input! Try again\n");
			clearBuffer();
			i = 0;
		}
	}
	for(int i=0; i<nCoeffs; i++)
		printf("%lf ", Coeffs[i]);
	printf("\n");
}

/*function that asks the user whether they want to test a program on values from
a text file tests.txt; if "yes", it tests the file and tells how many tests 
were successful; if no, finishes. It will not end until a user types in either "yes"
or "no", warning them that nothing else is accepted*/

void firstreq(void)
{
	char answer[]= "";
	puts("Would you like to test the program first?");
	scanf("%s", answer);
	if (strcmp(answer, "yes")==0){		
			int PassedTests = 0;
			FILE * fp;
			fp=fopen("tests.txt", "r");
			int TestsCount = 0;
			double CoeffsT [nCoeffs] = {};
			double RootsT [nRoots] = {};
			int rcountt = 0;
			while(fscanf(fp, "%lf %lf %lf %lf %lf %d", &CoeffsT[0], &CoeffsT[1], &CoeffsT[2], &RootsT[0], &RootsT[1], &rcountt) != EOF) {
				PassedTests += TestQuad(CoeffsT, RootsT, rcountt);
				TestsCount++;
				printf("\nPassed tests: %d out of %d \n\n", PassedTests, TestsCount);
				fgetc(fp);
			}
			fclose(fp);
	}
	else if (strcmp(answer, "no")==0){
		return;
	}
	else
	{
			puts("Type in \"yes\" or \"no\"  or else nothing's gonna work(((");
			firstreq();
	}
}

/*function that takes an array of coefficients Coeffs[], an array of expected VALUES that Roots[]
will have if such Coeffs[] are given to Input() function and rcountref, and an expected value of nroots
in format int. Finds the roots of equation with coefficients of Coeffs; if both roots and their amount 
are equal to expected values, returns 1 as a sign that the test has passed, otherwise returns 0 to 
warn user about a failed test*/

int TestQuad(double Coeffs[], double refRoots[], int rcountref)
{	
	assert(isfinite(Coeffs[0]));
	assert(isfinite(Coeffs[1]));
	assert(isfinite(Coeffs[2]));
	assert(!isnan(*(Coeffs)));
	assert(!isnan(*(Coeffs+1)));
	assert(!isnan(*(Coeffs+2)));
	assert(refRoots != refRoots+1);
	assert(refRoots != NULL);
	assert(refRoots+1 != NULL);
	double Roots[nRoots]={};
	int rcount = InfiniteRoots;
	rcount= (int) TypeEquation(Coeffs, Roots);
	if ((fabs((*(Roots)-*(refRoots))<EPS)) && (fabs(*(Roots+1)-*(refRoots+1)<EPS)) && (fabs(rcount-rcountref)<EPS))
	{
		printf("All right!\n");
		return 1;
	}
	else
	{
		printf("Failed test detected! \n\n Checking the data: \n x1 = %lf, expected %lf\n x2 = %lf, expected %lf\n number of roots = %d (-1 means infinite roots), expected %d\n", *Roots, *refRoots, *(Roots+1), *(refRoots+1), rcount, rcountref);
		return 0;
	}
}

/*function that takes rcount (information about how many roots an equation has) and array with 
computed equation roots Roots[]. prints information about how many roots an equation has and 
prints these roots themselves, but only in case there is a finite amount of them*/

void PrintingRoots(RootsCount rcount, double Roots[])
{	
	assert(Roots != Roots+1);
	assert(Roots != NULL);
	assert(Roots+1 != NULL);
	switch(rcount)
	{
		case InfiniteRoots:  
			puts("Infinite roots");
			break;
		case NoRoots:
			puts("No roots");
			break;
		case OneRoot:
			printf("One root: %lf", *Roots);
			break;
		case TwoRoots:
			printf("Two roots: %lf and %lf", *Roots, *(Roots+1));
			break;
		default:
			printf("Something went wrong, try checking the input");
			break;
	}
}

/*function that solves equation as a linear; assigns the root to Roots[0] if there is only one 
root. returns information about how many roots an equation has in format of RootsCount*/

RootsCount LnSolve(double Coeffs[], double Roots[])
{	
	assert(!isnan(*(Coeffs+1)));
	assert(!isnan(*(Coeffs+2)));
	assert(isfinite(*(Coeffs+1)));
	assert(isfinite(*(Coeffs+2)));
	printf("\nEquation is not quadratic\n");
	if ( (fabs(Coeffs[1]) < fabs(EPS)) && (fabs(Coeffs[2]) < fabs(EPS)) )
		return (RootsCount) -1;
	else if (fabs(Coeffs[1]) < fabs(EPS))
		return (RootsCount) 0;
	else
	{
		Roots[0]=-(Coeffs[2]/Coeffs[1]);
		return (RootsCount) 1;
	}
}

/*function that calculates discriminant of a quadratic equation. returns its square root if
discriminant is larger or equals to zero, else returns -1*/

double DiscrSquareRoot(double Coeffs[])
{
	assert(isfinite(Coeffs[0]));
	assert(isfinite(Coeffs[1]));
	assert(isfinite(Coeffs[2]));
	assert(!isnan(*(Coeffs)));
	assert(!isnan(*(Coeffs+1)));
	assert(!isnan(*(Coeffs+2)));
	double d = Coeffs[1] * Coeffs[1] - 4 * Coeffs[0] * Coeffs[2];
	if (d>=0)
		return sqrt(d);
	else
		return -1;
}

/*function that solves equation as quadratic. prints its discriminant and returns information 
about how many roots an equation has in format of RootsCount*/
	
RootsCount QdSolve(double Coeffs[], double Roots[])
{	
	assert(!isnan(*(Coeffs)));
	assert(!isnan(*(Coeffs+1)));
	assert(!isnan(*(Coeffs+2)));
	assert(Roots != Roots+1);
	assert(Roots != NULL);
	assert(Roots+1 != NULL);
	assert(isfinite(*(Coeffs)));			
	assert(isfinite(*(Coeffs+1)));
	assert(isfinite(*(Coeffs+2)));
	const double sqd = DiscrSquareRoot(Coeffs);
	printf("\nThe discriminant of the equation is %lf\n", Coeffs[1] * Coeffs[1] - 4 * Coeffs[0] * Coeffs[2]);
	if (sqd < -EPS)
	{
		return (RootsCount) 0;
	}
	else if (fabs(sqd) < fabs(EPS))
	{
		Roots[0] = -Coeffs[1] / (2.0 * Coeffs[0]);
		return (RootsCount) 1;
	}
	else
	{
		Roots[0] = (-Coeffs[1] + sqd) / (2.0 * Coeffs[0]); 
		Roots[1] = (-Coeffs[1] - sqd) / (2.0 * Coeffs[0]);
		return (RootsCount) 2;
	}
}

