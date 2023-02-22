#include "sort_num_linked_list.h"

void sorted_num_linked_list_playground() {
    printf("=================== sorted_num_linked_list_playground\n");

    linked_list *first_ptr = malloc(sizeof(linked_list));
    first_ptr->num = 100;
    first_ptr->next_ptr = NULL;
    // linked_list *first_ptr = NULL;
    printf("==== before first ptr is %p\n", first_ptr);

    // ここでptrを上書きしないと、引数内でpointerを変更しても、pointerのpositionがafterで戻ってしまう仕様になっている
    first_ptr = enter_for_sorted_linked_list(first_ptr, 90);
    first_ptr = enter_for_sorted_linked_list(first_ptr, 123);
    first_ptr = enter_for_sorted_linked_list(first_ptr, 1);

    printf("==== after first ptr is %p\n", first_ptr);
    for_each_for_sorted_linked_list(first_ptr);
    printf("========== end...!\n");
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
        current_ptr = current_ptr->next_ptr;
    }
}

void print_linked_list_value(linked_list *ptr) {
    if (ptr == NULL) {
        printf("===== NULLでした\n");
        return;
    }
    printf("========== this_ptr is %p\n", ptr);
    printf("========== value is %d\n", ptr->num);

    if (ptr->next_ptr != NULL) {
        printf("=========== next_ptr is %p\n", ptr->next_ptr);
    }

}

linked_list* enter_for_sorted_linked_list(linked_list *first_ptr, int value) {
    if (first_ptr == NULL) {
        first_ptr = malloc(sizeof(linked_list));
        first_ptr->num = value;
        first_ptr->next_ptr = NULL;
        return first_ptr;
    }

    // firstよりも数字が低い場合は、特別処理
    if (first_ptr->num > value) {
        printf("========== 指定の数字が先頭よりも少ない場合\n");
        linked_list *tmp = first_ptr;
        linked_list *new_ptr = malloc(sizeof(linked_list));
        new_ptr->num = value;
        new_ptr->next_ptr = tmp;
        first_ptr = new_ptr;
        first_ptr->next_ptr = tmp;
        // free(tmp);
        // first_ptr->num = value;
        // printf("========= changed_first_ptr is %p\n", first_ptr);
        // print_linked_list_value(first_ptr);
        // first_ptr->next_ptr = tmp;

        return first_ptr;
    }

    // printf("=== ここまでは来ている\n");
    linked_list *before_ptr = first_ptr;
    print_linked_list_value(before_ptr);
    // printf("=== ここまでは来ている_2\n");
    linked_list *after_ptr = first_ptr->next_ptr;
    print_linked_list_value(after_ptr);
    // printf("=== ここまでは来ている_3\n");

    for (;;) {
        // printf("==== ここは入る!\n");
        if (after_ptr == NULL) {
            // printf("nullだからbreakするよね\n");
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

    return first_ptr;
}
