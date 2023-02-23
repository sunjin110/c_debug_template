#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#ifndef _STRING_H_
#include <string.h>
#endif

typedef struct _node {
    char *data;
    struct _node *left;
    struct _node *right;
} node;

void node_playground(void);

void enter_word(node **node, char *new_word);
void print_tree(node *node, int depth);