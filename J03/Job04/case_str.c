char to_lower(char c);
char to_upper(char c);
char switch_case(char c);

void str_to_lower(char *s) {
    while (*s != '\0') {
        *s = to_lower(*s);
        s++;
    }
}

void str_to_upper(char *s) {
    while (*s != '\0') {
        *s = to_upper(*s);
        s++;
    }
}

void str_switch_case(char *s) {
    while (*s != '\0') {
        *s = switch_case(*s);
        s++;
    }
}