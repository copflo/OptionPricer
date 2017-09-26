# définition des extensions 
ifeq ($(OS),Windows_NT)
    DLLEXT := .dll
else
    DLLEXT := .so
endif

ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
else
    EXEEXT := 
endif


# répertoires
TARGETDIR := ../bin

ifeq ($(OS),Windows_NT)
    LIBDIR := ../bin
else
    LIBDIR := ../lib
endif


# cibles
EXE := $(TARGETDIR)/consoleapp$(EXEEXT)
LIBOPTIONS := $(LIBDIR)/libOptions$(DLLEXT)


# définition des variables
CXX := g++ 
CXXFLAGS := -std=c++11 -Wall

INC_PATH := ../include/options


#règles
all: $(EXE)

$(EXE): main.cpp $(LIBOPTIONS) $(TARGETDIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -I $(INC_PATH) -L$(LIBDIR) -lOptions -pthread 
	
$(LIBOPTIONS) : 
	make -C ../src/options
	
$(TARGETDIR) :
	mkdir ../bin
