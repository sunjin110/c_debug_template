#include <stdio.h>
#include "../../src/application/hist.h"

// https://qiita.com/janus_wel/items/a673793d448c72cbc95e
// cmakeはそのディレクトリごとにないとダメそうだ
int main(int argc, char *argv[]) {
    printf("==== hello histogram command...!\n");

    if (argc != 2) {
        printf("Error: Wrong number of arguments\n");
        printf("Usage is :\n");
        printf("\thistogram <file-name>\n");
        return 8;
    }

    char *file_name = argv[1];

    printf("filename is %s\n", file_name);
    hist_application_run(file_name);
    return 0;
}
