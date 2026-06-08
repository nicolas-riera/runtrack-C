#include <stdio.h>

int char_is_digit(char c) {

    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int str_is_digit(char *str) {

    if (str[0] == '\0') {
            return 0;
        }

    int i = 0;

    while (str[i] != '\0') {
        if (char_is_digit(str[i]) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {

    printf("Test avec '5' (devrait afficher 1) : %d\n", char_is_digit('5'));
    printf("Test avec 'c' (devrait afficher 0) : %d\n", char_is_digit('c'));
    printf("Test avec '9' (devrait afficher 1) : %d\n", char_is_digit('9'));
    printf("Test avec 'a' (devrait afficher 0) : %d\n", char_is_digit('a'));

    printf("Test \"12345\" (uniquement des chiffres) : %d\n", str_is_digit("12345"));
    printf("Test \"123a45\" (contient une lettre)    : %d\n", str_is_digit("123a45"));
    printf("Test \"42 42\"   (contient un espace)     : %d\n", str_is_digit("42 42"));
    printf("Test \"\"        (chaîne vide)            : %d\n", str_is_digit(""));
    printf("Test \"Bonjour\" (uniquement des lettres) : %d\n", str_is_digit("Bonjour"));

    return 0;
}