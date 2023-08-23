#include "quad_functions.h"
#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#include <string.h>

RootsCount TypeEquation(double a, double b, double c, 
			double* x1, double* x2)
{	
	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	assert(!isNan(a));
	assert(!isNan(b));
	assert(!isNan(c));
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	if (fabs(a) < fabs(EPS))
	{	
		return LnSolve(b, c, x1);
	}
	return SqSolve(a, b, c, x1, x2);
}

int TestQuad(double a, double b, double c, double x1ref, 
			double x2ref, RootsCount rcountref)
{	
	assert(&x1ref != NULL);
	assert(&x2ref != NULL);
	assert(&x1ref != &x2ref);
	assert(!isNan(a));
	assert(!isNan(b));
	assert(!isNan(c));
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	double x1 = 0;
	double x2 = 0;
	RootsCount rcount = InfiniteRoots;
	rcount= TypeEquation(a, b, c, &x1, &x2);
	if ((fabs(x1-x1ref)<EPS) && (fabs(x2-x2ref)<EPS) && (fabs(rcount-rcountref)<EPS))
	{
		printf("Всё ок\n");
		return 1;
	}
	else
	{
		printf("Найдено несоответствие! \n\n Проверка данных: \n x1 = %lf, ожидалось %lf\n x2 = %lf, ожидалось %lf\n количество корней = %d, ожидалось %d\n", x1, x1ref, x2, x2ref, rcount, rcountref);
		return 0;
	}
}

void firstreq(void)
{
	char tests[4]={};
	puts("Не желаете ли сначала провести программу через тесты?");
	scanf("%s", tests);
	if (strcmp(tests, "да")==0){		
			int PassedTests = 0;
			PassedTests += TestQuad(0.0, 0.0, 0.0, 0.0, 0.0, InfiniteRoots);
			PassedTests += TestQuad(1.0, 0.0, 0.0, 0.0, 0.0, OneRoot);
			PassedTests += TestQuad(1.0, -3.0, 2.0, 2.0, 1.0, TwoRoots);
			PassedTests += TestQuad(0.0, 0.0, 7.8, 0.0, 0.0, NoRoots);
			printf("\nПройдено тестов %d из 4\n\n", PassedTests);
	}
	else if (strcmp(tests, "нет")==0){
	}
	else
	{
			puts("Введите \"да\" или \"нет\", иначе ничего не будет работать(((");
			firstreq();
	}
}

void PrintingRoots(RootsCount rcount, double x1, double x2)
{	
	assert(&x1 != NULL);
	assert(&x2 != NULL);
	assert(&x1 != &x2);
	switch(rcount)
	{
		case InfiniteRoots:  
			puts("Бесконечно решений");
			break;
		case NoRoots:
			puts("Решений нет");
			break;
		case OneRoot:
			printf("Решение одно, это %lf", x1);
			break;
		case TwoRoots:
			printf("Решений два, это %lf и %lf", x1, x2);
			break;
		default:
			printf("Что-то пошло не так, проверьте входные данные");
			break;
	}
}

void Input(double* a, double* b, double* c)
{	
	printf("Введите коэффициенты a, b и c уравнения типа a*x^2+b*x+c=0\n");
	while(scanf("%lf %lf %lf", a, b, c) != 3)
		{
			printf("Некорректный ввод!\n");
			clearBuffer();
		}
	clearBuffer();
	printf("%lf, %lf, %lf\n", *a, *b, *c);
}
RootsCount LnSolve(double b, double c, double* x1)
{	
	assert(x1 != NULL);
	assert(!isNan(b));
	assert(!isNan(c));
	assert(isfinite(b));
	assert(isfinite(c));
	printf("\nУравнение не квадратное\n");
	if ( (fabs(b) < fabs(EPS)) && (fabs(c) < fabs(EPS)) )
		return (RootsCount) -1;
	else if (fabs(b) < fabs(EPS))
		return (RootsCount) 0;
	else
	{
		*x1=-c/b;
		return (RootsCount) 1;
	}
}

double DiscrSquareRoot(double a, double b, double c)
{
	double d = b * b - 4 * a * c;
	if (d>=0)
		return sqrt(d);
	else
		return -1;
}
	
RootsCount SqSolve(double a, double b, double c, double* x1, double* x2)
{	
	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);	
	const double sqd = DiscrSquareRoot(a, b, c);
	printf("\nДискриминант уравнения равен %lf\n",sqd * sqd);
	if (sqd < -EPS)
	{
		return (RootsCount) 0;
	}
	else if (fabs(sqd) < fabs(EPS))
	{
		*x1 = -b / (2.0 * a);
		return (RootsCount) 1;
	}
	else
	{
		*x1 = (-b + sqd) / (2.0 * a); 
		*x2 = (-b - sqd) / (2.0 * a);
		return (RootsCount) 2;
	}
}

int isNan(double n)
{
	if (n == n)
		return 0;
	else
		return 1;
}

void clearBuffer(void)
{
	int ch;
	while(((ch=getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}