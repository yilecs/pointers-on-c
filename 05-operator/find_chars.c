#include <stdlib.h>

char *find_chars(char const *source, char const *chars) {
    char *subchars = NULL;
    char *subsource = NULL;

    while(*source != '\0') {
        if (*source != *chars) {
            source++;
            continue;
        }

        subchars = chars + 1;
        subsource = source + 1;

        while(*subsource != '\0' && *subchars != '\0' && *subsource == *subchars) {
            subsource++;
            subchars++;
        }

        if (*subchars == '\0') {
            return source;
        }

        source++;
    }

    return NULL;
}
