#include <unistd.h>

int my_putchar(char c) {
    write(1, &c, 1);

    return 0;
}

int my_putstr(char *c) {
    int i = 0;

    while (c[i] != '\0')
    {
        my_putchar(c[i]);
        i++;
    }
    return 0;
}

int main() {
    my_putstr("Salut");
    return 0;
}