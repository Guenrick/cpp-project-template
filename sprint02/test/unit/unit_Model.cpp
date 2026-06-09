#include "unit_Model.h"
#include "../../src/flowImpl.hpp"
#include "../../src/factory.hpp"
#include <assert.h>
#include <cmath>

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(System* s = nullptr, System* t = nullptr) : FlowImpl(s, t) {}
    double execute() override {
        if (getSource() != nullptr)
            return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

void unit_Model_constructor(void) {
    Model* m = createModel();
    assert(m->beginSystems() == m->endSystems());
    assert(m->beginFlows()   == m->endFlows());

    delete m;
}

void unit_Model_destructor(void) {
    System* s = createSystem(50.0);
    { Model* m = createModel(); m->add(s); 
        delete m; // aqui testamos se o destructor do Model não deleta os sistemas, ou seja, o sistema deve continuar existindo mesmo depois do Model ser destruído   
    }
    assert(s->getValue() == 50.0);

    delete s;
}

void unit_Model_copyConstructor(void) {
    System* s1 = createSystem(10.0);
    System* s2 = createSystem(20.0);
    ExponentialFlow f(s1, s2);
    Model* original = createModel();
    original->add(s1); original->add(s2); original->add(&f);

    Model* copia = createModel();   //createModel não tem argumento, então criamos um Model vazio e depois copiamos os elementos do original para a cópia
    copia->add(s1); copia->add(s2); copia->add(&f); // aqui copiamos os elementos do original para a cópia, ou seja, a cópia tem os mesmos sistemas e fluxos do original
    assert(*copia->beginSystems() == s1);
    assert(*copia->beginFlows()   == &f);

    delete original;
    delete copia;
    delete s1;
    delete s2;
}

void unit_Model_assignmentOperator(void) {
    System* s1 = createSystem(30.0);
    ExponentialFlow f(s1, nullptr);
    Model* m1 = createModel();
    m1->add(s1); m1->add(&f);

    Model* m2 = createModel();
    // m2 = m1; antes copiava os elementos, agora m2 aponta para o mesmo objeto que m1, ou seja, m1 e m2 são o mesmo objeto
    m2->add(s1); m2->add(&f); // aqui copiamos os elementos de m1 para m2, ou seja, m2 tem os mesmos sistemas e fluxos de m1
    assert(m2->beginSystems() != m2->endSystems());
    assert(m2->beginFlows()   != m2->endFlows());

    m1 = m1;
    assert(m1->beginSystems() != m1->endSystems());

    delete m1;
    delete m2;
    delete s1;
}

void unit_Model_add_System(void) {
    Model* m = createModel();
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    m->add(s1);
    assert(m->beginSystems() != m->endSystems());
    assert(*m->beginSystems() == s1);

    m->add(s2);
    int count = 0;
    for (auto it = m->beginSystems(); it != m->endSystems(); ++it) count++;
    assert(count == 2);

    delete m;
    delete s1;
    delete s2;
}

void unit_Model_add_Flow(void) {
    Model* m = createModel();
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    ExponentialFlow f1(s1, s2), f2(s2, s1);
    m->add(&f1); m->add(&f2);
    int count = 0;
    for (auto it = m->beginFlows(); it != m->endFlows(); ++it) count++;
    assert(count == 2);

    delete m;
    delete s1;
    delete s2;
}

void unit_Model_remove_System(void) {
    Model* m = createModel();
    System* s1 = createSystem(10.0);
    System* s2 = createSystem(20.0);
    m->add(s1); m->add(s2);
    m->remove(s1);
    assert(*m->beginSystems() == s2);
    
    delete m;
    delete s1;
    delete s2;
}

void unit_Model_remove_Flow(void) {
    Model* m = createModel();
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    ExponentialFlow f1(s1, s2), f2(s2, s1);
    m->add(&f1); m->add(&f2);
    m->remove(&f1);
    assert(*m->beginFlows() == &f2);

    delete m;
    delete s1;
    delete s2;
}

void unit_Model_beginSystems(void) {
    Model* m = createModel();
    assert(m->beginSystems() == m->endSystems());
    System* s = createSystem(5.0);
    m->add(s);
    assert(m->beginSystems() != m->endSystems());
    assert(*m->beginSystems() == s);

    delete m;
    delete s;
}

void unit_Model_endSystems(void) {
    Model* m = createModel();
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    System* s3 = createSystem(3.0);
    m->add(s1); m->add(s2); m->add(s3);
    int count = 0;
    for (auto it = m->beginSystems(); it != m->endSystems(); ++it) count++;
    assert(count == 3);

    delete m;
    delete s1;
    delete s2;
    delete s3;
}


void unit_Model_beginFlows(void) {
    Model* m = createModel();
    assert(m->beginFlows() == m->endFlows());
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    ExponentialFlow f(s1, s2);
    m->add(&f);
    assert(*m->beginFlows() == &f);
    
    delete m;
    delete s1;
    delete s2;
}

void unit_Model_endFlows(void) {
    Model* m = createModel();
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    ExponentialFlow f1(s1, s2), f2(s2, s1);
    m->add(&f1); m->add(&f2);
    int count = 0;
    for (auto it = m->beginFlows(); it != m->endFlows(); ++it) count++;
    assert(count == 2);

    delete m;
    delete s1;
    delete s2;
}

void unit_Model_execute(void) {
    System* pop1 = createSystem(100.0);
    System* pop2 = createSystem(0.0);
    ExponentialFlow f(pop1, pop2);
    Model* sim = createModel();
    sim->add(pop1); sim->add(pop2); sim->add(&f);
    sim->execute(0, 100, 1);
    assert(std::trunc(pop1->getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2->getValue() * 10000 + 0.5) == 633968);

    delete sim;
    delete pop1;
    delete pop2;
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
