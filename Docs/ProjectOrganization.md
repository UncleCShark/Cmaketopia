---
layout: page
title: Project Organization
previous_page: CommandLine
next_page: BuildSystem
---

# Project Organization

In this part of the tutorial we'll develop a project SophisticatedMath.  We will do it in a three-person team. Each member of the team will use a different type of IDE, Visual Studio, Vs Code, QT Creator respectably. We'll be utilize IDE only for writing code. We'll compile source code outside of the IDE manually. Our task will be to create two executable and two libraries, one static and one dynamic. We will consider how to organize the work of our team, so that local settings of one person's programming environment do not have a destructive impact on the work of other team members. The structure of our projects should be easy to read and follow the same pattern.

## GitHub Repository

We are Cmaketopians thus we leverage a GitHub version control repository to backup and share our ideas. Our repositories should have the appropriate structure of directories and files based on convention. The similar structure help us reading easily other projects. Because we create a cross-platform project our domain project repository should be platform independent. Additional platform specific modules should create platform specific projects. In general our repository contains source code, data and documentation of projects, as well as a license, a readme and .gitignore files.

```txt
GitHub Repository
|
|   .gitignore
|   LICENSE
|   README.md
|
+---Docs
|       Settings.md
|
\---src
    +---Level04
    |   +---CheckPredefines
    |   |       checkpredefines.cpp
    |   |       checkpredefines.h
    |   |
    |   +---Hello
    |   |       hello.cpp
    |   |       hellowitherror.cpp
    |   |
    |   +---SQLite
    |   |       sqlite-amalgamation-3270000.zip
    |   |
    |   \---Sum
    |           Calculator.cpp
    |           Calculator.h
    |           Sum.cpp
    |
    +---Level05
           \---SophisticatedMath
            |
            +---AreaCalculation
            |       AreaCalculator.cpp
            |
            +---Calculator
            |       Calculator.cpp
            |       Calculator.h
            |       shared_EXPORTS.h
            |
            +---Docs
            |       readme.txt
            |
            \---PerimeterCalculation
                    PerimeterCalculator.cpp
```

We should create README file in your repository to explain other people what is a goal of our project, why it's useful and how they can use it. When we share open source software we ought to  license it. A software license will tells others what they can and can't do with our source code. Our local repository may contain configuration files, build output, or just backup files or user specific files created by IDE. To avoid pushing these files to GitHub repository we need specify unique file, types of files or directories in our .gitignore file. See an example below.

```txt
# VS Code
.vscode/
build/
# Visual Studio
.vs/
CMakeSettings.json
# QT Creator
build*/
CMakeLists.txt.user
# Ignore files
*.exe
*.dll
*.so
*.obj
*.o
*.lib
*.a
```

## C++ Project Structure

The most natural way of organizing C++ project is spreading source code into smaller parts. The modularity, code reuse and separation of concerns should be taken into account while dividing the code into logical parts. Common tasks can be grouped into functions and classes. They based on code reuse can be joined into file. Files predicated on separation of concerns can create a library. Libraries should be spread across different subdirectories in the source tree. Each executable should be placed in a different subdirectory also. This practice helps organizing code within a project. Because each library and executable can be build separately it simplifies and speeds up recompilation of a project during development. The source tree creates a hierarchy thus we call this source organization hierarchical project. We have a master directory and a subdirectory for each library and executable.  A master directory name of our project is SophisticatedMath. Each logical part of source code should be located in its own subdirectory. Our project has tree parts, two parts for applications and  one for libraries (static or dynamic). AreaCalculation application counts area of figures and depends on static library created from source code located in Calculator folder. On the other hand PerimeterCalculation app counts a perimeter of figure and depends this time on a dynamic library from the same source code like the static library (a common code located Calculator in subdirectory. To achieve this we use a solution bases on defining symbols) . The products of building will be placed in build folder. Inside build folder there are two folders bin and lib subfolders. Bin folder is for binaries and lib one is intended for static libraries, import libraries and export files.

```txt
The directory structure of a project

\---SophisticatedMath
    +---AreaCalculation
    |       AreaCalculator.cpp
    +---build
    |     \
    |      |
    |      +--bin
    |      |   *.exe; *.dll
    |      |
    |      \--lib
    |          *.a; ^.lib; *.exp
    |
    +---Calculator
    |       Calculator.cpp
    |       Calculator.h
    |       shared_EXPORTS.h
    |
    +---Docs
    |       readme.txt
    |
    \---PerimeterCalculation
            PerimeterCalculator.cpp
```

**Remark ! Build subdirectory is not placed on GitHub. This is a local folder utilized to store project binaries on a developer's machine.**  
Because we are funs of [DRY](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) we'll be building static and dynamic library from the same source code. To do that we'll use of preprocessor definition and this piece of code.  

```c++
#ifndef _SHARED_EXPORTS_H__
#define _SHARED_EXPORTS_H__

#if defined(_WIN32) && defined(DLL_BUILD)
    #ifdef shared_EXPORTS
        #define SHARED_EXPORT __declspec(dllexport)
    #else
        #define SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define SHARED_EXPORT
#endif

#endif /* _SHARED_EXPORTS_H__ */
```

