#include "unit_Model.h"
#include "../../src/model.hpp"
#include "../../src/flowImpl.hpp"
#include <assert.h>
#include <cmath>

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(std::string id = "", System* s = nullptr, System* t = nullptr) : FlowImpl(id, s, t) {}
    double execute() override {
        if (getSource() != nullptr)
            return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

void unit_Model_constructor(void) {
    Model& m = Model::createModel("m1");
    assert(m.beginSystems() == m.endSystems());
    assert(m.beginFlows()   == m.endFlows());

    delete &m;
}

void unit_Model_destructor(void) {
    Model& m = Model::createModel("m2");
    m.createSystem("s1", 50.0);
    m.createSystem("s2", 10.0);
    assert(m.beginSystems() != m.endSystems());

    delete &m; // o destrutor deve liberar os Systems internos sem causar erros
}

void unit_Model_createSystem(void) {
    Model& m = Model::createModel("m3");
    System& s1 = m.createSystem("populacao", 100.0);
    assert(s1.getValue() == 100.0);
    assert(s1.getName() == "populacao");
    assert(*m.beginSystems() == &s1);

    System& s2 = m.createSystem("recurso");
    assert(s2.getValue() == 0.0);

    int count = 0;
    for (auto it = m.beginSystems(); it != m.endSystems(); ++it) count++;
    assert(count == 2);

    delete &m;
}

void unit_Model_createFlux(void) {
    Model& m = Model::createModel("m4");
    System& s1 = m.createSystem("s1", 10.0);
    System& s2 = m.createSystem("s2", 20.0);

    Flow& f = m.createFlux<ExponentialFlow>("nascimento", &s1, &s2);
    assert(f.getSource() == &s1);
    assert(f.getTarget() == &s2);
    assert(*m.beginFlows() == &f);

    int count = 0;
    for (auto it = m.beginFlows(); it != m.endFlows(); ++it) count++;
    assert(count == 1);

    delete &m;
}

void unit_Model_deleteSystem(void) {
    Model& m = Model::createModel("m5");
    System& s1 = m.createSystem("s1", 1.0);
    System& s2 = m.createSystem("s2", 2.0);

    m.deleteSystem(s1);
    int count = 0;
    for (auto it = m.beginSystems(); it != m.endSystems(); ++it) count++;
    assert(count == 1);
    assert(*m.beginSystems() == &s2);

    delete &m;
}

void unit_Model_deleteFlux(void) {
    Model& m = Model::createModel("m6");
    System& s1 = m.createSystem("s1", 1.0);
    System& s2 = m.createSystem("s2", 2.0);
    Flow& f1 = m.createFlux<ExponentialFlow>("f1", &s1, &s2);
    Flow& f2 = m.createFlux<ExponentialFlow>("f2", &s2, &s1);

    m.deleteFlux(f1);
    int count = 0;
    for (auto it = m.beginFlows(); it != m.endFlows(); ++it) count++;
    assert(count == 1);
    assert(*m.beginFlows() == &f2);

    delete &m;
}

void unit_Model_setSource(void) {
    Model& m = Model::createModel("m7");
    System& s1 = m.createSystem("s1", 1.0);
    System& s2 = m.createSystem("s2", 2.0);
    Flow& f = m.createFlux<ExponentialFlow>("f");

    m.setSource(f, s1);
    assert(f.getSource() == &s1);

    m.setSource(f, s2);
    assert(f.getSource() == &s2);

    delete &m;
}

void unit_Model_setTarget(void) {
    Model& m = Model::createModel("m8");
    System& s1 = m.createSystem("s1", 1.0);
    System& s2 = m.createSystem("s2", 2.0);
    Flow& f = m.createFlux<ExponentialFlow>("f");

    m.setTarget(f, s1);
    assert(f.getTarget() == &s1);

    m.setTarget(f, s2);
    assert(f.getTarget() == &s2);

    delete &m;
}

void unit_Model_clearSource(void) {
    Model& m = Model::createModel("m9");
    System& s1 = m.createSystem("s1", 1.0);
    Flow& f = m.createFlux<ExponentialFlow>("f", &s1, nullptr);

    m.clearSource(f);
    assert(f.getSource() == nullptr);

    delete &m;
}

void unit_Model_clearTarget(void) {
    Model& m = Model::createModel("m10");
    System& s1 = m.createSystem("s1", 1.0);
    Flow& f = m.createFlux<ExponentialFlow>("f", nullptr, &s1);

    m.clearTarget(f);
    assert(f.getTarget() == nullptr);

    delete &m;
}

void unit_Model_beginSystems(void) {
    Model& m = Model::createModel("m11");
    assert(m.beginSystems() == m.endSystems());
    System& s = m.createSystem("s", 5.0);
    assert(m.beginSystems() != m.endSystems());
    assert(*m.beginSystems() == &s);

    delete &m;
}

void unit_Model_endSystems(void) {
    Model& m = Model::createModel("m12");
    m.createSystem("s1", 1.0);
    m.createSystem("s2", 2.0);
    m.createSystem("s3", 3.0);
    int count = 0;
    for (auto it = m.beginSystems(); it != m.endSystems(); ++it) count++;
    assert(count == 3);

    delete &m;
}

void unit_Model_beginFlows(void) {
    Model& m = Model::createModel("m13");
    assert(m.beginFlows() == m.endFlows());
    System& s1 = m.createSystem("s1", 1.0);
    System& s2 = m.createSystem("s2", 2.0);
    Flow& f = m.createFlux<ExponentialFlow>("f", &s1, &s2);
    assert(*m.beginFlows() == &f);

    delete &m;
}

void unit_Model_endFlows(void) {
    Model& m = Model::createModel("m14");
    System& s1 = m.createSystem("s1", 1.0);
    System& s2 = m.createSystem("s2", 2.0);
    m.createFlux<ExponentialFlow>("f1", &s1, &s2);
    m.createFlux<ExponentialFlow>("f2", &s2, &s1);
    int count = 0;
    for (auto it = m.beginFlows(); it != m.endFlows(); ++it) count++;
    assert(count == 2);

    delete &m;
}

void unit_Model_execute(void) {
    Model& sim = Model::createModel("sim");
    System& pop1 = sim.createSystem("pop1", 100.0);
    System& pop2 = sim.createSystem("pop2", 0.0);
    sim.createFlux<ExponentialFlow>("nascimento", &pop1, &pop2);
    sim.execute(0, 100, 1);
    assert(std::trunc(pop1.getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2.getValue() * 10000 + 0.5) == 633968);

    delete &sim;
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_createSystem();
    unit_Model_createFlux();
    unit_Model_deleteSystem();
    unit_Model_deleteFlux();
    unit_Model_setSource();
    unit_Model_setTarget();
    unit_Model_clearSource();
    unit_Model_clearTarget();
    unit_Model_beginSystems();
    unit_Model_endSystems();
    unit_Model_beginFlows();
    unit_Model_endFlows();
    unit_Model_execute();
}
