#include <unistd.h>
#include <stdlib.h>

char *my_itoa(int n);

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
    if (argc < 2) {
        return 1;
    }

    int count = argc - 1;

    int *tab = (int *)malloc(count * sizeof(int));
    if (tab == NULL) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        tab[i] = my_atoi_simple(argv[i + 1]);
        sum += tab[i];
    }

    char *sum_str = my_itoa(sum);
    if (sum_str != NULL) {
        my_putstr(sum_str);
        my_putstr("\n");
        free(sum_str);
    }

    int avg_int = sum / count;
    int avg_dec = ((sum * 10) / count) % 10;

    char *avg_int_str = my_itoa(avg_int);
    char *avg_dec_str = my_itoa(avg_dec);

    if (avg_int_str != NULL && avg_dec_str != NULL) {
        my_putstr(avg_int_str);
        my_putstr(".");
        my_putstr(avg_dec_str);
        my_putstr("\n");
    }

    if (avg_int_str != NULL) free(avg_int_str);
    if (avg_dec_str != NULL) free(avg_dec_str);

    free(tab);

    return 0;
}