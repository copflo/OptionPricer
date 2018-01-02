# répertoire cible
ifeq ($(OS),Windows_NT)
    LIBDIR := ../../bin
else
    LIBDIR := ../../lib
endif


# définition des variables
INCLUDE := ../../include
INCLUDE_OPT := $(INCLUDE)/options
HEADERS := $(wildcard $(INCLUDE_OPT)/*.h)
SOURCES := $(wildcard *.cpp)
OBJ := $(addprefix obj/,$(SOURCES:.cpp=.o))
LIB := $(LIBDIR)/libOptions$(DLLEXT)


# règles
all: $(LIB)

$(LIB): $(HEADERS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ -shared -fPIC -pthread

obj/%.o: %.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@ -fPIC -I$(INCLUDE) -I$(INCLUDE_OPT)

obj:
	mkdir -p $@
