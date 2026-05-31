#include "unit_Model.h"
#include "../../src/model.hpp"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include <assert.h>
#include <cmath>

// Flow concreta para testes: retorna 0.01 * valor da origem (decaimento exponencial simples)
class ExponentialFlow : public Flow {
public:
    ExponentialFlow(System* s = nullptr, System* t = nullptr) : Flow(s, t) {}
    double execute() override {
        if (getSource() != nullptr)
            return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

void unit_Model_constructor(void) {
    Model m;
    assert(m.beginSystems() == m.endSystems());
    assert(m.beginFlows()   == m.endFlows());
}

void unit_Model_destructor(void) {
    System s(50.0);
    {
        Model m;
        m.add(&s);
    }
    // Model não é dono dos objetos, s deve continuar intacto
    assert(s.getValue() == 50.0);
}

void unit_Model_copyConstructor(void) {
    System s1(10.0), s2(20.0);
    ExponentialFlow f(&s1, &s2);
    Model original;
    original.add(&s1);
    original.add(&s2);
    original.add(&f);

    Model copia(original);

    assert(copia.beginSystems() != copia.endSystems());
    assert(copia.beginFlows()   != copia.endFlows());
    assert(*copia.beginSystems() == &s1);
    assert(*copia.beginFlows()   == &f);
}

void unit_Model_assignmentOperator(void) {
    System s(30.0);
    ExponentialFlow f(&s, nullptr);
    Model m1;
    m1.add(&s);
    m1.add(&f);

    Model m2;
    m2 = m1;

    assert(m2.beginSystems() != m2.endSystems());
    assert(m2.beginFlows()   != m2.endFlows());

    m1 = m1; // auto-atribuição
    assert(m1.beginSystems() != m1.endSystems());
}

void unit_Model_add_System(void) {
    Model m;
    System s1(1.0), s2(2.0);

    m.add(&s1);
    assert(m.beginSystems() != m.endSystems());
    assert(*m.beginSystems() == &s1);

    m.add(&s2);
    int count = 0;
    for (auto it = m.beginSystems(); it != m.endSystems(); ++it) count++;
    assert(count == 2);
}

void unit_Model_add_Flow(void) {
    Model m;
    System s1(1.0), s2(2.0);
    ExponentialFlow f1(&s1, &s2), f2(&s2, &s1);

    m.add(&f1);
    assert(m.beginFlows() != m.endFlows());
    assert(*m.beginFlows() == &f1);

    m.add(&f2);
    int count = 0;
    for (auto it = m.beginFlows(); it != m.endFlows(); ++it) count++;
    assert(count == 2);
}

void unit_Model_remove_System(void) {
    Model m;
    System s1(10.0), s2(20.0);
    m.add(&s1);
    m.add(&s2);

    m.remove(&s1);

    assert(*m.beginSystems() == &s2);
    int count = 0;
    for (auto it = m.beginSystems(); it != m.endSystems(); ++it) count++;
    assert(count == 1);
}

void unit_Model_remove_Flow(void) {
    Model m;
    System s1(1.0), s2(2.0);
    ExponentialFlow f1(&s1, &s2), f2(&s2, &s1);
    m.add(&f1);
    m.add(&f2);

    m.remove(&f1);

    assert(*m.beginFlows() == &f2);
    int count = 0;
    for (auto it = m.beginFlows(); it != m.endFlows(); ++it) count++;
    assert(count == 1);
}

void unit_Model_beginSystems(void) {
    Model m;
    assert(m.beginSystems() == m.endSystems());

    System s(5.0);
    m.add(&s);
    assert(m.beginSystems() != m.endSystems());
    assert(*m.beginSystems() == &s);
}

void unit_Model_endSystems(void) {
    Model m;
    System s1(1.0), s2(2.0), s3(3.0);
    m.add(&s1); m.add(&s2); m.add(&s3);

    int count = 0;
    for (auto it = m.beginSystems(); it != m.endSystems(); ++it) count++;
    assert(count == 3);
}

void unit_Model_beginFlows(void) {
    Model m;
    assert(m.beginFlows() == m.endFlows());

    System s1(1.0), s2(2.0);
    ExponentialFlow f(&s1, &s2);
    m.add(&f);
    assert(m.beginFlows() != m.endFlows());
    assert(*m.beginFlows() == &f);
}

void unit_Model_endFlows(void) {
    Model m;
    System s1(1.0), s2(2.0);
    ExponentialFlow f1(&s1, &s2), f2(&s2, &s1);
    m.add(&f1); m.add(&f2);

    int count = 0;
    for (auto it = m.beginFlows(); it != m.endFlows(); ++it) count++;
    assert(count == 2);
}

void unit_Model_execute(void) {
    System pop1(100.0), pop2(0.0);
    ExponentialFlow f(&pop1, &pop2);
    Model sim;
    sim.add(&pop1);
    sim.add(&pop2);
    sim.add(&f);

    sim.execute(0, 100, 1);

    assert(std::trunc(pop1.getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2.getValue() * 10000 + 0.5) == 633968);
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_copyConstructor();
    unit_Model_assignmentOperator();
    unit_Model_add_System();
    unit_Model_add_Flow();
    unit_Model_remove_System();
    unit_Model_remove_Flow();
    unit_Model_beginSystems();
    unit_Model_endSystems();
    unit_Model_beginFlows();
    unit_Model_endFlows();
    unit_Model_execute();
}
