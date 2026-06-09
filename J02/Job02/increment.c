void increment(int *n) {
    (*n)++;
}

int main() {

    int a = 15;

    increment(&a);

    return 0;
}