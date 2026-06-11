#include "funcional_tests.hpp"
#include "../../src/model.hpp"
#include "../../src/flowImpl.hpp"
#include <cassert>
#include <cmath>

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(std::string id = "", System* s = nullptr, System* t = nullptr) : FlowImpl(id, s, t) {}
    double execute() override {
        if (getSource() != nullptr) return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

class LogisticFlow : public FlowImpl {
public:
    LogisticFlow(std::string id = "", System* s = nullptr, System* t = nullptr) : FlowImpl(id, s, t) {}
    double execute() override {
        if (getTarget() != nullptr) {
            double p2 = getTarget()->getValue();
            return 0.01 * p2 * (1.0 - p2 / 70.0);
        }
        return 0.0;
    }
};

class ComplexFlow : public FlowImpl {
public:
    ComplexFlow(std::string id = "", System* s = nullptr, System* t = nullptr) : FlowImpl(id, s, t) {}
    double execute() override {
        if (getSource() != nullptr) return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

void exponentialFuncionalTest(void) {
    Model& sim = Model::createModel("sim_exponencial");
    System& pop1 = sim.createSystem("pop1", 100.0);
    System& pop2 = sim.createSystem("pop2", 0.0);
    sim.createFlux<ExponentialFlow>("nascimento", &pop1, &pop2);
    sim.execute(0, 100, 1);
    assert(std::trunc(pop1.getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2.getValue() * 10000 + 0.5) == 633968);

    delete &sim;
}

void logisticalFuncionalTest(void) {
    Model& sim = Model::createModel("sim_logistico");
    System& p1 = sim.createSystem("p1", 100.0);
    System& p2 = sim.createSystem("p2", 10.0);
    sim.createFlux<LogisticFlow>("crescimento", &p1, &p2);
    sim.execute(0, 100, 1);
    assert(std::trunc(p1.getValue() * 10000 + 0.5) == 882167);
    assert(std::trunc(p2.getValue() * 10000 + 0.5) == 217833);

    delete &sim;
}

void complexFuncionalTest(void) {
    Model& sim = Model::createModel("sim_complexo");
    System& q1 = sim.createSystem("q1", 100.0);
    System& q2 = sim.createSystem("q2", 0.0);
    System& q3 = sim.createSystem("q3", 100.0);
    System& q4 = sim.createSystem("q4", 0.0);
    System& q5 = sim.createSystem("q5", 0.0);

    sim.createFlux<ComplexFlow>("f", &q1, &q2);
    sim.createFlux<ComplexFlow>("g", &q1, &q3);
    sim.createFlux<ComplexFlow>("r", &q2, &q5);
    sim.createFlux<ComplexFlow>("t", &q2, &q3);
    sim.createFlux<ComplexFlow>("u", &q3, &q4);
    sim.createFlux<ComplexFlow>("v", &q4, &q1);

    sim.execute(0, 100, 1);
    assert(std::trunc(q1.getValue() * 10000 + 0.5) == 318513);
    assert(std::trunc(q2.getValue() * 10000 + 0.5) == 184003);
    assert(std::trunc(q3.getValue() * 10000 + 0.5) == 771143);
    assert(std::trunc(q4.getValue() * 10000 + 0.5) == 561728);
    assert(std::trunc(q5.getValue() * 10000 + 0.5) == 164612);

    delete &sim;
}
