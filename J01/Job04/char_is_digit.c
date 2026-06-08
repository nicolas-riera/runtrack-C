#include <stdio.h>

int char_is_digit(char c) {

    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int main() {

    printf("Test avec '5' (devrait afficher 1) : %d\n", char_is_digit('5'));
    printf("Test avec 'c' (devrait afficher 0) : %d\n", char_is_digit('c'));
    printf("Test avec '9' (devrait afficher 1) : %d\n", char_is_digit('9'));
    printf("Test avec 'a' (devrait afficher 0) : %d\n", char_is_digit('a'));

    return 0;
}