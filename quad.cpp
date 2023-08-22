#include <stdio.h>
#include "TXLib.h"
#include <math.h>
#define EPS 1e-15
int SqSolve(double a, double b, double c, 
			double* x1, double* x2);
int main(void)
{	
	double a=0.0, b=0.0, c=0.0;
	printf("������� ������������ a, b � c ��������� ���� a*x^2+b*x+c=0\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	double x1=0.0, x2=0.0;
	int rt=1;
	rt=SqSolve(a,b,c,&x1,&x2);
	switch(rt){
		case -1: 
			puts("���������� �������");
			break;
		case 0:
			puts("������� ���");
			break;
		case 1:
			printf("������� ����, ��� %lf", x1);
			break;
		case 2:
			printf("������� ���, ��� %lf � %lf", x1, x2);
			break;
		default:
			printf("���-�� ����� �� ���, ��������� ������� ������");
			break;
	}
	return 0;
}

int SqSolve(double a, double b, double c, 
			double* x1, double* x2)
{	
	int status = 1;
	if (fabs(a)<fabs(EPS))
		{
			printf("��������� �� ����������\n");
			if ((fabs(b)<fabs(EPS))&(fabs(c)<fabs(EPS)))
				status=-1;
			else if (fabs(b)<fabs(EPS))
				status=0;
			else
				*x1=-c/b;
		}
	else
	{
			const double d=(b*b)-(4.0*a*c);
			printf("������������ ��������� ����� %lf\n",d);
			if (d<-EPS)
			{
				status=0;
			}
			else if (fabs(d)<fabs(EPS))
			{
				*x1=-b/(2.0*a);
			}
			else
			{
				status=2;
				*x1=(-b+sqrt(d))/(2.0*a); 
				*x2=(-b-sqrt(d))/(2.0*a);
			}
	}
	return status;
}