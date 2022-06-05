#include "stack.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Função principal do programa
 * 
 * @return int 
 */
int main() {
    STACK *s = create_stack();
    GLOBALS *g = init_globals();

    get_line(s, g);

    print_stack(s);
    
    free_stack(s);
    free(g);

    return 0;
}
