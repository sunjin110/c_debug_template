
static const int BLOCK_SIZE = 10;

typedef struct _infinite_array {
    float data[BLOCK_SIZE];
    struct _infinite_array *next_ptr;
} infinite_array;

extern void init_infinite_array(infinite_array *ptr);
extern int get_from_infinite_array(infinite_array *ptr, int index);
extern void store_to_infinite_array(infinite_array *ptr, int index, int store_data);

