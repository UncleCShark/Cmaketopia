---
layout: page
title: Build System
previous_page: ProjectOrganization
next_page: CmakePhilosophy
---

# Build system

Build automation is the process of automating the creation of a software package. In general it includes: compiling source code, running automated tests, and the creation of a installation package. Build-automation tools allow the automation of simple, repeatable tasks. When we use them we improve team efficiency and production as well as product quality. As a result of it we achieve faster product delivery. When we choose a build system we should take into consideration if we want:

- to support multiple compilers
- to use various IDEs,
- to support different OSs
- to use CI (continuous integration)  

 When the [build systems](https://en.wikipedia.org/wiki/List_of_build_automation_software) come into play we should be familiar with a notion of a [target](https://cmake.org/cmake/help/v3.13/manual/cmake-buildsystem.7.html). The build systems:construction_worker::construction_worker: organize files into targets. Each target corresponds to an executable or library, or is a custom target containing custom commands or actions the build tool must perform, such as installing an application, whereas a project is a logical group of targets gathered together into a self-contained collection that can be built on its own. Projects are the containers that developers use to organize source code files and other resources. When we think about building of software project two new concepts emerge. A source directory and a binary directory. The source directory is where source code and resources files are located. The build system needs them to create binaries. Inside the source directory there are build system files contain a set of directives describing how to build, test, and deploy a project. The source directory is frequently under version control (GIT, SVN, Mercurial etc). The binary directory is where every items created by the build system are placed. These are object and temporary files, executables, libraries, test output and packages created during the build process.

## Cross-platform solution

As cross-platform programmers we need a simple build system which we can leverage on many platforms in the same way irrespective of IDE or toolchain we utilize. We use it to configure the build options and create the final applications or libraries from sources. That tasks developers have to repeat several times every day, so it is extremely important to ensure that the process is under control and repeatable.

## Powerful duo comes to rescue

Our project is growing. More and more modules come into play. That will be harder to do all things manually. We need automate a build process. It's about time we need to get familiar with the main actors of our story. Ladies and gentlemen let me introduce a fantastic couple:couple: [Cmake](https://cmake.org/) and [Ninja](https://ninja-build.org/). As we may expect these are command line tools too. It means we need run they from a shell. [Run your shell](https://en.wikipedia.org/wiki/Shell_\(computing\)) such a bash on Unix , cmd.exe or Msys2 shell on Windows. Now an operating system is at our command.  
Type **cmake \-\-version** and press Enter.
![Cmake](../assets/cmake.png)  
Type **cmake \-\-help** don't forget about **enter**, now  **cmake \-\-help-command-list** and **cmake \-\-help-manual-list**. I feel we got the hang of the first tool.  
Now Ninja. Type **ninja \-\-version** and press Enter.  
![Ninja](../assets/ninja.png)  
Before we'll delve into building processes, we have the opportunity to strut our stuff.  
![Cmake stuff](../assets/cmakestuff.png)

- [cmake.exe](https://cmake.org/cmake/help/v3.14/manual/cmake.1.html) command-line tool of the cross-platform buildsystem generator
- [cmake-gui.exe](https://cmake.org/cmake/help/v3.14/manual/cmake-gui.1.html#manual:cmake-gui(1)) is Cmake GUI program
- cmcldeps.exe - wrapper around cl.exe (MSVC compiler) that adds /showIncludes to command line. /showIncludes option is an equivalent of gcc -MD
- [cpack.exe](https://gitlab.kitware.com/cmake/community/wikis/doc/cpack/Packaging-With-CPack) is Cmake packaging tool
- [ctest.exe](https://cmake.org/cmake/help/v3.14/manual/ctest.1.html) is a Cmake test runner tool
- [ninja.exe](https://ninja-build.org/) is a small build system with a focus on speed.

## Our first cmake project - HelloWorld

Open MSYS2 Mingw-w64 command line and create HelloWorld folder (mkdir HelloWorld) for a project. Then run your favourite text editor (notepad for example) and write code as below:

```c++
#include <iostream>
int main()
{
    std::cout << "Hello, World!";
    return 0;
}
```

Save a written source code as hello.cpp in HelloWorld folder.  
Create a new file inside the editor (File->New) and type:

```cmake
# CMakeList.txt : HelloWorld CMake project file
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project("HelloWorld" LANGUAGES CXX)

add_executable(hello hello.cpp)

```

Save text as CMakeLists.txt file. Close the editor. Make build directory. Your project folder structure should look like as follows:  

```txt
   HelloWorld
    \   CMakeLists.txt
    |   hello.cpp
    |
    \---build
```

You should be inside HelloWorld folder.  
Create and run hello executable.

```txt
cd build
cmake -GNinja ..
cmake --build .
./hello
```

Under construction stay tuned :smile:  
<!-- blank line -->
<figure class="video_container">
  <iframe src="https://www.youtube.com/embed/5A4k0q0KY1o" frameborder="0" allowfullscreen="true"> </iframe>
</figure>
<!-- blank line -->
