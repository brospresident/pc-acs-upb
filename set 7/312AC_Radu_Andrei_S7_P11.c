#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inlcouiesteLitere(char* sir) {
    sir[0] = toupper(sir[0]);
    sir[strlen(sir) - 1] = toupper(sir[strlen(sir) - 1]);

    for (int i = 1; i < strlen(sir) - 1; ++i) { // parcurg de la 1 la strlen(sir) - 1 deoarece primul si ultimul caracter le-am transformat deja.
        if (sir[i] == ' ' && isalpha(sir[i - 1])) {
            sir[i - 1] = toupper(sir[i - 1]);
        }
        if (sir[i] == ' ' && isalpha(sir[i + 1])) {
            sir[i + 1] = toupper(sir[i + 1]);
        }
    }
}

void main () { 
    char sir[256];

    printf("Introdu un sir: ");
    scanf("%[^\n]s", sir);

    inlcouiesteLitere(sir);

    printf("Sirul dupa modificari: \n");
    printf("%s", sir);
}