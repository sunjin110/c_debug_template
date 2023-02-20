#include "sort_num_linked_list.h"

typedef struct _linked_list {
    struct _linked_list *next_ptr;
    int num;
} linked_list;

void sorted_num_linked_list_playground() {
    printf("=================== sorted_num_linked_list_playground\n");
}

void for_each_for_sorted_linked_list(linked_list *list_first_ptr) {
    linked_list *current_ptr = list_first_ptr;
    int i = 0;
    for (;;) {
        if (current_ptr == NULL) {
            return;
        }
        printf("index:%d, value:%d\n", i, current_ptr->num);
        i++;
    }
}

void enter(linked_list *first_ptr, int value) {
    if (first_ptr == NULL) {
        first_ptr = malloc(sizeof(linked_list));
        return;
    }

    linked_list *before_ptr = first_ptr;
    linked_list *after_ptr = first_ptr->next_ptr;

    for (;;) {
        if (after_ptr == NULL) {
            break;
        }

        if (after_ptr->num >= value) {
            break;
        }

        before_ptr = before_ptr->next_ptr;
        after_ptr = after_ptr->next_ptr;
    }

    linked_list *new_ptr = malloc(sizeof(linked_list));
    new_ptr->num = value;
    before_ptr->next_ptr = new_ptr;
    new_ptr->next_ptr = after_ptr;
}
