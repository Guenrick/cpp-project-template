#ifndef FLOW_HPP
#define FLOW_HPP

#include "system.hpp"

/**
 * @brief Interface da classe Flow.
 * Define o contrato de um fluxo: conectar dois Systems e calcular
 * a taxa de transferencia. Todos os metodos sao virtuais puros.
 */
class Flow {
public:
    virtual ~Flow() {}
    virtual void setSource(System* s) = 0;
    virtual void setTarget(System* s) = 0;
    virtual System* getSource() const = 0;
    virtual System* getTarget() const = 0;
    virtual void clearSource() = 0;
    virtual void clearTarget() = 0;
    virtual double execute() = 0;
};

#endif // FLOW_HPP
