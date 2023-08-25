//quad2_functions.h- header file required by the .cpp file to work successfully

const int nCoeffs = 3; //a maximum number of coefficients that quadratic equation may have

const double EPS = 1e-15; //the permissible error of calculating values of the "double" type

/*an enumeration that allows us to turn an integer amount of roots into an information 
variable about them (-1 stands for infinite roots)*/

enum RootsCount
{
	InfiniteRoots = -1,
	NoRoots,
	OneRoot, 
	TwoRoots
};

//a maximum number of roots that quadratic equation may have

const int nRoots = 2;

//all the functions below are documented in quad2_functions.cpp

void Input(double Coeffs[]);

void clearBuffer(void);

int TestQuad(double Coeffs[], double refRoots[], int rcountref);

void PrintingRoots(RootsCount rcount, double Roots[]);

RootsCount TypeEquation(double Coeffs[], 
			double Roots[]);
			
void firstreq(void);

RootsCount LnSolve(double Coeffs[], double Roots[]);

double DiscrSquareRoot(double Coeffs[]);

RootsCount QdSolve(double Coeffs[], double Roots[]);