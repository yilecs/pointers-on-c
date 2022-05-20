#include <stdlib.h>

size_t strlen(const char *string) {
    size_t length = 0;

    while (*string++ != '\0') {
        length++;
    }

    return length;
}
