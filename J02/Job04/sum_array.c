int sum_array(int *arr, int n) {
    int somme = 0;
    for (int i = 0; i < n; i++) {
        somme += *(arr + i);
    }
    return somme;
}

int main() {

    int tableau[] = {5, 10, 15, 20, 25};
    int taille = 5;
    int resultat;

    resultat = sum_array(tableau, taille);

    return 0;
}