#ifndef MATHEMATICS_H
#define MATHEMATICS_H

/**
 * @brief Função que executa a adiçao de dois números
 * 
 * @param x 1º numero a ser somado
 * @param y 2º numero  ser somado
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void sum_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que executa a subtração de dois números
 * 
 * @param x diminuendo
 * @param y diminuidor
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void subtract_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que executa a multiplicação de dois números
 * 
 * @param x 1º numero a ser multiplicado
 * @param y 2º numero  ser multiplicado
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void multiply_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que executa o quociente de dois números
 * 
 * @param x dividendo
 * @param y divisor
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void divide_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que calcula o resto da divisão de dois números
 * 
 * @param x dividendo
 * @param y divisor
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void remainder_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que calcula a potência de dois números 
 * 
 * @param x base
 * @param y expoente
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void power_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que aplica o "XOR" a dois números
 * 
 * @param x 1º número
 * @param y 2 º número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void bitwise_xor_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que aplica o "OR/OU" a dois números
 * 
 * @param x 1º número
 * @param y 2 º número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void bitwise_or_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que aplica o "AND/E" a dois números
 * 
 * @param x 1º número
 * @param y 2 º número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void bitwise_and_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que aumenta em uma unidade um número 
 * 
 * @param x número a ser aumentado
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void increment_number(STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que diminui em uma unidade um número 
 * 
 * @param x número a ser diminuido
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void decrement_number(STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função aplica o "NOT/Negação" a um número
 * 
 * @param x número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void bitwise_not_one_number(STACK *s, STACK_ELEM x, STACK_ELEM *result);

/**
 * @brief Função que verifica se dois números são iguais
 * 
 * @param x 1º número
 * @param y 2 º número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void compare_two_numbers_equality(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que verifica se o segundo número é maior que o primeiro
 * 
 * @param x 1º número
 * @param y 2 º número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void compare_two_numbers_less(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

/**
 * @brief Função que verifica se o segundo número é menor que o primeiro
 * 
 * @param x 1º número
 * @param y 2 º número
 * @param result STACK_ELEM onde irá ser guardado o resultado
 */
void compare_two_numbers_more(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result);

#endif
