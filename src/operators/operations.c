#include "../stack.h"

#include "operations.h"
#include "mathematics.h"
#include "conversions.h"
#include "../structures/strings.h"
#include "../structures/arrays.h"
#include "../structures/blocks.h"

#include "../parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>

/**
 * @brief Macro utilizada para definir argumentos como nulos (uma vez que usamos uma dispatch table)
 * 
 */
#define UNUSED(x) (void) (x)

void plus_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    if (y.t == ARRAY) {
        concatenate_two_arrays(y, x, &result, 1);
    }
    else if (x.t == ARRAY) {
        concatenate_two_arrays(x, y, &result, 0);
    }
    else if (y.t == STRING || x.t == STRING) {
        concatenate_two_strings(y, x, &result);
    }
    else {
        sum_two_numbers(x, y, &result);
    }

    push(s, result);

    UNUSED(g);
}

void minus_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    subtract_two_numbers(x, y, &result);

    push(s, result);

    UNUSED(g);
}

void asterisk_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    if (y.t == STRING) {
        replicate_string(x, y, &result);
    }
    else if (x.t == BLOCK && y.t == ARRAY) {
        fold(y, x, &result, g);
    }
    else if (y.t == ARRAY) {
        replicate_array(x, y, &result);
    }
    else {
        multiply_two_numbers(x, y, &result);
    }

    push(s, result);

    UNUSED(g);
}

void slash_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    if (x.t == STRING && y.t == STRING) {
        result.t = ARRAY;
        STACK *new = create_stack();
        
        split_string_by_substring(&x, &y, new);
        
        result.data.a = new;
        
        free(x.data.s);
        free(y.data.s);
    }
    else if(x.t == STRING && y.t == CHAR) {
        result.t = ARRAY;
        STACK *new = create_stack();
        
        STACK_ELEM temp = {
            .t = STRING,
            .data.s = malloc(sizeof(char) * 2)
        };

        temp.data.s[0] = y.data.c;
        temp.data.s[1] = '\0';
        
        split_string_by_substring(&x, &temp, new);
        
        result.data.a = new;
        
        free(x.data.s);
        free(temp.data.s);
    }
    else {
        divide_two_numbers(x, y, &result);
    }

    push(s, result);

    UNUSED(g);
}

void percentage_operator(STACK *s, GLOBALS *g) { 
    STACK_ELEM x, y, result;
    
    assert(pop(s, &y) == 0); 
    assert(pop(s, &x) == 0); 
    
    if (y.t == BLOCK && (x.t == ARRAY || x.t == STRING)) { 
        map(x, y, &result, g); 
    }
    else { 
        remainder_two_numbers(x, y, &result); 
    } 
    
    push(s, result); 
}

void hashtag_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    if (x.t == STRING && y.t == STRING) {
        find_substring_index(x, y, &result);
    }
    else if (x.t == STRING && y.t == CHAR) {
        STACK_ELEM temp = {
            .t = STRING,
            .data.s = malloc(sizeof(char) * 2)
        };
        
        temp.data.s[0] = y.data.c;
        temp.data.s[1] = '\0';
        
        find_substring_index(x, temp, &result);
    }
    else {
        power_two_numbers(x, y, &result);
    }

    push(s, result);

    UNUSED(g);
}

void circumflex_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    bitwise_xor_two_numbers(x, y, &result);

    push(s, result);

    UNUSED(g);
}

void and_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    bitwise_and_two_numbers(x, y, &result);

    push(s, result);

    UNUSED(g);
}

void or_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    bitwise_or_two_numbers(x, y, &result);

    push(s, result);

    UNUSED(g);
}

void left_parenthesis_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;

    assert(pop(s, &x) == 0);

    if (x.t == STRING) {
        result.t = STRING;

        remove_first_element_from_string(s, x, &result);
    }
    else if (x.t == ARRAY) {
        result.t = ARRAY;

        remove_first_element_from_array(s, x, &result);
    }
    else {
        increment_number(x, &result);

        push(s, result);
    }

    UNUSED(g);
}   

void right_parenthesis_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;

    assert(pop(s, &x) == 0);

    if (x.t == STRING) {
        result.t = STRING;

        remove_last_element_from_string(s, x, &result);
    }
    else if (x.t == ARRAY) {
        result.t = ARRAY;

        remove_last_element_from_array(s, x, &result);
    }
    else {
        decrement_number(x, &result);

        push(s, result);
    }

    UNUSED(g);
}