How does it work? If it's Windows platform and we defined DLL_BUILD symbol, the value of SHARE_EXPORT depends on shared_EXPORTS symbol. If shared_EXPORTS is defined SHARED_EXPORT equals __declspec(dllexport). If not, SHARED_EXPORT equals __declspec(dllimport). Otherwise SHARED_EXPORT is empty. This trick allows us to define exports for a linker. Then we use SHARED_EXPORT symbol in Calculator.h file.  
Now time for a party. We'll be building **64-bit** apps so open a correct compiler environment.
Irrespective of a used compiler we can describe a process of building AreaCalculator very simple:

- make directory build if not exists
- switch to build directory
- create bin subfolder if not exists
- create lib subfolder if not exists
- create Calculator object file
- create static library from Calculator object file and put it in lib folder
- create AreaCalculation object file
- link all together to produce areacalc.exe executable and place it in bin folder  

and similar steps to create PerimeterCalculator app:

- make directory build if not exists
- switch to build directory
- create bin subfolder if not exists
- create lib subfolder if not exists
- create Calculator object file
- create dynamic library from Calculator object file and put it in lib folder
- create PerimeterCalculator object file
- link all together to produce perimcalc.exe executable and place it in bin folder  

Let's do it!  
First we create build folder structure inside our master folder.

- mkdir build
- cd build
- mkdir bin
- mkdir lib  

Now we are in build subfolder, so we begin to build our solution.

**Building AreaCalculator app (areacalc.exe)**  
To compile objects without errors we must inform the compiler in what folder it can find header files.
For this we use -I option.

Build with GNU compiler

| Create | GCC
| ----------- | ----------- |
| Calculator object file | g++.exe   -I../Calculator -c ../Calculator/Calculator.cpp
| Static library | ar.exe qc lib/libcalc-static.a  Calculator.o
| Main object file | g++.exe   -I../Calculator -c ../AreaCalculation/AreaCalculator.cpp
| Executable | g++.exe  AreaCalculator.o  -o bin/areacalc.exe lib/libcalc-static.a

Build with Microsoft compiler

| Create | MSVC
| ----------- | ----------- |
| Calculator object file | cl.exe  /nologo -I..\Calculator\. /EHsc  /FoCalculator.obj -c ..\Calculator\Calculator.cpp
| Static library | link.exe /lib[^1] /nologo /machine:x64 /out:lib\calc-static.lib Calculator.obj
| Main object file | cl.exe  /nologo -I..\Calculator\. /EHsc  /FoAreaCalculator.obj -c ..\AreaCalculation\AreaCalculator.cpp
| Executable | link.exe /nologo AreaCalculator.obj  /out:bin\areacalc.exe  /machine:x64  /subsystem:console  lib\calc-static.lib

[^1]: Another way of lib.exe /nologo /machine:x64 /out:lib\calc-static.lib Calculator.obj.

**Building PerimeterCalculator app (perimcalc.exe)**  
GNU compiler  

| Create | GCC
| ----------- | ----------- |
| Calculator object file | g++.exe  -DDLL_BUILD -Dshared_EXPORTS[^2] -I../Calculator -fvisibility=hidden[^3] -o Calculator.o -c ../Calculator/Calculator.cpp
| Dynamic library | g++.exe  -shared -o bin/libcalc-dll.dll -Wl,--out-implib,lib/libcalc-dll.dll.a Calculator.o  
| Main object file | g++.exe  -DDLL_BUILD -I../Calculator -o PerimeterCalculator.o -c ../PerimeterCalculation/PerimeterCalculator.cpp
| Executable | g++.exe PerimeterCalculator.o  -o bin/perimcalc.exe lib/libcalc-dll.dll.a

[^2]: To correctly export symbols to the object file we have to define preprocessor symbols.
[^3]: Because g++ by default exports all symbols we must change this. When we set -fvisibility=hidden option, only symbols tagged by an __declspec(dllexport) attribute will be exported.

Microsoft compiler

| Create | MSVC
| ----------- | ----------- |
| Calculator object file | cl.exe  /nologo  -DDLL_BUILD -Dshared_EXPORTS -I..\Calculator /EHsc /FoCalculator.obj -c ..\Calculator\Calculator.cpp
| Dynamic library | link.exe /nologo Calculator.obj  /out:bin\calc-dll.dll /implib:lib\calc-dll.lib /dll /machine:x64
| Main object file | cl.exe  /nologo -DDLL_BUILD -I..\Calculator /EHsc /FoPerimeterCalculator.obj -c ..\PerimeterCalculation\PerimeterCalculator.cpp
| Executable | link.exe /nologo PerimeterCalculator.obj  /out:bin\perimcalc.exe /machine:x64 /subsystem:console  lib\calc-dll.lib

After finishing a building process your build folder should look similar like that.

```txt
build
|   AreaCalculator.o
|   AreaCalculator.obj
|   Calculator.o
|   Calculator.obj
|   PerimeterCalculator.o
|   PerimeterCalculator.obj
|
+---bin
|       areacalc.exe
|       calc-dll.dll
|       libcalc-dll.dll
|       perimcalc.exe
|
\---lib
        calc-dll.exp
        calc-dll.lib
        calc-static.lib
        libcalc-dll.dll.a
        libcalc-static.a
```

Look at lib subfolder, there is  calc-dll.exp file. When LIB creates an import library, it also creates an export file. For more details see [Working with Import Libraries and Export Files]({{site.baseurl}}/Docs/AdditionalReadingResources#MSVC-id)
The project is still under construction, so stay tuned.:smile:
