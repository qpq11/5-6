//quad2_functions.h- header file required by the .cpp file to work successfully

/**
*  @brief A maximum number of coefficients that quadratic equation may have
*/
const int nCoeffs = 3;

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
	InfiniteRoots = -1,
	NoRoots,
	OneRoot, 
	TwoRoots
};

/**
*  @brief Maximum number of roots that quadratic equation may have
*/
const int nRoots = 2;

//all the functions below are documented in quad2_functions.cpp

/**
*  @brief This is a coefficient input function
*
*  @details A function that assigns entered double-type values to the elements of array Coeffs[]
*
*  @note If an incorrect input occurs, user has to enter ALL the values again; 
*  can be fixed by commenting/deleting line 45 in quad2_functions.cpp
*
*  @param Coeffs[] an array containing coefficients a, b and c of quadratic equation
*/
void Input(double Coeffs[]);

/**
*  @brief A function that clears the input buffer when called
*/

void clearBuffer(void);

/**
* @brief Function made to test a program on premade values
*
* @details A function that compares given roots and their number with values calculated using the coefficients a,b and c 
*
* @param Coeffs[] an array of coefficients 
*
* @param refRoots[] an array of expected VALUES that Roots[] will have if such Coeffs[] are given to Input() function 
*
* @param rcountref expected amount of roots (in format "RootsCount") 
*
* @returns if both roots and their amount are equal to expected values, returns 1 as a sign that the test has passed; 
* otherwise returns 0 to warn user about a failed test
*
*
*/

int TestQuad(double Coeffs[], double refRoots[], int rcountref);

/**
*  @brief Function that prints number of roots basing on the value of rcount
*
*  @param rcount information about how many roots an equation has
*  @param Roots[] array that contains equation's root(-s)
*
*  @returns value of variable x1 if equation has one solution; values of variables x1 and x2
*  if equation has two solutions; only prints information about the number of roots in other cases
*/

void PrintingRoots(RootsCount rcount, double Roots[]);

/**
*  @brief A function that defines the type of equation
*  @details This function checks whether the absolute value of coefficient a (referred as Coeffs[0]) is negligibly small;
*  if it is, solves equation as linear, else solves as quadratic
*  @param Coeffs[] an array of equation's coefficients
*  @param Roots[] an array that's meant to contain equation's roots
*
*  @returns the number of roots in format of RootsCount
*  @note calls QdSolve if an equation is quadratic; else calls LnSolve. In both cases, Roots[] is being changed
*/

RootsCount TypeEquation(double Coeffs[], 
			double Roots[]);

/**
*  @brief A function that performs first console request
*
*  @details This function asks the user whether they want to test a 
*  program on  values from a text file tests.txt
*  
*  @param Function takes no parameters but assigns user's answer to "string" 
*  variable answer.If "yes", it tests data from the file and tells how many tests 
*  were successful; if no, the function just finishes. 

*  @warning Function will not end until a user types in either "yes"
*  or "no", leaving them stuck on that step
*/

void firstreq(void);

/**
*   @brief Solves a linear equation
*   @details A function that solves equation as linear
*   @param Coeffs[] an array of equation's coefficients
*   @param Roots[] an array that's meant to contain equation's roots
*
*   @returns Information about how many roots an equation has in format of RootsCount
*/

RootsCount LnSolve(double Coeffs[], double Roots[]);

/**
*  @brief Discriminant solver
*  @details A function that calculates a discriminant of a quadratic equation 
*  @param Coeffs[] an array of equation's coefficients
*  @returns Square root of a discriminant if it is larger or equals to zero; else returns -1
*/

double DiscrSquareRoot(double Coeffs[]);

/**
*  @brief Solves a quadratic equation
*
*  @details A function that solves equation as quadratic 
*  @param Coeffs[] an array of equation's coefficients
*  @param Roots[] an array that's meant to contain equation's roots
*  @returns Information about how many roots an equation has in format of RootsCount;
*  also prints discriminant's value
*/

RootsCount QdSolve(double Coeffs[], double Roots[]);