char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

char switch_case(char c) {
    if (c >= 'A' && c <= 'Z') {
        return to_lower(c);
    }
    if (c >= 'a' && c <= 'z') {
        return to_upper(c);
    }
    return c;
}