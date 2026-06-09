#include <stdlib.h>

void array_delete(int *arr) {
    free(arr);
}

int main() {
    int taille = 5;
    int *tableau = malloc(taille * sizeof(int));

    if (tableau == NULL) {
        return 1;
    }

    *(tableau + 0) = 10;
    *(tableau + 1) = 20;
    *(tableau + 2) = 30;
    *(tableau + 3) = 40;
    *(tableau + 4) = 50;

    array_delete(tableau);

    tableau = NULL;

    return 0;
}