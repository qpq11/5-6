const int nCoeffs = 3;

const double EPS = 1e-15;

enum RootsCount
{
	InfiniteRoots = -1,
	NoRoots,
	OneRoot, 
	TwoRoots
};

const int nRoots = 2;

void Input(double Coeffs[]);

void clearBuffer(void);

int TestQuad(double Coeffs[], double refRoots[], int rcountref);

void PrintingRoots(RootsCount rcount, double Roots[]);

RootsCount TypeEquation(double Coeffs[], 
			double Roots[]);
			
void firstreq(void);

RootsCount LnSolve(double Coeffs[], double Roots[]);

double DiscrSquareRoot(double Coeffs[]);

RootsCount SqSolve(double Coeffs[], double Roots[]);

//void isNan(double n);