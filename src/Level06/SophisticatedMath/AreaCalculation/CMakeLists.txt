cmake_minimum_required(VERSION 3.8)

# create the executable
add_executable(areacalc AreaCalculator.cpp)

# link our executable "main" with the shared library "shared"
target_link_libraries(areacalc calc-static)