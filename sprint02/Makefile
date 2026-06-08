CXX      = g++
CXXFLAGS = -Wall -std=c++11 -I src -I test/unit -I test/funcional

SRC      = src/systemImpl.cpp src/flowImpl.cpp src/modelImpl.cpp

UNIT_SRC = test/unit/main.cpp \
           test/unit/unit_tests.cpp \
           test/unit/unit_System.cpp \
           test/unit/unit_Flow.cpp \
           test/unit/unit_Model.cpp

FUNC_SRC = test/funcional/main.cpp \
           test/funcional/funcional_tests.cpp

all: clean unit funcional run_unit run_funcional

unit:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) $(UNIT_SRC) -o bin/unit_tests

funcional:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) $(FUNC_SRC) -o bin/funcional_tests

run_unit:
	./bin/unit_tests

run_funcional:
	./bin/funcional_tests

clean:
	rm -f bin/*
