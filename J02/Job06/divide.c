void divide(int *val) {
    *val /= 2;
}

int main() {

    int a = 16;

    divide(&a);

    return 0;
}