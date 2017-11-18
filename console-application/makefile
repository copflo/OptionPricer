# répertoires
TARGETDIR := ../bin

ifeq ($(OS),Windows_NT)
    LIBDIR := ../bin
else
    LIBDIR := ../lib
endif

INC_PATH := ../include


# cibles
EXE := $(TARGETDIR)/consoleapp$(EXEEXT)


#règles
all: $(EXE)

$(EXE): main.cpp $(TARGETDIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -I$(INC_PATH) -L$(LIBDIR) -lOptions -pthread
