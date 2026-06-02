#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include <iostream>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  MyVensim - Testes Unitarios - Sprint 4" << std::endl;
    std::cout << "========================================" << std::endl;

    run_unit_tests_globals();
    std::cout << "[OK] Globals" << std::endl;

    run_unit_tests_System();
    std::cout << "[OK] System" << std::endl;

    run_unit_tests_Flow();
    std::cout << "[OK] Flow" << std::endl;

    run_unit_tests_Model();
    std::cout << "[OK] Model" << std::endl;

    std::cout << "========================================" << std::endl;
    std::cout << "  Todos os testes passaram com sucesso!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
