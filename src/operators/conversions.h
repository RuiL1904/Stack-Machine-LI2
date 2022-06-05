#ifndef CONVERSIONS_H
#define CONVERSIONS_H

/**
 * @brief Função que converte o argumento num inteiro
 * 
 * @param s  Apontador para a STACK
 * @param x argumento
 * @param result STACK_ELEM onde irá ser guardado o resultado 
 */
void convert_to_int(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que converte o argumento num double
 * 
 * @param s  Apontador para a STACK
 * @param x argumento
 * @param result STACK_ELEM onde irá ser guardado o resultado 
 */
void convert_to_double(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que converte o argumento num char
 * 
 * @param s  Apontador para a STACK
 * @param x argumento
 * @param result STACK_ELEM onde irá ser guardado o resultado 
 */
void convert_to_char(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que converte o argumento numa string
 * 
 * @param s  Apontador para a STACK
 * @param x argumento
 * @param result STACK_ELEM onde irá ser guardado o resultado 
 */
void convert_to_string(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que converte o argumentos num array
 * 
 * @param x argumento
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void convert_to_array(STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que converte um array numa string (não alterando a STACK)
 * 
 * @param x argumento
 * @param result STACK_ELEM onde irá ser guardado o resultado 
 */
void convert_array_to_string(STACK_ELEM x, STACK_ELEM *result);

#endif
