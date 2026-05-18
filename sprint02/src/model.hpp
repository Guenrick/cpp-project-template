#ifndef MODEL_H
#define MODEL_H

#include "system.hpp"
#include "flow.hpp"
#include <vector>

class Model {
protected:
    double time;

private:
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:

    Model();
    Model(const Model& obj);
    virtual ~Model();
    Model& operator=(const Model& obj);

    void execute(double start, double final_time, double inc);
    void add(System* s);
    void add(Flow* f);
    void remove(System* s);
    void remove(Flow* f);
};

#endif