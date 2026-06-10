#include <stdlib.h>

char *itoa_hex(int n) {
    int len = 0;
    int temp = n;

    if (n == 0) {
        len = 1;
    } else {
        while (temp > 0) {
            len++;
            temp /= 16;
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
            int rem = n % 16;
            if (rem < 10) {
                str[len] = rem + '0';
            } else {
                str[len] = (rem - 10) + 'A';
            }
            n /= 16;
        }
    }

    return str;
}