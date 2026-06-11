#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "system.hpp"
#include <string>

/**
 * @brief Implementacao concreta da interface System.
 * Possui um identificador (id_) e armazena o valor em um atributo
 * protegido (value_), implementando todos os metodos da interface.
 *
 * Os construtores de copia e o operador de atribuicao sao privados:
 * objetos SystemImpl sao criados e gerenciados pelo Model (via
 * Model::createSystem) e nao devem ser copiados.
 */
class SystemImpl : public System {
public:
    std::string id_;

protected:
    double value_;

public:
    SystemImpl(std::string id, double value = 0.0);
    virtual ~SystemImpl();

    double getValue() const override;
    void setValue(double v) override;
    std::string getName() const override;
    void setName(const std::string& name) override;

private:
    SystemImpl(const SystemImpl& obj);
    SystemImpl& operator=(const SystemImpl& obj);
};

#endif // SYSTEM_IMPL_HPP
