cmake_minimum_required(VERSION 3.8)

# create the executable
add_executable(perimcalc PerimeterCalculator.cpp)

# link our executable "main" with the shared library "shared"
target_link_libraries(perimcalc calc-dll)
target_compile_definitions(perimcalc PRIVATE DLL_BUILD)