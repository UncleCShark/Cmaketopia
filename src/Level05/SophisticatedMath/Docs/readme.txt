Remember to open a correct compiler environment change directory to src\Level05\SophisticatedMath and then copy and paste commands
one by one into your console !!!
Create subfolder build with a correct structure:
mkdir build
cd build
mkdir lib
mkdir bin

To build static dll and executable with GNU compiler:
g++.exe   -I../Calculator -c ../Calculator/Calculator.cpp
ar.exe qc lib/libcalc-static.a  Calculator.o
g++.exe   -I../Calculator -c ../AreaCalculation/AreaCalculator.cpp
g++.exe  AreaCalculator.o  -o bin/areacalc.exe lib/libcalc-static.a

To build dynamic dll and executable with GNU compiler :
g++.exe  -DDLL_BUILD -Dshared_EXPORTS -I../Calculator -fvisibility=hidden -o Calculator.o -c ../Calculator/Calculator.cpp
g++.exe  -shared -o bin/libcalc-dll.dll -Wl,--out-implib,lib/libcalc-dll.dll.a Calculator.o  
g++.exe  -DDLL_BUILD -I../Calculator -o PerimeterCalculator.o -c ../PerimeterCalculation/PerimeterCalculator.cpp
g++.exe PerimeterCalculator.o  -o bin/perimcalc.exe lib/libcalc-dll.dll.a

To build static dll and executable with MSVC compiler :
cl.exe  /nologo -I..\Calculator\. /EHsc  /FoCalculator.obj -c ..\Calculator\Calculator.cpp
link.exe /lib /nologo /machine:x64 /out:lib\calc-static.lib Calculator.obj
cl.exe  /nologo -I..\Calculator\. /EHsc  /FoAreaCalculator.obj -c ..\AreaCalculation\AreaCalculator.cpp
link.exe /nologo AreaCalculator.obj  /out:bin\areacalc.exe  /machine:x64  /subsystem:console  lib\calc-static.lib 

To build dynamic dll and executable with MSVC compiler :
cl.exe  /nologo  -DDLL_BUILD -Dshared_EXPORTS -I..\Calculator /EHsc /FoCalculator.obj -c ..\Calculator\Calculator.cpp
link.exe /nologo Calculator.obj  /out:bin\calc-dll.dll /implib:lib\calc-dll.lib /dll /machine:x64
cl.exe  /nologo -DDLL_BUILD -I..\Calculator /EHsc /FoPerimeterCalculator.obj -c ..\PerimeterCalculation\PerimeterCalculator.cpp
link.exe /nologo PerimeterCalculator.obj  /out:bin\perimcalc.exe /machine:x64 /subsystem:console  lib\calc-dll.lib

Create test static lib with GNU compiler:
g++.exe   -I../Calculator -c ../Tests/test.cpp
g++.exe  test.o  -o bin/test.exe lib/libcalc-static.a
