int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_alpha(char c) {
    return (is_lower(c) || is_upper(c));
}

int is_print(char c) {
    return (c >= 32 && c <= 126);
}