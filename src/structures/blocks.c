#include "../stack.h"
#include "../parser.h"
#include "../operators/conversions.h"
#include "../operators/operations.h"
#include "blocks.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void map(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g) {
    STACK *mapped = create_stack();
    STACK_ELEM array;

    convert_to_array(x, &array);

    for (int i = 0; i < array.data.a->sp; i++) {
        push(mapped, array.data.a->stc[i]);
        parse_line(mapped, y.data.b, g);
    }

    free_stack(array.data.a);
    array.data.a = mapped;

    if (all_char(array)) {
        result->t = STRING;
        convert_array_to_string(array, result);
    }
    else {
        *result = array;
    }
}

void fold(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g) {
    STACK *folded = create_stack();

    STACK_ELEM acc = x.data.a->stc[0];
    push(folded, acc);

    for (int i = 1; i < x.data.a->sp; i++) {
        push(folded, x.data.a->stc[i]);
        parse_line(folded, y.data.b, g);
    }

    result->t = ARRAY;
    result->data.a = folded;
}

void filter(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g) {
    STACK *filtered = create_stack();
    STACK_ELEM array, aux;

    convert_to_array(x, &array);

    for (int i = 0; i < array.data.a->sp; i++) {
        push(filtered, array.data.a->stc[i]);
        parse_line(filtered, y.data.b, g);

        assert(pop(filtered, &aux) == 0);

        if (truthy_value(aux)) {
            push(filtered, array.data.a->stc[i]);
        }
    }

    free_stack(array.data.a);
    array.data.a = filtered;

    if (all_char(array)) {
        result->t = STRING;
        convert_array_to_string(array, result);
    }
    else {
        *result = array;
    }
}

// Retorna 0 se x for menor ou igual a y, 1 se o contrário se verificar
int compare_on(STACK_ELEM x, STACK_ELEM y, STACK *temp, char *block,GLOBALS *g) {
    int result = 1;
    STACK_ELEM xp, yp;

    assert(push(temp, x) == 0);
    parse_line(temp, block, g);

    assert(push(temp, y) == 0);
    parse_line(temp, block, g);

    assert(pop(temp, &yp) == 0);
    assert(pop(temp, &xp) == 0);

    if (xp.t == STRING && yp.t == STRING) {
        if (strcmp(xp.data.s, yp.data.s) < 0) {
            result = 0;
        }
    } 
    else if (xp.t == ARRAY && yp.t == ARRAY) {
        return compare_arrays(xp.data.a, yp.data.a);
    } 
    else if(xp.t == DOUBLE && yp.t == DOUBLE){
        double xc = get_double_arg(xp), yc = get_double_arg(yp);
        
        if (xc < yc) {
            return 0;
        }
    }
    else {
        long xc = get_long_arg(xp), yc = get_long_arg(yp);
        
        if (xc < yc) {
            return 0;
        }
    }

    temp->sp = 0;  // Esvaziar a stack temporária, caso tenha elementos anteriores de modo a não causar erros (provavelmente não necessário, mas existe como segurança extra)

    return result;
}

int compare_arrays(STACK *x, STACK *y) {
    int result;

    for (int i = 0; i >= 0; i++) {
        if (x->stc[i].t == STRING && y->stc[i].t == STRING) {
            result = (strcmp(x->stc[i].data.s, y->stc[i].data.s));
        } 
        else if (x->stc[i].t == ARRAY && y->stc[i].t == ARRAY) {
            result = compare_arrays(x->stc[i].data.a, y->stc[i].data.a);
        } 
        else {
            double xc = get_double_arg(x->stc[i]), yc = get_double_arg(y->stc[i]);
            result = xc - yc;
        }

        if (result < 0) {
            return 0;
        } 
        else if (result > 0) {
            return 1;
        }

        // Se chegar ao fim de qualquer um dos arrays termina a comparação
        if (i == x->sp - 1) {
            return 0;
        }

        if (i == y->sp - 1) {
            return 1;
        }
    }

    return 0;
}

void sort_on(STACK_ELEM block, STACK_ELEM *array, GLOBALS *g) {
    STACK *temp = create_stack();
    int i, j;

    for (i = 1; i < array->data.a->sp; i++) {
        for (j = 0; j < i && compare_on(array->data.a->stc[i], array->data.a->stc[j], temp, block.data.s, g); j++);

        for (; j < i; j++) {
            swap(array->data.a, j, i);
        }
    }
}

void while_operation(STACK *s, STACK_ELEM x, GLOBALS *g) {
    STACK_ELEM aux;
    bool flag = true;

    while (flag) { // cursed do while
        parse_line(s, x.data.b, g);

        assert(pop(s, &aux) == 0);

        if (!truthy_value(aux)) {
            flag = false;
        }
    }
}

int truthy_value(STACK_ELEM x) {
    if (x.t == ARRAY && x.data.a->sp != 0) {
        return 1;
    } 
    else if (x.t == STRING && strlen(x.data.s) != 0) {
        return 1;
    } 
    else if (x.t == BLOCK && strlen(x.data.b) != 0) {
        return 1;
    }
    else if (is_arg(x)) {
        if (get_double_arg(x)) {
            return 1;
        }
    }

    return 0;
}

int is_arg(STACK_ELEM x) {
    return x.t == LONG || x.t == DOUBLE || x.t == CHAR;
}

int all_char(STACK_ELEM x) {
    for (int i = 0; i < x.data.a->sp; i++) {
        if (x.data.a->stc[i].t != CHAR) {
            return 0;
        }
    }

    return 1;
}
