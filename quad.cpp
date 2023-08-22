#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#define EPS 1e-15
int SqSolve(double a, double b, double c, 
			double* x1, double* x2);
int rootCnt(double a, double b, double c, 
			double* x1, double* x2);
int LnSolve(double b, double c, double* x1);			
int isNan(double n);
void clearBuffer(void);
int main(void)
{	
	double a=0.0, b=0.0, c=0.0;
	printf("Введите коэффициенты a, b и c уравнения типа a*x^2+b*x+c=0\n");
	while(scanf("%lf %lf %lf", &a, &b, &c)!=3){
			printf("Некорректный ввод!\n");
			clearBuffer();
		}
	clearBuffer();
	printf("%lf, %lf, %lf",a,b,c);
	double x1=0.0, x2=0.0;
	int rt;
	rt=rootCnt(a,b,c,&x1,&x2);
	int am;
	if (rt)
		am=SqSolve(a,b,c,&x1,&x2);
	else
		am=LnSolve(b,c,&x1);
	switch(am){
		case -1: 
			puts("Бесконечно решений");
			break;
		case 0:
			puts("Решений нет");
			break;
		case 1:
			printf("Решение одно, это %lf", x1);
			break;
		case 2:
			printf("Решений два, это %lf и %lf", x1, x2);
			break;
		default:
			printf("Что-то пошло не так, проверьте входные данные");
			break;
	}
	return 0;
}

int rootCnt(double a, double b, double c, 
			double* x1, double* x2)
{	
	assert(x1!=NULL);
	assert(x2!=NULL);
	assert(x1!=x2);
	assert(isNan(a));
	assert(isNan(b));
	assert(isNan(c));
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	int status = 1;
	if (fabs(a)<fabs(EPS))
		{	
			status=0;
		}
	return status;
}
int LnSolve(double b, double c, double* x1)
	{
		printf("\nУравнение не квадратное\n");
		if ((fabs(b)<fabs(EPS))&&(fabs(c)<fabs(EPS)))
			return -1;
		else if (fabs(b)<fabs(EPS))
			return 0;
		else
			*x1=-c/b;
		return 1;
	}
	
int SqSolve(double a, double b, double c, 
			double* x1, double* x2)
	{		
			const double d=(b*b)-(4.0*a*c);
			printf("\nДискриминант уравнения равен %lf\n",d);
			if (d<-EPS)
			{
				return 0;
			}
			else if (fabs(d)<fabs(EPS))
			{
				*x1=-b/(2.0*a);
				return 1;
			}
			else
			{
				*x1=(-b+sqrt(d))/(2.0*a); 
				*x2=(-b-sqrt(d))/(2.0*a);
				return 2;
			}
	}

int isNan(double n)
{
	if (n==n)
		return 1;
	else
		return 0;
}

void clearBuffer(void){
	int ch;
	while(((ch=getchar())!='\n')&&(ch!=EOF)){
		continue;
	}
}