#include "unit_System.h"
#include "../../src/systemImpl.hpp"
#include <assert.h>

// SystemImpl agora e criado diretamente neste teste, pois o construtor
// e protegido pelo Model em tempo de execucao normal, mas o teste
// unitario de SystemImpl precisa instanciar a implementacao concreta.

void unit_System_constructor(void) {
    SystemImpl s1("s1");
    assert(s1.getValue() == 0.0);
    assert(s1.getName() == "s1");

    SystemImpl s2("s2", 10.0);
    assert(s2.getValue() == 10.0);
    assert(s2.getName() == "s2");

    SystemImpl s3("s3", -5.5);
    assert(s3.getValue() == -5.5);
}

void unit_System_destructor(void) {
    {
        SystemImpl s("s", 42.0);
        assert(s.getValue() == 42.0);
    }
}

void unit_System_getValue(void) {
    SystemImpl s("s1", 10.0);
    assert(s.getValue() == 10.0);

    SystemImpl s2("s2", 0.0);
    assert(s2.getValue() == 0.0);

    SystemImpl s3("s3", -100.0);
    assert(s3.getValue() == -100.0);
}

void unit_System_setValue(void) {
    SystemImpl s("s", 0.0);

    s.setValue(100.0);
    assert(s.getValue() == 100.0);

    s.setValue(0.0);
    assert(s.getValue() == 0.0);

    s.setValue(-77.5);
    assert(s.getValue() == -77.5);
}

void unit_System_getName(void) {
    SystemImpl s("populacao", 5.0);
    assert(s.getName() == "populacao");
}

void unit_System_setName(void) {
    SystemImpl s("inicial", 5.0);
    s.setName("novoNome");
    assert(s.getName() == "novoNome");
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
    unit_System_getName();
    unit_System_setName();
}