void tilde_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;

    assert(pop(s, &x) == 0);

    if (x.t == BLOCK) {
        parse_line(s, x.data.b, g);
    }
    else if (x.t == ARRAY) {
        transfer_array_elements_to_stack(s, x);
    }
    else {
        STACK_ELEM result;
        
        bitwise_not_one_number(s, x, &result);
    }
}

void lowercase_i_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;
    
    assert(pop(s, &x) == 0);

    convert_to_int(s, x, &result);

    UNUSED(g);
}

void lowercase_f_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;
    
    assert(pop(s, &x) == 0);

    convert_to_double(s, x, &result);

    UNUSED(g);
}

void lowercase_c_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;
    
    assert(pop(s, &x) == 0);

    convert_to_char(s, x, &result);

    UNUSED(g);
}

void lowercase_s_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;
    
    assert(pop(s, &x) == 0);

    result.data.s = malloc(sizeof(char) * MAX_BUFFER_SIZE);

    convert_to_string(s, x, &result);

    UNUSED(g);
}

void underscore_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;
    
    assert(pop(s, &x) == 0);
    
    assert(push(s, x) == 0);
    assert(push(s, x) == 0);

    UNUSED(g);
}

void semicolon_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;
    
    assert(pop(s, &x) == 0);

    UNUSED(g);
}

void inverted_slash_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    assert(push(s, x) == 0);
    assert(push(s, y) == 0);

    UNUSED(g);
}

void arroba_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, z;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);
    assert(pop(s, &z) == 0);

    assert(push(s, y) == 0);
    assert(push(s, x) == 0);
    assert(push(s, z) == 0); 

    UNUSED(g);  
}

void dollar_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;
    
    assert(pop(s, &x) == 0);
    
    if (x.t == BLOCK) {
        assert(pop(s, &y) == 0);
        
        if (y.t == STRING) {
            STACK_ELEM aux;
            convert_to_array(y, &aux);
            sort_on(x, &aux, g);
            convert_array_to_string(aux, &result);
        }
        else {
            sort_on(x, &y, g);
            result = y; 
        }
        
        free(x.data.b);
    }
    else {
        assert(nth_element(s, &result, x.data.l) == 0);
    }

    assert(push(s, result) == 0);

    UNUSED(g);
}

void lowercase_l_operator(STACK *s, GLOBALS *g) {
    char *line = malloc(sizeof(char) * MAX_BUFFER_SIZE);

    if (fgets(line, MAX_BUFFER_SIZE, stdin) != NULL) {
        line[strlen(line) - 1] = '\0';

        STACK_ELEM result = {
            .t = STRING,
            .data.s = strdup(line)
        };

        assert(push(s, result) == 0);
    }

    UNUSED(g);
}

STACK_ELEM get_global(char value, GLOBALS *g) {
    STACK_ELEM new, current = g->globals[value -  65];
    
    if (current.t == DOUBLE) {
        new.t = DOUBLE;
        new.data.d = current.data.d;
    }
    else if (current.t == LONG) {
        new.t = LONG;
        new.data.l = current.data.l;
    }
    else if (current.t == STRING) {
        int len = strlen(current.data.s);
        
        char *copy_string = malloc(sizeof(char) * len + 1);
        strcpy(copy_string, current.data.s);
        copy_string[len] = '\0';
        
        new.t = STRING;
        new.data.s = copy_string;
    }
    else if (current.t == ARRAY) {
        STACK_ELEM temp;
        STACK *copy_array = create_stack();
        
        for (int i = current.data.a->sp - 1; i >= 0; i--) {
            nth_element(current.data.a, &temp, i);
            assert(push(copy_array, temp) == 0);
        }
        
        new.t = ARRAY;
        new.data.a = copy_array;
    }
    else if (current.t == BLOCK) {
        int len = strlen(current.data.b);
        
        char *copy_block = malloc(sizeof(char) * len + 1);
        strcpy(copy_block, current.data.b);
        copy_block[len] = '\0';
        
        new.t = BLOCK;
        new.data.b = copy_block;
    }
    else {
        new.t = CHAR;
        new.data.c = current.data.c;
    }

    return new;
}

