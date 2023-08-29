//quad2_functions.h- header file required by the .cpp file to work successfully

/**
*  @brief A maximum number of coefficients that quadratic equation may have
*/
const int NCOEFFS = 3;

/**
*  @brief A permissible miscalculation when computing values of "double" type
*/
const double EPS = 1e-15;

/**
 * @brief Enumeration of the numbers of roots an equation may have
 *
 * @details An enumeration that allows us to turn an integer amount of roots into an information 
 *			variable about them (-1 stands for infinite roots)
 */

enum RootsCount
{
	Infiniteroots = -1,
	Noroots,
	OneRoot, 
	Tworoots
};

/**
*  @brief Maximum number of roots that quadratic equation may have
*/
const int NROOTS = 2;

//all the functions below are documented in quad2_functions.cpp

/**
*  @brief This is a coefficient input function
*
*  @details A function that assigns entered double-type values to the elements of array coeffs[]
*
*  @note If an incorrect input occurs, user has to enter ALL the values again; 
*  can be fixed by commenting/deleting line 45 in quad2_functions.cpp
*
*  @param coeffs[] an array containing coefficients a, b and c of quadratic equation
*/
void Input(double coeffs[]);

/**
*  @brief A function that clears the input buffer when called
*/

void ClearBuffer(void);

/**
* @brief Function made to test a program on premade values
*
* @details A function that compares given roots and their number with values calculated using the coefficients a,b and c 
*
* @param coeffs[] an array of coefficients 
*
* @param refroots[] an array of expected VALUES that roots[] will have if such coeffs[] are given to Input() function 
*
* @param rcountref expected amount of roots (in format "RootsCount") 
*
* @returns if both roots and their amount are equal to expected values, returns 1 as a sign that the test has passed; 
* otherwise returns 0 to warn user about a failed test
*
*
*/

int TestQuad(const double coeffs[], const double refroots[], int rcountref);

/**
*  @brief Function that prints number of roots basing on the value of rcount
*
*  @param rcount information about how many roots an equation has
*  @param roots[] array that contains equation's root(-s)
*
*  @returns value of variable x1 if equation has one solution; values of variables x1 and x2
*  if equation has two solutions; only prints information about the number of roots in other cases
*/

void PrintingRoots(RootsCount rcount, const double roots[]);

/**
*  @brief A function that defines the type of equation
*
*  @details This function checks whether the absolute value of coefficient a (referred as coeffs[0]) is negligibly small;
*  if it is, solves equation as linear, else solves as quadratic
*
*  @param coeffs[] an array of equation's coefficients
*  @param roots[] an array that's meant to contain equation's roots
*
*  @returns the number of roots in format of RootsCount
*
*  @note calls QdSolve if an equation is quadratic; else calls LnSolve. In both cases, roots[] is being changed
*/

RootsCount EqSolver(const double coeffs[], 
			double roots[]);

/**
*  @brief A function that performs first console request
*
*  @details This function asks the user whether they want to test a 
*  program on  values from a text file tests.txt
*  
*  @param Function takes no parameters but assigns user's answer to "string" 
*  variable answer.If "yes", it tests data from the file and tells how many tests 
*  were successful; if no, the function just finishes. 
*
*  @note Function will not end until a user types in either "yes"
*  or "no", leaving them stuck on that step
*/

void LaunchTests(int argc, char str[]);

/**
*   @brief Solves a linear equation
*
*   @details A function that solves equation as linear
*
*   @param coeffs[] an array of equation's coefficients
*   @param roots[] an array that's meant to contain equation's roots
*
*   @returns Information about how many roots an equation has in format of RootsCount
*/

RootsCount LnSolve(const double coeffs[], double roots[]);

/**
*  @brief Discriminant solver
*
*  @details A function that calculates a discriminant of a quadratic equation 
*
*  @param coeffs[] an array of equation's coefficients
*
*  @returns Square root of a discriminant if it is larger or equals to zero; else returns -1
*/

double DiscrSquareRoot(const double coeffs[]);

/**
*  @brief Solves a quadratic equation
*
*  @details A function that solves equation as quadratic 
*
*  @param coeffs[] an array of equation's coefficients
*  @param roots[] an array that's meant to contain equation's roots
*
*  @returns Information about how many roots an equation has in format of RootsCount;
*  also prints discriminant's value
*/
RootsCount QdSolve(const double coeffs[], double roots[]);

/**
*  @brief Compares two "double" numbers
*  
*  @details Checks whether difference between n1 and n2 is negligibly small
*
*  @param n1 "double" format decimal
*
*  @param n2 "double" format decimal
*  
*  @returns returns 1 if difference between two decimals is less than EPS; else returns 0
*/
int IsEqual(double n1, double n2);

void ArgvCount(int argc, const char** argv);