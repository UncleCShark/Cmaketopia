---
layout: page
title: Project Structure
previous_page: CommandLine
next_page: CmakePhilosophy
---

# Project Structure

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
