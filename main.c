#include <stdio.h>

void scan_data(int data[5]);

int main() {
    int data[5];
    scan_data(data);

    int three_count = 0;
    int seven_count = 0;

    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {

        int value = data[i];
        if (value == 3) {
            three_count++;
            continue;
        }
        if (value == 7) {
            seven_count++;
            continue;
        }
    }

    printf("3 count is %d, 7 count is %d\n", three_count, seven_count);
    return 0;
}

void scan_data(int data[5]) {
    printf("Enter 5 numbers >");
    char line[100];
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d %d %d %d", &data[0], &data[1], &data[2], &data[3], &data[4]);
}
