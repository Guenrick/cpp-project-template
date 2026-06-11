#ifndef MODEL_HPP
#define MODEL_HPP

#include "system.hpp"
#include "flow.hpp"
#include "flowImpl.hpp"
#include <vector>
#include <string>

/**
 * @brief Interface da classe Model.
 *
 * O Model e o motor de simulacao e tambem a fabrica e dono de todos os
 * Systems e Flows que participam da simulacao: eles sao criados atraves
 * dele (createSystem / createFlux) e destruidos por ele (no seu
 * destrutor, ou explicitamente via deleteSystem / deleteFlux).
 *
 * As conexoes entre Systems e Flows (setSource/setTarget/clearSource/
 * clearTarget) tambem sao operacoes do Model, ja que Flow nao expoe
 * esses metodos em sua interface.
 */
class Model {
public:
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator   flowIterator;

    virtual ~Model() {}

    /**
     * @brief Cria um novo Model identificado por id.
     * @return Referencia para o Model criado. O chamador e responsavel
     * por destrui-lo (delete &model) quando nao for mais necessario.
     */
    static Model& createModel(std::string id);

    /**
     * @brief Cria um novo System gerenciado por este Model.
     * @param id Identificador do System.
     * @param value Valor inicial (padrao: 0.0).
     * @return Referencia para o System criado.
     */
    virtual System& createSystem(std::string id, double value = 0.0) = 0;

    /**
     * @brief Remove e destroi um System gerenciado por este Model.
     */
    virtual void deleteSystem(System& s) = 0;

    /**
     * @brief Remove e destroi um Flow gerenciado por este Model.
     */
    virtual void deleteFlux(Flow& f) = 0;

    /**
     * @brief Cria um novo Flow do tipo T_FLUX_IMPL, gerenciado por este Model.
     *
     * T_FLUX_IMPL deve possuir um construtor (string id, System* source,
     * System* target).
     *
     * @return Referencia para o Flow criado.
     */
    // Aqui template é uma forma de escrever código que funciona para vários tipos diferentes, sem precisar repetir a implementação de cada um
    // Ai o compilador vai preencher o tipo no momento qem que o template é usado
    template <typename T_FLUX_IMPL>
    Flow& createFlux(std::string id, System* source = nullptr, System* target = nullptr) {
        T_FLUX_IMPL* f = new T_FLUX_IMPL(id, source, target);
        add(f);
        return *f;
    }

    /// Define a origem (source) de um Flow.
    virtual void setSource(Flow& f, System& s) = 0;
    /// Define o destino (target) de um Flow.
    virtual void setTarget(Flow& f, System& s) = 0;
    /// Remove a origem (source) de um Flow.
    virtual void clearSource(Flow& f) = 0;
    /// Remove o destino (target) de um Flow.
    virtual void clearTarget(Flow& f) = 0;

    /// Executa a simulacao de start ate final_time, com passo inc.
    virtual void execute(double start, double final_time, double inc) = 0;

    /// Iterador para o primeiro System gerenciado por este Model.
    virtual systemIterator beginSystems() = 0;
    /// Iterador para o final da colecao de Systems gerenciados por este Model.
    virtual systemIterator endSystems() = 0;
    /// Iterador para o primeiro Flow gerenciado por este Model.
    virtual flowIterator   beginFlows() = 0;
    /// Iterador para o final da colecao de Flows gerenciados por este Model.
    virtual flowIterator   endFlows() = 0;

protected:
    /// Adiciona um System a colecao interna do Model. Usado por createSystem.
    virtual void add(System* s) = 0;
    /// Adiciona um Flow a colecao interna do Model. Usado por createFlux.
    virtual void add(Flow* f) = 0;
};

#endif // MODEL_HPP
