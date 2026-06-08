#include "funcional_tests.hpp"
#include <iostream>

int main() {
    std::cout << "Iniciando testes funcionais...\n" << std::endl;

    exponentialFuncionalTest();
    std::cout << "[OK] -> Teste Exponencial passou com sucesso!" << std::endl;

    logisticalFuncionalTest();
    std::cout << "[OK] -> Teste Logistico passou com sucesso!" << std::endl;

    complexFuncionalTest();
    std::cout << "[OK] -> Teste Complexo passou com sucesso!" << std::endl;

    return 0;
}
