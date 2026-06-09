#include "unit_System.h"
#include "../../src/factory.hpp"
#include <assert.h>

void unit_System_constructor(void) {
    // Agora usamos o factory para criar os objetos System
    // o createSystem serve para criar objetos do tipo SystemImpl, mas retorna um ponteiro para System, que é a interface abstrata.
    // O arquivo não conhece mais a classe SystemImpl, apenas a interface System, e o factory é responsável por criar os objetos concretos.
    System* s1 = createSystem();
    assert(s1->getValue() == 0.0);

    System* s2 = createSystem(10.0);
    assert(s2->getValue() == 10.0);

    System* s3 = createSystem(-5.5);
    assert(s3->getValue() == -5.5);

    delete s1;
    delete s2;
    delete s3;
}

void unit_System_destructor(void) {
    {
        System* s = createSystem(42.0);
        assert(s->getValue() == 42.0);
        delete s;
    }
}

void unit_System_copyConstructor(void) {
    System*  original = createSystem(99.0);
    System* copia = createSystem(original->getValue()); // Criamos uma cópia usando o valor do original

    assert(copia->getValue() == 99.0);

    copia->setValue(1.0);
    assert(original->getValue() == 99.0);
    assert(copia->getValue() == 1.0);

    delete original;
    delete copia;
}

void unit_System_assignmentOperator(void) {
    System* s1 = createSystem(50.0);
    System* s2 = createSystem(0.0);

    //s2 = s1; antes copiava o valor, agora s2 aponta para o mesmo objeto que s1, ou seja, s1 e s2 são o mesmo objeto
    s2->setValue(s1->getValue()); // Copiamos o valor de s1 para s2, mas s2 continua sendo um objeto diferente de s1
    assert(s2->getValue() == 50.0);

    s2->setValue(200.0);
    assert(s1->getValue() == 50.0);

    s1 = s1;
    assert(s1->getValue() == 50.0);

    delete s1;
    delete s2;
}

void unit_System_getValue(void) {
    System* s = createSystem(10.0);
    assert(s->getValue() == 10.0);

    System* s2 = createSystem(0.0);
    assert(s2->getValue() == 0.0);

    System* s3 = createSystem(-100.0);
    assert(s3->getValue() == -100.0);

    delete s;
    delete s2;
    delete s3;
}

void unit_System_setValue(void) {
    System* s = createSystem(0.0);

    s->setValue(100.0);
    assert(s->getValue() == 100.0);

    s->setValue(0.0);
    assert(s->getValue() == 0.0);

    s->setValue(-77.5);
    assert(s->getValue() == -77.5);

    delete s;
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_copyConstructor();
    unit_System_assignmentOperator();
    unit_System_getValue();
    unit_System_setValue();
}
