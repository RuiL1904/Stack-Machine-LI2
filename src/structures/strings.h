#ifndef STRINGS_H
#define STRINGS_H

/**
 * @brief Função que concatena duas strings
 * 
 * @param y string
 * @param x string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void concatenate_two_strings(STACK_ELEM y, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que concatena as duas substrings dependendo da ordem ('order') pretendida
 * 
 * @param y string
 * @param x string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 * @param order 
 */
void concatenate_two_strings_aux(STACK_ELEM y, STACK_ELEM x, STACK_ELEM *result, int order);

/**
 * @brief Função que replica uma string
 * 
 * @param x STACK_ELEM
 * @param y string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void replicate_string(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que separa uma string em substrings
 * 
 * @param main string principal
 * @param sub substring
 * @param new nova substring
 */
void split_string_by_substring(STACK_ELEM *main, STACK_ELEM *sub, STACK *new);

/**
 * @brief Função que obtém o index de uma substring
 * 
 * @param x string
 * @param y substring
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void find_substring_index(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que remove o char que se encontra no início de uma string
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void remove_first_element_from_string(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que remove o char que se encontra no final de uma string
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void remove_last_element_from_string(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que obtém o char que se encontra no index dado (o indíce é dado pelo elemento no topo da stack)
 * 
 * @param s Apontador para a STACK 
 * @param x STACK_ELEM de onde se obtem o indice
 * @param y string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void get_char_at_index(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que verifica a igualdade de duas strings
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param y string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void check_strings_equality(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que verifica se uma string é menor que outra
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param y string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void check_strings_less(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que remove os 'x' últimos elementos de um array
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param y STACK_ELEM
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void take_from_string(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que verifica se uma string é maoir que outra
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param y string
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void check_strings_more(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que remove os 'x' primeiros elementos de um array
 * 
 * @param s Apontador para a STACK 
 * @param x string
 * @param y STACK_ELEM
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void drop_from_string(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

#endif
