#include <stdlib.h>

char *my_strdup(char *str) {
    int len = 0;
    char *dup;

    if (str == NULL) {
        return NULL;
    }

    while (*(str + len) != '\0') {
        len++;
    }

    dup = malloc((len + 1) * sizeof(char));
    if (dup == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        *(dup + i) = *(str + i);
    }
    *(dup + len) = '\0';

    return dup;
}

int main() {
    char *original = "Salut";
    char *copie;

    copie = my_strdup(original);
    if (copie == NULL) {
        return 1;
    }

    free(copie);

    return 0;
}