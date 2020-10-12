#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    int suma = 0, nr;
    for (int i = 0; i < n; ++i) {
        printf("Introduceti termenul %d din medie: ", i + 1);
        scanf("%d", &nr); // citim un nou termen pana i ajunge n si il adaugam la suma
        suma += nr;
    }
    printf("Media numerelor citite este: %.2f", (float)suma / n); // am afisat media cu doar 2 zecimale
}