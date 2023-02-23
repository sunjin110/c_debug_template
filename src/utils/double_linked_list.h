#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#ifndef _STRING_H_
#include <string.h>
#endif

typedef struct _double_linked_list {
    int data;
    struct _double_linked_list *next_ptr;
    struct _double_linked_list *previous_ptr;
} double_linked_list;

void double_enter(double_linked_list *head_ptr, int data);
void double_linked_list_playground(void);
void for_each_double_linked_list(double_linked_list *head_ptr);
