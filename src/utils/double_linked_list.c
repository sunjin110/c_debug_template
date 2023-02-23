#include "double_linked_list.h"

void double_linked_list_playground() {
    printf("====== double_linked_list_playground\n");

    // new
    double_linked_list *first_ptr = malloc(sizeof(double_linked_list));
    first_ptr->data = 100;
    first_ptr->next_ptr = NULL;
    first_ptr->previous_ptr = NULL;

    double_enter(first_ptr, 200);
    double_enter(first_ptr, 120);
    double_enter(first_ptr, -100);
    double_enter(first_ptr, 0);
    double_enter(first_ptr, 100);
    double_enter(first_ptr, 0);


    for_each_double_linked_list(first_ptr);
}

void double_enter(double_linked_list *head_ptr, int data) {

    if (head_ptr == NULL) {
        printf("Error: head_ptr is NULL\n");
        return;
    }

    double_linked_list *insert_ptr = malloc(sizeof(double_linked_list));
    insert_ptr->data = data;
    insert_ptr->next_ptr = NULL;
    insert_ptr->previous_ptr = NULL;

    double_linked_list *current_ptr = head_ptr;
    for (;;) {
        if (current_ptr->data < data) {
            if (current_ptr->next_ptr == NULL) {
                current_ptr->next_ptr = insert_ptr;
                insert_ptr->previous_ptr = current_ptr;
                return;
            }

            if (current_ptr->next_ptr->data >= data) {
                // insert between current and next
                double_linked_list *next_tmp_ptr = current_ptr->next_ptr;
                current_ptr->next_ptr = insert_ptr;
                insert_ptr->previous_ptr = current_ptr;
                insert_ptr->next_ptr = next_tmp_ptr;
                return;
            }

            // data number is large than next_ptr->data
            current_ptr = current_ptr->next_ptr;
            continue;
        }

        if (current_ptr->previous_ptr == NULL) {
            current_ptr->previous_ptr = insert_ptr;
            insert_ptr->next_ptr = current_ptr;
            return;
        }

        if (current_ptr->previous_ptr->data <= data) {
            // insert between current adn previous
            printf("==== insert between current adn previous, data is %d\n", data);

            double_linked_list *previous_tmp_ptr = current_ptr->previous_ptr;
            current_ptr->previous_ptr = insert_ptr;
            insert_ptr->next_ptr = current_ptr;
            insert_ptr->previous_ptr = previous_tmp_ptr;
            return;
        }

        // data number is smaller than previous->data
        current_ptr = current_ptr->previous_ptr;
        continue;
    }
}

void for_each_double_linked_list(double_linked_list *head_ptr) {
    if (head_ptr == NULL) {
        printf("head_ptr is NULL\n");
        return;
    }

    double_linked_list *current_ptr = head_ptr;
    printf("======= next ptr...\n");
    for (;;) {
        if (current_ptr == NULL) {
            printf("=== next for each done\n");
            break;
        }

        printf("=== data:%d pointer:%p\n", current_ptr->data, current_ptr);
        current_ptr = current_ptr->next_ptr;
    }

    printf("======= previous ptr...\n");
    current_ptr = head_ptr;
    for (;;) {
        if (current_ptr == NULL) {
            printf("=== previous for each done\n");
            return;
        }

        printf("=== data:%d pointer:%p\n", current_ptr->data, current_ptr);
        current_ptr = current_ptr->previous_ptr;
    }
}
