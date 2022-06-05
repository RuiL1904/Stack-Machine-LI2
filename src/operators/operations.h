#ifndef OPERATIONS_H
#define OPERATIONS_H

/**
 * @brief Macro que define o número de operadores implementados na STACK
 *
 */
#define N_OPERATORS 37

/**
 * @brief Função que retorna o operador associado ao índice dado
 *
 * @param i O índice
 * @return char
 */
char *get_operator(int i);

/**
 * @brief Função que verifica se um dado char é um operador
 *
 * @param token Uma string cujo primeiro elemento é o char a ser verificado
 * @return int
 */
int is_operator(char *token);

/**
 * @brief Função que retorna o índice associado a um operador
 *
 * @param operator O operador
 * @return int
 */
int get_index(char *operator);

/**
 * @brief Funçao que obtém um argumento do tipo double
 * 
 * @param x argumento
 * @return double 
 */
double get_double_arg(STACK_ELEM x);

/**
 * @brief Funçao que obtém um argumento do tipo long
 * 
 * @param x argumento
 * @return long 
 */
long get_long_arg(STACK_ELEM x);
/**
 * @brief Uma tabela de despacho responsável por invocar a função correspondente ao operador dado
 *
 * @param s Apontador para a STACK
 * @param operator O operador
 * @param g Variáveis globais 
 * 
 */
void dispatch_table(STACK *s, char *operator, GLOBALS *g);

/**
 * @brief Definição do tipo de cada elemento da tabela de despacho (um apontador para uma função)
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
typedef void (*function_pointer)(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '+'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void plus_operator(STACK *s,GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '-'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void minus_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '*'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void asterisk_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '/'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void slash_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '%'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void percentage_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '#'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void hashtag_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '^'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void circumflex_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '&'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void and_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '|'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void or_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo ')'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void left_parenthesis_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '('
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void right_parenthesis_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '~'
 *
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void tilde_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'i'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void lowercase_i_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'f'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void lowercase_f_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'c'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */        
void lowercase_c_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 's'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void lowercase_s_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '_'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void underscore_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo ';'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void semicolon_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '\'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void inverted_slash_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '@'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void arroba_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '$'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void dollar_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'l'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void lowercase_l_operator(STACK *s, GLOBALS *g);

/**
 * @brief Coloca o valor atual da variável global na STACK
 * 
 * @param s Apontador para a STACK
 * @param value letra que se encontra na variável global
 * @param g Variáveis globais 
 * 
 * @return STACK_ELEM 
 */
STACK_ELEM get_global(char value, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '='
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void equal_sign_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '<'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 * 
 */
void less_sign_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '>'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void more_sign_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '!'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void exclamation_mark_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'e&'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void and_with_and_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'e|'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void and_with_or_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'e<'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void and_with_less_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'e>'
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void and_with_more_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo '?'
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void question_mark_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo ','
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void comma_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'S/'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void uppercase_s_and_slash_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'N/'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void uppercase_n_and_slash_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 't'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void lowercase_t_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'w'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void lowercase_w_operator(STACK *s, GLOBALS *g);

/**
 * @brief Função que gere as operações associadas ao símbolo 'p'
 * 
 * @param s Apontador para a STACK
 * @param g Variáveis globais 
 */
void lowercase_p_operator(STACK *s, GLOBALS *g);

#endif
