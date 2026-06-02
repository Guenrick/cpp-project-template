/**
 * @file unit_System.h
 * @brief Declaração dos testes unitários da classe System.
 */

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/**
 * @brief Testa os construtores da classe System.
 * Verifica o construtor padrão (valor 0.0) e o parametrizado com valores positivos, negativos e zero.
 */
void unit_System_constructor(void);

/**
 * @brief Testa o destrutor da classe System.
 * Um objeto criado em escopo local deve ser destruído sem erros ao sair do escopo.
 */
void unit_System_destructor(void);

/**
 * @brief Testa o construtor de cópia da classe System.
 * A cópia deve ter o mesmo valor que o original, e modificá-la não deve afetar o original.
 */
void unit_System_copyConstructor(void);

/**
 * @brief Testa o operador de atribuição da classe System.
 * Verifica atribuição normal, independência entre objetos e auto-atribuição.
 */
void unit_System_assignmentOperator(void);

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
 * @brief Executa todos os testes unitários da classe System.
 */
void run_unit_tests_System(void);

#endif // UNIT_SYSTEM_H
