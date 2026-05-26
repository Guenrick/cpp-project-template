/**
 * @mainpage Simulador de Dinâmica de Sistemas - Sprint 02
 *
 * @section intro_sec Introdução
 * Bem-vindo à documentação oficial do Simulador C++ (BCC322).
 * * Este projeto implementa uma arquitetura orientada a objetos para a simulação de sistemas e fluxos.
 * Utilize o menu superior para navegar por:
 * - **Classes:** Para visualizar a hierarquia, os diagramas UML gerados pelo Graphviz e os detalhes dos métodos.
 * - **Files (Ficheiros):** Para consultar a documentação de cada ficheiro de cabeçalho e as funções de teste.
 */
 
/**
 * @file model.hpp
 * @brief Declaração da classe Model.
 * Este arquivo contém a interface da classe Model, responsável por gerenciar
 * os sistemas e fluxos, além de controlar o relógio e a execução matemática da simulação.
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "system.hpp"
#include "flow.hpp"

/**
 * @brief Classe que representa o Modelo de simulação.
 * A classe Model atua como o motor principal do simulador. Ela armazena
 * coleções de sistemas (System) e fluxos (Flow) e orquestra a execução,
 * garantindo a transferência correta de dados a cada passo de tempo.
 */
class Model {
protected:
    double time;                  /*!< Tempo atual da simulação. */
    std::vector<System*> systems; /*!< Vetor contendo ponteiros para os sistemas gerenciados. */
    std::vector<Flow*> flows;     /*!< Vetor contendo ponteiros para os fluxos gerenciados. */

public:
    /**
     * @brief Construtor padrão da classe Model.
     */
    Model();
    
    /**
     * @brief Construtor de cópia do Model.
     * @param obj Referência constante para o objeto Model que será copiado.
     */
    Model(const Model& obj);
    
    /**
     * @brief Destrutor virtual do Model.
     * Garante a liberação adequada de memória das coleções (sistemas e fluxos).
     */
    virtual ~Model();
    
    /**
     * @brief Sobrecarga do operador de atribuição (=).
     * @param obj Referência constante para o objeto Model que será atribuído.
     * @return Referência para o próprio objeto recém-atualizado.
     */
    Model& operator=(const Model& obj);

    /** @brief Atalho (typedef) para o iterador do vetor de sistemas. */
    typedef std::vector<System*>::iterator systemIterator; //alterar
    
    /** @brief Atalho (typedef) para o iterador do vetor de fluxos. */
    typedef std::vector<Flow*>::iterator flowIterator;
    
    //for(systemIterator it; it != endSystems(); it++){}
    //*it
    
    /**
     * @brief Retorna o iterador para o início da coleção de sistemas.
     * @return systemIterator Iterador apontando para o primeiro System.
     */
    systemIterator beginSystems();
    
    /**
     * @brief Retorna o iterador para o fim da coleção de sistemas.
     * @return systemIterator Iterador apontando para a posição logo após o último System.
     */
    systemIterator endSystems();
    
    /**
     * @brief Retorna o iterador para o início da coleção de fluxos.
     * @return flowIterator Iterador apontando para o primeiro Flow.
     */
    flowIterator beginFlows();
    
    /**
     * @brief Retorna o iterador para o fim da coleção de fluxos.
     * @return flowIterator Iterador apontando para a posição logo após o último Flow.
     */
    flowIterator endFlows();

    /**
     * @brief Executa a simulação iterando sobre os fluxos e atualizando os sistemas.
     * @param start Tempo inicial (ou passo inicial) da simulação.
     * @param final_time Tempo final limitador da simulação.
     * @param inc Incremento de tempo adicionado ao relógio a cada passo.
     */
    void execute(double start, double final_time, double inc);
    
    /**
     * @brief Adiciona um novo sistema ao modelo.
     * @param s Ponteiro para o sistema (System) a ser incluído.
     */
    void add(System* s);
    
    /**
     * @brief Adiciona um novo fluxo ao modelo.
     * @param f Ponteiro para o fluxo (Flow) a ser incluído.
     */
    void add(Flow* f);
    
    /**
     * @brief Remove um sistema existente do modelo.
     * @param s Ponteiro para o sistema (System) a ser removido da coleção.
     */
    void remove(System* s);
    
    /**
     * @brief Remove um fluxo existente do modelo.
     * @param f Ponteiro para o fluxo (Flow) a ser removido da coleção.
     */
    void remove(Flow* f);
};

#endif // MODEL_HPP