#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#include <string.h>
#include "quad2_functions.h"

RootsCount TypeEquation(double Coeffs[], 
			double Roots[])
{	
	/*assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	assert(!isNan(a));
	assert(!isNan(b));
	assert(!isNan(c));*/
	assert(isfinite(*(Coeffs)f));
	assert(isfinite(*(Coeffs+1)f));
	assert(isfinite(*(Coeffs+2)f));
	if (fabs(Coeffs[0]) < fabs(EPS))
	{	
		return LnSolve(Coeffs, Roots);
	}
	return SqSolve(Coeffs, Roots);
}

void clearBuffer(void)
{
	int ch;
	while(((ch=getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}

void Input(double Coeffs[3]={})
{	
	printf("Enter coefficients a, b and c of the equation of type a*x^2+b*x+c=0\n");
	for(int i=0; i<nCoeffs; i++){
		while (scanf("%lf", &Coeffs[i]) != 1){
			puts("Incorrect input! Try again\n");
			clearBuffer();
		}
	}
	for(int i=0; i<nCoeffs; i++)
		printf("%lf ", Coeffs[i]);
	printf("\n");
}

/*void firstreq(void)
{
	char tests[4]={};
	puts("Would you like to test the program first?");
	scanf("%s", tests);
	if (strcmp(tests, "Yes")==0)
	{		
			PassedTests += TestQuad({0.0, 0.0, 0.0}, {0.0, 0.0}, InfiniteRoots);
			PassedTests += TestQuad({1.0, 0.0, 0.0}, {0.0, 0.0}, OneRoot);
			PassedTests += TestQuad({1.0, -3.0, 2.0}, {2.0, 1.0}, TwoRoots);
			PassedTests += TestQuad({0.0, 0.0, 7.8}, {0.0, 0.0}, NoRoots);
			printf("\nTests passed %d out of 4\n\n", PassedTests);
	}
	else if (strcmp(tests, "No")==0)
	{
	return;
	}
	else
	{
		puts("Type in \"Yes\" or \"No\" or else the program will not function(((");
		firstreq();
	}
}*/

void firstreq(void)
{
	char tests[4]={};
	puts("Не желаете ли сначала провести программу через тесты?");
	scanf("%s", tests);
	if (strcmp(tests, "да")==0){		
			int PassedTests = 0;
			FILE * fp;
			fp=fopen("tests.txt", "r");
			int TestsCount = 0;
			//int StringCount = 0;
			/*PassedTests += TestQuad(0.0, 0.0, 0.0, 0.0, 0.0, InfiniteRoots);
			PassedTests += TestQuad(1.0, 0.0, 0.0, 0.0, 0.0, OneRoot);
			PassedTests += TestQuad(1.0, -3.0, 2.0, 2.0, 1.0, TwoRoots);
			PassedTests += TestQuad(0.0, 0.0, 7.8, 0.0, 0.0, NoRoots);
			printf("\nПройдено тестов %d из 4\n\n", PassedTests);*/
			double CoeffsT [nCoeffs] = {};
			double RootsT [nRoots] = {};
			int rcountt = 0;
			//char TestString[64];
			while(fscanf(fp, "%lf %lf %lf %lf %lf %d", &CoeffsT[0], &CoeffsT[1], &CoeffsT[2], &RootsT[0], &RootsT[1], &rcountt) != EOF) {
				PassedTests += TestQuad(CoeffsT, RootsT, rcountt);
				TestsCount++;
				printf("\nПройдено тестов %d из %d \n", PassedTests, TestsCount);
				fgetc(fp);
			}
			fclose(fp);
	}
	else if (strcmp(tests, "нет")==0){
		return;
	}
	else
	{
			puts("Введите \"да\" или \"нет\", иначе ничего не будет работать(((");
			firstreq();
	}
}

int TestQuad(double Coeffs[], double refRoots[], int rcountref)
{	
	/*assert(&x1ref != NULL);
	assert(&x2ref != NULL);
	assert(&x1ref != &x2ref);*/
	/*assert(!isNan(a));
	assert(!isNan(b));
	assert(!isNan(c));*/
	assert(isfinite(Coeffs[0]f));
	assert(isfinite(Coeffs[1]f));
	assert(isfinite(Coeffs[2]f));
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

void PrintingRoots(RootsCount rcount, double Roots[])
{	
	/*assert(&x1 != NULL);
	assert(&x2 != NULL);
	assert(&x1 != &x2);*/
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
			printf("Two roots: %lf и %lf", *Roots, *(Roots+1));
			break;
		default:
			printf("Something went wrong, try checking the input");
			break;
	}
}

RootsCount LnSolve(double Coeffs[], double Roots[])
{	
	/*assert(x1 != NULL);
	assert(!isNan(b));
	assert(!isNan(c));*/
	assert(isfinite(*(Coeffs+1)f));
	assert(isfinite(*(Coeffs+2)f));
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

double DiscrSquareRoot(double Coeffs[])
{
	double d = Coeffs[1] * Coeffs[1] - 4 * Coeffs[0] * Coeffs[2];
	if (d>=0)
		return sqrt(d);
	else
		return -1;
}
	
RootsCount SqSolve(double Coeffs[], double Roots[])
{	
	/*assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);*/	
	const double sqd = DiscrSquareRoot(Coeffs);
	printf("\nThe descriminant of the equation is %lf\n", Coeffs[1] * Coeffs[1] - 4 * Coeffs[0] * Coeffs[2]);
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

/*int isNan(double n)
{
	if (n == n)
		return 0;
	else
		return 1;
}*/