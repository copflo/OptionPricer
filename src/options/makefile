# définition des cibles particulières
.PHONY: clean, mrproper
.SUFFIXES:


# définition des extensions
ifeq ($(OS),Windows_NT)
    DLLEXT := .dll
else
    DLLEXT := .so
endif


# répertoire cible
ifeq ($(OS),Windows_NT)
    LIBDIR := ../../bin
else
    LIBDIR := ../../lib
endif


# définition des variables
CXX := g++ 
CXXFLAGS := -std=c++11 -Wall

INC_PATH := ../../include/options
HEADERS := $(wildcard $(INC_PATH)/*.h)
SOURCES := $(wildcard *.cpp)
OBJ := $(addprefix obj/,$(SOURCES:.cpp=.o))

LIB := $(LIBDIR)/libOptions$(DLLEXT)


# règles
all: $(LIB)

$(LIB): $(HEADERS) $(OBJ) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ -shared -fPIC -pthread
	
obj/%.o: obj %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@ -fPIC -I $(INC_PATH) 

obj: 
	mkdir obj
	
clean: 
	rm -Rf obj/*.o

mrproper: clean
	rm -f $(LIB)