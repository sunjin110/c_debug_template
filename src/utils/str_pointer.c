#include "str_pointer.h"

void str_pointer_playground(void) {
    printf("Hello World Str Pointer\n");
    malloc_playground();
}

void malloc_playground() {
    char *string_ptr = malloc(80);
    // string_ptr = "sunjin";
    // printf("string_ptr is %s\n", string_ptr);

    sprintf(string_ptr, "sunjin");
    printf("string_ptr is %s\n", string_ptr);

    free(string_ptr);
    return;
}
