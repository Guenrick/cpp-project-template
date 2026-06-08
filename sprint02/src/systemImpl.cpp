#include "systemImpl.hpp"

SystemImpl::SystemImpl(double v) : value(v) {}

SystemImpl::SystemImpl(const SystemImpl& obj) : value(obj.value) {}

SystemImpl::~SystemImpl() {}

SystemImpl& SystemImpl::operator=(const SystemImpl& obj) {
    if (this == &obj) return *this;
    value = obj.value;
    return *this;
}

double SystemImpl::getValue() const {
    return value;
}

void SystemImpl::setValue(double v) {
    value = v;
}
