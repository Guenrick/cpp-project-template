#include "unit_Flow.h"
#include "../../src/flowImpl.hpp"
// Aqui o flow ainda precisa ser incluido, pois ConcreteFlow herda de FlowImpl para definir execute()
#include "../../src/factory.hpp"
#include <assert.h>

class ConcreteFlow : public FlowImpl {
public:
    ConcreteFlow(System* s = nullptr, System* t = nullptr) : FlowImpl(s, t) {}
    double execute() override {
        if (getSource() != nullptr)
            return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

void unit_Flow_constructor(void) {
    ConcreteFlow f1;
    assert(f1.getSource() == nullptr);
    assert(f1.getTarget() == nullptr);

    System* s1 = createSystem(100.0);
    System* s2 = createSystem(0.0);
    // aqui não passamos mais o endereço de s1 e s2
    ConcreteFlow f2(s1, s2);
    assert(f2.getSource() == s1);
    assert(f2.getTarget() == s2);

    delete s1;
    delete s2;
}

void unit_Flow_destructor(void) {
    System* s1 = createSystem(10.0);
    System* s2 = createSystem(20.0);
    {
        ConcreteFlow f(s1, s2);
    }
    assert(s1->getValue() == 10.0);
    assert(s2->getValue() == 20.0);

    delete s1;
    delete s2;
}

void unit_Flow_copyConstructor(void) {
    System* s1 = createSystem(5.0);
    System* s2 = createSystem(15.0);
    ConcreteFlow original(s1, s2);
    ConcreteFlow copia(original);

    assert(copia.getSource() == s1);
    assert(copia.getTarget() == s2);

    delete s1;
    delete s2;
}

void unit_Flow_assignmentOperator(void) {
    System* s1 = createSystem(1.0);
    System* s2 = createSystem(2.0);
    ConcreteFlow f1(s1, s2);
    ConcreteFlow f2;

    f2 = f1;
    assert(f2.getSource() == s1);
    assert(f2.getTarget() == s2);

    f1 = f1;
    assert(f1.getSource() == s1);

    delete s1;
    delete s2;
}

void unit_Flow_setSource(void) {
    System* s1 = createSystem(10.0);
    System* s2 = createSystem(20.0);
    ConcreteFlow f;
    f.setSource(s1);
    assert(f.getSource() == s1);
    f.setSource(s2);
    assert(f.getSource() == s2);

    delete s1;
    delete s2;
}

void unit_Flow_setTarget(void) {
    System* s1 = createSystem(10.0);
    System* s2 = createSystem(20.0);
    ConcreteFlow f;
    f.setTarget(s1);
    assert(f.getTarget() == s1);
    f.setTarget(s2);
    assert(f.getTarget() == s2);

    delete s1;
    delete s2;
}

void unit_Flow_getSource(void) {
    System* s = createSystem(42.0);
    ConcreteFlow f(s, nullptr);
    assert(f.getSource() == s);
    assert(f.getSource()->getValue() == 42.0);

    delete s;
}

void unit_Flow_getTarget(void) {
    System* s = createSystem(77.0);
    ConcreteFlow f(nullptr, s);
    assert(f.getTarget() == s);
    // aqui testamos o getValue() do target para garantir que o target é realmente o sistema que criamos
    assert(f.getTarget()->getValue() == 77.0);

    delete s;
}

void unit_Flow_clearSource(void) {
    System* s = createSystem(10.0);
    ConcreteFlow f(s, nullptr);
    f.clearSource();
    assert(f.getSource() == nullptr);

    delete s;
}

void unit_Flow_clearTarget(void) {
    System* s = createSystem(10.0);
    ConcreteFlow f(nullptr, s);
    f.clearTarget();
    assert(f.getTarget() == nullptr);

    delete s;
}

void unit_Flow_execute(void) {
    System* s1 = createSystem(100.0);
    System* s2 = createSystem(0.0);
    ConcreteFlow f(s1, s2);
    assert(f.execute() == 1.0);

    ConcreteFlow f2(nullptr, s2);
    assert(f2.execute() == 0.0);

    delete s1;
    delete s2;
}

void run_unit_tests_Flow(void) {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_copyConstructor();
    unit_Flow_assignmentOperator();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_getSource();
    unit_Flow_getTarget();
    unit_Flow_clearSource();
    unit_Flow_clearTarget();
    unit_Flow_execute();
}
