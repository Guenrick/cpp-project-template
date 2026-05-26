/**
 * @file flow.hpp
 * @brief Declaração da classe Flow.
 * Este arquivo contém a interface da classe abstrata Flow, que define a base
 * para as interações de transferência de dados entre instâncias de System.
 */

#ifndef FLOW_H
#define FLOW_H

#include "system.hpp"

/**
 * @brief Classe abstrata que representa um fluxo de simulação.
 * A classe Flow é responsável por conectar dois sistemas (origem e destino) e
 * ditar a regra matemática de transferência de massa/energia entre eles.
 */
class Flow {
protected:
    System* source; /*!< Ponteiro para o sistema de origem (de onde a massa sai). */
    System* target; /*!< Ponteiro para o sistema de destino (para onde a massa vai). */

public:
    /**
     * @brief Construtor padrão e parametrizado do Flow.
     * @param source Ponteiro inicial para o sistema de origem. O padrão é nullptr.
     * @param target Ponteiro inicial para o sistema de destino. O padrão é nullptr.
     */
    Flow(System* source = nullptr, System* target = nullptr);
    
    /**
     * @brief Construtor de cópia do Flow.
     * @param obj Referência constante para o objeto Flow que será copiado.
     */
    Flow(const Flow& obj);
    
    /**
     * @brief Destrutor virtual do Flow.
     * Garante a destruição correta de objetos em classes derivadas (herança).
     */
    virtual ~Flow();
    
    /**
     * @brief Sobrecarga do operador de atribuição (=).
     * @param obj Referência constante para o objeto Flow que será atribuído.
     * @return Referência para o próprio objeto recém-atualizado.
     */
    Flow& operator=(const Flow& obj);

    /**
     * @brief Define ou altera o sistema de origem do fluxo.
     * @param s Ponteiro para o novo sistema de origem (System).
     */
    void setSource(System* s);
    
    /**
     * @brief Define ou altera o sistema de destino do fluxo.
     * @param s Ponteiro para o novo sistema de destino (System).
     */
    void setTarget(System* s);
    
    /**
     * @brief Obtém o sistema de origem atual do fluxo.
     * @return System* Retorna o ponteiro para o sistema de origem.
     */
    System* getSource() const;
    
    /**
     * @brief Obtém o sistema de destino atual do fluxo.
     * @return System* Retorna o ponteiro para o sistema de destino.
     */
    System* getTarget() const;
    
    /**
     * @brief Limpa a referência ao sistema de origem.
     * Remove a conexão com a origem, definindo o ponteiro como nullptr.
     */
    void clearSource();
    
    /**
     * @brief Limpa a referência ao sistema de destino.
     * Remove a conexão com o destino, definindo o ponteiro como nullptr.
     */
    void clearTarget();

    /**
     * @brief Executa a equação matemática do fluxo.
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para calcular a quantidade exata de massa a ser transferida a cada iteração.
     * @return double O valor calculado que será transferido.
     */
    virtual double execute() = 0;
};