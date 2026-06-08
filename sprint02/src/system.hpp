#ifndef SYSTEM_HPP
#define SYSTEM_HPP

/**
 * @brief Interface da classe System.
 * Define o contrato que toda implementacao de System deve cumprir.
 * Nao possui atributos nem implementacoes — apenas metodos virtuais puros.
 */
class System {
public:
    virtual ~System() {}
    virtual double getValue() const = 0;
    virtual void setValue(double v) = 0;
};

#endif // SYSTEM_HPP
