#include "funcional_tests.hpp"
#include "../../src/modelImpl.hpp"
#include "../../src/systemImpl.hpp"
#include "../../src/flowImpl.hpp"
#include <cassert>
#include <cmath>

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(System* s = nullptr, System* t = nullptr) : FlowImpl(s, t) {}
    double execute() override {
        if (getSource() != nullptr) return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

class LogisticFlow : public FlowImpl {
public:
    LogisticFlow(System* s = nullptr, System* t = nullptr) : FlowImpl(s, t) {}
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
    ComplexFlow(System* s = nullptr, System* t = nullptr) : FlowImpl(s, t) {}
    double execute() override {
        if (getSource() != nullptr) return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

void exponentialFuncionalTest(void) {
    SystemImpl pop1(100.0), pop2(0.0);
    ExponentialFlow f1(&pop1, &pop2);
    ModelImpl sim;
    sim.add(&pop1); sim.add(&pop2); sim.add(&f1);
    sim.execute(0, 100, 1);
    assert(std::trunc(pop1.getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2.getValue() * 10000 + 0.5) == 633968);
}

void logisticalFuncionalTest(void) {
    SystemImpl p1(100.0), p2(10.0);
    LogisticFlow f1(&p1, &p2);
    ModelImpl sim;
    sim.add(&p1); sim.add(&p2); sim.add(&f1);
    sim.execute(0, 100, 1);
    assert(std::trunc(p1.getValue() * 10000 + 0.5) == 882167);
    assert(std::trunc(p2.getValue() * 10000 + 0.5) == 217833);
}

void complexFuncionalTest(void) {
    SystemImpl q1(100.0), q2(0.0), q3(100.0), q4(0.0), q5(0.0);
    ComplexFlow f(&q1,&q2), g(&q1,&q3), r(&q2,&q5);
    ComplexFlow t(&q2,&q3), u(&q3,&q4), v(&q4,&q1);
    ModelImpl sim;
    sim.add(&q1); sim.add(&q2); sim.add(&q3); sim.add(&q4); sim.add(&q5);
    sim.add(&f);  sim.add(&g);  sim.add(&r);  sim.add(&t);  sim.add(&u);  sim.add(&v);
    sim.execute(0, 100, 1);
    assert(std::trunc(q1.getValue() * 10000 + 0.5) == 318513);
    assert(std::trunc(q2.getValue() * 10000 + 0.5) == 184003);
    assert(std::trunc(q3.getValue() * 10000 + 0.5) == 771143);
    assert(std::trunc(q4.getValue() * 10000 + 0.5) == 561728);
    assert(std::trunc(q5.getValue() * 10000 + 0.5) == 164612);
}
