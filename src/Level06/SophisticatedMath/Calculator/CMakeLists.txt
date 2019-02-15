cmake_minimum_required(VERSION 3.8)

# Export no symbols by default (if the compiler supports it).
# This makes e.g. GCC's "visibility behavior" consistent with MSVC's. 
# On Windows/MSVC this is a noop.
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# create the shared library
add_library(calc-dll SHARED Calculator.cpp)
target_include_directories(calc-dll PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(calc-dll PRIVATE shared_EXPORTS PUBLIC DLL_BUILD)

# create the shared library
add_library(calc-static STATIC Calculator.cpp)
target_include_directories(calc-static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
