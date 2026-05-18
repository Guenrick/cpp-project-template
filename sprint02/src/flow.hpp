#ifndef FLOW_H
#define FLOW_H

#include "system.hpp"

class Flow {
protected:
    System* source;
    System* target;

public:

    Flow(System* source = nullptr, System* target = nullptr);
    Flow(const Flow& obj);
    virtual ~Flow();
    Flow& operator=(const Flow& obj);

    void setSource(System* s);
    void setTarget(System* s);
    System* getSource() const;
    System* getTarget() const;
    void clearSource();
    void clearTarget();

    virtual double execute() = 0;
};

#endif