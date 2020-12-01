#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isVowel(char a) { 
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
    return false;
}

void inlocuiesteVocala(char* vocala) {
    if (!isVowel(*vocala)) return;
    if (islower(*vocala)) *vocala = toupper(*vocala);
}

void main () {
    char sir[256];
    printf("Introdu un sir: ");

    scanf("%[^\n]s", sir);

    for (int i = 0; i < strlen(sir); ++i) {
        inlocuiesteVocala(&sir[i]);
    }

    printf("%s", sir);
}