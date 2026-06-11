#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "model.hpp"
#include <string>
#include <vector>

/**
 * @brief Implementacao concreta da interface Model.
 *
 * Armazena as colecoes de Systems e Flows em vetores, sendo o unico
 * dono desses objetos: ela os cria (createSystem / createFlux) e os
 * destroi (deleteSystem, deleteFlux ou no proprio destrutor).
 *
 * Mantem ainda um registro estatico (models) com todas as instancias
 * vivas de ModelImpl. Quando um ModelImpl e destruido, ele se remove
 * desse vetor para que nao reste nenhum ponteiro pendurado (dangling).
 *
 * Os construtores de copia e o operador de atribuicao sao privados:
 * um Model nao deve ser copiado, pois isso duplicaria a posse de
 * ponteiros que ele gerencia.
 */
class ModelImpl : public Model {
protected:
    std::string id_;
    double time;
    std::vector<System*> systems;
    std::vector<Flow*>   flows;

    static std::vector<Model*> models;

public:
    ModelImpl(std::string id);
    virtual ~ModelImpl();

    void execute(double start, double final_time, double inc) override;

    System& createSystem(std::string id, double value = 0.0) override;
    void deleteSystem(System& s) override;
    void deleteFlux(Flow& f) override;

    void setSource(Flow& f, System& s) override;
    void setTarget(Flow& f, System& s) override;
    void clearSource(Flow& f) override;
    void clearTarget(Flow& f) override;

    systemIterator beginSystems() override;
    systemIterator endSystems() override;
    flowIterator   beginFlows() override;
    flowIterator   endFlows() override;

protected:
    void add(System* s) override;
    void add(Flow* f) override;

private:
    ModelImpl(const ModelImpl& obj);
    ModelImpl& operator=(const ModelImpl& obj);
};

#endif // MODEL_IMPL_HPP
