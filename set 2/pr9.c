#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    int suma = 0, produs = 1, coeficient = 1;
    for (int i = 1; i <= n; ++i) {
        produs *= coeficient; // calculeaza ce trebuie adunat la suma, pt coeficient = 1, produs = 1 * coeficient = 1, coeficient = 2, produs = 1 * coeficient = 1 * 2 = 2, etc...
        suma += produs;
        coeficient++;
    }
    printf("suma = %d", suma);
}