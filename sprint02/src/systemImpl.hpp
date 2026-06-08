#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "system.hpp"

/**
 * @brief Implementacao concreta da interface System.
 * Armazena o valor em um atributo double privado e implementa
 * todos os metodos da interface.
 */
class SystemImpl : public System {
private:
    double value;

public:
    SystemImpl(double v = 0.0);
    SystemImpl(const SystemImpl& obj);
    virtual ~SystemImpl();
    SystemImpl& operator=(const SystemImpl& obj);

    double getValue() const override;
    void setValue(double v) override;
};

#endif // SYSTEM_IMPL_HPP
