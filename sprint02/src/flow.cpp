#include "flow.hpp"

Flow::Flow(System* source, System* target) : source(source), target(target) {}

Flow::Flow(const Flow& obj) : source(obj.source), target(obj.target) {}

Flow::~Flow() {}

Flow& Flow::operator=(const Flow& obj) {
    if (this == &obj) return *this; 
    source = obj.source;
    target = obj.target;
    return *this;
}

void Flow::setSource(System* s) { source = s; }

void Flow::setTarget(System* s) { target = s; }

System* Flow::getSource() const { return source; }

System* Flow::getTarget() const { return target; }

void Flow::clearSource() { source = nullptr; }

void Flow::clearTarget() { target = nullptr; }
