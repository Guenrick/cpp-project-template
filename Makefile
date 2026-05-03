# Variáveis
CC = g++
CFLAGS = -Iinclude -Wall
SRC_DIR = src
BIN_DIR = bin

# Regra principal: compila o main.cpp
all: $(BIN_DIR)/main.exe

$(BIN_DIR)/main.exe: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp -o $(BIN_DIR)/main.exe

# Regra para limpar a pasta bin
clean:
	rm -f $(BIN_DIR)/*
