/**
 * @file unit_Model.h
 * @brief Declaração dos testes unitários da classe Model.
 */

#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/**
 * @brief Testa o construtor padrão de Model.
 * Um Model recém-criado deve ter listas de sistemas e fluxos vazias.
 */
void unit_Model_constructor(void);

/**
 * @brief Testa o destrutor de Model.
 * Model não é dono dos objetos — sistemas devem continuar intactos após o destrutor.
 */
void unit_Model_destructor(void);

/**
 * @brief Testa o construtor de cópia de Model.
 * A cópia deve conter os mesmos ponteiros que o original.
 */
void unit_Model_copyConstructor(void);

/**
 * @brief Testa o operador de atribuição de Model.
 * Verifica atribuição normal e auto-atribuição.
 */
void unit_Model_assignmentOperator(void);

/**
 * @brief Testa add(System*).
 * Após adicionar, o iterador deve encontrar o sistema na lista.
 */
void unit_Model_add_System(void);

/**
 * @brief Testa add(Flow*).
 * Após adicionar, o iterador deve encontrar o fluxo na lista.
 */
void unit_Model_add_Flow(void);

/**
 * @brief Testa remove(System*).
 * Após remover, o sistema não deve mais estar na lista.
 */
void unit_Model_remove_System(void);

/**
 * @brief Testa remove(Flow*).
 * Após remover, o fluxo não deve mais estar na lista.
 */
void unit_Model_remove_Flow(void);

/**
 * @brief Testa beginSystems().
 * Em modelo vazio, begin == end. Após adicionar um sistema, deve apontar para ele.
 */
void unit_Model_beginSystems(void);

/**
 * @brief Testa endSystems().
 * A iteração completa deve percorrer exatamente todos os sistemas adicionados.
 */
void unit_Model_endSystems(void);

/**
 * @brief Testa beginFlows().
 * Em modelo vazio, begin == end. Após adicionar um fluxo, deve apontar para ele.
 */
void unit_Model_beginFlows(void);

/**
 * @brief Testa endFlows().
 * A iteração completa deve percorrer exatamente todos os fluxos adicionados.
 */
void unit_Model_endFlows(void);

/**
 * @brief Testa execute() com o modelo exponencial clássico.
 * Configuração: pop1=100, pop2=0, ExponentialFlow, 100 iterações.
 * Resultado esperado: pop1 ≈ 36.6032, pop2 ≈ 63.3968.
 */
void unit_Model_execute(void);

/**
 * @brief Executa todos os testes unitários da classe Model.
 */
void run_unit_tests_Model(void);

#endif // UNIT_MODEL_H
