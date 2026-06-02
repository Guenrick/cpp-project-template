#include "unit_System.h"
#include "../../src/system.hpp"
#include <assert.h>

void unit_System_constructor(void) {
    System s1;
    assert(s1.getValue() == 0.0);

    System s2(10.0);
    assert(s2.getValue() == 10.0);

    System s3(-5.5);
    assert(s3.getValue() == -5.5);

    System s4(0.0);
    assert(s4.getValue() == 0.0);
}

void unit_System_destructor(void) {
    {
        System s(42.0);
        assert(s.getValue() == 42.0);
    }
}

void unit_System_copyConstructor(void) {
    System original(99.0);
    System copia(original);

    assert(copia.getValue() == 99.0);

    copia.setValue(1.0);
    assert(original.getValue() == 99.0);
    assert(copia.getValue() == 1.0);
}

void unit_System_assignmentOperator(void) {
    System s1(50.0);
    System s2(0.0);

    s2 = s1;
    assert(s2.getValue() == 50.0);

    s2.setValue(200.0);
    assert(s1.getValue() == 50.0);

    s1 = s1; // auto-atribuição
    assert(s1.getValue() == 50.0);
}

void unit_System_getValue(void) {
    System s(10.0);
    assert(s.getValue() == 10.0);

    System s2(0.0);
    assert(s2.getValue() == 0.0);

    System s3(-100.0);
    assert(s3.getValue() == -100.0);
}

void unit_System_setValue(void) {
    System s;

    s.setValue(100.0);
    assert(s.getValue() == 100.0);

    s.setValue(0.0);
    assert(s.getValue() == 0.0);

    s.setValue(-77.5);
    assert(s.getValue() == -77.5);
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_copyConstructor();
    unit_System_assignmentOperator();
    unit_System_getValue();
    unit_System_setValue();
}
