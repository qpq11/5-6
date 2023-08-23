void Input(double coeffs[3]={})
{	
	printf("Enter coefficients a, b and c of the equation of type a*x^2+b*x+c=0\n");
	for(i=0; i<nCoeffs; i++){
		while (scanf("%lf", &Coeffs[i]) != 1){
			puts("Incorrect input! Try again\n");
			clearBuffer();
		}
	}
	for(i=0; i<nCoeffs; i++)
		printf("%lf ", Coeffs[i]);
	printf('\n');
}

void clearBuffer(void)
{
	int ch;
	while(((ch=getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}