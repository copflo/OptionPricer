# shell commands
ifeq ($(OS),Windows_NT)
    RM := del
else
    RM := rm -Rf
endif


# définition des cibles particulières
.PHONY: clean, mrproper
.SUFFIXES:


# définition des extensions
ifeq ($(OS),Windows_NT)
    DLLEXT := .dll
else
    DLLEXT := .so
endif

ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
endif


# définition des variables
CXX := g++
CXXFLAGS := -std=c++11 -Wall


# export variables
export DLLEXT
export EXEEXT
export CXX
export CXXFLAGS


# définition des répertoires
ifeq ($(OS),Windows_NT)
    LIBDIR := bin
else
    LIBDIR := lib
endif


# cibles
CONSOLEAPP := bin/consoleapp$(EXEEXT)
TEST_OPTIONS := bin/test-options$(EXEEXT)
LIB_OPTIONS := $(LIBDIR)/libOptions$(DLLEXT)


# règles
all: $(CONSOLEAPP) $(TEST_OPTIONS)

$(CONSOLEAPP): $(LIB_OPTIONS)
	make -C console-application all

$(TEST_OPTIONS): $(LIB_OPTIONS)
	make -C test/test-options all

$(LIB_OPTIONS):
	make -C src/options all

clean:
	$(RM) **/obj/*.o

mrproper: clean
	$(RM) $(CONSOLEAPP) $(LIB_OPTIONS)
