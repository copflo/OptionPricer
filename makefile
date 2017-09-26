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
else
    EXEEXT := 
endif


# définition des répertoires
ifeq ($(OS),Windows_NT)
    LIBDIR := bin
else
    LIBDIR := lib
endif


# définition des variables
CONSOLEAPP := bin/consoleapp$(EXEEXT)
LIBOPTIONS := $(LIBDIR)/libOptions$(DLLEXT)


# règles
all: $(CONSOLEAPP) $(LIBOPTIONS)

$(CONSOLEAPP): 
	make -C console-application 
	
$(LIBOPTIONS): 
	make -C src/options 

clean: 
	rm -Rf **/obj/*.o

mrproper: clean
	rm -f $(CONSOLEAPP) $(LIBOPTIONS)
