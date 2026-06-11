#include "modelImpl.hpp"
#include "systemImpl.hpp"
#include "flowImpl.hpp"

// Registro estatico com todas as instancias de Model vivas no momento.
std::vector<Model*> ModelImpl::models;

Model& Model::createModel(std::string id) {
    return *(new ModelImpl(id));
}

ModelImpl::ModelImpl(std::string id) : id_(id), time(0.0) {
    models.push_back(this);
}

ModelImpl::~ModelImpl() {
    // O Model e dono dos Systems e Flows: ele e responsavel por destrui-los.
    for (auto it = systems.begin(); it != systems.end(); ++it)
        delete *it;
    systems.clear();

    for (auto it = flows.begin(); it != flows.end(); ++it)
        delete *it;
    flows.clear();

    // Remove este Model do registro estatico, evitando ponteiro pendurado.
    for (auto it = models.begin(); it != models.end(); ++it) {
        if (*it == this) {
            models.erase(it);
            break;
        }
    }
}

Model::systemIterator ModelImpl::beginSystems() { return systems.begin(); }
Model::systemIterator ModelImpl::endSystems()   { return systems.end();   }
Model::flowIterator   ModelImpl::beginFlows()   { return flows.begin();   }
Model::flowIterator   ModelImpl::endFlows()     { return flows.end();     }

void ModelImpl::add(System* s) { systems.push_back(s); }
void ModelImpl::add(Flow* f)   { flows.push_back(f);   }

System& ModelImpl::createSystem(std::string id, double value) {
    SystemImpl* s = new SystemImpl(id, value);
    add(s);
    return *s;
}

void ModelImpl::deleteSystem(System& s) {
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        if (*it == &s) {
            delete *it;
            systems.erase(it);
            break;
        }
    }
}

void ModelImpl::deleteFlux(Flow& f) {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        if (*it == &f) {
            delete *it;
            flows.erase(it);
            break;
        }
    }
}

void ModelImpl::setSource(Flow& f, System& s) {
    static_cast<FlowImpl&>(f).setSource(&s);
}

void ModelImpl::setTarget(Flow& f, System& s) {
    static_cast<FlowImpl&>(f).setTarget(&s);
}

void ModelImpl::clearSource(Flow& f) {
    static_cast<FlowImpl&>(f).clearSource();
}

void ModelImpl::clearTarget(Flow& f) {
    static_cast<FlowImpl&>(f).clearTarget();
}

void ModelImpl::execute(double start, double final_time, double inc) {
    time = start;
    while (time < final_time) {
        std::vector<double> results;
        for (Flow* f : flows)
            results.push_back(f->execute());

        for (std::size_t i = 0; i < flows.size(); ++i) {
            System* origem  = flows[i]->getSource();
            System* destino = flows[i]->getTarget();
            if (origem  != nullptr) origem->setValue(origem->getValue()   - results[i]);
            if (destino != nullptr) destino->setValue(destino->getValue() + results[i]);
        }
        time += inc;
    }
}
