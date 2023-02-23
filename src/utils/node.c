#include "node.h"

void node_playground() {
    printf("=== node_playground\n");

    node *root = NULL;
    enter_word(&root, "hello world");
    enter_word(&root, "sunjin");
    enter_word(&root, "aaaa");
    enter_word(&root, "hogehoge");
    enter_word(&root, "uuu");
    enter_word(&root, "z");

    print_tree(root, 0);
}

char *save_string(char *str) {
    char *saved_str = malloc((unsigned) (strlen(str) + 1));
    if (saved_str == NULL) {
        printf("Error: failed allocate memory...\n");
        exit(8);
    }
    strcpy(saved_str, str);
    return saved_str;
}

// 再帰処理に利用するため、nodeのpointerが書き変わる可能性がある
void enter_word(node **n, char *new_word) {

    if (*n == NULL) {
        *n = malloc(sizeof(node));
        if (*n == NULL) {
            printf("Error: failed allocate memory...\n");
            exit(8);
        }
        (*n)->data = save_string(new_word);
        (*n)->left = NULL;
        (*n)->right = NULL;
        return;
    }

    int cmp_result = strcmp((*n)->data, new_word);

    if (cmp_result == 0) {
        // already exists word
        return;
    } 

    if (cmp_result < 0) {
        enter_word(&(*n)->right, new_word);
    } else {
        enter_word(&(*n)->left, new_word);
    }
}

void print_tree(node *node, int depth) {
    if (node == NULL) {
        return;
    }
    print_tree(node->left, depth+1);
    for (int i = 0; i < depth; i++) {
        printf("->");
    }
    printf("%s\n", node->data);
    print_tree(node->right, depth+1);
}
