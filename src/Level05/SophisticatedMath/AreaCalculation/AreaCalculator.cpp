#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Calculator.h"

using namespace std;

int main()
{
	double result = 0.0;
	

	cout << "Area Calculator Console Application" << endl << endl;

	Calculator c;
	/*Square 2x2 */
	cout << endl << "Square 2x2" << endl;
	result = c.Multiply(2, 2);
	cout << "Square area result is: " << result << endl;
	/* rectangle 3x4 */
	cout << endl << "Rectangle 3x4" << endl;
	result = c.Multiply(3, 4);
	cout << "Rectangle result is: " << result << endl;
	/* circle radius 3 */
	cout << endl << "Circle radius 3" << endl;
	result = c.Multiply(3, 3);
	result = c.Multiply(M_PI, result);
	cout << "Circle result is: " << result << endl << endl;
	system("pause");
	return 0;
}