# répertoire cible
ifeq ($(OS),Windows_NT)
    LIBDIR := ../../bin
else
    LIBDIR := ../../lib
endif


# définition des variables
INC_PATH := ../../include/options
HEADERS := $(wildcard $(INC_PATH)/*.h)
SOURCES := $(wildcard *.cpp)
OBJ := $(addprefix obj/,$(SOURCES:.cpp=.o))
LIB := $(LIBDIR)/libOptions$(DLLEXT)


# règles
all: $(LIB)

$(LIB): $(HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ -shared -fPIC -pthread

obj/%.o: %.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@ -fPIC -I$(INC_PATH)

obj:
	mkdir -p $@
