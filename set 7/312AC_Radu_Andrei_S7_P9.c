#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isVowel(char a) { 
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
    return false;
}

void main () {
    char* sir = (char*)calloc(256, sizeof(char));

    printf("Introdu un sir: ");
    scanf("%[^\n]s", sir);

    int sursa = 0, destinatie = 0;

    while (true) {
        // luam caracterul si crestem indicele din sir.
        char caracter = sir[sursa++]; 

        // daca caracter e caracterul null atunci inseamna ca am ajuns la finalul sirului
        if (caracter == '\0') break; 

        // sarim peste vocale
        if (isVowel(caracter)) continue;

        // copiem caracterul la noua destinatie
        sir[destinatie] = caracter;

        // crestem destinatia doar daca am copiat o consoana
        ++destinatie;
    }

    // adaug caracterul null la finalul sirului
    sir[destinatie] = 0;

    sir = realloc(sir, destinatie);

    printf("Sirul dupa stergerea vocalelor: %s\n", sir);

    int p, q;
    printf("Introdu 2 pozitii: ");
    scanf("%d%d", &p, &q);

    for (int i = p; i < q; ++i) {
        printf("%c", sir[i]);
    }
}