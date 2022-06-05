#include "../stack.h"
#include "../operators/operations.h"
#include "strings.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void concatenate_two_strings(STACK_ELEM y, STACK_ELEM x, STACK_ELEM *result) {
    if (y.t == STRING) {
        concatenate_two_strings_aux(y, x, result, 1);
    }
    else {
        concatenate_two_strings_aux(x, y, result, 0);
    }
}

void concatenate_two_strings_aux(STACK_ELEM y, STACK_ELEM x, STACK_ELEM *result, int order) {
    if (x.t == STRING) {
        char *new = malloc(strlen(y.data.s) + strlen(x.data.s) + 1);
        
        if (order) {
            strcpy(new, y.data.s);
            strcat(new, x.data.s);
        }
        else {
            strcpy(new, x.data.s);
            strcat(new, y.data.s);
        }
        
        result->t = STRING;
        result->data.s = new;
        
        free(y.data.s);
    }
    else if (x.t == CHAR) {
        int len = strlen(y.data.s);
        char *new = malloc(len + 2);
        
        if (order) {
            strcpy(new, y.data.s);
            new[len] = x.data.c;
        }
        else {
            new[0] = x.data.c;
            new[1] = '\0';
            
            strcat(new, y.data.s);
        }
       
        new[len + 1] = '\0';
        result->t = STRING;
        result->data.s = new;
        
        free(y.data.s);
    }
    else {
        char *temp = malloc(sizeof(char) * MAX_BUFFER_SIZE);
        char *new = malloc(sizeof(char) * MAX_BUFFER_SIZE + strlen(y.data.s) + 1);
        
        snprintf(temp, MAX_BUFFER_SIZE, "%g", get_double_arg(x));
        
        if (order) {
            strcpy(new, y.data.s);
            strcat(new, temp);
        }
        else {
            strcpy(new, temp);
            strcat(new, y.data.s);
        }

        result->t = STRING;
        result->data.s = new;
        
        free(y.data.s);
        free(temp);
    }
}

void replicate_string(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    int len = strlen(y.data.s) + 1;

    char *new = malloc(len * x.data.l * sizeof(char));
    strcpy(new, y.data.s);

    for (int i = 0; i < x.data.l - 1; i++) {
        strcat(new, y.data.s);
    }

    result->t = STRING;
    result->data.s = new;

    free(y.data.s);
}

void split_string_by_substring(STACK_ELEM *main, STACK_ELEM *sub, STACK *new) {
    char *init = main->data.s, *current;
    
    STACK_ELEM temp;
    temp.t = STRING;
    
    int sub_len = strlen(sub->data.s);
    int main_len = strlen(main->data.s);
    
    if (sub->data.s[0] =='\0'){
        temp.t = CHAR;
        for (int i = 0 ;i < main_len; i++) {
            temp.data.c = main->data.s[i];
            
            assert(push(new, temp) == 0);
        }

        return;
    }
    
    while ((current = strstr(init, sub->data.s)) != NULL) {
        char *section = malloc(sizeof(char) * (current - init + 1));
        
        strncpy(section, init, current - init);
        section[current - init] = '\0';
        
        temp.data.s = section;
        
        assert(push(new, temp) == 0);
        
        init = current + sub_len;
    }

    if (strlen(init) >= 2 || (strlen(init) == 1 && init[0] != '\n')) {
        char *section = malloc(sizeof(char) * (strlen(init) + 1));
        strcpy(section, init);
        
        temp.data.s = section;
        
        assert(push(new,temp) == 0);
    }
}

void find_substring_index(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    result->t = LONG;
    char *temp;
    
    if (strlen(x.data.s) > strlen(y.data.s)) {
        if ((temp = (strstr(x.data.s, y.data.s))) == NULL) {
            result->data.l = -1;
        }
        else {
            result->data.l = temp - x.data.s;
        }
    }
    else {
        if ((temp = (strstr(y.data.s, x.data.s))) == NULL) {
            result->data.l = -1;
        }
        else {
            result->data.l = temp - y.data.s;
        }
    }
}

void remove_first_element_from_string(STACK *s, STACK_ELEM x, STACK_ELEM *result) {
    int len = strlen(x.data.s);

    STACK_ELEM to_push = {
        .t = CHAR,
        .data.c = x.data.s[len - 1]
    };

    x.data.s[len - 1] = '\0';

    char *token = x.data.s;

    result->data.s = strdup(token);

    push(s, *result);
    push(s, to_push);

    free(token);
}

void remove_last_element_from_string(STACK *s, STACK_ELEM x, STACK_ELEM *result) {
    STACK_ELEM to_push = {
        .t = CHAR,
        .data.c = x.data.s[0]
    };

    char *token = x.data.s + 1;
    
    result->data.s = strdup(token);

    push(s, *result);
    push(s, to_push);

    free(x.data.s);
}

void get_char_at_index(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    long pos = get_long_arg(x);

    result->t = CHAR;        
    result->data.c = y.data.s[pos];
    
    push(s, *result);
}

void check_strings_equality(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    result->t = LONG;
    result->data.l = strcmp(x.data.s, y.data.s) == 0 ? 1 : 0;
    
    push(s, *result);
}

void check_strings_less(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    result->t = LONG;
    result->data.l = strcmp(x.data.s, y.data.s) < 0 ? 1 : 0;
    
    push(s, *result);
}

void take_from_string(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    int len = strlen(x.data.s), extract = get_long_arg(y);
        
    if (extract > len) {
        extract = len; // Se for pedido para extrair mais caracteres do que aqueles que existem na string, será apenas extraída a string toda
    }
    
    char *new = malloc(sizeof(char) * (extract + 1));
    
    strncpy(new, x.data.s, extract);
    new[extract] = '\0';
    
    result->t = STRING;
    result->data.s = new;
    
    assert(push(s, *result) == 0);
    
    free(x.data.s);
}

void check_strings_more(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    result->t = LONG;
    result->data.l = strcmp(x.data.s, y.data.s) > 0 ? 1 : 0;
    
    push(s, *result);
}

void drop_from_string(STACK *s, STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result) {
    int len = strlen(x.data.s), extract = get_long_arg(y);
        
    if (extract > len) {
        extract = len; // Se for pedido para extrair mais caracteres do que aqueles que existem na string, será apenas extraída a string toda
    }
    
    char *new = malloc(sizeof(char) * (extract + 1));
    
    strncpy(new, x.data.s + len - extract, extract);
    new[extract] = '\0';
    
    result->t = STRING;
    result->data.s = new;
    
    assert(push(s, *result) == 0);
    
    free(x.data.s);       
}
