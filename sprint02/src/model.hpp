#ifndef MODEL_HPP
#define MODEL_HPP

#include "system.hpp"
#include "flow.hpp"
#include <vector>

/**
 * @brief Interface da classe Model.
 * Define o contrato do motor de simulacao: adicionar/remover Systems e Flows,
 * expor iteradores para percorrer as colecoes e executar o laco de simulacao.
 */
class Model {
public:
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator   flowIterator;

    virtual ~Model() {}

    virtual void execute(double start, double final_time, double inc) = 0;
    virtual void add(System* s) = 0;
    virtual void add(Flow* f) = 0;
    virtual void remove(System* s) = 0;
    virtual void remove(Flow* f) = 0;
    virtual systemIterator beginSystems() = 0;
    virtual systemIterator endSystems() = 0;
    virtual flowIterator   beginFlows() = 0;
    virtual flowIterator   endFlows() = 0;
};

#endif // MODEL_HPP
