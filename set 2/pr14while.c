#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    int contor = 0;
    int nr, suma = 0;
    while (contor != n) {
        printf("Introduceti termenul %d din medie: ", contor + 1);
        scanf("%d", &nr); // citim un numar si il adaugam la suma cat timp contor != n, contor creste la fiecare pas
        suma += nr;
        contor++;
    }
    printf("Media numerelor citite = %.2f", (float)suma / n); // am afisat media cu doar 2 zecimale
}