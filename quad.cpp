#include <stdio.h>
#include "TXLib.h"
#include <math.h>
int main(void)
{
	double a, b, c, d;
	printf("������� ������������ a, b � c ��������� ���� a*x^2+b*x+c=0\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	d= (b*b)-(4.0*a*c);
	printf("������������ ��������� ����� %lf\n",d);
	if (d<0){
		printf("��� �������������� �������");
	}
	else if (d==.0lf){
		printf("�������� ��������� �������� %lf", -b/(2.0*a));
	}
	else{
		printf("��������� ��������� �������� %lf � %lf", (-b+sqrt(d))/(2.0*a), (-b-sqrt(d))/(2.0*a));
	}
	return 0;
}