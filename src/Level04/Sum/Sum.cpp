#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
	double result,first,second = 0.0;

	cout << "Sum Calculator Console Application" << endl << endl;
	Calculator c;
	/* Add two double */
	first=2.0;
	second=4.0;
	cout << first <<" + "<<second;
	result=c.Add(first,second);
	cout << " Sum is: " << result << endl << endl;
	system("pause");
	return 0;
}