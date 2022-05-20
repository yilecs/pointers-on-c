#include <stdio.h>
#include <stdbool.h>

int find_char(char **strings, char value) {
    char *string;

    while((string = *strings++) != NULL) {
        while(*string != '\0') {
            if (*string++ == value) {
                return true;
            }
        }
    }

    return false;
}
