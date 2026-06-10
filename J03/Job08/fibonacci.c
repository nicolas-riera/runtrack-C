int fibonacci_it(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0;
    int b = 1;
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = a + b;
        a = b;
        b = res;
    }
    return res;
}

int fibonacci_rec(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}