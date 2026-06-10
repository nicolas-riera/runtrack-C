void str_sanitize(char *s) {
    while (*s != '\0') {
        if (!(*s >= 32 && *s <= 126)) {
            *s = '?';
        }
        s++;
    }
}