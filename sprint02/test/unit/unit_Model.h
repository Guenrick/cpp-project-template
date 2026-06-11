/**
 * @file unit_Model.h
 * @brief Declaração dos testes unitários da classe Model.
 */

#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/**
 * @brief Testa Model::createModel().
 * Um Model recém-criado deve ter listas de sistemas e fluxos vazias.
 */
void unit_Model_constructor(void);

/**
 * @brief Testa o destrutor de Model.
 * Model é dono dos Systems e Flows criados por ele: destruí-lo deve
 * liberar essas memórias sem causar erros.
 */
void unit_Model_destructor(void);

/**
 * @brief Testa createSystem().
 * O System criado deve ter o id e o valor informados, e deve ser
 * encontrado na coleção interna do Model.
 */
void unit_Model_createSystem(void);

/**
 * @brief Testa createFlux<T_FLUX_IMPL>().
 * O Flow criado deve estar conectado às origens/destinos informados
 * e deve ser encontrado na coleção interna do Model.
 */
void unit_Model_createFlux(void);

/**
 * @brief Testa deleteSystem().
 * Após remover, o System não deve mais estar na lista de sistemas.
 */
void unit_Model_deleteSystem(void);

/**
 * @brief Testa deleteFlux().
 * Após remover, o Flow não deve mais estar na lista de fluxos.
 */
void unit_Model_deleteFlux(void);

/**
 * @brief Testa setSource(Flow&, System&).
 * Após a chamada, getSource() do Flow deve retornar o novo System.
 */
void unit_Model_setSource(void);

/**
 * @brief Testa setTarget(Flow&, System&).
 * Após a chamada, getTarget() do Flow deve retornar o novo System.
 */
void unit_Model_setTarget(void);

/**
 * @brief Testa clearSource(Flow&).
 * Após a chamada, getSource() do Flow deve retornar nullptr.
 */
void unit_Model_clearSource(void);

/**
 * @brief Testa clearTarget(Flow&).
 * Após a chamada, getTarget() do Flow deve retornar nullptr.
 */
void unit_Model_clearTarget(void);

/**
 * @brief Testa beginSystems().
 * Em modelo vazio, begin == end. Após criar um sistema, deve apontar para ele.
 */
void unit_Model_beginSystems(void);

/**
 * @brief Testa endSystems().
 * A iteração completa deve percorrer exatamente todos os sistemas criados.
 */
void unit_Model_endSystems(void);

/**
 * @brief Testa beginFlows().
 * Em modelo vazio, begin == end. Após criar um fluxo, deve apontar para ele.
 */
void unit_Model_beginFlows(void);

/**
 * @brief Testa endFlows().
 * A iteração completa deve percorrer exatamente todos os fluxos criados.
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
