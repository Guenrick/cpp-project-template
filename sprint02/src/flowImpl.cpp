#include "flowImpl.hpp"

FlowImpl::FlowImpl(std::string id, System* source, System* target)
    : id_(id), source(source), target(target) {}

FlowImpl::~FlowImpl() {}

System* FlowImpl::getSource() const { return source; }
System* FlowImpl::getTarget() const { return target; }

void FlowImpl::setSource(System* s) { source = s; }
void FlowImpl::setTarget(System* s) { target = s; }
void FlowImpl::clearSource()        { source = nullptr; }
void FlowImpl::clearTarget()        { target = nullptr; }
