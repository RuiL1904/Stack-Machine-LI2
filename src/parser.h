#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

/**
 * @brief Função que lê uma linha do stdin
 * 
 * @param s Apontador para a STACK 
 * @param g Variáveis Globais 
 * @return int 
 */
int get_line(STACK *s, GLOBALS *g);

/**
 * @brief Função que dá parse a uma linha, tokenizando e verificando do que se trata cada símbolo, etc
 * 
 * @param s Apontador para a STACK 
 * @return int 
 */
void parse_line(STACK *s, char *line, GLOBALS *g);

/**
 * @brief Função que recebe um token/símbolo e realiza a operação pretendida
 * 
 * @param s Apontador para a STACK
 * @param token Símbolo lido
 */
void handle_token(STACK *s, char *token, GLOBALS *g);

/**
 * @brief Função que verifica se a string contém apenas algarismos (^[0-9]+$)
 * 
 * @param token 
 * @return int 
 */
int is_long(char *token);

/**
 * @brief Função que verifica se a string contém apenas algarismos e um ponto (^[0-9]+\.[0-9]+$)
 * 
 * @param token 
 * @return int 
 */
int is_double(char *token);

/**
 * @brief Função que verifica se o token é uma string (^\"+.*\"+$)
 * 
 * @param token 
 * @return int 
 */
int is_string(char *token);

/**
 * @brief Função que verifica se o token é um array
 * 
 * @param token 
 * @return int 
 */
int is_array(char *token);

/**
 * @brief Função que verifica se o token é um bloco
 * 
 * @param token 
 * @return int 
 */
int is_block(char *token);

/**
 * @brief Função que verifica se o token é uma "variável global"
 * 
 * @param token 
 */
int is_global(char *token);

/**
 * @brief Função que verifica se o token é um readress da "variável global"
 * 
 * @param token 
 * @return int 
 */
int is_readress_global(char *token);

/**
 * @brief Função responsável pelo token caso este seja do tipo long
 * 
 * @param s Apontador para a STACK 
 * @param token 
 */
void handle_long(STACK *s, char *token);

/**
 * @brief Função responsável pelo token caso este seja do tipo double
 * 
 * @param s Apontador para a STACK 
 * @param token 
 */
void handle_double(STACK *s, char *token);

/**
 * @brief Função responsável pelo token caso este seja do tipo string
 * 
 * @param s Apontador para a STACK 
 * @param token 
 */
void handle_string(STACK *s, char *token);

/**
 * @brief Função responsável pelo token caso este seja do tipo array
 * 
 * @param s Apontador para a STACK 
 * @param token 
 * @param g Variáveis Globais 
 */
void handle_array(STACK *s, char *token, GLOBALS *g);

/**
 * @brief Função responsável pelo token caso este seja do tipo bloco
 * 
 * @param s Apontador para a STACK 
 * @param token 
 */
void handle_block(STACK *s, char *token);

/**
 * @brief Função responsável pelo token caso este seja uma "variável global"
 * 
 * @param s Apontador para a STACK 
 * @param token 
 * @param g Variáveis Globais 
 */
void handle_global(STACK *s, char *token, GLOBALS *g);

/**
 * @brief Função resposável pelo token caso este seja uma variavel global, e tenha falhado as outras verificações
 * 
 * @param s Apontador para a STACK 
 * @param token 
 * @param g Variáveis Globais 
 */
void handle_readress_global(STACK *s, char *token, GLOBALS *g);

/**
 * @brief Função que devolve o index do char 'c'
 * 
 * @param line array
 * @param c char que se quer encontar
 * @param parsed índice onde se começa a procura
 */
int find_char(char *line, char c, int parsed);

/**
 * @brief Função que devolve o tamanho total do array
 * 
 * @param line array
 * @param parsed índice do início do array
 */
int get_array_length(char *line, int parsed);

/**
 * @brief Função que devolve o tamanho total do bloco
 * 
 * @param line bloco
 * @param parsed índice do início do bloco
 * @return int 
 */
int get_block_length(char *line, int parsed);

/**
 * @brief Função que copia a line para o token a partir da posição 'parsed' até que tenha um tamanho de 'len'
 * 
 * @param token 
 * @param line
 * @param len tamanho do token
 * @param parsed índice de início do token
 */
void copy(char *token, char *line, int len, int parsed);

/**
 * @brief Remove o caracter na posição 'p'
 * 
 * @param s Apontador para a STACK 
 * @param p indice
 */
void remove_char(char *s, int p);

#endif
