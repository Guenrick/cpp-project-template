/**
 * @file funcional_tests.cpp
 * @brief Implementação dos testes funcionais e das classes de fluxo específicas.
 * Este arquivo contém as implementações das classes filhas de Flow (Exponencial, 
 * Logístico e Complexo) utilizadas exclusivamente para validar a arquitetura do simulador,
 * bem como o código de execução de cada cenário de teste.
 */

#include "funcional_tests.hpp"
#include "../../src/model.hpp"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include <cassert>
#include <cmath> 

/**
 * @brief Classe que implementa um fluxo Exponencial para os testes.
 * Calcula a transferência de massa com base em uma taxa fixa (0.01) multiplicada
 * pelo valor atual do sistema de origem.
 */
class ExponentialFlow : public Flow {
public:
    /**
     * @brief Construtor da classe ExponentialFlow.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    ExponentialFlow(System* source = nullptr, System* target = nullptr) : Flow(source, target) {}
    
    /**
     * @brief Executa a equação do fluxo exponencial.
     * @return double O valor correspondente a 1% da massa do sistema de origem.
     */
    double execute() override {
        if (getSource() != nullptr) {
            return 0.01 * getSource()->getValue();
        }
        return 0.0;
    }
};

/**
 * @brief Classe que implementa um fluxo Logístico para os testes.
 * Calcula a transferência com base em uma equação de crescimento logístico 
 * dependente do valor do sistema de destino e de uma capacidade máxima (70.0).
 */
class LogisticFlow : public Flow {
public:
    /**
     * @brief Construtor da classe LogisticFlow.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    LogisticFlow(System* source = nullptr, System* target = nullptr) : Flow(source, target) {}
    
    /**
     * @brief Executa a equação do fluxo logístico.
     * @return double O valor calculado pela equação diferencial logística.
     */
    double execute() override {
        if (getTarget() != nullptr) {
            double p2 = getTarget()->getValue();
            return 0.01 * p2 * (1.0 - p2 / 70.0);
        }
        return 0.0;
    }
};

/**
 * @brief Classe que implementa um fluxo Complexo para os testes de rede.
 * Possui o mesmo comportamento matemático do fluxo exponencial, servindo
 * especificamente para interligar múltiplos sistemas no teste complexo de grafos.
 */
class ComplexFlow : public Flow {
public:
    /**
     * @brief Construtor da classe ComplexFlow.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    ComplexFlow(System* source = nullptr, System* target = nullptr) : Flow(source, target) {}
    
    /**
     * @brief Executa a equação do fluxo complexo.
     * @return double O valor correspondente a 1% da massa do sistema de origem.
     */
    double execute() override {
        if (getSource() != nullptr) {
            return 0.01 * getSource()->getValue();
        }
        return 0.0;
    }
};


void exponentialFuncionalTest() {
    System pop1(100.0);
    System pop2(0.0);
    ExponentialFlow f1(&pop1, &pop2);
    Model sim;
    
    sim.add(&pop1);
    sim.add(&pop2);
    sim.add(&f1);
    
    sim.execute(0, 100, 1);
    
    assert(std::round(pop1.getValue() * 10000) == 366032);
    assert(std::round(pop2.getValue() * 10000) == 633968);
}

void logisticalFuncionalTest() {
    System p1(100.0);
    System p2(10.0);
    LogisticFlow f1(&p1, &p2);
    Model sim;
    
    sim.add(&p1);
    sim.add(&p2);
    sim.add(&f1);
    
    sim.execute(0, 100, 1);
    
    assert(std::round(p1.getValue() * 10000) == 882167);
    assert(std::round(p2.getValue() * 10000) == 217833);
}

void complexFuncionalTest() {
    System q1(100.0), q2(0.0), q3(100.0), q4(0.0), q5(0.0);
    ComplexFlow f(&q1, &q2);
    ComplexFlow g(&q1, &q3);
    ComplexFlow r(&q2, &q5);
    ComplexFlow t(&q2, &q3);
    ComplexFlow u(&q3, &q4);
    ComplexFlow v(&q4, &q1);
    
    Model sim;
    sim.add(&q1); sim.add(&q2); sim.add(&q3); sim.add(&q4); sim.add(&q5);
    sim.add(&f); sim.add(&g); sim.add(&r); sim.add(&t); sim.add(&u); sim.add(&v);
    
    sim.execute(0, 100, 1);

    assert(std::round(q1.getValue() * 10000) == 318513);
    assert(std::round(q2.getValue() * 10000) == 184003);
    assert(std::round(q3.getValue() * 10000) == 771143);
    assert(std::round(q4.getValue() * 10000) == 561728);
    assert(std::round(q5.getValue() * 10000) == 164612);
}