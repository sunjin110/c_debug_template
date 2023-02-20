#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#ifndef _STRING_H_
#include <string.h>
#endif

typedef struct _linked_list {
    struct _linked_list *next_ptr;
    int num;
} linked_list;

void sorted_num_linked_list_playground(void);
void for_each_for_sorted_linked_list(linked_list *list_first_ptr);
linked_list* enter_for_sorted_linked_list(linked_list *first_ptr, int value);