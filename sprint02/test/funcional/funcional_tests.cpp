#include "funcional_tests.hpp"
#include "../../src/model.hpp"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include <cassert>
#include <cmath> 


class ExponentialFlow : public Flow {
public:
    ExponentialFlow(System* source = nullptr, System* target = nullptr) : Flow(source, target) {}
    
    double execute() override {
        if (getSource() != nullptr) {
            return 0.01 * getSource()->getValue();
        }
        return 0.0;
    }
};

class LogisticFlow : public Flow {
public:
    LogisticFlow(System* source = nullptr, System* target = nullptr) : Flow(source, target) {}
    
    double execute() override {
        if (getTarget() != nullptr) {
            double p2 = getTarget()->getValue();
            return 0.01 * p2 * (1.0 - p2 / 70.0);
        }
        return 0.0;
    }
};

class ComplexFlow : public Flow {
public:
    ComplexFlow(System* source = nullptr, System* target = nullptr) : Flow(source, target) {}
    
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
    
    assert(std::trunc(pop1.getValue() * 10000 + 0.5) == 366032);
    assert(std::trunc(pop2.getValue() * 10000 + 0.5) == 633968);
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
    
    assert(std::trunc(p1.getValue() * 10000 + 0.5) == 882167);
    assert(std::trunc(p2.getValue() * 10000 + 0.5) == 217833);
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
    
    assert(std::trunc(q1.getValue() * 10000 + 0.5) == 318513);
    assert(std::trunc(q2.getValue() * 10000 + 0.5) == 184003);
    assert(std::trunc(q3.getValue() * 10000 + 0.5) == 771143);
    assert(std::trunc(q4.getValue() * 10000 + 0.5) == 561728);
    assert(std::trunc(q5.getValue() * 10000 + 0.5) == 164612);
}