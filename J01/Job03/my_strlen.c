int my_strlen(char *c) {
    int count = 0;

    while (c[count] != '\0')
    {
        count++;
    }
    return count;
}

int main() {
    
    int len = my_strlen("Salut");

    return 0;
}