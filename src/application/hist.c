#include "../utils/infinite_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static const int NUMBER_OF_LINE = 30;
static const int DATA_MIN = 1;
static const int DATA_MAX = 30;
static const int WIDTH = 60;
static const int LINE_CHAR_NUM = 256;

// TODO なぜconstを付けるかを調べる
static void read_and_store(infinite_array *ia_ptr, int *latest_index, const char file_name[]);
static void print_histogram(infinite_array *ia_ptr, int latest_index);

extern void hello() {
    printf("hello\n");
}


extern void hist_application_run(const char file_name[]) {
    printf("==== hist_application_run\n");

    infinite_array *hist_list = malloc(sizeof(infinite_array));
    hist_list->next_ptr = NULL;
    // init_infinite_array(hist_list);

    int latest_index = 0;
    read_and_store(hist_list, &latest_index, file_name);
    print_histogram(hist_list, latest_index);
}

static void read_and_store(infinite_array *ia_ptr, int *latest_index, const char file_name[]) {

    FILE *in_file = fopen(file_name, "r");
    if (in_file == NULL) {
        printf("Error: Unable to open %s\n", file_name);
        exit(8);
    }

    // char line[LINE_CHAR_NUM];
    for (;;) {
        char line[LINE_CHAR_NUM];
        if (fgets(line, sizeof(line), in_file) == NULL) {
            break;
        }

        int num = 0;
        if (sscanf(line, "%d", &num) != 1) {
            printf("Warning: Skip line because Input data is not integer number\n");
            printf("Line: %s\n", line);
            continue;
        }

        store_to_infinite_array(ia_ptr, *latest_index, num);

        // move latest index
        *latest_index = *latest_index + 1;
    }
}

void print_histogram(infinite_array *ia_ptr, int latest_index) {

    int counters[NUMBER_OF_LINE];

    int out_of_range = 0;
    int max_count = 0;
    // float scale = 0.0;

    memset(counters, '\0', sizeof(counters));

    for (int index = 0; index < latest_index; index++) {
        int current_data = get_from_infinite_array(ia_ptr, index);

        if ((current_data < DATA_MIN) || (current_data > DATA_MAX)) {
            out_of_range++;
            continue;
        }

        int position = current_data - DATA_MIN;
        counters[position]++;
        if (counters[position] > max_count) {
            max_count = counters[position];
        }
    }

    float dots_scale = ((float) max_count) / ((float) WIDTH);
    // printf("dots_scale is %f\n", dots_scale);
    // float dots_scale = 1.0;

    for (int index = 0; index < NUMBER_OF_LINE; index++) {
        printf("%2d (%4d): ", index + DATA_MIN, counters[index]);
        int number_of_dots = (int)(((float) counters[index]) / dots_scale);        
        for (int i = 0; i < number_of_dots; i++) {
            printf("*");
        }
        printf("\n");
    }

    printf("%d items out of range \n", out_of_range);
}

// void print_histogram(infinite_array *ia_ptr, int latest_index) {

//     for (int index = 0; index < latest_index; index++) {
//         int current_data = get_from_infinite_array(ia_ptr, index);
//         printf("current_data is %d\n", current_data);
//     }



// }
