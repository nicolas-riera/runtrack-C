#include <stdio.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int main(void)
{
    printf("Comparaison \"abc\" et \"abd\" (attendu négatif) : %d\n", my_strcmp("abc", "abd"));
    printf("Comparaison \"abd\" et \"abc\" (attendu positif)  : %d\n", my_strcmp("abd", "abc"));
    printf("Comparaison \"abc\" et \"abc\" (attendu 0)        : %d\n", my_strcmp("abc", "abc"));
    printf("Comparaison \"abc\" et \"ab\"  (attendu positif)  : %d\n", my_strcmp("abc", "ab"));
    printf("Comparaison \"ab\"  et \"abc\" (attendu négatif) : %d\n", my_strcmp("ab", "abc"));

    return 0;
}