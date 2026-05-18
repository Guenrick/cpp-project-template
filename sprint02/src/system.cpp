#include "system.hpp"

System::System(double v) : value(v) {}

System::System(const System& obj) : value(obj.value) {}

System::~System() {}

System& System::operator=(const System& obj) {
    if (this == &obj) return *this; // Proteção contra auto-atribuição (ex: s1 = s1)
    value = obj.value;
    return *this;
}

double System::getValue() const {
    return value;
}

void System::setValue(double v) {
    value = v;
}