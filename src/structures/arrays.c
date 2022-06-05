#include "../stack.h"
#include "../operators/operations.h"
#include "arrays.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void concatenate_two_arrays(STACK_ELEM y, STACK_ELEM x, STACK_ELEM *result, int order) {
    if (x.t == ARRAY) {
        for (int i = 0 ; i < x.data.a->sp; i++) {
            assert(push(y.data.a, x.data.a->stc[i]) == 0);
        }

        *result = y;
    }
    else if (order) {
        assert(push(y.data.a, x) == 0);
        *result = y;
    }
    else {
        STACK *s = create_stack();
        assert(push(s, x) == 0);
        
        for (int i = 0; i < y.data.a->sp; i++) {
            assert(push(s, y.data.a->stc[i]) == 0);
        }
        
        result->t = ARRAY;
        result->data.a = s;
    }
}

void replicate_array(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    int len = y.data.a->sp;

    for (int i = 0; i < len * x.data.l - len; i++) {
        push(y.data.a, y.data.a->stc[i]);
    }

    result->t = ARRAY;
    result->data.a = y.data.a;
}

void remove_first_element_from_array(STACK *s, STACK_ELEM x, STACK_ELEM *result) {
    assert(pop(x.data.a, result) == 0);

    push(s, x);
    push(s, *result);
}

void remove_last_element_from_array(STACK *s, STACK_ELEM x, STACK_ELEM *result) {
    STACK *new = create_stack();

    STACK_ELEM to_push = x.data.a->stc[0];

    for (int i = 1; i < x.data.a->sp; i++) {
        push(new, x.data.a->stc[i]);
    }

    result->t = ARRAY;
    result->data.a = new;

    push(s, *result);
    push(s, to_push);
}

void transfer_array_elements_to_stack(STACK *s, STACK_ELEM x) {
    for (int i = x.data.a->sp - 1; i >= 0; i--) {
        STACK_ELEM new;
        
        assert(nth_element(x.data.a, &new, i) == 0);
        assert(push(s, new) == 0);
    }

    free(x.data.a);
}

void get_element_at_index(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    long pos = get_long_arg(x);
        
    assert(nth_element(y.data.a, result, y.data.a->sp - pos - 1) == 0);
    
    push(s, *result);
}

void take_from_array(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    long len = x.data.a->sp, extract = get_long_arg(y);

    STACK *new_array = create_stack();
    
    if (extract > len) {
        extract = len; // Se for pedido para extrair mais elementos do que aqueles que existem no array, será apenas extraído o array todo (é impossivel estrair mais elementos do que aqueles que existem)
    }
    
    for (int i = 0; i < extract; i++) {
        assert(nth_element(x.data.a, result, x.data.a->sp - i - 1) == 0);
        assert(push(new_array, *result) == 0);
    }

    result->t = ARRAY;
    result->data.a = new_array;
}

void drop_from_array(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    long len = x.data.a->sp, extract = get_long_arg(y);

    STACK *new_array = create_stack();
        
    if (extract > len) {
        extract = len; // Se for pedido para extrair mais elementos do que aqueles que existem no array, será apenas extraído o array todo (é impossivel estrair mais elementos do que aqueles que existem)
    }
        
    for (int i = len - extract; i < len ; i++) {
        assert(push(new_array, x.data.a->stc[i]) == 0);
    }

    result->t = ARRAY;
    result->data.a = new_array;
}

void create_array_in_range(STACK_ELEM x, STACK_ELEM *result) {
    STACK *new = create_stack();

    for (int i = 0; i < x.data.l; i++) {
        STACK_ELEM to_push = { 
            .t = LONG,
            .data.l = i
        };

        push(new, to_push);
    }

    result->t = ARRAY;
    result->data.a = new;
}

void check_array_equality(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    long len1 = x.data.a->sp, len2 = y.data.a->sp;
    int flag = 1;

    if (len1 != len2)
        flag = 0;

    for(int i = 0; i < len1 && flag == 1; i++) {
        if(get_double_arg(x.data.a->stc[i]) != get_double_arg(y.data.a->stc[i]))
            flag = 0;
    }

    result->t = LONG;
    result->data.l = flag;

    push(s, *result);
}