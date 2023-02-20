#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#ifndef _STRING_H_
#include <string.h>
#endif

struct linked_list {
    struct linked_list *next_ptr;
    char *data;
};

void linked_list_playground(void);
void add_list(struct linked_list *list, char *data);
struct linked_list* new(char *data, size_t data_size);
struct linked_list* append(struct linked_list *list, char *data, size_t data_size);
void linked_list_free(struct linked_list *list);
void for_each(struct linked_list *list);

int find_in_linked_list(struct linked_list *first_ptr, char *data);