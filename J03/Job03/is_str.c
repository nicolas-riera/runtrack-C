int is_digit(char c);
int is_alpha(char c);
int is_print(char c);

int str_is_digit(char *s) {
    if (*s == '\0') {
        return 0;
    }
    while (*s != '\0') {
        if (!is_digit(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int str_is_alpha(char *s) {
    if (*s == '\0') {
        return 0;
    }
    while (*s != '\0') {
        if (!is_alpha(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int str_is_print(char *s) {
    if (*s == '\0') {
        return 0;
    }
    while (*s != '\0') {
        if (!is_print(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}