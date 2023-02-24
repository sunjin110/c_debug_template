#include "infinite_array.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

void init_infinite_array(infinite_array *ptr) {
    ptr->next_ptr = NULL;
}

// get array locate pointer
static infinite_array* locate(infinite_array *ptr, int index, int *current_index_ptr) {
    infinite_array *current_ptr = ptr;
    *current_index_ptr = index;

    while (*current_index_ptr >= BLOCK_SIZE) {
        if (current_ptr->next_ptr == NULL) {
            // 次のlinked arrayが必要な場合に作成するみたい
            current_ptr->next_ptr = malloc(sizeof(infinite_array));
            if (current_ptr->next_ptr == NULL) {
                printf("Error: memory allocate error...\n");
                exit(8);
            }

            // ??? why
            memset(current_ptr->next_ptr, '\0', sizeof(infinite_array));
        }
        current_ptr = current_ptr->next_ptr;
        *current_index_ptr -= BLOCK_SIZE;
    }
    return current_ptr;
}

void store_to_infinite_array(infinite_array *ptr, int index, int store_data) {
    int current_index = 0;
    infinite_array *current_ptr = locate(ptr, index, &current_index);
    current_ptr->data[current_index] = store_data;
}

int get_from_infinite_array(infinite_array *ptr, int index) {
    int current_index = 0;
    infinite_array *current_ptr = locate(ptr, index, &current_index);
    return current_ptr->data[current_index];
}


