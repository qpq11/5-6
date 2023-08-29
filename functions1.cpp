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
			double x2ref, int rcountref)
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
	int rcount = -1;
	rcount= (int) TypeEquation(a, b, c, &x1, &x2);
	if ((fabs(x1-x1ref)<EPS) && (fabs(x2-x2ref)<EPS) && (fabs(rcount-rcountref)<EPS))
	{
		printf("�� ��\n");
		return 1;
	}
	else
	{
		printf("������� ��������������! \n\n �������� ������: \n x1 = %lf, ��������� %lf\n x2 = %lf, ��������� %lf\n ���������� ������ = %d (-1 - ���������� �������), ��������� %d\n", x1, x1ref, x2, x2ref, rcount, rcountref);
		return 0;
	}
}

void firstreq(void)
{
	char tests[4]={};
	puts("�� ������� �� ������� �������� ��������� ����� �����?");
	scanf("%s", tests);
	if (strcmp(tests, "��")==0){		
			int PassedTests = 0;
			FILE * fp;
			fp=fopen("tests.txt", "r");
			int TestsCount = 0;
			//int StringCount = 0;
			/*PassedTests += TestQuad(0.0, 0.0, 0.0, 0.0, 0.0, InfiniteRoots);
			PassedTests += TestQuad(1.0, 0.0, 0.0, 0.0, 0.0, OneRoot);
			PassedTests += TestQuad(1.0, -3.0, 2.0, 2.0, 1.0, TwoRoots);
			PassedTests += TestQuad(0.0, 0.0, 7.8, 0.0, 0.0, NoRoots);
			printf("\n�������� ������ %d �� 4\n\n", PassedTests);*/
			double at, bt, ct = 0;
			double x1t, x2t = 0;
			int rcountt = 0;
			//char TestString[64];
			while(fscanf(fp, "%lf %lf %lf %lf %lf %d", &at, &bt, &ct, &x1t, &x2t, &rcountt) != EOF) {
				PassedTests += TestQuad(at, bt, ct, x1t, x2t, rcountt);
				TestsCount++;
				printf("\n�������� ������ %d �� %d \n", PassedTests, TestsCount);
				fgetc(fp);
			}
			fclose(fp);
	}
	else if (strcmp(tests, "���")==0){
		return;
	}
	else
	{
			puts("������� \"��\" ��� \"���\", ����� ������ �� ����� ��������(((");
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
			puts("���������� �������");
			break;
		case NoRoots:
			puts("������� ���");
			break;
		case OneRoot:
			printf("������� ����, ��� %lf", x1);
			break;
		case TwoRoots:
			printf("������� ���, ��� %lf � %lf", x1, x2);
			break;
		default:
			printf("���-�� ����� �� ���, ��������� ������� ������");
			break;
	}
}

void Input(double* a, double* b, double* c)
{	
	printf("������� ������������ a, b � c ��������� ���� a*x^2+b*x+c=0\n");
	while(scanf("%lf %lf %lf", a, b, c) != 3)
		{
			printf("������������ ����!\n");
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
	printf("\n��������� �� ����������\n");
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
	printf("\n������������ ��������� ����� %lf\n", b * b - 4 * a * c);
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

/*int StringCount(FILE * fp)
{	
	assert(fp != NULL);
	char TestString[64];
	int StrCnt = 0;
	while ((fgets(TestString, 256, fp))!=NULL)
	{
		StrCnt+=1;
	}
	return StrCnt;
}*/