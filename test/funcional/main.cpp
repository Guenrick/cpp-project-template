#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.hpp"
#include "../../src/model.hpp"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
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

#endif