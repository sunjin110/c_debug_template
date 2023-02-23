

int counter = 0;

// global levelでのstaticはprivateという意味があるみたい

int flag;

void inc_counter(void) {
    // counter * 2;
    counter++;
    // counter = counter * 2;
}
