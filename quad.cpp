#include <stdio.h>
#include "TXLib.h"
#include <math.h>
int main(void)
{
	double a, b, c, d;
	printf("Введите коэффициенты a, b и c уравнения вида a*x^2+b*x+c=0\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	d= (b*b)-(4.0*a*c);
	printf("Дискриминант уравнения равен %lf\n",d);
	if (d<0){
		printf("Нет действительных решений");
	}
	else if (d==.0lf){
		printf("Решением уравнения является %lf", -b/(2.0*a));
	}
	else{
		printf("Решениями уравнения являются %lf и %lf", (-b+sqrt(d))/(2.0*a), (-b-sqrt(d))/(2.0*a));
	}
	return 0;
}