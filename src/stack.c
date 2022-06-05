#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

STACK *create_stack() {
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    s->size = 100;
    s->stc = calloc(sizeof(STACK_ELEM), s->size);

    return s;
}

GLOBALS *init_globals() {
    GLOBALS *g = malloc(sizeof(GLOBALS));

    for (int i = 0; i < 6; i++) {
        g->globals[i].t = LONG;
        g->globals[i].data.l = i + 10;
    }
    
    g->globals[13].t = CHAR;
    g->globals[13].data.c = '\n';
    g->globals[18].t = CHAR;
    g->globals[18].data.c = ' ';
    
    for (int i = 0; i < 3; i++) {
        g->globals[i + 23].t = LONG;
        g->globals[i + 23].data.l = i;
    }

    return g;
}

int increase_stack(STACK *s){
    s->stc = realloc(s->stc,sizeof(STACK_ELEM) * s->size * 2);
    
    // Se a realocação da stack falhar: retorna 1 (ERRO)
    if (s->stc == NULL) {
        return 1;
    }
    
    s->size *= 2;

    return 0;
}

void print_stack(STACK *s) {
    print_elems(s); // É necessária para não imprimir /n quando lê um array
    putchar('\n');
}

void print_elems(STACK *s) {
    for (int i = 0; i < s->sp; i++) {
        STACK_ELEM current = s->stc[i];

        if (current.t == LONG) {
            printf("%ld", current.data.l);
        }
        else if (current.t == CHAR) {
            printf("%c", current.data.c);
        }
        else if (current.t == DOUBLE) {
            printf("%lg", current.data.d);
        }
        else if (current.t == STRING) {
            printf("%s", current.data.s);
        }
        else if (current.t == ARRAY) {
            print_elems(current.data.a);
        }
        else if (current.t == BLOCK) {
            if (*(current.data.b) == '\0') {
                printf("{ }");
            }
            else {
                printf("{ %s }", current.data.b);
            }
        }
    }
}

void free_stack(STACK *s) {
    // De seguida liberta-se o outro conteúdo da stack
    free(s->stc);
    
    // Finalmente liberta-se a estrutura da stack
    free(s);
}

int push(STACK *s, STACK_ELEM elem) {
    if (s->sp == s->size) { 
        // Se não for possível duplicar o tamanho da stack: retorna 1 (ERRO)
        if (increase_stack(s)) { 
            return 1; 
        }
    }
    
    s->stc[s->sp] = elem;
    s->sp++;

    return 0;
}

int pop(STACK *s, STACK_ELEM *elem) {
    // Se a stack estiver vazia: retorna 1 (ERRO)
    if (s->sp == 0) {
        return 1; 
    }
    
    s->sp--;
    STACK_ELEM current = s->stc[s->sp];
    *elem = current;
    
    return 0;
}

// Caso especial da 'nth_element' quando n = 0
int peek(STACK *s, STACK_ELEM *elem) {
    // Se a stack estiver vazia: retorna 1 (ERRO)
    if (s->sp == 0) {
        return 1;
    }
    
    *elem = s->stc[s->sp - 1];

    return 0;
}

int nth_element(STACK *s, STACK_ELEM *elem, int n) {
    if (s->sp == 0) {
        return 1;
    }
    
    *elem = s->stc[s->sp - n - 1];

    return 0;
}

// Troca a posição de dois elementos numa stack (onde a posição 0 é o fundo da stack e sp - 1 o topo)
void swap(STACK *array, int x, int y) {
    STACK_ELEM temp;
    
    nth_element(array, &temp, array->sp - 1 - x);
    nth_element(array, &array->stc[x], array->sp - 1 - y);

    array->stc[y] = temp;
}
