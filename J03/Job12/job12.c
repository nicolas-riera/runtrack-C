#include <unistd.h>
#include <stdlib.h>

char *my_itoa(int n);
char *itoa_hex(int n);
int factorial(int n);
int fibonacci_it(int n);

void my_putstr(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    write(1, str, len);
}

int my_atoi_simple(char *str) {
    int res = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }

    int n = my_atoi_simple(argv[1]);

    char *dec_str = my_itoa(n);
    if (dec_str != NULL) {
        my_putstr("Décimal : ");
        my_putstr(dec_str);
        my_putstr("\n");
        free(dec_str);
    }

    char *hex_str = itoa_hex(n);
    if (hex_str != NULL) {
        my_putstr("Hexadécimal : ");
        my_putstr(hex_str);
        my_putstr("\n");
        free(hex_str);
    }

    if (n < 10 && n >= 0) {
        int fact = factorial(n);
        char *fact_str = my_itoa(fact);
        if (fact_str != NULL) {
            my_putstr("Factorielle : ");
            my_putstr(fact_str);
            my_putstr("\n");
            free(fact_str);
        }
    }

    if (n < 20 && n >= 0) {
        int fib = fibonacci_it(n);
        char *fib_str = my_itoa(fib);
        if (fib_str != NULL) {
            my_putstr("Fibonacci : ");
            my_putstr(fib_str);
            my_putstr("\n");
            free(fib_str);
        }
    }

    return 0;
}