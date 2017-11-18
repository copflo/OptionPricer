# répertoires
TARGETDIR := ../../bin
ifeq ($(OS),Windows_NT)
    LIBDIR := $(TARGETDIR)
else
    LIBDIR := ../../lib
endif
INC_DIR := ../../include

# cibles
EXE := $(TARGETDIR)/test-options$(EXEEXT)


# règles
all: $(EXE)

$(EXE): main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ -I$(INC_DIR) -L$(LIBDIR) -lOptions -lgtest -pthread
