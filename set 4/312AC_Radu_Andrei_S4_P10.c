#include <stdio.h>

void main () {
    int vector[10], poz[10], n, p;

    printf("Dati numarul de elemente din vector: ");
    scanf("%d", &n);

    printf("Dati numarul de elemente din vectorul de pozitii: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int q = 0;
    do {
        int elem;
        printf("poz[%d] = ", q);
        scanf("%d", &elem);
        if (poz[q] >= 0 && poz[q] < n) {
            poz[q] = elem;
            q++;
        }
        else printf("Valoarea trebuie sa fie cuprinsa intre 0 si n.\n");
    } while (poz[q] >= 0 && poz[q] < n && q < p);

    for (int i = 0; i < p; ++i) {
        printf("%d ", vector[poz[i]]);
    }
}