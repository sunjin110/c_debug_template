#include "linked_list.h"

void linked_list_playground() {
    struct linked_list *list = new("sunjin", sizeof("sunjin"));
    list = append(list, "yun_sunjin", sizeof("yun_sunjin"));
    list = append(list, "hoge", sizeof("hoge"));

    int result = find_in_linked_list(list, "sunjin");
    printf("result is %d\n", result);



    linked_list_free(list);

}

void add_list(struct linked_list *list, char *data) {
    struct linked_list *new_item_ptr;

    new_item_ptr = malloc(sizeof(struct linked_list));
    strcpy(new_item_ptr->data, data);
    new_item_ptr->next_ptr = list;
    list = new_item_ptr;
}

struct linked_list* new(char *data, size_t data_size) {
     struct linked_list *new_item_ptr = malloc(sizeof(struct linked_list));
     new_item_ptr->data = malloc(data_size);
     strcpy(new_item_ptr->data, data);
     new_item_ptr->next_ptr = NULL; // ここが終端になる
     return new_item_ptr;
}

struct linked_list* append(struct linked_list *list, char *data, size_t data_size) {
    struct linked_list *new_item_ptr = malloc(sizeof(struct linked_list));

    new_item_ptr->data = malloc(data_size);
    strcpy(new_item_ptr->data, data);
    new_item_ptr->next_ptr = list;
    return new_item_ptr;
}

// 1:found, 0:not found
int find_in_linked_list(struct linked_list *first_ptr, char *data) {
    struct linked_list *current_ptr = first_ptr;

    // TODO linked_listがloopしている場合は無限ループしてしまうため、それをもしかすると考慮する必要があるかも
    for (;;) {
        if (current_ptr == NULL) {
            return 0;
        }
        printf("======== data is %s\n", current_ptr->data);
        printf("======== match data is %s\n", data);
        if (strcmp(current_ptr->data, data) == 0) {
            return 1;
        }

        current_ptr = current_ptr->next_ptr;
    }
}

void linked_list_free(struct linked_list *list) {

    struct linked_list *current_list = list;

    for (;;) {
        if (current_list == NULL) {
            free(current_list);
            return;
        }
        printf("freeしようとしています。%s\n", current_list->data);
        struct linked_list *temp = current_list->next_ptr;
        free(current_list->data);
        current_list->data = NULL;
        free(current_list);
        current_list = temp;
    }
}