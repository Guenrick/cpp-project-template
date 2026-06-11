/**
 * @file unit_System.h
 * @brief Declaração dos testes unitários da classe System (SystemImpl).
 */

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/**
 * @brief Testa o construtor de SystemImpl.
 * Verifica o valor padrão (0.0) e valores parametrizados positivos,
 * negativos e zero, alem do id atribuido.
 */
void unit_System_constructor(void);

/**
 * @brief Testa o destrutor de SystemImpl.
 * Um objeto criado em escopo local deve ser destruído sem erros ao sair do escopo.
 */
void unit_System_destructor(void);

/**
 * @brief Testa o método getValue().
 * Deve retornar exatamente o valor armazenado no sistema.
 */
void unit_System_getValue(void);

/**
 * @brief Testa o método setValue().
 * Após a chamada, getValue() deve retornar o novo valor imediatamente.
 */
void unit_System_setValue(void);

/**
 * @brief Testa o método getName().
 * Deve retornar o identificador (id) atribuido na construção.
 */
void unit_System_getName(void);

/**
 * @brief Testa o método setName().
 * Após a chamada, getName() deve retornar o novo identificador.
 */
void unit_System_setName(void);

/**
 * @brief Executa todos os testes unitários da classe System.
 */
void run_unit_tests_System(void);

#endif // UNIT_SYSTEM_H
