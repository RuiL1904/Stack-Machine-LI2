#ifndef BLOCKS_H
#define BLOCKS_H

/**
 * @brief Função que aplica um bloco a todos os elementos de um array ou string
 * 
 * @param x array ou string
 * @param y bloco
 * @param result STACK_ELEM onde irá ser guardado o resultado  
 * @param g Variáveis Globais 
 */
void map(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

/**
 * @brief Função que aplica um fold sobre um array usando um bloco
 * 
 * @param x bloco
 * @param y array
 * @param result STACK_ELEM onde irá ser guardado o resultado  
 * @param g Variáveis Globais 
 */
void fold(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

/**
 * @brief Função que filtra um array conforme um bloco
 * 
 * @param x array ou string
 * @param y bloco
 * @param result STACK_ELEM onde irá ser guardado o resultado  
 * @param g Variáveis Globais 
 */
void filter(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

/**
 * @brief Função que compara dois elementos da stack: retorna 0 se x for menor ou igual a y, 1 se o contrário se verificar
 * 
 * @param x array
 * @param y array
 * @param temp uma stack
 * @param block bloco
 * @param g Variáveis Globais 
 * @return int 0 ou 1
 */
int compare_on(STACK_ELEM x, STACK_ELEM y, STACK *temp, char *block, GLOBALS *g);

/**
 * @brief Função que compara dois arrays
 * 
 * @param x array
 * @param y array
 * @return int 0 ou 1
 */
int compare_arrays(STACK *x, STACK *y);

/**
 * @brief Função que ordena um array segundo a condição dada por um bloco
 * 
 * @param block bloco
 * @param array array
 * @param g Variáveis Globais 
 */
void sort_on(STACK_ELEM block,STACK_ELEM *array,GLOBALS *g);

/**
 * @brief Função que realiza um loop do while na stack segundo um bloco
 * 
 * @param s Apontador para a STACK 
 * @param x bloco
 * @param g Variáveis Globais 
 */
void while_operation(STACK *s, STACK_ELEM x, GLOBALS *g);

/**
 * @brief Função que verifica se o elemento é considerado um valor 'truthy'
 * 
 * @param x Elemento a verificar
 * @return int 0 ou 1
 */
int truthy_value(STACK_ELEM x);

/**
 * @brief Função que verifica se um elemento é argumento das funções 'get_long_arg' e 'get_double_arg', ou seja, se o elemento é um char/long/double
 * 
 * @param x Elemento a verificar
 * @return int 0 ou 1
 */
int is_arg(STACK_ELEM x);

/**
 * @brief Funçâo que verifica se todos elementos de um array são chars
 * 
 * @param x array
 * @return int 0 ou 1
 */
int all_char(STACK_ELEM x);

#endif
