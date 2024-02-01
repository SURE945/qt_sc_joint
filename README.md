# qt_sc_joint
qt and systemc joint compile, this can be used to implement a Man-machine interaction module, like uart etc.

## Install QT in Ubuntu
```
sudo apt-get install qtcreator
```
## Install SystemC in Ubuntu
1. download systemc (release 2.3.3) in https://github.com/accellera-official/systemc
2. unzip package
3. refer to INSTALL in systemc package to install
```
$ cd ./systemc-2.3.3 (your local directory)
$ mkdir objdir
$ cd objdir
$ export CXX=g++
$ ../configure CXXFLAGS=-std=c++11 (use c++11, default is 98)
$ gmake
$ gmake install
```
## new a project in QT
1. open qt
```
$ qtcreator &
```
2. new project, choose qt widgets projects
3. Build system choose CMake
## modify c_cpp_properties.json
add item in includePath, let vscode can find source code for QT and SystemC
```
"~/lib/systemc-2.3.3/include",
"/usr/include/x86_64-linux-gnu/qt5/QtWidgets",
"/usr/include/x86_64-linux-gnu/qt5/"
```
## modify the CMakeLists.txt
1. before add_executable(...) add systemc directory
```
link_directories(~/lib/systemc-2.3.3/lib-linux64)
include_directories(~/lib/systemc-2.3.3/include)
```
2. add include systemc in compile options
```
target_link_libraries(${PROJECT_NAME} PRIVATE -lsystemc)
```
## build and run
```
cd ./qt_sc_joint
cmake .
make
./qt_window
```