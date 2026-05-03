#include <iostream>
#include "../include/bib.hpp"
#include <cassert>

int main() {
    std::cout << "Iniciando testes de regressao..." << std::endl;
    assert(fatorial(5) == 120);
    assert(fatorial(0) == 1);
    std::cout << "Todos os testes passaram!" << std::endl;
    return 0;
}