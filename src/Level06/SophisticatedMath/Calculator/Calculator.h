#ifndef SHARED_H__
#define SHARED_H__

#include "shared_EXPORTS.h"   

extern "C" void SHARED_EXPORT f();

class SHARED_EXPORT Calculator {
public:
	Calculator();
	double Add(double x, double y);
	double Substract(double x, double y);
	double Multiply(double x, double y);
};

#endif