void equal_sign_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &x) == 0);
    assert(pop(s, &y) == 0);

    if (x.t != ARRAY && y.t == ARRAY) {
        get_element_at_index(s, x, y, &result);
    }
    else if (x.t == ARRAY && y.t == ARRAY) {
        check_array_equality(s, x, y, &result);
    }
    else if (x.t != STRING && y.t == STRING) {
        get_char_at_index(s, x, y, &result);
    }
    else if (x.t == STRING && y.t == STRING) {
        check_strings_equality(s, x, y, &result);
    }
    else {
        compare_two_numbers_equality(s, x, y, &result);
    }

    UNUSED(g);
}

void less_sign_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    if (x.t == ARRAY) {
        take_from_array(x, y, &result);
        
        push(s, result);
    }
    else if (x.t == STRING && y.t == STRING) {
        check_strings_less(s, x, y, &result);
    }
    else if (x.t == STRING) {
        take_from_string(s, x, y, &result);
    }
    else {
        compare_two_numbers_less(s, x, y, &result);
    }

    UNUSED(g);
}

void more_sign_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, result;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);   

    if (x.t == ARRAY) {
        drop_from_array(x, y, &result);
        
        push(s, result);
    }
    else if (x.t == STRING && y.t == STRING) {
        check_strings_more(s, x, y, &result);
    }
    else if (x.t == STRING) {
        drop_from_string(s, x, y, &result);
    }
    else {
        compare_two_numbers_more(s, x, y, &result);
    }

    UNUSED(g);
}

void exclamation_mark_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;
    long to_push = 1;

    result.t = LONG;

    assert(pop(s, &x) == 0);

    if (truthy_value(x)) {
        to_push = 0;
    }
    
    result.data.l = to_push;
    
    push(s, result);

    UNUSED(g);
}

void and_with_and_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y;
    
    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    STACK_ELEM result = x;

    if (truthy_value(x)) {
        result = y;
    }

    push(s, result);

    UNUSED(g);
}

void and_with_or_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y;
    
    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    STACK_ELEM result = y;

    if (truthy_value(x)) {
        result = x;
    }

    push(s, result);

    UNUSED(g);
}

void and_with_less_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    STACK_ELEM result = y;

    if (x.t == STRING && y.t == STRING) {
        if (strcmp(x.data.s, y.data.s) < 0) {
            result = x;
        }
    }
    else if (get_double_arg(x) < get_double_arg(y)) {
        result = x;
    }
    
    push(s, result);

    UNUSED(g);
}

void and_with_more_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y;

    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    STACK_ELEM result = y;

    if (x.t == STRING && y.t == STRING) {
        if (strcmp(x.data.s, y.data.s) > 0) {
            result = x;
        }
    }
    else if (get_double_arg(x) > get_double_arg(y)) {
        result = x;
    }
    
    push(s, result);

    UNUSED(g);
}

void question_mark_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, y, z;

    assert(pop(s, &z) == 0);
    assert(pop(s, &y) == 0);
    assert(pop(s, &x) == 0);

    STACK_ELEM result = z;

    if (truthy_value(x)) {
        result = y;
    }    

    push(s, result);

    UNUSED(g);
}

void comma_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x, result;

    assert(pop(s, &x) == 0);

    if (x.t == STRING) {
        result.t = LONG;
        result.data.l = strlen(x.data.s);
    }
    else if (x.t == ARRAY) {
        result.t = LONG;
        result.data.l = x.data.a->sp;
    }
    else if (x.t == LONG || x.t == CHAR) {
        result.t = ARRAY;
        
        create_array_in_range(x, &result);
    }
    else {
        STACK_ELEM y;
        
        assert(pop(s, &y) == 0);
        
        filter(y, x, &result, g);
    }

    push(s, result);

    UNUSED(g);
}

void uppercase_s_and_slash_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;
    
    assert(pop(s, &x) == 0);

    STACK_ELEM result = {
        .t = ARRAY,
        .data.a = create_stack()
    };

    if (x.t == STRING) {
        char *token, *rest = x.data.s;

        while ((token = strtok_r(rest, " \t\r\n\v\f", &rest))) {
            STACK_ELEM to_push = {
                .t = STRING,
                .data.s = strdup(token)
            };
            
            push(result.data.a, to_push);
        }
        
        push(s, result);
        
        free(token);
    }

    UNUSED(g);
}

void uppercase_n_and_slash_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;
    
    assert(pop(s, &x) == 0);

    STACK_ELEM result = {
        .t = ARRAY,
        .data.a = create_stack()
    };

    if (x.t == STRING) {
        char *token, *rest = x.data.s;

        while ((token = strtok_r(rest, "\n", &rest))) {
            STACK_ELEM to_push = {
                .t = STRING,
                .data.s = strdup(token)
            };
            
            push(result.data.a, to_push);
        }
        
        push(s, result);
        
        free(token);
    }

    UNUSED(g);
}

