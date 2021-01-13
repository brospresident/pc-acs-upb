#include <stdio.h>
#include <stdlib.h>

void main () {
    FILE* fisier = fopen("problema5.txt", "w+");

    if (fisier == NULL) {
        printf("Nu s-a alocat bine fisierul.");
        exit(1);
    }
    char secventa[256];
    printf("Introdu secventa de valori: ");
    scanf("%[^\n]s", secventa);

    fprintf(fisier, "%s", secventa);

    char secventaFisier[256];
    rewind(fisier);
    fgets(secventaFisier, 256, fisier);
    printf("%s", secventaFisier);
}