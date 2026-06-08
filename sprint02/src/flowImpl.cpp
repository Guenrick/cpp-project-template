#include "flowImpl.hpp"

FlowImpl::FlowImpl(System* source, System* target)
    : source(source), target(target) {}

FlowImpl::FlowImpl(const FlowImpl& obj)
    : source(obj.source), target(obj.target) {}

FlowImpl::~FlowImpl() {}

FlowImpl& FlowImpl::operator=(const FlowImpl& obj) {
    if (this == &obj) return *this;
    source = obj.source;
    target = obj.target;
    return *this;
}

void    FlowImpl::setSource(System* s) { source = s; }
void    FlowImpl::setTarget(System* s) { target = s; }
System* FlowImpl::getSource() const    { return source; }
System* FlowImpl::getTarget() const    { return target; }
void    FlowImpl::clearSource()        { source = nullptr; }
void    FlowImpl::clearTarget()        { target = nullptr; }
