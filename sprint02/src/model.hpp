#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "system.hpp"
#include "flow.hpp"

class Model {
protected:
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    Model();
    Model(const Model& obj);
    virtual ~Model();
    Model& operator=(const Model& obj);

    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    systemIterator beginSystems();
    systemIterator endSystems();
    flowIterator beginFlows();
    flowIterator endFlows();

    void execute(double start, double final_time, double inc);
    void add(System* s);
    void add(Flow* f);
    void remove(System* s);
    void remove(Flow* f);
};

#endif