/**
 * @file factory.cpp
 * @brief Implementacao das funcoes de fabrica.
 *
 * Este arquivo e o unico ponto do projeto que conhece SystemImpl e ModelImpl.
 * Fica compilado dentro da biblioteca compartilhada (libmyvensim.so),
 * permanecendo invisivel para os clientes da biblioteca.
 */

#include "factory.hpp"
#include "systemImpl.hpp"
#include "modelImpl.hpp"

/**
 * @brief Cria um SystemImpl e retorna como ponteiro para System.
 */
System* createSystem(double value) {
    return new SystemImpl(value);
}

/**
 * @brief Cria um ModelImpl e retorna como ponteiro para Model.
 */
Model* createModel() {
    return new ModelImpl();
}