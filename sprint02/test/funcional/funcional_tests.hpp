/**
 * @file funcional_tests.hpp
 * @brief Declaração das funções de testes funcionais do simulador.
 * * Este arquivo contém os protótipos dos testes funcionais que validam o comportamento
 * das simulações de fluxo Exponencial, Logístico e de Redes Complexas.
 */

#ifndef FUNCIONAL_TESTS_HPP
#define FUNCIONAL_TESTS_HPP


/**
 * @brief Executa o teste funcional para o modelo exponencial.
 * * Cria um cenário com dois sistemas e um fluxo exponencial para validar a transferência
 * de massa ao longo de um determinado período de tempo, comparando o resultado final
 * com a precisão matemática esperada.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional para o modelo logístico.
 * * Configura uma simulação utilizando a equação de crescimento logístico entre dois sistemas,
 * avaliando se os limites de capacidade e taxas de variação estão sendo respeitados 
 * conforme os requisitos do modelo.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional complexo (cenário de rede).
 * * Monta uma rede interconectada de múltiplos sistemas (s1, s2, s3, s4, s5) e fluxos (u, v, g, r, t)
 * para simular um ecossistema completo. Valida a robustez do laço de execução do modelo principal
 * sob condições de concorrência e dependência de dados.
 */
void complexFuncionalTest();

#endif // FUNCIONAL_TESTS_HPP