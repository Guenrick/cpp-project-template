#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "flow.hpp"

/**
 * @brief Implementacao concreta base da interface Flow.
 * Gerencia os ponteiros source e target e implementa todos os metodos
 * da interface, exceto execute() — que permanece abstrato para que
 * cada tipo de fluxo defina sua propria equacao matematica.
 */
class FlowImpl : public Flow {
protected:
    System* source;
    System* target;

public:
    FlowImpl(System* source = nullptr, System* target = nullptr);
    FlowImpl(const FlowImpl& obj);
    virtual ~FlowImpl();
    FlowImpl& operator=(const FlowImpl& obj);

    void setSource(System* s) override;
    void setTarget(System* s) override;
    System* getSource() const override;
    System* getTarget() const override;
    void clearSource() override;
    void clearTarget() override;

    virtual double execute() = 0; // ainda abstrato — subclasse define a equacao
};

#endif // FLOW_IMPL_HPP
