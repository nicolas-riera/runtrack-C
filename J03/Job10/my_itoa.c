#include <stdlib.h>

char *my_itoa(int n) {
    int len = 0;
    int temp = n;

    if (n == 0) {
        len = 1;
    } else {
        while (temp > 0) {
            len++;
            temp /= 10;
        }
    }

    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    str[len] = '\0';

    if (n == 0) {
        str[0] = '0';
    } else {
        while (n > 0) {
            len--;
            str[len] = (n % 10) + '0';
            n /= 10;
        }
    }

    return str;
}