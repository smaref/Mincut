OBJ=obj
BIN=bin
SRC=src
INC=include
TEST=test
#OBJECTFILES= ${OBJECTDIR}/function.o ${OBJECTDIR}/build_components.o
OBJECTFILES = $(OBJ)/*

# C Compiler Flags
CFLAGS=

# CC Compiler
CXX=clang++

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

all: mkdir build_components obj_func test_build_edge_vector test_objec_gradient

mkdir:
	mkdir -p obj
	mkdir -p bin

build_comp: $(SRC)/build_components.cpp
	$(CXX) -c $< -I$(INC) -o $(OBJ)/$@.o
	
obj_func: $(SRC)/obj_func.cpp
	$(CXX) -c $< -I$(INC) -o $(OBJ)/$@.o
	

test_build_edge_vector: $(TEST)/edge_vec.cpp build_comp
	$(CXX) -c $< -I$(INC) -o $(OBJ)/$@.o
	$(CXX) -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/build_comp.o
	
test_mat_coeff: $(TEST)/coeff.cpp build_comp
	$(CXX) -c $< -I$(INC) -o $(OBJ)/$@.o
	$(CXX) -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/build_comp.o
	
test_objec_gradient: $(TEST)/create_vector_base.cpp obj_func
	$(CXX) -c $< -I$(INC) -o $(OBJ)/$@.o
	$(CXX) -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/obj_func.o
#test_objec_gradient: $(TEST)/create_matrix_vector.cpp obj_func
#	$(CXX) -c $< -I$(INC) -o $(OBJ)/$@.o
#	$(CXX) -o $(BIN)/$@ $(OBJ)/$@.o $(OBJ)/obj_func.o

clean:
	rm -if $(OBJ)/*
	rm -if $(BIN)/*
