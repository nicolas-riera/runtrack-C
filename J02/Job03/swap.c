void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int a = 15;
    int b = 20;

    swap(&a, &b);

    return 0;
}