#include "model.hpp"

Model::Model() : time(0.0) {}

Model::Model(const Model& obj) : time(obj.time), systems(obj.systems), flows(obj.flows) {}

Model::~Model() {
    systems.clear();
    flows.clear();
}

Model& Model::operator=(const Model& obj) {
    if (this == &obj) return *this;
    time = obj.time;
    systems = obj.systems;
    flows = obj.flows;
    return *this;
}

Model::systemIterator Model::beginSystems() {
    return systems.begin();
}

Model::systemIterator Model::endSystems() {
    return systems.end();
}

Model::flowIterator Model::beginFlows() {
    return flows.begin();
}

Model::flowIterator Model::endFlows() {
    return flows.end();
}

void Model::add(System* s) { systems.push_back(s); }

void Model::add(Flow* f) { flows.push_back(f); }

void Model::remove(System* s) {
    for (auto it = systems.begin(); it != systems.end(); ) {
        if (*it == s) it = systems.erase(it);
        else ++it;
    }
}

void Model::remove(Flow* f) {
    for (auto it = flows.begin(); it != flows.end(); ) {
        if (*it == f) it = flows.erase(it);
        else ++it;
    }
}

void Model::execute(double start, double final_time, double inc) {
    time = start;
    
    // Loop principal
    while (time < final_time) {
        std::vector<double> results;
        
        // Calcula a taxa de todos os fluxos e armazena temporariamente
        for (Flow* f : flows) {
            results.push_back(f->execute());
        }
        
        for (std::size_t i = 0; i < flows.size(); ++i) {
            System* origem = flows[i]->getSource();
            System* destino = flows[i]->getTarget();
            
            if (origem != nullptr) {
                origem->setValue(origem->getValue() - results[i]);
            }
            if (destino != nullptr) {
                destino->setValue(destino->getValue() + results[i]);
            }
        }
        
        time += inc; 
    }
}