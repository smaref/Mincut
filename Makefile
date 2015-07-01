OBJECTDIR=obj
BIN=bin
SRC=src
INC=include
TEST=test
OBJECTFILES= ${OBJECTDIR}/function.o


# C Compiler Flags
CFLAGS=

# CC Compiler
CXX=icpc

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

all: mkdir func test

mkdir:
	mkdir -p obj
	mkdir -p bin

func: $(SRC)/function.cpp
	$(CXX) -c $(SRC)/function.cpp -I$(INC) -o $(OBJECTDIR)/function.o

test: func
	$(CXX) -c $(TEST)/test.cpp -I$(INC) -o $(OBJECTDIR)/test.o
	$(CXX) -o $(BIN)/test $(OBJECTDIR)/test.o $(OBJECTDIR)/function.o

clean:
	rm -if $(OBJECTDIR)/*
	rm -if $(BIN)/*