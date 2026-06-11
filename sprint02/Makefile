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

LIB = bin/libmyvensim.so

#alvo: dependencias
#	comandos
# -shared vai gerar uma biblioteca compartilhada .so ao invés de um executável, e -fPIC é necessário para criar código independente de posição, que é necessário para bibliotecas compartilhadas.	
lib:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -shared -fPIC $(SRC) -o $(LIB)
	@echo "Library compiled successfully."

all: clean lib unit funcional run_unit run_funcional
	@echo "All targets built and tests executed successfully."

#unit:lib garante que a .so é compilada antes dos testes
unit: lib #dependencia
	mkdir -p bin 
	$(CXX) $(CXXFLAGS) $(UNIT_SRC) -L bin -lmyvensim -Wl,-rpath,'$$ORIGIN' -o bin/unit_tests
	@echo "Unit tests compiled successfully."

funcional: lib
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(FUNC_SRC) -L bin -lmyvensim -Wl,-rpath,'$$ORIGIN' -o bin/funcional_tests
	@echo "Functional tests compiled successfully."

run_unit:
	./bin/unit_tests
	@echo "Unit tests executed successfully."

run_funcional:
	./bin/funcional_tests
	@echo "Functional tests executed successfully."

clean:
	rm -f bin/*
	@echo "Cleaned up bin directory."
