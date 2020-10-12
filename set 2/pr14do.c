#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    int suma = 0, nr, contor = 0;
    do {
        printf("Introduceti termenul %d din medie: ", contor + 1);
        scanf("%d", &nr); // citim un numar si il adaugam la suma cat timp contor != n, contor creste la fiecare pas
        suma += nr;
        contor++;
    } while (contor != n);
    printf("Media numerelor citite = %.2f", (float)suma / n); // am afisat media cu doar 2 zecimale
}


/* Diferenta dintre programele cu for si while si programul cu do while este ca in cel cu do while codul va fi executat o data fara sa se verifice conditia de oprire. */