#ifndef STACK_H
#define STACK_H

/**
 * @brief Tamanho máximo do buffer
 * 
 */
#define MAX_BUFFER_SIZE 10081

typedef struct STACK STACK;

/**
 * @brief Enum que guarda os tipos implementados na STACK
 * 
 */
typedef enum { 
    LONG, /**< Identificação do tipo long */
    CHAR, /**< Identificação do tipo char */
    DOUBLE, /**< Identificação do tipo double */
    STRING, /**< Identificação do tipo 'string' */
    ARRAY, /**< Identificação do tipo 'array' */
    BLOCK /**< Identificação do tipo 'bloco' */
} TYPE;

/**
 * @brief Estrutura que guarda o tipo e o conteúdo de um elemento da STACK
 * 
 */
typedef struct {
    TYPE t; /**< Tipo do elemento (vindo do enum 'TYPE') */
    union {
        long l; /**< Espaço de memória reservado para um long */
        char c; /**< Espaço de memória reservado para um char */
        double d; /**< Espaço de memória reservado para um double */
        char *s; /**< Espaço de memória reservado para uma 'string' */
        STACK *a; /**< Espaço de memória reservado para um 'array' */
        char *b; /**< Espaço de memória reservado para um 'bloco' */
    } data; /**< Conteúdo do elemento */
} STACK_ELEM;

/**
 * @brief A estrutura onde constam os parâmetros da STACK
 * 
 */
typedef struct STACK {
    int sp; /**< O STACK pointer */
    int size; /**< O tamanho total da STACK */
    STACK_ELEM *stc; /**< O conteúdo da STACK */
} STACK;

/**
 * @brief A estrutura onde constam as variáveis "globais" do programa
 * 
 */
typedef struct {
    STACK_ELEM globals[26]; /**< Variáveis "globais" */
} GLOBALS;

/**
 * @brief Inicializa uma STACK com 100 posições
 * 
 * @return STACK* 
 */
STACK *create_stack();

/**
 * @brief Inicializa as variáveis "globais"
 * 
 * @return GLOBALS* 
 */
GLOBALS *init_globals();

/**
 * @brief Aumenta o tamanho da STACK (para o dobro), se possível
 * 
 * @param s Apontador para a STACK
 * @return int 
 */
int increase_stack(STACK *s);

/**
 * @brief Imprime todos os elementos da STACK, começando pelo elemento do fundo e acabando no do topo
 * 
 * @param s Apontador para a STACK
 */
void print_stack(STACK *s);

/**
 * @brief Função que imprime os elementos na STACK
 * 
 * @param s Apontador para a STACK
 */
void print_elems(STACK *s);

/**
 * @brief Liberta a memória alocada, na heap, pela STACK
 * 
 * @param s Apontador para a STACK
 */
void free_stack(STACK *s);

/**
 * @brief Adiciona um elemento à STACK, se possível
 * 
 * @param s Apontador para a STACK
 * @param elem Elemento a ser adicionado à STACK
 * @return int 
 */
int push(STACK *s, STACK_ELEM elem);

/**
 * @brief Retira o elemento que está no topo da STACK
 * 
 * @param s Apontador para a STACK
 * @param elem Apontador para o elemento que será retirado
 * @return int 
 */
int pop(STACK *s, STACK_ELEM *elem);

/**
 * @brief Encontra o elemento no topo da STACK, mas não o retiro (ao contrário da 'pop')
 * 
 * @param s Apontador para a STACK
 * @param elem Apontador para o elemento que receberá o conteúdo do topo da STACK
 * @return int 
 */
int peek(STACK *s, STACK_ELEM *elem);

/**
 * @brief Verifica o conteudo do n-ésimo elemento
 * 
 * @param s Apontador para a STACK
 * @param elem Apontador para o elemento que receberá o conteúdo do topo da STACK
 * @param n índice
 * @return int 
 */
int nth_element(STACK *s, STACK_ELEM *elem, int n);

/**
 * @brief Função que troca a posição de dois elementos numa STACK (onde a posição 0 é o fundo da STACK e sp - 1 o topo)
 * 
 * @param array array
 * @param x elemento
 * @param y elemento
 */
void swap(STACK *array, int x, int y);

#endif
