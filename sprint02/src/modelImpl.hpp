#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "model.hpp"

/**
 * @brief Implementacao concreta da interface Model.
 * Armazena as colecoes de Systems e Flows em vetores e implementa
 * o algoritmo de atualizacao simultanea em execute().
 */
class ModelImpl : public Model {
protected:
    double time;
    std::vector<System*> systems;
    std::vector<Flow*>   flows;

public:
    ModelImpl();
    ModelImpl(const ModelImpl& obj);
    virtual ~ModelImpl();
    ModelImpl& operator=(const ModelImpl& obj);

    void execute(double start, double final_time, double inc) override;
    void add(System* s) override;
    void add(Flow* f) override;
    void remove(System* s) override;
    void remove(Flow* f) override;
    systemIterator beginSystems() override;
    systemIterator endSystems() override;
    flowIterator   beginFlows() override;
    flowIterator   endFlows() override;
};

#endif // MODEL_IMPL_HPP
