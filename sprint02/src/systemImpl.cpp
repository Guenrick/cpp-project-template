#include "systemImpl.hpp"

SystemImpl::SystemImpl(std::string id, double value) : id_(id), value_(value) {}

SystemImpl::~SystemImpl() {}

double SystemImpl::getValue() const {
    return value_;
}

void SystemImpl::setValue(double v) {
    value_ = v;
}

std::string SystemImpl::getName() const {
    return id_;
}

void SystemImpl::setName(const std::string& name) {
    id_ = name;
}
