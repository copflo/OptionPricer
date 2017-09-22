# définition des cibles particulières
.PHONY: clean, mrproper
.SUFFIXES:

# définition des variables
CC := g++ -std=c++11
CFLAGS := -Wall

OPTIONS_INC := include/options
OPTIONS_HEAD := $(wildcard $(OPTIONS_INC)/*.h)
OPTIONS_SRC := $(wildcard src/options/*.cpp)
OPTIONS_OBJ := $(subst src,obj,$(OPTIONS_SRC:.cpp=.o))

EXEC := bin/consoleapp
LIB_OPTIONS := lib/libOptions.so


# règles
all: $(EXEC)

bin/consoleapp: console-application/main.cpp $(LIB_OPTIONS)
	$(CC) $(CFLAGS) $< -o $@ -I $(OPTIONS_INC) -L lib -Wl,-rpath=lib -lOptions -pthread 

lib/libOptions.so: $(OPTIONS_OBJ) $(OPTIONS_HEAD)
	$(CC) $(CFLAGS) $(OPTIONS_OBJ) -o $@ -shared -fPIC -pthread 

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -fPIC -I $(OPTIONS_INC) 

clean: 
	rm -Rf obj/**/*.o

mrproper: clean
	rm -f $(EXEC)
