#include <unistd.h>

void print_address(int *n) {
    unsigned long addr = (unsigned long)n;
    char hex_digits[] = "0123456789abcdef";
    char buffer[19];
    int i = 17;

    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[18] = '\n';

    while (i >= 2) {
        buffer[i] = hex_digits[addr & 0xF];
        addr >>= 4;
        i--;
    }

    write(1, buffer, 19);
}

int main() {

    int a = 15;

    print_address(&a);

    return 0;
}