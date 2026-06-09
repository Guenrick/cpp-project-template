#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "system.hpp"
#include "model.hpp"

/**
 * @file factory.hpp
 * @brief Funcoes de fabrica para criacao de objetos do MyVENSIM.
 *
 * Expoe apenas as interfaces publicas (System e Model),
 * ocultando completamente as implementacoes concretas (SystemImpl, ModelImpl).
 */

/**
 * @brief Cria um novo objeto System.
 * @param value Valor inicial do sistema (padrao: 0.0).
 * @return Ponteiro para a interface System. O chamador e responsavel por deletar o objeto.
 */
System* createSystem(double value = 0.0);

/**
 * @brief Cria um novo objeto Model.
 * @return Ponteiro para a interface Model. O chamador e responsavel por deletar o objeto.
 */
Model* createModel();

#endif // FACTORY_HPP