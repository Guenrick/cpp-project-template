/**
 * @file unit_Flow.h
 * @brief Declaração dos testes unitários da classe Flow.
 */

#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/**
 * @brief Testa os construtores da classe Flow.
 * Verifica o construtor padrão (ponteiros nullptr) e o parametrizado.
 */
void unit_Flow_constructor(void);

/**
 * @brief Testa o destrutor da classe Flow.
 * Flow não é dona dos Systems — eles devem continuar intactos após o destrutor.
 */
void unit_Flow_destructor(void);

/**
 * @brief Testa o construtor de cópia da classe Flow.
 * A cópia deve apontar para os mesmos sistemas que o original.
 */
void unit_Flow_copyConstructor(void);

/**
 * @brief Testa o operador de atribuição da classe Flow.
 * Verifica atribuição normal e auto-atribuição.
 */
void unit_Flow_assignmentOperator(void);

/**
 * @brief Testa o método setSource().
 * Após a chamada, getSource() deve retornar o novo ponteiro.
 */
void unit_Flow_setSource(void);

/**
 * @brief Testa o método setTarget().
 * Após a chamada, getTarget() deve retornar o novo ponteiro.
 */
void unit_Flow_setTarget(void);

/**
 * @brief Testa o método getSource().
 * Verifica que o ponteiro e o valor da origem são retornados corretamente.
 */
void unit_Flow_getSource(void);

/**
 * @brief Testa o método getTarget().
 * Verifica que o ponteiro e o valor do destino são retornados corretamente.
 */
void unit_Flow_getTarget(void);

/**
 * @brief Testa o método clearSource().
 * Após a chamada, getSource() deve retornar nullptr.
 */
void unit_Flow_clearSource(void);

/**
 * @brief Testa o método clearTarget().
 * Após a chamada, getTarget() deve retornar nullptr.
 */
void unit_Flow_clearTarget(void);

/**
 * @brief Testa o método execute() da subclasse ConcreteFlow.
 * Verifica o cálculo com origem válida e com origem nula.
 */
void unit_Flow_execute(void);

/**
 * @brief Executa todos os testes unitários da classe Flow.
 */
void run_unit_tests_Flow(void);

#endif // UNIT_FLOW_H
