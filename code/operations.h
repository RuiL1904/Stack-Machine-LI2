/**
 * @brief Macro que define o número de operadores implementados na stack
 *
 */
#define N_OPERATORS 22

/**
 * @brief Função que retorna o operador associado ao índice dado
 *
 * @param i O índice
 * @return char
 */
char const *get_operator(int i);

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
int get_index(char const *operator);

/**
 * @brief Uma tabela de despacho responsável por invocar a função correspondente ao operador dado
 *
 * @param s Apontador para a stack
 * @param operator O operador
 */
void dispatch_table(STACK *s, char const *operator);

/**
 * @brief Definição do tipo de cada elemento da tabela de despacho
 *
 */
typedef void (*function)(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e coloca no topo a soma dos mesmos
 *
 * @param s Apontador para a stack
 */
void sum(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e coloca no topo a subtração do penúltimo pelo último
 *
 * @param s Apontador para a stack
 */
void sub(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e coloca no topo a multiplicação dos mesmos
 *
 * @param s Apontador para a stack
 */
void mult(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e coloca no topo a divisão do penúltimo pelo último
 *
 * @param s Apontador para a stack
 */
void divi(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e coloca no topo o resto da divisão do penúltimo pelo último
 *
 * @param s Apontador para a stack
 */
void rem(STACK *s);

/**
 * @brief Função que calcula a exponenciação de dois elementos da stack
 *
 * @param s
 */
void power(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e retorna o resultado da operação XOR ("ou exclusivo" ao nível dos bits)
 *
 * @param s Apontador para a stack
 */
void bw_xor(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e retorna o resultado da operação AND ("e" ao nível dos bits)
 *
 * @param s Apontador para a stack
 */
void bw_and(STACK *s);

/**
 * @brief Retira os dois elementos do topo da stack e retorna o resultado da operação OR ("ou" ao nível dos bits)
 *
 * @param s Apontador para a stack
 */
void bw_or(STACK *s);

/**
 * @brief Retira um elemento da stack, incrementa o seu valor, e de seguida coloca-o de volta na stack
 *
 * @param s Apontador para a stack
 */
void increment(STACK *s);

/**
 * @brief Retira um elemento da stack, decrementa o seu valor, e de seguida coloca-o de volta na stack
 *
 * @param s Apontador para a stack
 */
void decrement(STACK *s);

/**
 * @brief Retira os um elementos do topo da stack e retorna o resultado da operação NOT ("negação" ao nível dos bits)
 *
 * @param s Apontador para a stack
 */
void bw_not(STACK *s);

void conv_int(STACK *s);
void conv_double(STACK *s);
void conv_char(STACK *s);
void conv_str(STACK *s);

void duplicate(STACK *s);
void other_pop(STACK *s);
void swap(STACK *s);
void rotate(STACK *s);
void copy_nth(STACK *s);

void read_line(STACK *s);
