#include <stdio.h>

void show_bytes(unsigned char * pointer, size_t len);

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
    unsigned mask = ((~0) << (starting_bit + 1)) | (~ ((~0) << ending_bit));
    original_value = original_value & mask;
    value_to_store = value_to_store << ending_bit;
    value_to_store = value_to_store & (~mask);

    original_value = original_value | value_to_store;

    return original_value;
}

void show_bytes(unsigned char * pointer, size_t len) {
    size_t i;

    for (i = 0; i < len; i++) {
        printf("%p\t0x%.2x\n", pointer+i, pointer[i]);
    }

    printf("\n");
}

int main(void) {
    int original_value = 0xffff;
    unsigned starting_bit = 13;
    unsigned ending_bit = 9;
    int value_to_store = 0x123;

    original_value = store_bit_field(original_value, value_to_store, starting_bit, ending_bit);

    printf("0x%x\n", original_value);

    show_bytes((unsigned char *)&original_value, sizeof(int));

    return 0;
}
