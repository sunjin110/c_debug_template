#include <stdio.h>
#include <time.h>
#include <memory.h>
#include "src/utils/str_pointer.h"
#include "src/utils/linked_list.h"
#include "src/utils/sort_num_linked_list.h"
#include "src/utils/double_linked_list.h"
#include "src/utils/node.h"

const int X_SIZE = 60;
const int Y_SIZE = 32;

void init_matrix_v1(void);
void init_matrix_v2(void);
void init_matrix_v3(void);
void init_matrix_v4(void);
void init_matrix_v5(void);

int main() {

    // str_pointer_playground();

    // linked_list_playground();

    // sorted_num_linked_list_playground();

    // double_linked_list_playground();

    node_playground();

    // printf("======= v4\n");
    // init_matrix_v4();
    // printf("======= v2\n");
    // init_matrix_v2();
    // printf("======= v5\n");
    // init_matrix_v5();
    // printf("======= v1\n");
    // init_matrix_v1();
    // printf("======= v3 \n");
    // init_matrix_v3();
    return 0;
} 

void init_matrix_v1() {
    // random matrix
    int matrix[X_SIZE][Y_SIZE];
    clock_t start = clock();
    for (int x = 0; x < X_SIZE; x++) {
        for (int y = 0; y < Y_SIZE; y++) {
            matrix[x][y] = -1;
        }
    }
    clock_t end = clock();
    printf("%.2fms\n", (double)(end - start));
}

void init_matrix_v2() {

    int matrix[X_SIZE][Y_SIZE];
    clock_t start = clock();
    for (register int x = 0; x < X_SIZE; x++) {
        for (register int y = 0; y < Y_SIZE; y++) {
            matrix[x][y] = -1;
        }
    }
    clock_t end = clock();
    printf("%.2fms\n", (double)(end - start));
}

void init_matrix_v3() {
    int matrix[X_SIZE][Y_SIZE];
    clock_t start = clock();
    for (register int y = 0; y < Y_SIZE; y++) {
        for (register int x = 0; x < X_SIZE; x++) {
            matrix[x][y] = -1;
        }
    }
    clock_t end = clock();
    printf("%.2fms\n", (double)(end - start));
}

void init_matrix_v4() {
    int matrix[X_SIZE][Y_SIZE];

    clock_t start = clock();
    register int index;
    register int *matrix_ptr = &matrix[0][0];
    for (index = 0; index < X_SIZE * Y_SIZE; index++) {
        *matrix_ptr = -1;
        matrix_ptr++;
    }
    clock_t end = clock();
    printf("%.2fms\n", (double)(end - start));
}

void init_matrix_v5() {
    int matrix[X_SIZE][Y_SIZE];
    clock_t start = clock();
    memset(matrix, -1, sizeof(matrix));
    clock_t end = clock();
    printf("%.2fms\n", (double)(end - start));
}