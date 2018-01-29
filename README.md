OptionPricer
============

A project school on the pricing of several option classes by using several
widespread models (Binomial Trees, Black Scholes, Monte Carlo simulations, ...).
It is written in C++ and built with CMake. It also offers a graphical interface
written with Qt5.

## Building

### Windows

#### MinGW
There will probably be the need to tell CMake where to find Qt and to use MinGW
instead of MSVC.
In the command line, type:
```
>cmake -DCMAKE_PREFIX_PATH="path/to/Qt5/lib/cmake" -G"MinGW Makefiles" path/to/source
```

#### Visual Studio
As for MinGW, there will probably be the need to tell CMake where to find Qt.
CMake also needs to be told to generate a DEF file for exporting symbols and
create a .lib file for linking.
In the command line, type:
```
>cmake -DCMAKE_PREFIX_PATH="path/to/Qt5/lib/cmake" -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -G"Visual Studio <version_of_msvc> Win64" path/to/source
```

### Linux

#### Makefile
Just type:
```
>cmake path/to/source
```
