#include "unit_Flow.h"
#include "../../src/flowImpl.hpp"
#include "../../src/systemImpl.hpp"
#include <assert.h>

// ConcreteFlow agora recebe um id (3 parametros: id, source, target),
// conforme exigido pelo Model::createFlux<T_FLUX_IMPL>.
class ConcreteFlow : public FlowImpl {
public:
    ConcreteFlow(std::string id = "", System* s = nullptr, System* t = nullptr) : FlowImpl(id, s, t) {}
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

    SystemImpl s1("s1", 100.0);
    SystemImpl s2("s2", 0.0);
    ConcreteFlow f2("f2", &s1, &s2);
    assert(f2.getSource() == &s1);
    assert(f2.getTarget() == &s2);
}

void unit_Flow_destructor(void) {
    SystemImpl s1("s1", 10.0);
    SystemImpl s2("s2", 20.0);
    {
        ConcreteFlow f("f", &s1, &s2);
    }
    assert(s1.getValue() == 10.0);
    assert(s2.getValue() == 20.0);
}

void unit_Flow_copyConstructor(void) {
    SystemImpl s1("s1", 5.0);
    SystemImpl s2("s2", 15.0);
    ConcreteFlow original("original", &s1, &s2);
    ConcreteFlow copia(original);

    assert(copia.getSource() == &s1);
    assert(copia.getTarget() == &s2);
}

void unit_Flow_assignmentOperator(void) {
    SystemImpl s1("s1", 1.0);
    SystemImpl s2("s2", 2.0);
    ConcreteFlow f1("f1", &s1, &s2);
    ConcreteFlow f2;

    f2 = f1;
    assert(f2.getSource() == &s1);
    assert(f2.getTarget() == &s2);

    f1 = f1;
    assert(f1.getSource() == &s1);
}

void unit_Flow_setSource(void) {
    SystemImpl s1("s1", 10.0);
    SystemImpl s2("s2", 20.0);
    ConcreteFlow f;
    f.setSource(&s1);
    assert(f.getSource() == &s1);
    f.setSource(&s2);
    assert(f.getSource() == &s2);
}

void unit_Flow_setTarget(void) {
    SystemImpl s1("s1", 10.0);
    SystemImpl s2("s2", 20.0);
    ConcreteFlow f;
    f.setTarget(&s1);
    assert(f.getTarget() == &s1);
    f.setTarget(&s2);
    assert(f.getTarget() == &s2);
}

void unit_Flow_getSource(void) {
    SystemImpl s("s", 42.0);
    ConcreteFlow f("f", &s, nullptr);
    assert(f.getSource() == &s);
    assert(f.getSource()->getValue() == 42.0);
}

void unit_Flow_getTarget(void) {
    SystemImpl s("s", 77.0);
    ConcreteFlow f("f", nullptr, &s);
    assert(f.getTarget() == &s);
    // aqui testamos o getValue() do target para garantir que o target é realmente o sistema que criamos
    assert(f.getTarget()->getValue() == 77.0);
}

void unit_Flow_clearSource(void) {
    SystemImpl s("s", 10.0);
    ConcreteFlow f("f", &s, nullptr);
    f.clearSource();
    assert(f.getSource() == nullptr);
}

void unit_Flow_clearTarget(void) {
    SystemImpl s("s", 10.0);
    ConcreteFlow f("f", nullptr, &s);
    f.clearTarget();
    assert(f.getTarget() == nullptr);
}

void unit_Flow_execute(void) {
    SystemImpl s1("s1", 100.0);
    SystemImpl s2("s2", 0.0);
    ConcreteFlow f("f", &s1, &s2);
    assert(f.execute() == 1.0);

    ConcreteFlow f2("f2", nullptr, &s2);
    assert(f2.execute() == 0.0);
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
