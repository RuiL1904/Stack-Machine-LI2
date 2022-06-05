#include "../stack.h"
#include "operations.h"
#include "mathematics.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sum_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == DOUBLE || y.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = get_double_arg(x) + get_double_arg(y);
    } 
    else if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) + get_long_arg(y);
    }
    else {
        result->t = CHAR;
        result->data.c = x.data.c + y.data.c;
    }
}

void subtract_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == DOUBLE || y.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = get_double_arg(x) - get_double_arg(y);
    } 
    else if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) - get_long_arg(y);
    } 
    else {
        result->t = CHAR;
        result->data.c = x.data.c - y.data.c;
    }
}

void multiply_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == DOUBLE || y.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = get_double_arg(x) * get_double_arg(y);
    } 
    else if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) * get_long_arg(y);
    } 
    else if (x.t == CHAR && y.t == CHAR) {
        result->t = CHAR;
        result->data.c = x.data.c * y.data.c;
    }
}

void divide_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == DOUBLE || y.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = get_double_arg(x) / get_double_arg(y);
    } 
    else if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) / get_long_arg(y);
    } 
    else {
        result->t = CHAR;
        result->data.c = x.data.c / y.data.c;
    }    
}

void remainder_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) % get_long_arg(y);
    } 
    else {
        result->t = CHAR;
        result->data.c = x.data.c % y.data.c;
    }
}

void power_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == DOUBLE || y.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = pow(get_double_arg(x), get_double_arg(y));
    } 
    else if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = (long) pow(get_long_arg(x), get_long_arg(y));
    } 
    else {
        result->t = CHAR;
        result->data.c = (char) pow(x.data.c, y.data.c);
    }
}

void bitwise_xor_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) ^ get_long_arg(y);
    } 
    else {
        result->t = CHAR;
        result->data.c = x.data.c ^ y.data.c;
    }
}

void bitwise_and_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) & get_long_arg(y);
    } 
    else {
        result->t = CHAR;
        result->data.c = x.data.c & y.data.c;
    }
}

void bitwise_or_two_numbers(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (x.t == LONG || y.t == LONG) {
        result->t = LONG;
        result->data.l = get_long_arg(x) | get_long_arg(y);
    } 
    else {
        result->t = CHAR;
        result->data.c = x.data.c | y.data.c;
    }
}

void increment_number(STACK_ELEM x, STACK_ELEM *result) {
    if (x.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = ++x.data.d;
    } 
    else if (x.t == LONG) {
        result->t = LONG;
        result->data.l = ++x.data.l;
    } 
    else {
        result->t = CHAR;
        result->data.c = ++x.data.c;
    }
}

void decrement_number(STACK_ELEM x, STACK_ELEM *result) {
    if (x.t == DOUBLE) {
        result->t = DOUBLE;
        result->data.d = --x.data.d;
    } 
    else if (x.t == LONG) {
        result->t = LONG;
        result->data.l = --x.data.l;
    } 
    else {
        result->t = CHAR;
        result->data.c = --x.data.c;
    }
}

void bitwise_not_one_number(STACK *s, STACK_ELEM x, STACK_ELEM *result) {
    if (x.t == LONG) {
        result->t = LONG;
        result->data.l = ~x.data.l;
    } 
    else {
        result->t = CHAR;
        result->data.c = ~x.data.c;
    }
    
    push(s, *result);
}

void compare_two_numbers_equality(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (get_double_arg(x) == get_double_arg(y)) {
        result->t = LONG;
        result->data.l = 1;
        
        push(s, *result);
    }
    else {
        result->t = LONG;
        result->data.l = 0;
        
        push(s, *result);
    }
}

void compare_two_numbers_less(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (get_double_arg(x) < get_double_arg(y)) {
        result->t = LONG;
        result->data.l = 1;
        
        push(s, *result);
    }
    else {
        result->t = LONG;
        result->data.l = 0;
        
        push(s, *result);
    }
}

void compare_two_numbers_more(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    if (get_double_arg(x) > get_double_arg(y)) {
        result->t = LONG;
        result->data.l = 1;
        
        push(s, *result);
    }
    else {
        result->t = LONG;
        result->data.l = 0;
        
        push(s, *result);
    }
}
