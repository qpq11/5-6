void Input(double* a, double* b, double* c);

enum RootsCount
{
	InfiniteRoots = -1,
	NoRoots,
	OneRoot, 
	TwoRoots
};

double DiscrSquareRoot(double a, double b, double c);

int TestQuad(double a, double b, double c, double x1ref, 
			 double x2ref, RootsCount rcountref);

void PrintingRoots(RootsCount rcount, double x1, double x2);

void firstreq(void);

const double EPS = 1e-15;

RootsCount SqSolve(double a, double b, double c, 
			double* x1, double* x2);
			
RootsCount TypeEquation(double a, double b, double c, 
			double* x1, double* x2);
			
RootsCount LnSolve(double b, double c, double* x1);
			
int isNan(double n);

void clearBuffer(void);