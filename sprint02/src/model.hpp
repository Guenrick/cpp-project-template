/**
 * @file model.hpp
 * @brief Declaração da classe Model.
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "system.hpp"
#include "flow.hpp"

/**
 * @brief Contêiner e motor principal da simulação.
 *
 * Model gerencia coleções de Systems e Flows e executa o laço de simulação,
 * aplicando o princípio da atualização simultânea: calcula todos os fluxos
 * antes de atualizar qualquer sistema.
 */
class Model {
protected:
    double time;                   /*!< Relógio interno da simulação. */
    std::vector<System*> systems;  /*!< Lista de ponteiros para os sistemas. */
    std::vector<Flow*>   flows;    /*!< Lista de ponteiros para os fluxos. */

public:
    /** @brief Atalho para o iterador do vetor de sistemas. */
    typedef std::vector<System*>::iterator systemIterator;

    /** @brief Atalho para o iterador do vetor de fluxos. */
    typedef std::vector<Flow*>::iterator flowIterator;

    /**
     * @brief Construtor padrão.
     */
    Model();

    /**
     * @brief Construtor de cópia (Forma Canônica).
     * @param obj Objeto Model a ser copiado.
     */
    Model(const Model& obj);

    /**
     * @brief Destrutor virtual (Forma Canônica).
     */
    virtual ~Model();

    /**
     * @brief Operador de atribuição (Forma Canônica).
     * @param obj Objeto Model a ser atribuído.
     * @return Referência para o próprio objeto.
     */
    Model& operator=(const Model& obj);

    /**
     * @brief Iterador para o início da lista de sistemas.
     * @return systemIterator apontando para o primeiro System.
     */
    systemIterator beginSystems();

    /**
     * @brief Iterador para o fim da lista de sistemas.
     * @return systemIterator apontando após o último System.
     */
    systemIterator endSystems();

    /**
     * @brief Iterador para o início da lista de fluxos.
     * @return flowIterator apontando para o primeiro Flow.
     */
    flowIterator beginFlows();

    /**
     * @brief Iterador para o fim da lista de fluxos.
     * @return flowIterator apontando após o último Flow.
     */
    flowIterator endFlows();

    /**
     * @brief Executa o laço principal da simulação.
     * @param start      Tempo inicial.
     * @param final_time Tempo final.
     * @param inc        Incremento por iteração.
     */
    void execute(double start, double final_time, double inc);

    /**
     * @brief Adiciona um sistema ao modelo.
     * @param s Ponteiro para o System a ser adicionado.
     */
    void add(System* s);

    /**
     * @brief Adiciona um fluxo ao modelo.
     * @param f Ponteiro para o Flow a ser adicionado.
     */
    void add(Flow* f);

    /**
     * @brief Remove um sistema do modelo.
     * @param s Ponteiro para o System a ser removido.
     */
    void remove(System* s);

    /**
     * @brief Remove um fluxo do modelo.
     * @param f Ponteiro para o Flow a ser removido.
     */
    void remove(Flow* f);
};

#endif // MODEL_HPP
