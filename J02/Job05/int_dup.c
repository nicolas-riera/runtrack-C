#include <stdlib.h>

int *int_dup(int value) {
    int *ptr;

    ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        return NULL;
    }
    *ptr = value;
    return ptr;
}

int main() {
    int *p;

    p = int_dup(42);
    if (p == NULL) {
        return 1;
    }

    free(p);

    return 0;
}