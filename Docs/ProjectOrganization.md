---
layout: page
title: Project Organization
previous_page: CommandLine
next_page: CmakePhilosophy
---

# Project Organization

In this part of the tutorial we'll develop a project SophisticatedMath.  We will do it in a three-person team. Each member of the team will use a different type of IDE, Visual Studio, Vs Code, QT Creator respectably. We'll be utilize IDE only for writing code. We'll compile source code outside of the IDE manually. Our task will be to create two executable and two libraries, one static and one dynamic. We will consider how to organize the work of our team, so that local settings of one person's programming environment do not have a destructive impact on the work of other team members. The structure of our projects should be easy to read and follow the same pattern.

## GitHub Repository

We are Cmaketopians thus we leverage a GitHub version control repository to backup and share our ideas. Our repositories should have the appropriate structure of directories and files based on convention. The similar structure help us reading easily other projects. Because we create a cross-platform project our domain project repository should be platform independent. Additional platform specific modules should create platform specific projects. In general our repository contains source code, data and documentation of projects, as well as a license, a readme and .gitignore files.

## C++ Project Structure

The most natural way of organizing C++ project is spreading source code into smaller parts. The modularity, code reuse and separation of concerns should be taken into account while dividing the code into logical parts. Common tasks can be grouped into functions and classes. They based on code reuse can be joined into file. Files predicated on separation of concerns can create a library. Libraries should be spread across different subdirectories in the source tree. Each executable should be placed in a different subdirectory also. This practice helps organizing code within a project. Because each library and executable can be build separately it simplifies and speeds up recompilation of a project during development. The source tree creates a hierarchy thus we call this source organization hierarchical project. We have a master directory and a subdirectory for each library and executable.  A master directory name of project is SophisticatedMath. Each logical part of source code should be located in its own subdirectory. One application will count area of figures and the other perimeters. Binaries will be placed in a folder named "build" inside of a project directory.  Because we have common repository for our tutorial we'll place SophisticatedMath directory in src/Level05 folder. In a typical repository the project directory is located in src folder. Let's do it!

```txt
The directory structure of a project

\---SophisticatedMath
    +---AreaCalculation
    |       AreaCalculator.cpp
    +---build
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

**Remark ! Build subdirectory is not placed on GitHub. This is a local folder intended for project binaries on a local machine.**  
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
The project is still under construction, so stay tuned.:smile:

## Build system

As cross-platform programmers we need a simple build system which we can leverage on many platforms in the same way irrespective of IDE or toolchain we utilize. We use it to configure the build options and create the final applications or libraries from sources. That tasks developers have to repeat several times every day, so it is extremely important to ensure that the process is under control and repeatable. When the [build systems](https://en.wikipedia.org/wiki/List_of_build_automation_software) come into play we should be familiar with a notion of a [target](https://cmake.org/cmake/help/v3.13/manual/cmake-buildsystem.7.html). The build systems:construction_worker::construction_worker: organize files into targets. Each target corresponds to an executable or library, or is a custom target containing custom commands or actions the build tool must perform, such as installing an application. It's about time we need to get familiar with the main actors of our story. Ladies and gentlemen let me introduce a fantastic couple:couple: [Cmake](https://cmake.org/) and [Ninja](https://ninja-build.org/). As we may expect these are command line tools too. It means we need run they from a shell. [Run your shell](https://en.wikipedia.org/wiki/Shell_\(computing\)) such a bash on Unix , cmd.exe or Mingw64-w64 shell on Windows. Now an operating system is at our command.  
Type **cmake \-\-version** and press Enter.
![Cmake](../assets/cmake.png)  
Type **cmake \-\-help** don't forget about **enter**, now  **cmake \-\-help-command-list** and **cmake \-\-help-manual-list**. I feel we got the hang of the first tool.  
Now Ninja. Type **ninja \-\-version** and press Enter. See Ninja documentation for more details and try another command. All is under our control. We are not rabbits :rabbit::rabbit2: now.  
![Ninja](../assets/ninja.png)  

<!-- blank line -->
<figure class="video_container">
  <iframe src="https://www.youtube.com/embed/9jK-NcRmVcw" frameborder="0" allowfullscreen="true"> </iframe>
</figure>
<!-- blank line -->
