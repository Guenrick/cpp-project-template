CXX = g++
# O -I avisa o compilador para buscar os cabecalhos dentro dessas pastas
CXXFLAGS = -Wall -Wextra -std=c++11 -I src -I test/funcional

# Fontes e testes
SRC = src/system.cpp src/flow.cpp src/model.cpp
TEST_FUNC = test/funcional/main.cpp test/funcional/funcional_tests.cpp

# Destino do executavel
EXEC = bin/funcional_tests

all: clean funcional run

funcional:
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST_FUNC) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -f bin/*