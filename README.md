OptionPricer
============

A project school on the pricing of several option classes by using several
widespread models (Binomial Trees, Black Scholes, Monte Carlo simulations, ...).
It is written in C++ and built with CMake. It also offers a graphical interface
written with Qt.


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
In the command line, type:
```
>cmake -DCMAKE_PREFIX_PATH="path/to/Qt5/lib/cmake" -G"Visual Studio <version_of_msvc> Win64" path/to/source
```