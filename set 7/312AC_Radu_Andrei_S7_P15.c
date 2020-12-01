#include <stdio.h>
#include <string.h>
#include <ctype.h>


void main () {
    char sir[256];

    printf("Introdu o propozitie: ");
    scanf("%[^\n]s", sir);

    int cuvinte = 1;

    for (int i = 0; i < strlen(sir); ++i) {
        if (sir[i] == ' ' && isalpha(sir[i + 1])) {
            cuvinte++;
            printf("\n");
            i++;
        }
        printf("%c", sir[i]);
    }

    printf("\nSirul are %d cuvinte.", cuvinte);
}