#ifndef FLOW_HPP
#define FLOW_HPP

#include "system.hpp"

/**
 * @brief Interface da classe Flow.
 * Define o contrato minimo de um fluxo: ler suas conexoes (origem e
 * destino) e calcular a taxa de transferencia. Todos os metodos sao
 * virtuais puros.
 *
 * As operacoes de conexao (setSource/setTarget/clearSource/clearTarget)
 * nao fazem parte desta interface — elas sao responsabilidade do Model,
 * que e quem gerencia o ciclo de vida e as ligacoes entre Systems e Flows.
 */
class Flow {
public:
    virtual ~Flow() {}

    /// Retorna o System de origem deste Flow (ou nullptr se nao houver).
    virtual System* getSource() const = 0;
    /// Retorna o System de destino deste Flow (ou nullptr se nao houver).
    virtual System* getTarget() const = 0;
    /// Calcula a quantidade transferida de origem para destino neste passo.
    virtual double execute() = 0;
};

#endif // FLOW_HPP
