#include <stdio.h>

char *my_strcpy(char *dst, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

int main(void)
{
    char source[] = "Salut";
    char destination[50];

    my_strcpy(destination, source);

    printf("Source      : %s\n", source);
    printf("Destination : %s\n", destination);

    return 0;
}