CC = g++
CFLAGS = -Iinclude -Wall
SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test

# Garante que a pasta bin existe antes de compilar
$(shell mkdir -p $(BIN_DIR))

all: $(BIN_DIR)/main.exe

# Compilação do programa principal (main + biblioteca)
$(BIN_DIR)/main.exe: $(SRC_DIR)/main.cpp $(SRC_DIR)/bib.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(SRC_DIR)/bib.cpp -o $(BIN_DIR)/main.exe

# Regra para o teste de regressão (Item 9)
test: $(SRC_DIR)/bib.cpp $(TEST_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/bib.cpp $(TEST_DIR)/main.cpp -o $(BIN_DIR)/testeRegressivo.exe
	./$(BIN_DIR)/testeRegressivo.exe

clean:
	rm -f $(BIN_DIR)/*