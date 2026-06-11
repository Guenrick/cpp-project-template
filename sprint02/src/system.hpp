#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

/**
 * @brief Interface da classe System.
 * Define o contrato que toda implementacao de System deve cumprir.
 * Nao possui atributos nem implementacoes — apenas metodos virtuais puros.
 */
class System {
public:
    virtual ~System() {}

    /// Retorna o valor (estoque) atual do System.
    virtual double getValue() const = 0;
    /// Define o valor (estoque) atual do System.
    virtual void setValue(double v) = 0;
    /// Retorna o identificador/nome do System.
    virtual std::string getName() const = 0;
    /// Define o identificador/nome do System.
    virtual void setName(const std::string& name) = 0;
};

#endif // SYSTEM_HPP
