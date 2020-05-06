# Qt-Application
A repository of practice of Qt applications. 

I'm still working on deployments of Qt applications. I'll update the ways of deployment ASAP.

## Software Requirements
Requires Qt 5.14.2 (Mingw-w64 on Windows, gcc on Mac/Linux). Tested only in Windows 10 & Ubuntu 20.04 LTS.

## How to Build
- If you're on Windows 10, build with Qt Creator.
  - Open Qt creator
  - Configure project compiler to be Mingw-w64.
  - `Ctrl` + `B` for build, `Ctrl` + `R` for run.
- If you're on macOS/Linux, you can either build with Qt Creator or terminal.
  - **Building in terminal &mdash; make sure `qmake` is in your system path!**
  - Open a terminal and navigate to the project directory.
  - Type in the following command:
    - `mkdir build && cd build`
    - `qmake ../<project_name>.pro && make`
    - `./<project_name>`