void lowercase_t_operator(STACK *s, GLOBALS *g) {
    char *line = malloc(sizeof(char) * MAX_BUFFER_SIZE), *total = line;
    int len = 0;

    while (fgets(line, MAX_BUFFER_SIZE, stdin) != NULL) {
        len = strlen(line);
        line += len;
    }

    STACK_ELEM result = {
        .t = STRING,
        .data.s = strdup(total)
    };

    // line[strlen(line) - 1] = '\0';

    assert(push(s, result) == 0);

    UNUSED(g);
}

void lowercase_w_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;

    assert(pop(s, &x) == 0);

    if (x.t == BLOCK) {
        while_operation(s, x, g);
    }
}

void lowercase_p_operator(STACK *s, GLOBALS *g) {
    STACK_ELEM x;

    assert(peek(s, &x) == 0);

    if (x.t == LONG) {
        printf("%ld\n", x.data.l);
    }
    else if (x.t == CHAR) {
        printf("%c\n", x.data.c);
    }
    else if (x.t == DOUBLE) {
        printf("%lg\n", x.data.d);
    }
    else if (x.t == STRING) {
        printf("%s\n", x.data.s);
    }
    else if (x.t == ARRAY) {
        print_stack(x.data.a);
    }
    else if (x.t == BLOCK) {
        printf("{ %s }\n", x.data.b);
    }

    UNUSED(g);
}

double get_double_arg(STACK_ELEM x) {
    if (x.t == DOUBLE) {
        return x.data.d;
    } 
    else if (x.t == LONG) {
        return x.data.l;
    } 
    else {
        return x.data.c;
    }
}

long get_long_arg(STACK_ELEM x) {
    if (x.t == LONG) {
        return x.data.l;
    } 
    else {
        return x.data.c;
    }
}

char *get_operator(int i) {
    static char *operators[N_OPERATORS] = {
        "+",
        "-",
        "*",
        "/",
        "%",
        "#",
        "^",
        "&",
        "|",
        ")",
        "(",
        "~",
        "i",
        "f",
        "c",
        "s",
        "_",
        ";",
        "\\",
        "@",
        "$",
        "l",
        "=",
        "<",
        ">",
        "!",
        "e&",
        "e|",
        "e<",
        "e>",
        "?",
        ",",
        "S/",
        "N/",
        "t",
        "w",
        "p"
    };

    return operators[i];
}

int is_operator(char *token) {
    for (int i = 0; i < N_OPERATORS; i++) {
        if (strcmp(token, get_operator(i)) == 0) {
            return 1;
        }
    }

    return 0;
}

int get_index(char *operator) {
    for (int i = 0; i < N_OPERATORS; i++) {
        if (strcmp(operator, get_operator(i)) == 0) {
            return i;
        }
    }

    // Caso o operador não tenha sido encontrado: retorna -1 (ERRO)
    return -1;
}

void dispatch_table(STACK *s, char *operator, GLOBALS *g) {
    static function_pointer table[] = {
        plus_operator,
        minus_operator,
        asterisk_operator,
        slash_operator,
        percentage_operator,
        hashtag_operator,
        circumflex_operator,
        and_operator,
        or_operator,
        left_parenthesis_operator,
        right_parenthesis_operator,
        tilde_operator,
        lowercase_i_operator,
        lowercase_f_operator,
        lowercase_c_operator,
        lowercase_s_operator,
        underscore_operator,
        semicolon_operator,
        inverted_slash_operator,
        arroba_operator,
        dollar_operator,
        lowercase_l_operator,
        equal_sign_operator,
        less_sign_operator,
        more_sign_operator,
        exclamation_mark_operator,
        and_with_and_operator,
        and_with_or_operator,
        and_with_less_operator,
        and_with_more_operator,
        question_mark_operator,
        comma_operator,
        uppercase_s_and_slash_operator,
        uppercase_n_and_slash_operator,
        lowercase_t_operator,
        lowercase_w_operator,
        lowercase_p_operator
    }; // As funções até agora implementadas são colocadas em posições análogas às referenciadas na função 'get_operator'.

    int index = get_index(operator);
    assert(index != -1);

    // Chama o function pointer
    table[index](s, g);
}
