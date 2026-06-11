#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "flow.hpp"
#include <string>

/**
 * @brief Implementacao concreta base da interface Flow.
 *
 * Possui um identificador (id_) e gerencia os ponteiros source e target.
 * Implementa getSource()/getTarget() (parte da interface Flow) e tambem
 * expoe setSource/setTarget/clearSource/clearTarget como metodos
 * concretos — usados internamente pelo Model para (des)conectar Systems
 * a um Flow, ja que essas operacoes nao fazem parte da interface Flow.
 *
 * execute() permanece abstrato para que cada tipo de fluxo defina sua
 * propria equacao matematica.
 */
class FlowImpl : public Flow {
public:
    std::string id_;

protected:
    System* source;
    System* target;

public:
    FlowImpl(std::string id = "", System* source = nullptr, System* target = nullptr);
    virtual ~FlowImpl();

    System* getSource() const override;
    System* getTarget() const override;

    /// Define o System de origem deste Flow. Usado pelo Model::setSource.
    void setSource(System* s);
    /// Define o System de destino deste Flow. Usado pelo Model::setTarget.
    void setTarget(System* s);
    /// Remove a referencia ao System de origem. Usado pelo Model::clearSource.
    void clearSource();
    /// Remove a referencia ao System de destino. Usado pelo Model::clearTarget.
    void clearTarget();

    /// Calcula e retorna a quantidade transferida de source para target neste passo.
    /// Permanece abstrato — cada subclasse define sua propria equacao.
    virtual double execute() = 0;
};

#endif // FLOW_IMPL_HPP
