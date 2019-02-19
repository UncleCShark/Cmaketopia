#include <assert.h>
#include "Calculator.h"
#undef NDEBUG /* Force assert output if any */

main()
{
    Calculator calc;
    assert(calc.Add(2.0,2.0)==4.0);
    assert(calc.Add(2.0,3.0)==4.0); /* Error in the test case to show assert output*/
}