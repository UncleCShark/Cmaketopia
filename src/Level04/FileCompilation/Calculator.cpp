#include "Calculator.h"
#include <iostream>

void f() {
  std::cout << "f()\n";
}

Calculator::Calculator() {
  std::cout << "Calculator constructor\n";
}


double Calculator::Add(double x, double y)
{
	return x + y;
}
