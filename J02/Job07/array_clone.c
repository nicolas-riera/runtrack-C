#include <stdlib.h>

int *array_clone(int *arr, int n) {
    int *clone;

    if (arr == NULL || n <= 0) {
        return NULL;
    }

    clone = malloc(n * sizeof(int));
    if (clone == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        *(clone + i) = *(arr + i);
    }

    return clone;
}

int main() {

    int tableau[] = {5, 10, 15, 20, 25};
    int taille = 5;
    int *resultat;

    resultat = array_clone(tableau, taille);

    return 0;
}