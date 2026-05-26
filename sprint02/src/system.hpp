/**
 * @file system.h
 * @brief Declaração da classe System.
 * * Este arquivo contém a interface da classe System, que atua como os nós
 * de armazenamento (reservatórios) na simulação.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

/**
 * @brief Classe que representa um Sistema no simulador.
 * * A classe System é responsável por armazenar uma quantidade de "massa" ou "energia" 
 * que pode ser consumida ou incrementada pelos fluxos (Flow) durante a execução do modelo.
 */
class System {
private:
    double value; /*!< Valor atual armazenado no sistema. */

public:
    /**
     * @brief Construtor padrão e parametrizado do System.
     * @param v Valor inicial a ser armazenado no sistema. O padrão é 0.0.
     */
    System(double v = 0.0);                 
    
    /**
     * @brief Construtor de cópia do System.
     * @param obj Referência constante para o objeto System que será copiado.
     */
    System(const System& obj);             
    
    /**
     * @brief Destrutor virtual do System.
     * Garante a destruição correta de objetos em heranças, caso necessário no futuro.
     */
    virtual ~System();                      
    
    /**
     * @brief Sobrecarga do operador de atribuição (=).
     * @param obj Referência constante para o objeto System que será atribuído.
     * @return Referência para o próprio objeto recém-atualizado.
     */
    System& operator=(const System& obj);  

    /**
     * @brief Obtém o valor atual do sistema.
     * @return double Retorna o valor (massa/energia) armazenado.
     */
    double getValue() const;
    
    /**
     * @brief Define ou atualiza o valor do sistema.
     * @param v Novo valor (double) que substituirá o valor atual do sistema.
     */
    void setValue(double v);
};

#endif // SYSTEM_H