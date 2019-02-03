#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Calculator.h"

using namespace std;

int main()
{
	double result = 0.0;
	

	cout << "Perimeter Calculator Console Application" << endl << endl;

	Calculator c;
	/*Square 2x2 */
	cout << endl << "Square 2x2"  << endl;
	result = c.Multiply(4, 2);
	cout << "Square perimeter result is: " << result << endl;
	/* Rectangle 3x4 */
	cout << endl << "Rectangle 3x4" << endl;
	result = c.Add(3, 4);
	result = c.Multiply(result, 2);
	cout << "Rectangle perimeter result is: " << result << endl;
	/* Circle radius 3 */
	cout << endl << "Circle radius 3" << endl;
	result = c.Multiply(2, M_PI);
	result = c.Multiply(3, result);
	cout << "Circle perimeter result is: " << result << endl << endl;
	system("pause");
	return 0;
}