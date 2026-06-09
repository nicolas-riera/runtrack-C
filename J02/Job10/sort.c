#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *sort(int *array) {
    int len = 0;
    int swapped;

    if (array == NULL) {
        return NULL;
    }

    while (*(array + len) != 0) {
        len++;
    }

    if (len < 2) {
        return array;
    }

    do {
        swapped = 0;
        for (int i = 0; i < len - 1; i++) {
            if (*(array + i) > *(array + i + 1)) {
                swap((array + i), (array + i + 1));
                swapped = 1;
            }
        }
    } while (swapped);

    return array;
}

int main() {
    int tableau[] = {42, 15, 23, 8, 4, 0}; 
    int *resultat;

    resultat = sort(tableau);

    int i = 0;
    while (*(resultat + i) != 0) {
        i++;
    }
    return 0;
}