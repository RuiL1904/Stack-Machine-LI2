#include "stack.h"
#include "operations.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <regex.h>

// Verifica se a string contém apenas algarismos
int is_long(char *token) {
    static bool flag = false;
    static regex_t regex;

    if (!flag) {
        assert(regcomp(&regex, "^-?[0-9]+$", REG_EXTENDED) == 0);
        flag = true;
    }

    return regexec(&regex, token, 0, NULL, 0) == 0;
}

// Verifica se a string contém apenas algarismos e um ponto (.)
int is_double(char *token) {
    static bool flag = false;
    static regex_t regex;

    if (!flag) {
        assert(regcomp(&regex, "^-?[0-9]+\\.[0-9]+$", REG_EXTENDED) == 0);
        flag = true;
    }

    return regexec(&regex, token, 0, NULL, 0) == 0;
}

int is_string(char *token) {
    static bool flag = false;
    static regex_t regex;

    if (!flag) {
        assert(regcomp(&regex, "^\".+\"$", REG_EXTENDED) == 0);
    }

    return regexec(&regex, token, 0, NULL, 0) == 0;
}

int is_global(char *token) {
    static bool flag = false;
    static regex_t regex;

    if (!flag) {
        assert(regcomp(&regex, "^[A-Z]$", REG_EXTENDED) == 0);
    }
    
    return regexec(&regex, token, 0, NULL, 0) == 0;
}

// Remove o caracter na posição indicada por 'p'
void remove_char(char *s, size_t p) {
    for (size_t i = p; s[i] != '\0'; i++) {
        s[i] = s[i + 1];
    }
}

void handle_token(STACK *s, char *token) {
    if (is_long(token)) {
        long value;
        sscanf(token, "%ld", &value);

        STACK_ELEM new = {
            .t = LONG, 
            .data = { .l = value }
        };
        assert(push(s, new) == 0);
    } 
    else if (is_double(token)) {
        double value;
        sscanf(token, "%lg", &value);

        STACK_ELEM new = {
            .t = DOUBLE, 
            .data = { .d = value }
        };
        assert(push(s, new) == 0);
    }
    // Se não for 'long' nem 'int' é uma 'string' (char *)
    else if (is_string(token)) {
        size_t len = strlen(token);
        char *heap_token = malloc(sizeof(char) * (len + 1));
        
        strncpy(heap_token, token, len + 1);

        // Remove as aspas da string
        remove_char(heap_token, 0);
        remove_char(heap_token, len - 2);

        STACK_ELEM new = {
            .t = STRING, 
            .data = { .s = heap_token }
        };
        assert(push(s, new) == 0);
    }
    else if (is_global(token)) {
        char value;
        sscanf(token, "%c", &value);
        
        STACK_ELEM new = get_global(s, value);
        assert(push(s, new) == 0);
    }
    else if (is_operator(token)) {
        dispatch_table(s, token);
    }
}

int parse_line(STACK *s) {
    char line[BUFSIZ];
    char token[BUFSIZ];

    if (fgets(line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            handle_token(s, token);
        }
        handle_token(s, token);
    }

    return 0;
}
